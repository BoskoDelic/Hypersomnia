#pragma once
#include "test_scenes/test_id_to_pool_id.h"

enum class test_scene_image_id {
	// GEN INTROSPECTOR enum class test_scene_image_id
	BLANK = 0,

	BLANK_2X2,

	CRATE,

	TRUCK_INSIDE,
	TRUCK_FRONT,

	JMIX114,

	TEST_CROSSHAIR,

	SMOKE_1,
	SMOKE_2,
	SMOKE_3,
	SMOKE_4,
	SMOKE_5,
	SMOKE_6,

	PIXEL_THUNDER_1,
	PIXEL_THUNDER_2,
	PIXEL_THUNDER_3,
	PIXEL_THUNDER_4,
	PIXEL_THUNDER_5,

	ASSAULT_RIFLE,
	BILMER2000,
	KEK9,
	URBAN_CYAN_MACHETE,

	LEWSII,
	LEWSII_MAG,

	FLOWER_PINK_1,
	FLOWER_PINK_2,
	FLOWER_PINK_3,
	FLOWER_PINK_4,
	FLOWER_PINK_5,
	FLOWER_PINK_6,
	FLOWER_PINK_7,
	FLOWER_PINK_8,
	FLOWER_PINK_9,

	FLOWER_CYAN_1,
	FLOWER_CYAN_2,
	FLOWER_CYAN_3,
	FLOWER_CYAN_4,
	FLOWER_CYAN_5,
	FLOWER_CYAN_6,
	FLOWER_CYAN_7,
	FLOWER_CYAN_8,
	FLOWER_CYAN_9,

	CONSOLE_LIGHT_1,
	CONSOLE_LIGHT_2,
	CONSOLE_LIGHT_3,

	VINDICATOR_SHOOT_1,
	VINDICATOR_SHOOT_2,
	VINDICATOR_SHOOT_3,
	VINDICATOR_SHOOT_4,
	VINDICATOR_SHOOT_5,
	VINDICATOR_SHOOT_6,
	VINDICATOR_SHOOT_7,
	VINDICATOR_SHOOT_8,
	VINDICATOR_SHOOT_9,
	VINDICATOR_SHOOT_10,
	VINDICATOR_SHOOT_11,
	VINDICATOR_SHOOT_12,
	VINDICATOR_SHOOT_13,
	VINDICATOR_SHOOT_14,
	VINDICATOR_SHOOT_15,
	VINDICATOR_SHOOT_16,
	VINDICATOR_SHOOT_17,
	VINDICATOR_SHOOT_18,
	VINDICATOR_SHOOT_19,

	DATUM_GUN_SHOOT_1,
	DATUM_GUN_SHOOT_2,
	DATUM_GUN_SHOOT_3,
	DATUM_GUN_SHOOT_4,
	DATUM_GUN_SHOOT_5,
	DATUM_GUN_SHOOT_6,
	DATUM_GUN_SHOOT_7,
	DATUM_GUN_SHOOT_8,

	SOIL,
	FLOOR,

	SAMPLE_MAGAZINE,
	SMALL_MAGAZINE,
	ROUND_TRACE,
	ELECTRIC_MISSILE,
	PINK_CHARGE,
	PINK_SHELL,
	CYAN_CHARGE,
	CYAN_SHELL,
	RED_CHARGE,
	RED_SHELL,
	GREEN_CHARGE,
	GREEN_SHELL,
	STEEL_CHARGE,
	STEEL_SHELL,
	STEEL_ROUND,

	STEEL_ROUND_REMNANT_1,
	STEEL_ROUND_REMNANT_2,
	STEEL_ROUND_REMNANT_3,

	BACKPACK,
	BROWN_BACKPACK,

	HAVE_A_PLEASANT,
	AWAKENING,
	METROPOLIS,

	BRICK_WALL,
	ROAD,
	ROAD_FRONT_DIRT,

