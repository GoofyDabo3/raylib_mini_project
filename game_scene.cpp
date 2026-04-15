#include "game_scene.hpp"

GameScene::GameScene()
{
    game_over = false;
}

void GameScene::update()
{
    if(CheckCollisionRecs(player.get_collision_rec(), slime.get_collision_rec()))
    {
        slime.attack(player);
    }
    player.update();
    slime.update();
}

void GameScene::draw()
{
    DrawText(player.get_hp().c_str(), 30, 30, 30, RED);
    slime.animate();
    game_over = player.animate();
}

bool GameScene::is_over()
{
    return game_over;
}
