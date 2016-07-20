#include "game_gui_root.h"
#include "game/stateful_systems/gui_system.h"
#include "game/temporary_systems/physics_system.h"
#include "game/cosmos.h"
#include "game/entity_id.h"
#include "game/enums/filters.h"
#include "game/components/name_component.h"
#include "game/components/render_component.h"
#include <algorithm>

entity_id game_gui_world::get_hovered_world_entity(vec2 camera_pos) {
	auto& physics = gui_system->parent_cosmos.temporary_systems.get<physics_system>();

	auto cursor_pointing_at = camera_pos + gui_crosshair_position - size / 2;

	std::vector<vec2> v{ cursor_pointing_at, cursor_pointing_at + vec2(1, 0), cursor_pointing_at + vec2(1, 1) , cursor_pointing_at + vec2(0, 1) };
	auto hovered = physics.query_polygon(v, filters::renderable_query());

	if(hovered.entities.size() > 0) {
		std::vector<entity_id> sorted_by_visibility(hovered.entities.begin(), hovered.entities.end());
		sorted_by_visibility.erase(std::remove_if(sorted_by_visibility.begin(), sorted_by_visibility.end(), [](entity_id e) {
			return e.find<components::render>() == nullptr;
		}), sorted_by_visibility.end());

		std::sort(sorted_by_visibility.begin(), sorted_by_visibility.end(), [](entity_id a, entity_id b) {
			return a.get<components::render>().last_visibility_index > b.get<components::render>().last_visibility_index;
		});

		std::vector<entity_id> hovered_and_named;

		for (auto h : sorted_by_visibility) {
			auto named = get_first_named_ancestor(h);
			
			if (named.alive())
				hovered_and_named.push_back(named);
		}

		if (hovered_and_named.size() > 0) {
			return *hovered_and_named.begin();
		}
	}

	return entity_id();
}

