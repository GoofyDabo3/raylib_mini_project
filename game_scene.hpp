#ifndef GAME_SCENE
#define GAME_SCENE

#include <raylib.h>
#include "player.hpp"

typedef struct Layer
{
    Texture2D texture;
    Vector2 position;
    float speed;
}Layer;

class Background{
    private:
        Layer sky;
        Layer layer[7][2];
        int layernum;
        int screenwidth;
        int layer_gap;
        int other_tile;
        void initLayer(int i, int j, const char *file, Vector2 pos, float speed);
    public:
        Background();
        void update();
        void draw();
        ~Background();
};

class GameScene{
    private:
        Player player;
        Background background;
        Layer foreground;
    public:
        void update();
        void draw();
};


#endif