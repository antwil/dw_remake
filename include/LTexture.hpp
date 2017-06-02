#ifndef LTEXTURE_HPP_INCLUDED
#define LTEXTURE_HPP_INCLUDED

#include <SDL.h>
#include <stdio.h>
#include <string>

//Texture wrapper class
class LTexture
{
    public:
        //Initialize variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( std::string imgPath, SDL_Renderer* renderer );

        //Deallocates texture
        void free();

        //Set color modulation
        void setColor( Uint8 red, Uint8 green, Uint8 blue );

        //Set blending
        void setBlendMode( SDL_BlendMode blending );

        //Set alpha modulation
        void setAlpha( Uint8 alpha );

        //Renders texture at given point
        void render( int x, int y, SDL_Renderer* renderer, double angle, SDL_Rect* clip = NULL );

        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};

#endif // LTEXTURE_HPP_INCLUDED
