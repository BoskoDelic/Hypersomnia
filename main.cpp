#pragma once
#include "augs/global_libraries.h"
#include "application/setups/menu_setup.h"
#include "application/setups/local_setup.h"
#include "application/setups/determinism_test_setup.h"
#include "application/setups/two_clients_and_server_setup.h"
#include "application/setups/client_setup.h"
#include "application/setups/server_setup.h"
#include "application/setups/director_setup.h"

#include "application/game_window.h"
#include "game/resources/manager.h"

#include "game/scene_managers/resource_setups/all.h"
#include "game/transcendental/types_specification/all_component_includes.h"

#include <thread>

#include "augs/filesystem/file.h"
#include "augs/filesystem/directory.h"

int main(int argc, char** argv) {
	augs::global_libraries::init();
	augs::global_libraries::run_googletest(argc, argv);

	LOG(argv[0]);

	game_window window;
	window.call_config_script("config.lua", "config.local.lua");

	audio_manager::generate_alsoft_ini(window.config.enable_hrtf);
	audio_manager audio;

	resource_setups::load_standard_everything();

	const auto mode = window.get_launch_mode();
	LOG("Launch mode: %x", static_cast<int>(mode));

	switch (mode) {
	case game_window::launch_mode::MAIN_MENU:
	{
		menu_setup setup;
		setup.process(window);
	}
		break;
	case game_window::launch_mode::LOCAL:
	{
		local_setup setup;
		setup.process(window);
	}
		break;
	case game_window::launch_mode::LOCAL_DETERMINISM_TEST:
	{
		determinism_test_setup setup;
		setup.process(window);
	}
	case game_window::launch_mode::DIRECTOR:
	{
		director_setup setup;
		setup.process(window);
	}
		break;
	case game_window::launch_mode::CLIENT_AND_SERVER:
	{
		server_setup serv_setup;
		
		std::thread server_thread([&window, &serv_setup]() {
			serv_setup.process(window);
		});
		
		serv_setup.wait_for_listen_server();
		
		client_setup setup;
		setup.process(window);
		
		serv_setup.should_quit = true;
		
		server_thread.join();
	}
	break;
	case game_window::launch_mode::TWO_CLIENTS_AND_SERVER:
	{
		two_clients_and_server_setup setup;
		setup.process(window);
	}
	break;
	case game_window::launch_mode::ONLY_CLIENT:  
	{

		client_setup setup;
		setup.process(window);
	}
		break;
	case game_window::launch_mode::ONLY_SERVER: 
	{
		server_setup setup;
		setup.process(window);
	}
		break;

	default: ensure(false); break;
	}

	augs::global_libraries::deinit();
	return 0;
}