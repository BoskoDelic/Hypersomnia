#include "test_scenes/ingredients/ingredients.h"
#include "game/assets/all_logical_assets.h"
#include "game/transcendental/cosmos.h"
#include "game/components/fixtures_component.h"

namespace test_flavours {
	void populate_crate_flavours(const populate_flavours_input in) {
		auto& caches = in.caches;
		auto flavour_with_sprite = in.flavour_with_sprite_maker();

		{
			auto& meta = flavour_with_sprite(
				test_plain_sprited_bodys::CRATE,
				test_scene_image_id::CRATE,
				render_layer::DYNAMIC_BODY
			);

			add_shape_invariant_from_renderable(meta, caches);

			test_flavours::add_standard_dynamic_body(meta);

			auto& fixtures_def = meta.get<invariants::fixtures>();

			fixtures_def.restitution = 0.8f;
			fixtures_def.density = 0.7f;
			fixtures_def.material = to_physical_material_id(test_scene_physical_material_id::WOOD);
		}

		{
			auto& meta = flavour_with_sprite(
				test_plain_sprited_bodys::BRICK_WALL,
				test_scene_image_id::BRICK_WALL,
				render_layer::DYNAMIC_BODY
			);

			add_shape_invariant_from_renderable(meta, caches);

			test_flavours::add_standard_static_body(meta);

			auto& fixtures_def = meta.get<invariants::fixtures>();

			fixtures_def.restitution = 0.0f;
			fixtures_def.density = 100.f;
			fixtures_def.material = to_physical_material_id(test_scene_physical_material_id::WOOD);
		}

		{
			auto& meta = flavour_with_sprite(
				test_plain_sprited_bodys::LAB_WALL_SMOOTH_END,
				test_scene_image_id::LAB_WALL_SMOOTH_END,
				render_layer::DYNAMIC_BODY
			);

			add_shape_invariant_from_renderable(meta, caches);

			test_flavours::add_standard_static_body(meta);

			auto& fixtures_def = meta.get<invariants::fixtures>();

			fixtures_def.restitution = 0.0f;
			fixtures_def.density = 100.f;
			fixtures_def.material = to_physical_material_id(test_scene_physical_material_id::METAL);
		}

		{
			auto& meta = flavour_with_sprite(
				test_plain_sprited_bodys::AQUARIUM_GLASS,
				test_scene_image_id::AQUARIUM_GLASS,
				render_layer::DYNAMIC_BODY,
				rgba(white.rgb(), 200)
			);

			add_shape_invariant_from_renderable(meta, caches);

			test_flavours::add_standard_static_body(meta);

			auto& fixtures_def = meta.get<invariants::fixtures>();

			fixtures_def.restitution = 0.5f;
			fixtures_def.density = 100.f;
			fixtures_def.material = to_physical_material_id(test_scene_physical_material_id::GLASS);
		}

		{
			auto& meta = flavour_with_sprite(
				test_plain_sprited_bodys::AQUARIUM_GLASS_START,
				test_scene_image_id::AQUARIUM_GLASS_START,
				render_layer::DYNAMIC_BODY,
				rgba(white.rgb(), 200)
			);

			add_shape_invariant_from_renderable(meta, caches);

			test_flavours::add_standard_static_body(meta);

			auto& fixtures_def = meta.get<invariants::fixtures>();

			fixtures_def.restitution = 0.5f;
			fixtures_def.density = 100.f;
			fixtures_def.material = to_physical_material_id(test_scene_physical_material_id::GLASS);
		}
	}
}

namespace prefabs {
	entity_handle create_crate(const logic_step step, const transformr pos) {
		const auto crate = create_test_scene_entity(step.get_cosmos(), test_plain_sprited_bodys::CRATE, pos);
		return crate;
	}

	entity_handle create_brick_wall(const logic_step step, transformr pos) {
		const auto crate = create_test_scene_entity(step.get_cosmos(), test_plain_sprited_bodys::BRICK_WALL, pos);
		return crate;
	}
}
