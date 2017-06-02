#ifndef RENDERER_HPP_INCLUDED
#define RENDERER_HPP_INCLUDED

#include "LTexture.hpp"
#include "Constants.hpp"
#include <SDL.h>
#include <stdio.h>
#include <string>

//Forward declare the map and player classes
//We are only using pointers to these classes so no probs here.
//Using '#include' would give circular dependencies that the header guards
//will block and the compiler will complain.
class Player;
class Map;

class Renderer
{
    public:
        Renderer( SDL_Renderer* renderer, Map* map, Player* player );

        void renderAll( uint8_t* frame );

    private:
        SDL_Renderer* rRenderer;

        Map* rMap;

        Player* rPlayer;
};

#endif // RENDERER_HPP_INCLUDED
