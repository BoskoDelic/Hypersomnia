#pragma once

enum class client_state_type {
	NETCODE_NEGOTIATING_CONNECTION,

	PENDING_WELCOME,
	WELCOME_ARRIVED,
	RECEIVING_INITIAL_SNAPSHOT,
	IN_GAME
};

