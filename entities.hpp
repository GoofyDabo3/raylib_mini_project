#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>
#include <iostream>

const int DELAYSPEED = 6;
const float GRAVITY = 1.1;
const int GROUND = 1080 - 230;

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

typedef enum{
    WALK,
    ATTACK
}EnemyState;

typedef struct{
    Texture2D texture;
    int framecount;
    float framewidth;
    float frameheight;
    Rectangle sourceRec;
}textureAnimation;

class Entity{
    protected:
        Vector2 position;
        int delaycounter;
        int currentframe;
        int Speed;
        float rotation;
        float scale;
        Vector2 origin;
        Rectangle dest_rec;
        float hitbox_shrink;
    
    public:
        Entity();
        void initAnimation(textureAnimation& anim, const char* file, int frames);
        Rectangle get_collision_rec();
        void toggle_center();
        ~Entity();
};

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

class Enemy : public Entity{
    private:
        textureAnimation animation[2];
        EnemyState state;
        EnemyState last_state;
        int speed;
        double current_time, attack_time, cooldown;
    public:
        Enemy();
        void update();
        void animate();
        Rectangle get_collision_rec();
        void attack(Player &player);
        void reset();
        ~Enemy();
};

#endif