	CAST_BLINK_1,
	CAST_BLINK_2,
	CAST_BLINK_3,
	CAST_BLINK_4,
	CAST_BLINK_5,
	CAST_BLINK_6,
	CAST_BLINK_7,
	CAST_BLINK_8,
	CAST_BLINK_9,
	CAST_BLINK_10,
	CAST_BLINK_11,
	CAST_BLINK_12,
	CAST_BLINK_13,
	CAST_BLINK_14,
	CAST_BLINK_15,
	CAST_BLINK_16,
	CAST_BLINK_17,
	CAST_BLINK_18,
	CAST_BLINK_19,

	SILVER_TROUSERS_1,
	SILVER_TROUSERS_2,
	SILVER_TROUSERS_3,
	SILVER_TROUSERS_4,
	SILVER_TROUSERS_5,

	SILVER_TROUSERS_STRAFE_1,
	SILVER_TROUSERS_STRAFE_2,
	SILVER_TROUSERS_STRAFE_3,
	SILVER_TROUSERS_STRAFE_4,
	SILVER_TROUSERS_STRAFE_5,
	SILVER_TROUSERS_STRAFE_6,
	SILVER_TROUSERS_STRAFE_7,
	SILVER_TROUSERS_STRAFE_8,
	SILVER_TROUSERS_STRAFE_9,
	SILVER_TROUSERS_STRAFE_10,

	METROPOLIS_CHARACTER_BARE_1,
	METROPOLIS_CHARACTER_BARE_2,
	METROPOLIS_CHARACTER_BARE_3,
	METROPOLIS_CHARACTER_BARE_4,
	METROPOLIS_CHARACTER_BARE_5,

	METROPOLIS_CHARACTER_RIFLE_1,
	METROPOLIS_CHARACTER_RIFLE_2,
	METROPOLIS_CHARACTER_RIFLE_3,
	METROPOLIS_CHARACTER_RIFLE_4,
	METROPOLIS_CHARACTER_RIFLE_5,
	METROPOLIS_CHARACTER_RIFLE_6,
	METROPOLIS_CHARACTER_RIFLE_7,
	METROPOLIS_CHARACTER_RIFLE_8,
	METROPOLIS_CHARACTER_RIFLE_9,
	METROPOLIS_CHARACTER_RIFLE_10,
	METROPOLIS_CHARACTER_RIFLE_11,
	METROPOLIS_CHARACTER_RIFLE_12,
	METROPOLIS_CHARACTER_RIFLE_13,
	METROPOLIS_CHARACTER_RIFLE_14,
	METROPOLIS_CHARACTER_RIFLE_15,
	METROPOLIS_CHARACTER_RIFLE_16,
	METROPOLIS_CHARACTER_RIFLE_17,
	METROPOLIS_CHARACTER_RIFLE_18,
	METROPOLIS_CHARACTER_RIFLE_19,
	METROPOLIS_CHARACTER_RIFLE_20,

	METROPOLIS_CHARACTER_AKIMBO_1,
	METROPOLIS_CHARACTER_AKIMBO_2,
	METROPOLIS_CHARACTER_AKIMBO_3,
	METROPOLIS_CHARACTER_AKIMBO_4,
	METROPOLIS_CHARACTER_AKIMBO_5,

	RESISTANCE_CHARACTER_BARE_1,
	RESISTANCE_CHARACTER_BARE_2,
	RESISTANCE_CHARACTER_BARE_3,
	RESISTANCE_CHARACTER_BARE_4,
	RESISTANCE_CHARACTER_BARE_5,

	RESISTANCE_CHARACTER_RIFLE_1,
	RESISTANCE_CHARACTER_RIFLE_2,
	RESISTANCE_CHARACTER_RIFLE_3,
	RESISTANCE_CHARACTER_RIFLE_4,
	RESISTANCE_CHARACTER_RIFLE_5,

	RESISTANCE_CHARACTER_RIFLE_SHOOT_1,
	RESISTANCE_CHARACTER_RIFLE_SHOOT_2,
	RESISTANCE_CHARACTER_RIFLE_SHOOT_3,
	RESISTANCE_CHARACTER_RIFLE_SHOOT_4,
	RESISTANCE_CHARACTER_RIFLE_SHOOT_5,

