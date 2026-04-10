#include "game_scene.hpp"

void Background::initLayer(int i, int j, const char *file, Vector2 pos, float speed)
{
    layer[i][j].texture = LoadTexture(file);
    layer[i][j].position = {pos.x, pos.y};
    layer[i][j].speed = speed;
}

Background::Background()
{
    sky.texture = LoadTexture("resources/background_3/layer_1.png");
    sky.position = {0, 0};
    sky.speed = 0;

    screenwidth = 1920;
    layer_gap = 4;

    initLayer(0, 0, "resources/background_3/layer_2.png", {0, 0}, 0.5);
    initLayer(0, 1, "resources/background_3/layer_2.png", {1920, 0},0.5);

    initLayer(1, 0, "resources/background_3/layer_3.png", {0, 0}, 1.25);
    initLayer(1, 1, "resources/background_3/layer_3.png", {1920, 0}, 1.25);

    initLayer(2, 0, "resources/background_3/layer_4.png", {0, 0}, 1.75);
    initLayer(2, 1, "resources/background_3/layer_4.png", {1920, 0}, 1.75);

    initLayer(3, 0, "resources/background_3/layer_5.png", {0, 0}, 2.25);
    initLayer(3, 1, "resources/background_3/layer_5.png", {1920, 0}, 2.25);

    initLayer(4, 0, "resources/background_3/layer_6.png", {0, 0}, 2.75);
    initLayer(4, 1, "resources/background_3/layer_6.png", {1920, 0}, 2.75);

    initLayer(5, 0, "resources/background_3/layer_7.png", {0, 0}, 3.25);
    initLayer(5, 1, "resources/background_3/layer_7.png", {1920, 0}, 3.25);

    initLayer(6, 0, "resources/background_3/layer_8.png", {0, 0}, 3.75);
    initLayer(6, 1, "resources/background_3/layer_8.png", {1920, 0}, 3.75);
}

void Background::update()
{
    DrawTextureV(sky.texture, sky.position, WHITE);
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            layer[i][j].position.x -= layer[i][j].speed;
            if(layer[i][j].position.x < -screenwidth){
                other_tile = 1 - j;
                layer[i][j].position.x = layer[i][other_tile].position.x + layer[i][other_tile].texture.width - layer_gap;
            }
        }
    }
}

void Background::draw()
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            DrawTextureV(layer[i][j].texture, layer[i][j].position, WHITE);
        }
    }
    DrawText("PRESS 'space_bar' TO JUMP", 10, 10, 25, WHITE);
    DrawText("PRESS 'x' TO CHANGE CHARACTER", 10, 45, 25, WHITE);

}

Background::~Background()
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            UnloadTexture(layer[i][j].texture);
        }
    }
}

void GameScene::update()
{
    background.update();
    player.update();
}

void GameScene::draw()
{
    background.draw();
    player.animate();
}
