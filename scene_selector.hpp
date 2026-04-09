#ifndef SCENE_SELECTOR_HPP
#define SCENE_SELECTOR_HPP

#include <raylib.h>
#include <vector>

typedef enum Scene_enum{
    MAIN_MENU, 
    PAUSE, 
    GAME
}Scene_enum;

class Scene_selector{
    private:
        Scene_enum current_scene;
        Scene_enum previous_scene;
    public:
        Scene_selector();
        void select_scene();
        ~Scene_selector();
};

class Scene{
    private:
        std::vector<Rectangle> buttons;
        Image backgorund;
};


#endif