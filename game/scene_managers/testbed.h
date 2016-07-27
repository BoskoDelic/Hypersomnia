#pragma once
#include <vector>
#include "game/transcendental/entity_id.h"
#include "game/transcendental/entity_handle_declaration.h"

namespace augs {
	struct machine_entropy;
}

struct cosmic_entropy;
class basic_viewing_step;
class fixed_step;
class cosmos;
class world_camera;

namespace scene_managers {
	class testbed {
	public:
		std::vector<entity_id> characters;
		unsigned current_character = 0;
		entity_id currently_controlled_character;
		std::vector<entity_id> draw_bodies;

		template <class Archive>
		void serialize(Archive& ar) {
			ar(
				CEREAL_NVP(characters),
				CEREAL_NVP(current_character),
				CEREAL_NVP(currently_controlled_character),
				CEREAL_NVP(draw_bodies)
			);
		}

		void populate_world_with_entities(fixed_step&);
		cosmic_entropy make_cosmic_entropy(augs::machine_entropy, cosmos&);
		entity_id get_controlled_entity() const;

		void inject_input_to(entity_handle);

		void pre_solve(fixed_step&);
		void post_solve(fixed_step&);
		
		void view_cosmos(basic_viewing_step&, world_camera&) const;
	};
}