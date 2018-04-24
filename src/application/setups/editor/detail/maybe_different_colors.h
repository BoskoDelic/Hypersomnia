#pragma once
#include <tuple>
#include "augs/misc/imgui/imgui_scope_wrappers.h"

inline auto maybe_different_value_cols(
	const property_editor_settings& settings,
	const bool values_different
) {
	using namespace augs::imgui;

	return std::make_tuple(
		cond_scoped_style_color(values_different, ImGuiCol_FrameBg, settings.different_values_frame_bg),
		cond_scoped_style_color(values_different, ImGuiCol_FrameBgHovered, settings.different_values_frame_hovered_bg),
		cond_scoped_style_color(values_different, ImGuiCol_FrameBgActive, settings.different_values_frame_active_bg)
	);
};

inline auto maybe_disabled_cols(
	const property_editor_settings& settings,
	const bool are_disabled
) {
	using namespace augs::imgui;

	return std::make_tuple(
		cond_scoped_item_flag(are_disabled, ImGuiItemFlags_Disabled, true),
		cond_scoped_style_color(are_disabled, ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled)),
		cond_scoped_style_color(are_disabled, ImGuiCol_FrameBg, rgba(10, 10, 10, 255)),
		cond_scoped_style_color(are_disabled, ImGuiCol_FrameBgHovered, rgba(10, 10, 10, 255)),
		cond_scoped_style_color(are_disabled, ImGuiCol_FrameBgActive, rgba(10, 10, 10, 255))
	);
};
