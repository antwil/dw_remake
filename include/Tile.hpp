#ifndef TILE_HPP_INCLUDED
#define TILE_HPP_INCLUDED

#include "LTexture.hpp"
#include <SDL.h>
#include <stdio.h>
#include <string>

class Tile
{
    public:
        //The dimensions of the map tiles
        static const int TILE_WIDTH = 16;
        static const int TILE_HEIGHT = 16;

        //Default constructor
        Tile();

        //Initializes type
        Tile( uint8_t tileType );

        //Get the tile type
        uint8_t getType();

        //Set the tile type
        void setType( uint8_t tileType );

        //Determine if a tile can be entered by a character
        bool enterable();

    private:
        //The tile type
        uint8_t tileType;
};

#endif // TILE_HPP_INCLUDED
