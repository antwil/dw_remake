#ifndef CONTROLLER_HPP_INCLUDED
#define CONTROLLER_HPP_INCLUDED

#include "SDL.h"

class Controller
{
    public:
        Controller( SDL_GameController* controller );

        void update();
        void checkButton( bool* button, bool* button_held, SDL_GameControllerButton sdl_button );

        bool upPressed();
        bool upHeld();
        bool downPressed();
        bool leftPressed();
        bool rightPressed();
        bool aPressed();
        bool aHeld();
        bool bPressed();
        bool xPressed();
        bool yPressed();
        bool startPressed();
        bool selectPressed();
        bool leftShoulderPressed();
        bool rightShoulderPressed();

    private:
        SDL_GameController* controller;

        bool up;
        bool up_held;
        bool down;
        bool down_held;
        bool left;
        bool left_held;
        bool right;
        bool right_held;
        bool start;
        bool start_held;
        bool select;
        bool select_held;
        bool a_button;
        bool a_button_held;
        bool b_button;
        bool b_button_held;
        bool x_button;
        bool x_button_held;
        bool y_button;
        bool y_button_held;
        bool left_shoulder;
        bool left_shoulder_held;
        bool right_shoulder;
        bool right_shoulder_held;
};

#endif // CONTROLLER_HPP_INCLUDED
