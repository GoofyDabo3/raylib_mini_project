#ifndef GAME_SCENE
#define GAME_SCENE

#include <raylib.h>
#include "entities.hpp"
#include "background.hpp"

class GameScene{
    private:
        Player player;
        Enemy enemy;
        Layer foreground;
    public:
        void update();
        void draw();
};



#endif