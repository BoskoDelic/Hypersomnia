#include "game/common_state/entity_flavours.h"
#include "test_scenes/test_scene_flavours.h"
#include "test_scenes/ingredients/ingredients.h"
#include "test_scenes/test_scene_animations.h"
#include "test_scenes/test_scene_images.h"

#include "augs/templates/enum_introspect.h"
#include "augs/string/format_enum.h"

void populate_test_scene_flavours(const populate_flavours_input in) {
	test_flavours::populate_grenade_flavours(in);
	test_flavours::populate_character_flavours(in);
	test_flavours::populate_gun_flavours(in);
	test_flavours::populate_other_flavours(in);
	test_flavours::populate_car_flavours(in);
	test_flavours::populate_crate_flavours(in);
	test_flavours::populate_decoration_flavours(in);
	test_flavours::populate_melee_flavours(in);
	test_flavours::populate_backpack_flavours(in);
}

namespace test_flavours {
	void populate_other_flavours(const populate_flavours_input in) {
		auto& flavours = in.flavours;
		auto flavour_with_sprite = in.flavour_with_sprite_maker();

		{
			auto& meta = get_test_flavour(flavours, test_static_lights::STRONG_LAMP);

			invariants::light light; 
			meta.set(light);
		}

		{
			auto& meta = get_test_flavour(flavours, test_static_lights::AQUARIUM_LAMP);

			invariants::light light; 
			light.constant.base_value = 75;
			light.quadratic.base_value = 631;
			meta.set(light);
		}

		{
			auto& meta = get_test_flavour(flavours, test_wandering_pixels_decorations::WANDERING_PIXELS);

			{
				invariants::render render_def;
				render_def.layer = render_layer::WANDERING_PIXELS_EFFECTS;

				meta.set(render_def);
			}

			invariants::wandering_pixels wandering;
			wandering.animation_id = to_animation_id(test_scene_plain_animation_id::WANDERING_PIXELS_ANIMATION);
			meta.set(wandering);
		}

		{
			auto& meta = get_test_flavour(flavours, test_wandering_pixels_decorations::AQUARIUM_PIXELS_LIGHT);

			{
				invariants::render render_def;
				render_def.layer = render_layer::WANDERING_PIXELS_EFFECTS;

				meta.set(render_def);
			}

			{
				invariants::wandering_pixels wandering;
				wandering.animation_id = to_animation_id(test_scene_plain_animation_id::WANDERING_PIXELS_ANIMATION);
				wandering.max_direction_ms = 2000;
				wandering.max_direction_ms = 700;
				wandering.base_velocity = { 2, 20 };
				meta.set(wandering);
			}

			{
				components::wandering_pixels wandering;
				wandering.keep_particles_within_bounds = true;
				wandering.colorize = { 234, 228, 201, 255 };
				wandering.particles_count = 15;
				wandering.size = { 750, 750 };
				meta.set(wandering);
			}
		}

		{
			auto& meta = get_test_flavour(flavours, test_wandering_pixels_decorations::AQUARIUM_PIXELS_DIM);

			{
				invariants::render render_def;
				render_def.layer = render_layer::DIM_WANDERING_PIXELS_EFFECTS;

				meta.set(render_def);
			}

			{
				invariants::wandering_pixels wandering;
				wandering.animation_id = to_animation_id(test_scene_plain_animation_id::WANDERING_PIXELS_ANIMATION);
				wandering.max_direction_ms = 500;
				wandering.direction_interp_ms = 300;
				wandering.base_velocity = { 40, 120 };
				meta.set(wandering);
			}

			{
				components::wandering_pixels wandering;
				wandering.keep_particles_within_bounds = true;
				wandering.colorize = { 234, 228, 201, 255 };
				wandering.particles_count = 500;
				wandering.size = { 750, 750 };
				meta.set(wandering);
			}
		}

		{
			auto& meta = flavour_with_sprite(
				test_sprite_decorations::SOIL,
				test_scene_image_id::SOIL,
				render_layer::GROUND,
				gray1
			);

			invariants::ground ground_def;

			footstep_effect_input dirt;
			dirt.sound.id = to_sound_id(test_scene_sound_id::FOOTSTEP_DIRT);
			dirt.sound.modifier.gain = .35f;
			dirt.particles.id = to_particle_effect_id(test_scene_particle_effect_id::FOOTSTEP_SMOKE);

			ground_def.footstep_effect.emplace(dirt);

			meta.set(ground_def);
		}

		flavour_with_sprite(
			test_sprite_decorations::ROAD_DIRT,
			test_scene_image_id::ROAD_FRONT_DIRT,
			render_layer::FLOOR_AND_ROAD
		);

		flavour_with_sprite(
			test_sprite_decorations::ROAD,
			test_scene_image_id::ROAD,
			render_layer::FLOOR_AND_ROAD
		);

		{
			auto& meta = flavour_with_sprite(
				test_sprite_decorations::FLOOR,
				test_scene_image_id::FLOOR,
				render_layer::FLOOR_AND_ROAD
			);

			invariants::ground ground_def;

			footstep_effect_input dirt;
			dirt.sound.id = to_sound_id(test_scene_sound_id::FOOTSTEP_FLOOR);
			dirt.sound.modifier.gain = .6f;
			dirt.sound.modifier.pitch = .9f;
			dirt.particles.id = to_particle_effect_id(test_scene_particle_effect_id::FOOTSTEP_SMOKE);

			ground_def.footstep_effect.emplace(dirt);

			meta.set(ground_def);
		}

		flavour_with_sprite(
			test_sprite_decorations::HAVE_A_PLEASANT,
			test_scene_image_id::HAVE_A_PLEASANT,
			render_layer::NEON_CAPTIONS
		);

		flavour_with_sprite(
			test_sprite_decorations::AWAKENING,
			test_scene_image_id::AWAKENING,
			render_layer::NEON_CAPTIONS,
			white,
			augs::sprite_special_effect::COLOR_WAVE
		);

		flavour_with_sprite(
			test_sprite_decorations::METROPOLIS,
			test_scene_image_id::METROPOLIS,
			render_layer::NEON_CAPTIONS
		);
	}
}
