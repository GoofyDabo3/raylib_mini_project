#include "game_scene.hpp"

void GameScene::update()
{
    player.update();
    enemy.update();
}

void GameScene::draw()
{
    player.animate();
    enemy.animate();
}
