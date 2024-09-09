#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <iostream>

#include <string>
#include <chrono>
#include <ratio>

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
    
    void update() {
        this->updates++;

        if (this->updates % 60 == 0) {
            std::cout << this->updates << std::endl;
        }
    };
    void render() {};
    
public:

    Game(const GameParams &params) {

        SDL_Init(SDL_INIT_VIDEO);
        
	this->sdl_window = SDL_CreateWindow(
	    params.window_title.c_str(),
	    SDL_WINDOWPOS_UNDEFINED,
	    SDL_WINDOWPOS_UNDEFINED,
            params.window_width,
	    params.window_height,
            SDL_WINDOW_OPENGL
        );
    }

    virtual ~Game() {
        if (this->sdl_window != nullptr) SDL_DestroyWindow(this->sdl_window);
    }

    void run() {
        this->running = true;

        using std::chrono::steady_clock;
        using std::chrono::time_point;
        using std::chrono::duration;
        using std::chrono::duration_cast;

        typedef duration<double, std::ratio<1,60>> updates;
        
        time_point prev_tp = steady_clock::now();
        time_point curr_tp = steady_clock::now();
        
        updates update_accumulator;
        
        SDL_Event event;

        while (this->running) {

            // poll input events
            while(SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                    this->running = false;
                    break;
                default:
                    break;
                }
            }

            // maintain update accumulator
            curr_tp = steady_clock::now();
            update_accumulator += duration_cast<updates>(curr_tp - prev_tp);
            prev_tp = curr_tp;

            // call update for each update that has been accumulated
            while (update_accumulator.count() >= 1.0) {
                update_accumulator--;
                
                this->update();
            }

            // rendering decoupled from updates
            this->render();
        }
    }
};

int main(int argc, char** argv) {

    GameParams params = {};
    params.window_width = 800;
    params.window_height = 600;
    params.window_title = std::string("game window");
    
    Game game(params);
    game.run();

    return 0;
}
