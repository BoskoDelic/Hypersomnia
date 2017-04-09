#include "shape_variant.h"

#include "game/components/polygon_component.h"
#include "game/components/sprite_component.h"

#include "game/transcendental/entity_handle.h"
#include "game/transcendental/cosmos.h"

void shape_variant::from_renderable(
	const const_logic_step step,
	const entity_id id
) {
	const auto& cosmos = step.cosm;
	const auto handle = cosmos[id];
	const auto& metas = step.input.metas_of_assets;

	if (handle.has<components::sprite>()) {
		const auto& cosm = handle.get_cosmos();
		const auto sprite = handle.get<components::sprite>();

		const auto image_size = metas[sprite.tex].get_size();
		vec2 scale = sprite.get_size(metas) / image_size;

		convex_partitioned_shape coll = metas[sprite.tex].shape.get<convex_partitioned_shape>();
		coll.scale(scale);

		set(coll);
	}
	if (handle.has<components::polygon>()) {
		convex_partitioned_shape coll;

		std::vector<vec2> input;

		const auto& poly = handle.get<components::polygon>();

		input.reserve(poly.vertices.size());

		for (const auto& v : poly.vertices) {
			input.push_back(v.pos);
		}

		coll.add_concave_polygon(input);

		set(coll);
	}
}