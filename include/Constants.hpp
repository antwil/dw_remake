#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include <stdint.h>

//Screen dimension constants
const int SCREEN_WIDTH = 496;
const int SCREEN_HEIGHT = 448;
const int CAMERA_X_ADJUST = 8;
const int CAMERA_Y_ADJUST = 8;
const float TEXTURE_SCALE = 2.0;

//Player constants
const uint8_t ANIMATION_FRAMES = 2;

//Character direction constants
const uint8_t DOWN = 0;
const uint8_t LEFT = 1;
const uint8_t UP = 2;
const uint8_t RIGHT = 3;

//enum class Movement { STAY, UP, DOWN, LEFT, RIGHT };

//Tile constants
const uint8_t TILE_FOUR_STONE = 0;
const uint8_t TILE_STONE_WALL = 1;
const uint8_t TILE_COUNTER = 2;
const uint8_t TILE_BRICK_FLOOR = 3;
const uint8_t TILE_CHEST = 4;
const uint8_t TILE_DOOR_CLOSED = 5;
const uint8_t TILE_TOWN_STAIR_DOWN = 6;
const uint8_t TILE_TOWN_STAIR_UP = 7;
const uint8_t TILE_SECURITY_FLOOR = 8;
const uint8_t TILE_ARMORER_SIGN = 9;
const uint8_t TILE_INN_SIGN = 10;
const uint8_t TILE_CASTLE = 11;
const uint8_t TILE_TOWN = 12;
const uint8_t TILE_GRASS = 13;
const uint8_t TILE_FOREST = 14;
const uint8_t TILE_HILL = 15;
const uint8_t TILE_MOUNTAIN = 16;
const uint8_t TILE_CAVE = 17;
const uint8_t TILE_OUT_STAIR_DOWN = 18;
const uint8_t TILE_DESERT = 19;
const uint8_t TILE_SWAMP = 20;
const uint8_t TILE_BRIDGE = 21;
const uint8_t TILE_PRINCESS = 22;
const uint8_t TILE_WATER = 23;
const uint8_t TILE_SHORE_BOTTOM = 24;
const uint8_t TILE_SHORE_BOTTOM_LEFT = 25;
const uint8_t TILE_SHORE_LEFT = 26;
const uint8_t TILE_SHORE_UP_LEFT = 27;
const uint8_t TILE_SHORE_UP = 28;
const uint8_t TILE_SHORE_UP_RIGHT = 29;
const uint8_t TILE_SHORE_RIGHT = 30;
const uint8_t TILE_SHORE_BOTTOM_RIGHT = 31;
const uint8_t TILE_SHORE_OPEN_RIGHT = 32;
const uint8_t TILE_SHORE_OPEN_BOTTOM = 33;
const uint8_t TILE_SHORE_OPEN_LEFT = 34;
const uint8_t TILE_SHORE_OPEN_TOP = 35;
const uint8_t TILE_SHORE_UP_DOWN = 36;
const uint8_t TILE_SHORE_LEFT_RIGHT = 37;
const uint8_t TILE_BLANK = 38;

const uint8_t NUM_TILES = 39;

//Treasure types (Treasure chest or Hidden treasure)
const uint8_t TREASURE_CHEST = 0;
const uint8_t HIDDEN_ITEM = 1;

#endif // CONSTANTS_HPP_INCLUDED
