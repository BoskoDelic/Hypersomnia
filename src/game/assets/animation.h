#pragma once
#include "augs/math/declare_math.h"
#include "augs/misc/constant_size_vector.h"
#include "game/assets/ids/asset_ids.h"
#include "game/container_sizes.h"

struct animation_frame {
	// GEN INTROSPECTOR struct animation_frame
	assets::image_id image_id;
	float duration_milliseconds = 0.f;
	// END GEN INTROSPECTOR
};

using plain_animation_frames_type = augs::constant_size_vector<animation_frame, ANIMATION_FRAME_COUNT>;

struct simple_animation_advance {
	const real32 delta_ms;
	const unsigned frame_count;
};

struct simple_animation_state {
	// GEN INTROSPECTOR struct simple_animation_state
	unsigned frame_num = 0;
	real32 frame_elapsed_ms = 0.f;
	// END GEN INTROSPECTOR

	template <class F, class C>
	void advance(
		const simple_animation_advance in,
		F nth_frame_duration_ms,
		C exit_frame_callback
	) {
		frame_elapsed_ms += in.delta_ms;

		while (frame_num < in.frame_count) {
			const auto current_frame_duration = nth_frame_duration_ms(frame_num);

			if (frame_elapsed_ms > current_frame_duration) {
				frame_elapsed_ms -= current_frame_duration;
				exit_frame_callback(frame_num);
				++frame_num;
			}
			else {
				break;
			}
		}
	}

	template <class F>
	void advance(
		const simple_animation_advance in,
		F&& nth_frame_duration_ms
	) {
		advance(in, std::forward<F>(nth_frame_duration_ms), [](auto){});
	}

	bool advance(
		const real32 dt,
		const plain_animation_frames_type& source,
		const unsigned frame_offset = 0
	);
};

struct plain_animation {
	// GEN INTROSPECTOR struct plain_animation
	plain_animation_frames_type frames = {};
	// END GEN INTROSPECTOR

	auto get_image_id(const unsigned index) const {
		return frames[index].image_id;
	}

	auto get_image_id(
		const simple_animation_state& state,
	   	const unsigned frame_offset
	) const {
		return get_image_id(std::min(static_cast<unsigned>(frames.size() - 1), state.frame_num + frame_offset));
	}
};

template <class T, class = void>
struct has_frames : std::false_type {};

template <class T>
struct has_frames<T, decltype(std::declval<T&>().frames, void())> : std::true_type {};

template <class T>
constexpr bool has_frames_v = has_frames<T>::value; 
