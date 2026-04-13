#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <raylib.h>

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
        void draw(Color color);
        ~Background();
};

#endif