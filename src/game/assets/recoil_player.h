#pragma once
#include "augs/math/vec2.h"
#include "augs/misc/constant_size_vector.h"
#include "game/container_sizes.h"
#include "game/assets/recoil_player_id.h"

struct recoil_player {
	// GEN INTROSPECTOR struct recoil_player
	augs::constant_size_vector<real32, RECOIL_OFFSET_COUNT> offsets;
	float fallback_random_magnitude = 90;
	// END GEN INTROSPECTOR
};

struct recoil_player_instance {
	// GEN INTROSPECTOR struct recoil_player_instance
	assets::recoil_player_id id = assets::recoil_player_id::INVALID;

	real32 heat_per_shot = 1;
	real32 cooldown_speed = 0.01f; // heat/ms

	real32 current_heat = 0;
	// END GEN INTROSPECTOR

	real32 shoot_and_get_impulse(const recoil_player& meta);

	void cooldown(real32 amount_ms);
};
