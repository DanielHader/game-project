#include "input.hpp"

#include <SDL2/SDL.h>

Input::Input() {

}

Input::~Input() {

}

void Input::poll() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            this->quit_flag = true;
            break;
        default:
            break;
        }
    }
}

bool Input::has_quit() { return this->quit_flag; }
