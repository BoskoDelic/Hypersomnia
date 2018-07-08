#pragma once
#include "augs/drawing/flip.h"
#include "augs/drawing/drawing.h"

class interpolation_system;
struct randomizing_system;
class images_in_atlas_map;

struct specific_draw_input {
	const augs::drawer drawer;
	const images_in_atlas_map& manager;
	const double global_time_seconds;
	const flip_flags flip;
	randomizing_system& randomizing;
};

struct draw_renderable_input : specific_draw_input {
	const interpolation_system& interp;
};