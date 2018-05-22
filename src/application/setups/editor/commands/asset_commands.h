#pragma once
#include "augs/filesystem/path.h"
#include "game/assets/ids/asset_ids.h"
#include "application/setups/editor/editor_command_input.h"
#include "application/setups/editor/commands/editor_command_structs.h"
#include "application/setups/editor/commands/change_property_command.h"
#include "application/setups/editor/commands/id_allocating_command.h"
#include "application/setups/editor/detail/field_address.h"
#include "application/setups/editor/detail/get_asset_pool.h"
#include "view/viewables/all_viewables_declarations.h"
#include "view/maybe_official_path.h"
#include "augs/enums/callback_result.h"

namespace augs {
	struct introspection_access;
}

template <class id_type>
struct create_asset_id_command : id_allocating_command<id_type> {
	using base = id_allocating_command<id_type>;
	using introspect_base = base;

	// GEN INTROSPECTOR struct create_asset_id_command class id_type
	maybe_official_path<id_type> use_path;
	// END GEN INTROSPECTOR

	std::string describe() const;
	void redo(const editor_command_input in);
	void undo(const editor_command_input in);
};

template <class id_type>
struct forget_asset_id_command : id_freeing_command<id_type> {
	using base = id_freeing_command<id_type>;
	using introspect_base = base;

	// GEN INTROSPECTOR struct forget_asset_id_command class id_type
	std::string built_description;
	// END GEN INTROSPECTOR

	std::string describe() const;
	void redo(const editor_command_input in);
	void undo(const editor_command_input in);
};

template <class id_type>
struct asset_property_id {
	field_address field;

	template <class C, class Container, class F>
	void access(
		C& in,
		const Container& asset_ids,
		F callback
	) const {
		auto& definitions = get_asset_pool<id_type>(in);

		for (const auto& id : asset_ids) {
			const auto result = on_field_address(
				definitions[id],
				field,
				[&](auto& resolved_field) -> callback_result {
					return callback(resolved_field);
				}
			);

			if (callback_result::ABORT == result) {
				break;
			}
		}
	}
};

template <class id_type>
struct change_asset_property_command : change_property_command<change_asset_property_command<id_type>> {
	using introspect_base = change_property_command<change_asset_property_command>;

	// GEN INTROSPECTOR struct change_asset_property_command class id_type
	editor_command_common common;

	asset_property_id<id_type> property_id;
	std::vector<id_type> affected_assets;
	// END GEN INTROSPECTOR

	auto count_affected() const {
		return affected_assets.size();
	}

	template <class T, class F>
	void access_each_property(
		T in,
		F&& callback
	) const {
		property_id.access(
			in,
		   	affected_assets,
			continue_if_nullptr(std::forward<F>(callback))
		);
	}
};

template <class T>
struct is_create_asset_id_command : std::false_type {};

template <class T>
struct is_create_asset_id_command<create_asset_id_command<T>> : std::true_type {};

template <class T>
constexpr bool is_create_asset_id_command_v = is_create_asset_id_command<T>::value;

