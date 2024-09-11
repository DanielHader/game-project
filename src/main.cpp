#include "game.hpp"
#include "math/affine_transform.hpp"

#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
    
    GameParams params = {};
    params.window_width = 800;
    params.window_height = 600;
    params.window_title = std::string("game window");

    auto A = AffineTransform::from_angle_axis_offset(M_PI, glm::vec3(0, 1, 0), glm::vec3(1, 0, 0));
    glm::vec3 v(1, 0, 0);

    auto vp = A(v);

    std::cout << vp.x << " " << vp.y << " " << vp.z << std::endl;
    
    Game game(params);
    game.run();
    
    return 0;
}
