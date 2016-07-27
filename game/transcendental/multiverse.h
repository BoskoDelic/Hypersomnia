#pragma once
#include "cosmos.h"
#include "game/scene_managers/testbed.h"
#include "game/scene_managers/one_entity.h"
#include "game/transcendental/entropy_player.h"
#include "augs/misc/fixed_delta_timer.h"

class game_window;
class viewing_session;

namespace augs {
	class renderer;
}

class multiverse {
	scene_managers::testbed main_cosmos_manager;

	cosmos::significant_state stashed_cosmos;
	augs::fixed_delta_timer stashed_timer;

	augs::measurements reading_savefile = augs::measurements(L"Loading savefile", true, 1);
	augs::measurements writing_savefile = augs::measurements(L"Writing savefile", true, 1);
	augs::measurements duplication = augs::measurements(L"Duplication");

	void print_summary(augs::renderer&, const viewing_session&) const;
	std::wstring summary(bool detailed, const viewing_session&) const;
public:
	float stepping_speed = 1.f;

	bool show_profile_details = true;

	std::string recording_filename = "recorded.inputs";
	std::string save_filename = "save.state";
	std::string saves_folder = "saves/";
	std::string sessions_folder = "sessions/";

	entropy_player main_cosmos_player;

	bool try_to_load_save();
	bool try_to_load_or_save_new_session();

	multiverse();
	
	void populate_cosmoi();

	void save_cosmos_to_file(std::string);
	void load_cosmos_from_file(std::string);

	cosmos main_cosmos;
	augs::fixed_delta_timer main_cosmos_timer;

	void control(augs::machine_entropy);
	void simulate();
	void view(game_window&, viewing_session&) const;
};