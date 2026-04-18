#ifndef GAME_SCENE
#define GAME_SCENE

#include <raylib.h>
#include "player.hpp"
#include "enemies.hpp"
#include "background.hpp"

class GameScene{
    private:
        Player player;
        Enemy enemies[3];
        Layer foreground;
        float elapsed_time;
        float time_limit;
        float spawn_interval;
        float spawn_timer;
        int spawn_index;
        int enemies_size;
        bool game_over;
    public:
        GameScene();
        void update();
        void draw();
        bool is_over();
        void reset();
};



#endif