/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "LTexture.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Renderer.hpp"
#include "Controller.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <string>

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close( int status = 0 );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene sprites
LTexture gCharacterSpriteSheetTexture;
LTexture gTileSpriteSheetTexture;

//Game controller 1 handler
SDL_GameController* pad = NULL;

//Set default direction to down
int CHARACTER_DIRECTION = 1;

bool init()
{
    //SDL_SetHint( SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1" );

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) )
    {
        printf( "Warning: Linear texture filtering not enabled!\n" );
    }

    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    if( SDL_IsGameController( 0 ))
    {
        pad = SDL_GameControllerOpen( 0 );
    }
    else
    {
        printf( "Warning: No controllers connected!\n" );
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( gRenderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Set the scale for the textures
    SDL_RenderSetScale( gRenderer, TEXTURE_SCALE, TEXTURE_SCALE );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }

    return true;
}

bool loadMedia()
{
    std::string charactersImage = "res/characters.png";

    //Load character sprite sheet texture
    if( !gCharacterSpriteSheetTexture.loadFromFile( charactersImage, gRenderer ) )
    {
        printf( "Failed to load sprite sheet texture: %s!\n", charactersImage.c_str() );
        return false;
    }

    std::string tilesImage = "res/tiles.png";

    //Load tile sprite sheet texture
    if( !gTileSpriteSheetTexture.loadFromFile( tilesImage, gRenderer ) )
    {
        printf( "Failed to load sprite sheet texture: %s!\n", tilesImage.c_str() );
        return false;
    }

    return true;
}

void close( int status )
{
    //Free loaded images
    gCharacterSpriteSheetTexture.free();
    gTileSpriteSheetTexture.free();

    //Close the game controller
    SDL_GameControllerClose( pad );

    //Destroy window and renderer
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gRenderer = NULL;
    gWindow = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    if( status != 0 )
    {
        exit( status );
    }
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
		close( 1 );
	}

	//Load media
	if( !loadMedia() )
	{
		printf( "Failed to load media!\n" );
		close( 2 );
	}
    int player_x_start = 11;
    int player_y_start = 11;

	//Level camera
    SDL_Rect camera = { 0, 0, int (SCREEN_WIDTH / TEXTURE_SCALE), int (SCREEN_HEIGHT / TEXTURE_SCALE) };

    //Initialize the player and the camera
    Player player( player_x_start, player_y_start, &gCharacterSpriteSheetTexture, gRenderer, &camera );


    Map map( &gTileSpriteSheetTexture, gRenderer, &camera );

    Renderer renderer( gRenderer, &map, &player );

    Controller gameController( pad );

    //Load the map
    std::string mapName = "overworld";
    if( !map.loadMap( mapName ) )
    {
        printf( "Failed to load map from file %s!\n", mapName.c_str() );
        close( 3 );
    }

    //Main loop flag
    bool quit = false;

    SDL_Event e;

    //Current animation frame
    uint8_t frame = 0;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            switch( e.type )
            {
                case SDL_QUIT:
                    quit = true;
                    break;

            }
        }
        gameController.update();
        player.handleEvent( &gameController, &map, &renderer, &frame );
        renderer.renderAll( &frame );

 /*       //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0x80, 0x80, 0x80, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render the map
        map.render( frame );

        //Render character to middle of screen
        player.render( frame );

        //Update screen
        SDL_RenderPresent( gRenderer );
*/
        //Go to next frame
        //++frame;

	}

	//Free resources and close SDL
	close();
	return 0;
}
