#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "LTexture.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Constants.hpp"
#include "MapInfo.hpp"
#include <SDL.h>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

//The map that the player will be navigating
class Map
{
    public:

        //Initialize the variables
        Map( LTexture* spriteSheet, SDL_Renderer* renderer, SDL_Rect* mCamera );

        //Free the map resources
        ~Map();

        //Load the map
        bool loadMap( std::string mapName );

        //Render the player to the center of the screen
        void render( uint8_t frame );

        //Get the number of rows in the entire map
        int getNumRows();

        //Get the number of columns in the entire map
        int getNumCols();

        Tile getTile(int row, int col);

        //Get the width of the map in pixels
        int getWidth();

        //Get the height of the map in pixels
        int getHeight();

        //Check if moving to this position on the map triggers an event
        void checkLocationEvent( Player* mPlayer );

        //Check if there is a door to open. If there is then open it.
        bool openDoor( int xPos, int yPos, uint8_t playerDir );

        //Check if there is a treasure chest or hidden item.
        //If there is then get the item and add it to Player's inventory
        bool getItem( int xPos, int yPos );

    private:
        //The tile sprite sheet
        LTexture* sprites;

        //Character sprite clips
        SDL_Rect spriteClips[ NUM_TILES ];

        //Map tiles
        //Tile** tiles;
        std::vector< std::vector< Tile > > tiles;
        SDL_Renderer* mRenderer;

        SDL_Rect* mCamera;

        std::string mapName;

        //Number of rows and columns in the map
        int NUM_ROWS;
        int NUM_COLS;

        //The dimensions of the map
        int MAP_WIDTH;
        int MAP_HEIGHT;

        std::map<MapPoint, std::string> exits;

        std::map<MapPoint, pair<int, string>> treasures;

        //Clear the map
        void freeTiles();

        bool validateMap( std::string mapFile );

        void loadMapInfo( std::string mapName );

        bool rotateTile( const uint8_t tileType );
};

#endif // MAP_HPP_INCLUDED
