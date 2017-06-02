#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "LTexture.hpp"
#include "Renderer.hpp"
#include "Constants.hpp"
#include "Map.hpp"
#include "Controller.hpp"
#include <SDL.h>
#include <stdio.h>
#include <string>

//The character/player/hero that will move around the screen
class Player
{
    public:
        //The dimensions of the character
        static const int PLAYER_WIDTH = 16;
        static const int PLAYER_HEIGHT = 16;

        //Initialize the variables
        Player( int xLoc, int yLoc, LTexture* spriteSheet, SDL_Renderer* renderer, SDL_Rect* camera );

        //Takes key presses and adjusts the characters position
        void handleEvent( Controller* controller, Map* map, Renderer* renderer, uint8_t* frame );

        //Render the player to the center of the screen
        void render( uint8_t frame );

        int getXTile();

        int getYTile();

        void centerCamera();

        void setLocation( int x, int y );

    private:
        int xTile;

        int yTile;

        //The players current direction
        uint8_t currentDirection;

        //The player sprite sheet
        LTexture* sprites;

        //Character sprite clips
        SDL_Rect spriteClips[ 8 ];

        SDL_Renderer* pRenderer;

        SDL_Rect* pCamera;

        //Moves the player
        void move( int xDir, int yDir, Map* map, Renderer* renderer, uint8_t* frame );

        bool talk( Map* map );
};

#endif // PLAYER_HPP_INCLUDED
