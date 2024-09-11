#include "game.hpp"
#include "math/affine_transform.hpp"

#include <iostream>

int main(int argc, char** argv) {
    
    GameParams params = {};
    params.window_width = 800;
    params.window_height = 600;
    params.window_title = std::string("game window");

    AffineTransform at;
    
    Game game(params);
    game.run();
    
    return 0;
}
