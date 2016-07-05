#include "behaviour_tree_system.h"

#include "game/cosmos.h"
#include "game/entity_id.h"
#include "ensure.h"

#include "game/components/behaviour_tree_component.h"

#include "game/entity_handle.h"
#include "game/step.h"

using namespace augs;

void behaviour_tree_system::evaluate_trees(fixed_step& step) {
	auto& cosmos = step.cosm;

	for (auto t : cosmos.get(processing_subjects::WITH_BEHAVIOUR_TREE)) {
		auto& behaviour_tree = t.get<components::behaviour_tree>();
		
		for (auto& t : behaviour_tree.concurrent_trees) {
			auto& tree = *t.tree_id;
			tree.evaluate_instance_of_tree(t.state);
		}
	}
}