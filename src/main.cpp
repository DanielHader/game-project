#include "game.hpp"

#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
    
    GameParams params = {};
    params.window_width = 800;
    params.window_height = 600;
    params.window_title = std::string("game window");

    Game game(params);
    game.run();
    
    return 0;
}
