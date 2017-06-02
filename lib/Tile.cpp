#include "Tile.hpp"
#include "Constants.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

Tile::Tile()
{
    this->tileType = 0;
}

Tile::Tile( uint8_t tileType )
{
    //Set the sprite sheet
    this->tileType = tileType;
}

uint8_t Tile::getType()
{
    return tileType;
}

void Tile::setType( uint8_t tileType )
{
    this->tileType = tileType;
}

bool Tile::enterable()
{
    switch( tileType )
    {
        case TILE_BRICK_FLOOR:
        case TILE_CHEST:
        case TILE_TOWN_STAIR_DOWN:
        case TILE_TOWN_STAIR_UP:
        case TILE_SECURITY_FLOOR:
        case TILE_CASTLE:
        case TILE_TOWN:
        case TILE_GRASS:
        case TILE_FOREST:
        case TILE_HILL:
        case TILE_CAVE:
        case TILE_OUT_STAIR_DOWN:
        case TILE_DESERT:
        case TILE_SWAMP:
        case TILE_BRIDGE: return true;
        default: return true;
    }
}