	BIG_BUBBLE_1,
	BIG_BUBBLE_2,
	BIG_BUBBLE_3,
	BIG_BUBBLE_4,
	BIG_BUBBLE_5,
	BIG_BUBBLE_6,
	BIG_BUBBLE_7,
	BIG_BUBBLE_8,
	BIG_BUBBLE_9,
	BIG_BUBBLE_10,
	BIG_BUBBLE_11,
	BIG_BUBBLE_12,
	BIG_BUBBLE_13,
	BIG_BUBBLE_14,
	BIG_BUBBLE_15,
	BIG_BUBBLE_16,
	BIG_BUBBLE_17,
	BIG_BUBBLE_18,
	BIG_BUBBLE_19,
	BIG_BUBBLE_20,
	BIG_BUBBLE_21,
	BIG_BUBBLE_22,
	BIG_BUBBLE_23,

	MEDIUM_BUBBLE_1,
	MEDIUM_BUBBLE_2,
	MEDIUM_BUBBLE_3,
	MEDIUM_BUBBLE_4,
	MEDIUM_BUBBLE_5,
	MEDIUM_BUBBLE_6,
	MEDIUM_BUBBLE_7,
	MEDIUM_BUBBLE_8,
	MEDIUM_BUBBLE_9,
	MEDIUM_BUBBLE_10,
	MEDIUM_BUBBLE_11,
	MEDIUM_BUBBLE_12,
	MEDIUM_BUBBLE_13,
	MEDIUM_BUBBLE_14,
	MEDIUM_BUBBLE_15,
	MEDIUM_BUBBLE_16,

	SMALL_BUBBLE_LB_1,
	SMALL_BUBBLE_LB_2,
	SMALL_BUBBLE_LB_3,
	SMALL_BUBBLE_LB_4,
	SMALL_BUBBLE_LB_5,
	SMALL_BUBBLE_LB_6,
	SMALL_BUBBLE_LB_7,

	SMALL_BUBBLE_LT_1,
	SMALL_BUBBLE_LT_2,
	SMALL_BUBBLE_LT_3,
	SMALL_BUBBLE_LT_4,
	SMALL_BUBBLE_LT_5,
	SMALL_BUBBLE_LT_6,
	SMALL_BUBBLE_LT_7,
	SMALL_BUBBLE_LT_8,
	SMALL_BUBBLE_LT_9,

	SMALL_BUBBLE_RB_1,
	SMALL_BUBBLE_RB_2,
	SMALL_BUBBLE_RB_3,
	SMALL_BUBBLE_RB_4,
	SMALL_BUBBLE_RB_5,
	SMALL_BUBBLE_RB_6,
	SMALL_BUBBLE_RB_7,
	SMALL_BUBBLE_RB_8,
	SMALL_BUBBLE_RB_9,

	SMALL_BUBBLE_RT_1,
	SMALL_BUBBLE_RT_2,
	SMALL_BUBBLE_RT_3,
	SMALL_BUBBLE_RT_4,
	SMALL_BUBBLE_RT_5,
	SMALL_BUBBLE_RT_6,
	SMALL_BUBBLE_RT_7,
	SMALL_BUBBLE_RT_8,
	SMALL_BUBBLE_RT_9,

	YELLOW_FISH_1,
	YELLOW_FISH_2,
	YELLOW_FISH_3,
	YELLOW_FISH_4,
	YELLOW_FISH_5,
	YELLOW_FISH_6,
	YELLOW_FISH_7,
	YELLOW_FISH_8,

	DARKBLUE_FISH_1,
	DARKBLUE_FISH_2,
	DARKBLUE_FISH_3,
	DARKBLUE_FISH_4,
	DARKBLUE_FISH_5,
	DARKBLUE_FISH_6,
	DARKBLUE_FISH_7,
	DARKBLUE_FISH_8,

	CYANVIOLET_FISH_1,
	CYANVIOLET_FISH_2,
	CYANVIOLET_FISH_3,
	CYANVIOLET_FISH_4,
	CYANVIOLET_FISH_5,
	CYANVIOLET_FISH_6,
	CYANVIOLET_FISH_7,
	CYANVIOLET_FISH_8,

