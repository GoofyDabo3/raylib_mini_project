#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "entity.hpp"

typedef enum{
    PINKY,
    OWLET,
    DUDE
}PlayerSkin;

typedef enum{
    RUN,
    JUMP,
    HURT,
    DEAD
}PlayerState;

class Player : public Entity{
    private:
        textureAnimation animation[3][4];
        PlayerSkin skin;
        PlayerState state;
        PlayerState last_state;
        float jumpspeed;
        int hp;
        
    public:
        Player();
        void update();
        bool animate();
        void switch_skin();
        std::string get_hp();
        void hurt();
        void die();
        void reset();
        ~Player();
};

#endif