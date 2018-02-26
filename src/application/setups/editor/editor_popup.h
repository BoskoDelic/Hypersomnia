#pragma once
#include <map>
#include "augs/misc/typesafe_sprintf.h"

struct editor_popup {
	template <class C>
	static editor_popup sum_all(const C& popups) {
		editor_popup result;

		// for example: 11 Error(s), 23 Warning(s)

		std::map<std::string, std::size_t> counts;

		for (const auto& p : popups) {
			counts[p.title]++;

			result.message += p.message + "\n";
			result.details += p.details + "\n";
		}

		for (const auto& e : counts) {
			result.title += typesafe_sprintf("%x %x(s), ", e.second, e.first);
		}

		if (result.title.size() >= 2) {
			result.title.pop_back();
			result.title.pop_back();
		}

		return result;
	}

	std::string title;
	std::string message;
	std::string details;

	bool details_expanded = false;
};
