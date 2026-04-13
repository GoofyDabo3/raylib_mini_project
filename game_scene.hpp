#ifndef GAME_SCENE
#define GAME_SCENE

#include <raylib.h>
#include "player.hpp"
#include "background.hpp"

class GameScene{
    private:
        Player player;
        Layer foreground;
    public:
        void update();
        void draw();
};



#endif