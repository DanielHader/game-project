#ifndef INPUT_HPP
#define INPUT_HPP

class Input {
private:
    bool quit_flag = false;
    
    Input();
    virtual ~Input();
    
    void poll();

public:

    bool has_quit();
    
    friend class Game;
};

#endif
