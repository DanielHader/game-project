#include "game.hpp"
#include "graphics/shader.hpp"

#include <fstream>
#include <sstream>

#include <string>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <ratio>

Game::Game(const GameParams &params) {
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

    this->sdl_window = SDL_CreateWindow(
        params.window_title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        params.window_width,
        params.window_height,
        SDL_WINDOW_OPENGL
    );

    if (this->sdl_window == nullptr) {
        std::string message = "Unable to create window: ";
        message += SDL_GetError(); SDL_ClearError();

        throw std::runtime_error(message);
    }
    
    this->gl_context = SDL_GL_CreateContext(this->sdl_window);

    if (this->gl_context == nullptr) {
        std::string message = "Unable to create GL context: ";
        message += SDL_GetError(); SDL_ClearError();

        SDL_DestroyWindow(this->sdl_window);
        
        throw std::runtime_error(message);
    }

    glewInit();
    
    std::ifstream vs_if("../assets/shaders/test.vert");
    std::stringstream vs_ss;
    vs_ss << vs_if.rdbuf();

    std::ifstream fs_if("../assets/shaders/test.frag");
    std::stringstream fs_ss;
    fs_ss << fs_if.rdbuf();

    Shader vs(vs_ss.str(), ShaderType::Vertex);
    Shader fs(fs_ss.str(), ShaderType::Fragment);
    
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glViewport(0, 0, params.window_width, params.window_height);
}

Game::~Game() {

    if (this->gl_context != nullptr) { SDL_GL_DeleteContext(this->gl_context); }
    if (this->sdl_window != nullptr) { SDL_DestroyWindow(this->sdl_window); }

    SDL_Quit();
}

void Game::update() {
    this->updates++;

    /*
    if (this->updates % 60 == 0) {
        std::cout << this->updates << std::endl;
    }
    */
}

void Game::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    

    SDL_GL_SwapWindow(this->sdl_window);
}

void Game::run() {
    this->running = true;
    this->updates = 0;

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
        this->input.poll();
        if (this->input.has_quit()) {
            this->running = false;
            break;
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
