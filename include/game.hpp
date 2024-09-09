#ifndef GAME_HPP
#define GAME_HPP

#include "input.hpp"

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <string>

struct GameParams {
    unsigned int window_width = 640;
    unsigned int window_height = 480;
    std::string window_title = std::string("");
};

class Game {
private:
    SDL_Window *sdl_window;
    
    bool running;
    unsigned int updates;

    Input input;

public:
    Game(const GameParams &params);
    virtual ~Game();

    void run();

protected:
    virtual void update();
    virtual void render();
};

#endif
