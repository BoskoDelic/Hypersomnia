#pragma once
#include <optional>
#include "augs/misc/time_utils.h"

struct editor_command_common {
	// GEN INTROSPECTOR struct editor_command_common
	std::time_t timestamp = {};
	bool has_parent = false;
	// END GEN INTROSPECTOR

	void reset_timestamp() {
		timestamp = augs::date_time();
	}
};
