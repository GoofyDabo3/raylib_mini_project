#ifndef GAME_SCENE
#define GAME_SCENE

#include <raylib.h>
#include "entities.hpp"
#include "background.hpp"

class GameScene{
    private:
        Player player;
        Enemy slime;
        Layer foreground;
        bool game_over;
    public:
        GameScene();
        void update();
        void draw();
        bool is_over();
        void reset();
};



#endif