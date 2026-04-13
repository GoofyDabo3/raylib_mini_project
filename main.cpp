#include <raylib.h>
#include "scene_selector.hpp"

const int width = 1920;
const int height = 1080;

int main()
{
    InitWindow(width, height, "pink monster animation");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    Scene_selector scene_selector;

    if(!IsWindowFullscreen())
    {
        ToggleFullscreen();
    }
    
    while(!scene_selector.quit)
    {
        BeginDrawing();

        // scene_selector.select_scene();
        ClearBackground(DARKGRAY);

        scene_selector.update_scenes();
        
        EndDrawing();
    }

    return 0;
}