	JELLYFISH_1,
	JELLYFISH_2,
	JELLYFISH_3,
	JELLYFISH_4,
	JELLYFISH_5,
	JELLYFISH_6,
	JELLYFISH_7,
	JELLYFISH_9,
	JELLYFISH_10,
	JELLYFISH_11,
	JELLYFISH_12,
	JELLYFISH_13,
	JELLYFISH_14,

	DRAGON_FISH_1,
	DRAGON_FISH_2,
	DRAGON_FISH_3,
	DRAGON_FISH_4,
	DRAGON_FISH_5,
	DRAGON_FISH_6,
	DRAGON_FISH_7,
	DRAGON_FISH_9,
	DRAGON_FISH_10,
	DRAGON_FISH_11,
	DRAGON_FISH_12,

	AQUARIUM_BOTTOM_LAMP_LIGHT,
	AQUARIUM_BOTTOM_LAMP_BODY,

	AQUARIUM_HALOGEN_1_LIGHT,
	AQUARIUM_HALOGEN_1_BODY,

	AQUARIUM_SAND_EDGE,
	AQUARIUM_SAND_CORNER,

	AQUARIUM_SAND_1,
	AQUARIUM_SAND_2,

	AQUARIUM_GLASS_START,
	AQUARIUM_GLASS,

	LAB_WALL_SMOOTH_END,
	LAB_WALL,

	LAB_WALL_CORNER_CUT,
	LAB_WALL_CORNER_SQUARE,

	WATER_SURFACE_1,
	WATER_SURFACE_2,
	WATER_SURFACE_3,
	WATER_SURFACE_4,
	WATER_SURFACE_5,
	WATER_SURFACE_6,
	WATER_SURFACE_7,
	WATER_SURFACE_8,
	WATER_SURFACE_9,
	WATER_SURFACE_10,
	WATER_SURFACE_11,
	WATER_SURFACE_12,
	WATER_SURFACE_13,
	WATER_SURFACE_14,
	WATER_SURFACE_15,
	WATER_SURFACE_16,
	WATER_SURFACE_17,
	WATER_SURFACE_18,
	WATER_SURFACE_19,
	WATER_SURFACE_20,
	WATER_SURFACE_21,
	WATER_SURFACE_22,
	WATER_SURFACE_23,
	WATER_SURFACE_24,
	WATER_SURFACE_25,
	WATER_SURFACE_26,
	WATER_SURFACE_27,
	WATER_SURFACE_28,
	WATER_SURFACE_29,
	WATER_SURFACE_30,
	WATER_SURFACE_31,
	WATER_SURFACE_32,
	WATER_SURFACE_33,

	DUNE_BIG,
	DUNE_SMALL,

	METROPOLIS_HEAD,
	RESISTANCE_HEAD,

	TRUCK_ENGINE,

	HEALTH_ICON,
	PERSONAL_ELECTRICITY_ICON,
	CONSCIOUSNESS_ICON,

	AMPLIFIER_ARM,

	SPELL_HASTE_ICON,
	SPELL_ELECTRIC_SHIELD_ICON,
	SPELL_ELECTRIC_TRIAD_ICON,
	SPELL_FURY_OF_THE_AEONS_ICON,
	SPELL_ULTIMATE_WRATH_OF_THE_AEONS_ICON,
	SPELL_EXALTATION_ICON,
	SPELL_ECHOES_OF_THE_HIGHER_REALMS_ICON,

	PERK_HASTE_ICON,
	PERK_ELECTRIC_SHIELD_ICON,

	FORCE_GRENADE,
	PED_GRENADE,
	INTERFERENCE_GRENADE,

	FORCE_GRENADE_RELEASED,
	PED_GRENADE_RELEASED,
	INTERFERENCE_GRENADE_RELEASED,
	FORCE_ROCKET,

	FAN,

	COUNT
	// END GEN INTROSPECTOR
};

inline auto to_image_id(const test_scene_image_id id) {
	return to_pool_id<assets::image_id>(id);
}
