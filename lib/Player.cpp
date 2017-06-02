#include "Player.hpp"
#include "Renderer.hpp"
#include "Constants.hpp"
#include "Tile.hpp"
#include "Map.hpp"
#include "Controller.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

Player::Player( int xLoc, int yLoc, LTexture* spriteSheet, SDL_Renderer* renderer, SDL_Rect* camera )
{
    xTile = xLoc;
    yTile = yLoc;

    //Set the sprite sheet
    sprites = spriteSheet;

    pRenderer = renderer;

    pCamera = camera;
    centerCamera();
    //pCamera->x = (( xTile * Tile::TILE_WIDTH + Player::PLAYER_WIDTH / 2 ) - (SCREEN_WIDTH / TEXTURE_SCALE) / 2 ) - (CAMERA_X_ADJUST/TEXTURE_SCALE);
    //pCamera->y = (( yTile * Tile::TILE_HEIGHT + Player::PLAYER_HEIGHT / 2 ) - (SCREEN_HEIGHT / TEXTURE_SCALE) / 2) ;
    //SDL_Rect camera = { CAMERA_X_ADJUST, CAMERA_Y_ADJUST, int (SCREEN_WIDTH / TEXTURE_SCALE), int (SCREEN_HEIGHT / TEXTURE_SCALE) };

    //Initialize current direction
    currentDirection = 0;

    //Set front facing sprites
    spriteClips[ 0 ].x = 3;
    spriteClips[ 0 ].y = 4;
    spriteClips[ 0 ].w = 16;
    spriteClips[ 0 ].h = 16;

    spriteClips[ 1 ].x = 19;
    spriteClips[ 1 ].y = 4;
    spriteClips[ 1 ].w = 16;
    spriteClips[ 1 ].h = 16;

    //Left facing sprites
    spriteClips[ 2 ].x = 36;
    spriteClips[ 2 ].y = 4;
    spriteClips[ 2 ].w = 12;
    spriteClips[ 2 ].h = 16;

    spriteClips[ 3 ].x = 49;
    spriteClips[ 3 ].y = 4;
    spriteClips[ 3 ].w = 12;
    spriteClips[ 3 ].h = 16;

    //Up facing sprites
    spriteClips[ 4 ].x = 61;
    spriteClips[ 4 ].y = 4;
    spriteClips[ 4 ].w = 16;
    spriteClips[ 4 ].h = 16;

    spriteClips[ 5 ].x = 77;
    spriteClips[ 5 ].y = 4;
    spriteClips[ 5 ].w = 16;
    spriteClips[ 5 ].h = 16;

    //Right facing sprites
    spriteClips[ 6 ].x = 95;
    spriteClips[ 6 ].y = 4;
    spriteClips[ 6 ].w = 12;
    spriteClips[ 6 ].h = 16;

    spriteClips[ 7 ].x = 108;
    spriteClips[ 7 ].y = 4;
    spriteClips[ 7 ].w = 12;
    spriteClips[ 7 ].h = 16;
}

void Player::handleEvent( Controller* controller, Map* map, Renderer* renderer, uint8_t* frame )
{
    if( controller->upPressed() )
    {
        currentDirection = UP;
        move( 0, -1, map, renderer, frame );
    }
    else if( controller->downPressed() )
    {
        currentDirection = DOWN;
        move( 0, 1, map, renderer, frame );
    }
    else if( controller->leftPressed() )
    {
        currentDirection = LEFT;
        move( -1, 0, map, renderer, frame );
    }
    else if( controller->rightPressed() )
    {
        currentDirection = RIGHT;
        move( 1, 0, map, renderer, frame );
    }
    else if( controller->aPressed() && ! controller->aHeld() )
    {
        if( talk( map ) )
            return;
        else if( map->openDoor( xTile, yTile, currentDirection ) )
            return;
        else if( map->getItem( xTile, yTile ) )
            return;

        return;
    }
    /*
    //If a key was pressed
    if( e.type == SDL_KEYDOWN ) //&& e.key.repeat == 0
    {
        //Change the direction character is facing
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                currentDirection = UP;
                move( 0, -1, map, renderer, frame );
                break;
            case SDLK_DOWN:
                currentDirection = DOWN;
                move( 0, 1, map, renderer, frame );
                break;
            case SDLK_LEFT:
                currentDirection = LEFT;
                move( -1, 0, map, renderer, frame );
                break;
            case SDLK_RIGHT:
                currentDirection = RIGHT;
                move( 1, 0, map, renderer, frame );
                break;
        }
    }
    else if( e.type == SDL_CONTROLLERBUTTONDOWN )
    {
        switch( e.cbutton.button )
        {
            case SDL_CONTROLLER_BUTTON_DPAD_UP:
                currentDirection = UP;
                move( 0, -1, map, renderer, frame );
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                currentDirection = DOWN;
                move( 0, 1, map, renderer, frame );
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                currentDirection = LEFT;
                move( -1, 0, map, renderer, frame );
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                currentDirection = RIGHT;
                move( 1, 0, map, renderer, frame );
                break;
        }
    }
    */
}

void Player::setLocation( int x, int y )
{
    xTile = x;
    yTile = y;
    centerCamera();
}

int Player::getXTile()
{
    return xTile;
}

int Player::getYTile()
{
    return yTile;
}

void Player::move( int xDir, int yDir, Map* map, Renderer* renderer, uint8_t* frame )
{
    if( !map->getTile(yTile + yDir, xTile + xDir).enterable() )
        return;
    int xDest = pCamera->x + xDir * Tile::TILE_WIDTH;
    int yDest = pCamera->y + yDir * Tile::TILE_HEIGHT;

    while( pCamera->x != xDest || pCamera->y != yDest )
    {
        if( pCamera->x != xDest )
        {
            pCamera->x = pCamera->x + xDir;
        }

        if( pCamera->y != yDest )
        {
            pCamera->y = pCamera->y + yDir;
        }

        //printf("pCamera->x = %d\n", pCamera->x);
        //printf("pCamera->y = %d\n", pCamera->y);

        renderer->renderAll( frame );
    }

    xTile += xDir;
    yTile += yDir;

    map->checkLocationEvent( this );
}

bool Player::talk( Map* map )
{
    return false;
}

void Player::render( uint8_t frame )
{
    SDL_Rect* currentSprite = &spriteClips[ ( currentDirection * 2 ) + ( frame / 20 ) ];
    sprites->render( (( pCamera->w - currentSprite->w ) / 2) + 4, ( pCamera->h - currentSprite->h ) / 2, pRenderer, 0, currentSprite );
}

void Player::centerCamera()
{
    pCamera->x = ( ( xTile * Tile::TILE_WIDTH + Player::PLAYER_WIDTH / 2 ) - ( SCREEN_WIDTH / TEXTURE_SCALE ) / 2 ) - ( CAMERA_X_ADJUST / TEXTURE_SCALE );
    pCamera->y = ( ( yTile * Tile::TILE_HEIGHT + Player::PLAYER_HEIGHT / 2 ) - ( SCREEN_HEIGHT / TEXTURE_SCALE ) / 2) ;
}
