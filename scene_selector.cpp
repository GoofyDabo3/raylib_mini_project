#include "scene_selector.hpp"



Scene_selector::Scene_selector()
{
    previous_scene = MAIN_MENU;
    current_scene = MAIN_MENU;
}

void Scene_selector::select_scene()
{

    
    switch (current_scene)
    {
        case MAIN_MENU:
            
            break;

        case GAME:
        
            break;

        case PAUSE:

            break;

        default:
            break;
    }
}

Scene_selector::~Scene_selector()
{

}