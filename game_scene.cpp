#include "game_scene.hpp"

void GameScene::update()
{
    player.update();
}

void GameScene::draw()
{
    player.animate();
}
