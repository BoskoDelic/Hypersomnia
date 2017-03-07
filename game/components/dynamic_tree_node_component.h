#pragma once
#include "game/transcendental/component_synchronizer.h"
#include "augs/math/vec2.h"
#include "augs/math/rects.h"
#include "padding_byte.h"

namespace components {
	struct dynamic_tree_node : synchronizable_component {
		enum class tree_type : unsigned char {
			SOUND_EXISTENCES,
			PARTICLE_EXISTENCES,
			RENDERABLES,
			COUNT
		};
		
		bool always_visible = false;
		bool activated = true;
		tree_type type = tree_type::RENDERABLES;

		padding_byte pad;

		ltrb aabb;

		template <class Archive>
		void serialize(Archive& ar) {
			ar(
				CEREAL_NVP(always_visible),
				CEREAL_NVP(activated),
				
				CEREAL_NVP(aabb)
			);
		}

		static dynamic_tree_node get_default(const_entity_handle);
	};
}

template<bool is_const>
class basic_dynamic_tree_node_synchronizer : public component_synchronizer_base<is_const, components::dynamic_tree_node> {
protected:
public:
	using component_synchronizer_base<is_const, components::dynamic_tree_node>::component_synchronizer_base;

	bool is_activated() const;
};

template<>
class component_synchronizer<false, components::dynamic_tree_node> : public basic_dynamic_tree_node_synchronizer<false> {
	void resubstantiation() const;
public:
	using basic_dynamic_tree_node_synchronizer<false>::basic_dynamic_tree_node_synchronizer;

	void update_proxy() const;
	void set_activated(bool) const;
};

template<>
class component_synchronizer<true, components::dynamic_tree_node> : public basic_dynamic_tree_node_synchronizer<true> {
public:
	using basic_dynamic_tree_node_synchronizer<true>::basic_dynamic_tree_node_synchronizer;
};