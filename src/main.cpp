#include "game.hpp"
#include "math/vector.hpp"

#include <iostream>

int main(int argc, char** argv) {
    
    GameParams params = {};
    params.window_width = 800;
    params.window_height = 600;
    params.window_title = std::string("game window");

    Game game(params);
    game.run();

    //vec3 vec = { 1.0f, 2.0f, 3.0f };
    vec3 vec;
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << sizeof(float) << " " << sizeof(vec3) << std::endl;
    
    return 0;
}
