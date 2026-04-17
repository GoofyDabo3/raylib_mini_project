#include "game_scene.hpp"

GameScene::GameScene()
{
    game_over = false;
    elapsed_time = 0.0f;
    time_limit = 60.0f;
}

void GameScene::update()
{
    if(CheckCollisionRecs(player.get_collision_rec(), slime.get_collision_rec()))
    {
        slime.attack(player);
    }
    player.update();
    slime.update();
    if(!game_over)
    {
        elapsed_time += GetFrameTime();
        if(elapsed_time >= time_limit)
        {
            game_over = true;
        }
    }
}

void GameScene::draw()
{
    DrawText(player.get_hp().c_str(), 30, 30, 30, RED);
    DrawText(TextFormat("Time: %.2f", time_limit - elapsed_time), 30, 80, 30, RED);
    slime.animate();
    if(player.animate())
    {
        game_over = true;
    }
}

bool GameScene::is_over()
{
    return game_over;
}

void GameScene::reset()
{
    game_over = false;
    elapsed_time = 0.0f;
    player.reset();
    slime.reset();
}
