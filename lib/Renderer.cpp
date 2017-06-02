#include "Tile.hpp"
#include "Renderer.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

Renderer::Renderer( SDL_Renderer* renderer, Map* map, Player* player )
{
    rRenderer = renderer;
    rMap = map;
    rPlayer = player;
}

void Renderer::renderAll( uint8_t* frame )
{
    //Clear screen
    SDL_SetRenderDrawColor( rRenderer, 0x80, 0x80, 0x80, 0xFF );
    SDL_RenderClear( rRenderer );

    //Render the map
    rMap->render( *frame );

    //Render character to middle of screen
    rPlayer->render( *frame );

    //Update screen
    SDL_RenderPresent( rRenderer );

    (*frame)++;

    //Cycle animation
    if( *frame / 20 >= ANIMATION_FRAMES )
    {
        *frame = 0;
    }
}

