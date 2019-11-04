#pragma once
#include "augs/filesystem/path.h"

struct cmd_line_params {
	augs::path_type exe_path;
	augs::path_type editor_target;
	bool force_update_check = false;
	bool unit_tests_only = false;
	bool help_only = false;
	bool version_only = false;
	bool start_server = false;
	bool start_dedicated_server = false;
	bool upgraded_successfully = false;
	bool should_connect = false;
	std::string connect_address;

	cmd_line_params(const int argc, const char* const * const argv) {
		exe_path = argv[0];

		if (argc > 1) {
			const auto a = std::string(argv[1]);

			if (a == "--unit-tests-only") {
				unit_tests_only = true;
			}
			else if (a == "--help" || a == "-h") {
				help_only = true;
			}
			else if (a == "--version" || a == "-v") {
				version_only = true;
			}
			else if (a == "--server") {
				start_server = true;
			}
			else if (a == "--upgraded-successfully") {
				upgraded_successfully = true;
			}
			else if (a == "--force-update-check") {
				force_update_check = true;
			}
			else if (a == "--dedicated-server") {
				start_dedicated_server = true;
			}
			else if (a == "--connect") {
				should_connect = true;
				
				if (argc > 2) {
					connect_address = argv[2];
				}
			}
			else {
				editor_target = a;
			}
		}
	}
};