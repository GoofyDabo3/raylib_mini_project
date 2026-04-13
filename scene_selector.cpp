#include "scene_selector.hpp"

bool DrawButton(Rectangle rect, const char* text)
{
    DrawRectangleRec(rect, BLACK);
    DrawText(text, rect.x + 20, rect.y + 15, 20, WHITE);

    return CheckCollisionPointRec(GetMousePosition(), rect) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

Scene_selector::Scene_selector()
{
    previous_scene = MAIN_MENU;
    current_scene = MAIN_MENU;
    quit = false;
}

void Scene_selector::update_scenes()
{
    switch (current_scene)
    {
        case MAIN_MENU:
            background.draw(GRAY);
            if(DrawButton({100, 100, 200, 50}, "PLAY"))
            {
                current_scene = GAME;
            }
            else if(DrawButton({100, 200, 200, 50}, "QUIT") || IsKeyPressed(KEY_ESCAPE))
            {
                quit = true;
            }
            break;

        case GAME:
            background.update();
            gamescene.update();
            background.draw();
            gamescene.draw();
            
            if(IsKeyPressed(KEY_ESCAPE))
            {
                current_scene = PAUSE;
            }
            break;
        case PAUSE:
            background.draw(GRAY);
            if(DrawButton({100, 100, 200, 50}, "RESUME"))
            {
                current_scene = GAME;
            }
            else if(DrawButton({100, 200, 200, 50}, "MAIN MENU"))
            {
                current_scene = MAIN_MENU;
            }
            break;

        default:
            break;
    }
    previous_scene = current_scene;
}

Scene_selector::~Scene_selector()
{

}