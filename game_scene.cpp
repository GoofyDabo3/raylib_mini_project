#include "game_scene.hpp"

GameScene::GameScene()
{
    game_over = false;
    elapsed_time = 0.0f;
    time_limit = 60.0f;
    spawn_index = 0;
    enemies_size = 3;
    spawn_interval = 4.0f;
    spawn_timer = 0.0f;
    enemies[spawn_index].reset();
    enemies[spawn_index].activate();
    ++spawn_index;
}

void GameScene::update()
{
    for(int i = 0; i < enemies_size; i++)
    {
        if(!enemies[i].is_inactive() && CheckCollisionRecs(player.get_collision_rec(), enemies[i].get_collision_rec()))
        {
            enemies[i].attack(player);
        }
        enemies[i].update();
    }
    if(!game_over)
    {
        elapsed_time += GetFrameTime();
        if(elapsed_time >= time_limit)
        {
            game_over = true;
        }
    }
    player.update();
    spawn_timer += GetFrameTime();
    if(spawn_timer >= spawn_interval)
    {
        if(enemies[spawn_index].is_inactive())
        {
            enemies[spawn_index].reset();
            enemies[spawn_index].activate();
            ++spawn_index;
            spawn_index %= enemies_size;
        }
        spawn_timer = 0;

        spawn_interval = 4.0f - elapsed_time / 30.0f;
        if(spawn_interval < 1.0f)
            spawn_interval = 1.0f;
    }
}

void GameScene::draw()
{
    DrawText(player.get_hp().c_str(), 30, 30, 30, RED);
    DrawText(TextFormat("Time: %.2f", time_limit - elapsed_time), 30, 80, 30, RED);
    for(int i = 0; i < enemies_size; i++)
    {
        if(!enemies[i].is_inactive())
        enemies[i].animate();
    }
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
    spawn_interval = 4.0f;
    spawn_timer = 0.0f;
    player.reset();
    for(int i = 0; i < enemies_size; i++)
    {
        enemies[i].reset();
    }
    enemies[spawn_index].activate();
    ++spawn_index;
}
