#include "Controller.hpp"
#include <SDL.h>
#include <iostream>

Controller::Controller( SDL_GameController* controller )
{
    this->controller = controller;

    up = false;
    up_held = false;

    down = false;
    down_held = false;

    left = false;
    left_held = false;

    right = false;
    right_held = false;

    start = false;
    start_held = false;

    select = false;
    select_held = false;

    a_button = false;
    a_button_held = false;

    b_button = false;
    b_button_held = false;

    x_button = false;
    x_button_held = false;

    y_button = false;
    y_button_held = false;

    left_shoulder = false;
    left_shoulder_held = false;

    right_shoulder = false;
    right_shoulder_held = false;
}

void Controller::update()
{
    up = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_DPAD_UP );
    //checkButton( &up, &up_held, SDL_CONTROLLER_BUTTON_DPAD_UP );
    down = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN );
    left = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT );
    right = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT );
    start = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_START );
    select = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_BACK );
    //a_button = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_A );
    checkButton( &a_button, &a_button_held, SDL_CONTROLLER_BUTTON_A );
    b_button = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_B );
    x_button = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_X );
    y_button = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_Y );
    left_shoulder = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER );
    right_shoulder = SDL_GameControllerGetButton( controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER );
}

void Controller::checkButton( bool* button, bool* button_held, SDL_GameControllerButton sdl_button )
{
    bool button_pressed = SDL_GameControllerGetButton( controller, sdl_button );

    *button_held = button_pressed && *button;
    *button = button_pressed;
}

bool Controller::upPressed()
{
    return up;
}

bool Controller::upHeld()
{
    return up_held;
}

bool Controller::downPressed()
{
    return down;
}

bool Controller::leftPressed()
{
    return left;
}

bool Controller::rightPressed()
{
    return right;
}

bool Controller::startPressed()
{
    return start;
}

bool Controller::selectPressed()
{
    return select;
}

bool Controller::aPressed()
{
    return a_button;
}

bool Controller::aHeld()
{
    return a_button_held;
}

bool Controller::bPressed()
{
    return b_button;
}

bool Controller::xPressed()
{
    return x_button;
}

bool Controller::yPressed()
{
    return y_button;
}

bool Controller::leftShoulderPressed()
{
    return left_shoulder;
}

bool Controller::rightShoulderPressed()
{
    return right_shoulder;
}
