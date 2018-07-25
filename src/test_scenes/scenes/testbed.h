#pragma once
#include "game/transcendental/cosmic_entropy.h"
#include "game/transcendental/step_declaration.h"
#include "game/transcendental/standard_solver.h"

class loaded_image_caches_map;

namespace test_scenes {
	class testbed {
		entity_id populate(const loaded_image_caches_map&, const logic_step) const;
	public:
		entity_id populate_with_entities(const loaded_image_caches_map& caches, const logic_step_input input) {
			entity_id controlled;

			standard_solver(
				input,
				[&](const logic_step step) { controlled = populate(caches, step); }, 
				[](auto) {},
				[](auto) {}
			);

			return controlled;
		}
	};
}