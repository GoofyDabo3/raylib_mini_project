#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

const int DELAYSPEED = 6;
const float GRAVITY = 1.1;
const int GROUND = 1080 - 300;

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
        Vector2 Position;
        int delaycounter;
        int currentframe;
        int Speed;
        float rotation;
        float scale;
        Vector2 origin;
        Rectangle dest_rec;
    
    public:
        Entity();
        void initAnimation(textureAnimation& anim, const char* file, int frames);
        void toggle_center();
        ~Entity();
};

class Player:Entity{
    private:
        textureAnimation animation[3][4];
        PlayerSkin skin;
        PlayerState state;
        PlayerState last_state;
        float jumpspeed;
    
    public:
        Player();
        void update();
        void animate();
        void switch_skin();
        ~Player();
};

class Enemy:Entity{
    private:
        textureAnimation animation[2];
        EnemyState state;
        EnemyState last_state;
        int speed;

    public:
        Enemy();
        void update();
        void animate();
        ~Enemy();
};

#endif