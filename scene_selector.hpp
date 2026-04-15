#ifndef SCENE_SELECTOR_HPP
#define SCENE_SELECTOR_HPP

#include <raylib.h>
#include <vector>
#include "background.hpp"
#include "game_scene.hpp"

typedef enum Scene_enum{
    MAIN_MENU, 
    PAUSE, 
    GAME,
    OVER
}Scene_enum;

class Scene_selector{
    private:
        Scene_enum current_scene;
        Scene_enum previous_scene;
        GameScene gamescene;
        Background background;
    public:
        bool quit;
        Scene_selector();
        void update_scenes();
        ~Scene_selector();
};

class Scene{
    private:
        std::vector<Rectangle> buttons;
        Image backgorund;
};

bool DrawButton(Rectangle rect, const char* text);

#endif