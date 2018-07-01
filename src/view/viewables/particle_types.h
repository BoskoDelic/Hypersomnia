#pragma once
#include "augs/drawing/drawing.h"
#include "augs/math/vec2.h"
#include "view/viewables/particle_types_declaration.h"
#include "augs/graphics/rgba.h"
#include "game/transcendental/entity_id.h"

#include "game/detail/view_input/particle_effect_modifier.h"
#include "game/assets/all_logical_assets.h"
#include "game/assets/asset_pools.h"
#include "game/assets/animation.h"

#include "augs/drawing/sprite_helpers.h"

template <class T, class = void>
struct has_lifetime : std::false_type {};

template <class T>
struct has_lifetime<T, decltype(std::declval<T&>().current_lifetime_ms, void())> : std::true_type {};

template <class T>
constexpr bool has_lifetime_v = has_lifetime<T>::value;

struct draw_particles_input {
	augs::drawer output;
	bool use_neon_map = false;
};

struct general_particle {
	// GEN INTROSPECTOR struct general_particle
	vec2 pos;
	vec2 vel;
	vec2 acc;
	assets::image_id image_id;
	rgba color = white;
	vec2i size;
	float rotation = 0.f;
	float rotation_speed = 0.f;
	float linear_damping = 0.f;
	float angular_damping = 0.f;
	float current_lifetime_ms = 0.f;
	float max_lifetime_ms = 0.f;
	float shrink_when_ms_remaining = 0.f;
	float unshrinking_time_ms = 0.f;

	int alpha_levels = -1;
	// END GEN INTROSPECTOR

	void integrate(const float dt);

	template <class M>
	void draw_as_sprite(
		const M& manager,
		const draw_particles_input in
	) const {
		float size_mult = 1.f;

		if (shrink_when_ms_remaining > 0.f) {
			const auto alivity_multiplier = std::min(1.f, (max_lifetime_ms - current_lifetime_ms) / shrink_when_ms_remaining);

			size_mult *= sqrt(alivity_multiplier);

			//const auto desired_alpha = static_cast<rgba_channel>(alivity_multiplier * static_cast<float>(temp_alpha));
			//
			//if (fade_on_disappearance) {
			//	if (alpha_levels > 0) {
			//		face.color.a = desired_alpha == 0 ? 0 : ((255 / alpha_levels) * (1 + (desired_alpha / (255 / alpha_levels))));
			//	}
			//	else {
			//		face.color.a = desired_alpha;
			//	}
			//}
		}

		if (unshrinking_time_ms > 0.f) {
			size_mult *= std::min(1.f, (current_lifetime_ms / unshrinking_time_ms)*(current_lifetime_ms / unshrinking_time_ms));
		}

		auto draw = [&](const vec2i drawn_size) {
			if (in.use_neon_map) {
				augs::detail_neon_sprite(in.output.output_buffer, manager, image_id, drawn_size, pos, rotation, color);
			}
			else {
				augs::detail_sprite(in.output.output_buffer, manager, image_id, drawn_size, pos, rotation, color);
			}
		};

		if (size_mult != 1.f) {
			if (const auto target_size = vec2i(vec2(size) * size_mult); target_size.area() > 1) {
				draw(target_size);
			}
		}
		else {
			draw(size);
		}
	}

	bool is_dead() const;

	void set_position(const vec2);
	void set_velocity(const vec2);
	void set_acceleration(const vec2);
	void multiply_size(const float);
	void set_rotation(const float);
	void set_rotation_speed(const float);
	void set_max_lifetime_ms(const float);
	void colorize(const rgba);

	void set_image(assets::image_id, vec2i size, rgba);
};

struct animation_in_particle {
	// GEN INTROSPECTOR struct animation_in_particle
	float speed_factor = 1.f;

	assets::plain_animation_id id;
	simple_animation_state state;
	// END GEN INTROSPECTOR

	void advance(const real32 dt, const plain_animations_pool& anims) {
		if (state.advance(dt * speed_factor, anims[id].frames)) {
			speed_factor = -1.f;
		}
	}

	auto get_image_id(const plain_animations_pool& anims) const {
		return anims[id].get_image_id(state);
	}

	bool is_dead() const {
		return speed_factor <= 0.f;
	}

	bool should_integrate(const plain_animations_pool& anims) const {
		const auto& stop = anims[id].meta.stop_movement_at_frame;

		if (stop.is_enabled) {
			if (state.frame_num >= stop.value) {
				return false;
			}
		}

		return true;
	}
};

struct animated_particle {
	// GEN INTROSPECTOR struct animated_particle
	vec2 pos;
	vec2 vel;
	vec2 acc;
	animation_in_particle animation;
	float linear_damping = 0.f;

	rgba color = white;
	// END GEN INTROSPECTOR

	void integrate(const float dt, const plain_animations_pool& anims);

	template <class M>
	void draw_as_sprite(
		const M& manager,
		const plain_animations_pool& anims,
		const draw_particles_input in
	) const {
		const auto image_id = animation.get_image_id(anims);

		if (in.use_neon_map) {
			augs::detail_neon_sprite(in.output.output_buffer, manager, image_id, pos, 0, color);
		}
		else {
			augs::detail_sprite(in.output.output_buffer, manager, image_id, pos, 0, color);
		}
	}

	bool is_dead() const {
		return animation.is_dead();
	}

	void set_position(const vec2);
	void set_velocity(const vec2);
	void set_acceleration(const vec2);
	void multiply_size(const float);
	void set_rotation(const float);
	void set_rotation_speed(const float);
	void set_max_lifetime_ms(const float);
	void colorize(const rgba);
};

struct homing_animated_particle {
	// GEN INTROSPECTOR struct homing_animated_particle
	vec2 pos;
	vec2 vel;
	vec2 acc;

	float linear_damping = 0.f;
	float homing_force = 3000.f;

	animation_in_particle animation;
	rgba color = white;

	simple_animation_state animation_state;
	// END GEN INTROSPECTOR

	void integrate(
		const float dt, 
		const vec2 homing_target,
		const plain_animations_pool& anims
	);

	template <class M>
	void draw_as_sprite(
		const M& manager,
		const plain_animations_pool& anims,
		const draw_particles_input in
	) const {
		const auto image_id = animation.get_image_id(anims);

		if (in.use_neon_map) {
			augs::detail_neon_sprite(in.output.output_buffer, manager, image_id, pos, 0, color);
		}
		else {
			augs::detail_sprite(in.output.output_buffer, manager, image_id, pos, 0, color);
		}
	}

	bool is_dead() const {
		return animation.is_dead();
	}

	void set_position(const vec2);
	void set_velocity(const vec2);
	void set_acceleration(const vec2);
	void multiply_size(const float);
	void set_rotation(const float);
	void set_rotation_speed(const float);
	void set_max_lifetime_ms(const float);
	void colorize(const rgba);
};

template <class T>
T& apply_to_particle(const particle_effect_modifier& m, T& p) {
	p.colorize(m.colorize);

	if constexpr(has_lifetime_v<T>) {
		p.max_lifetime_ms *= m.scale_lifetimes;
	}

	return p;
}