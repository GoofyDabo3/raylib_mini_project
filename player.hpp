#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

const int DELAYSPEED = 6;
const float GRAVITY = 1.1;
const int GROUND = 1080 - 300;

typedef enum Skin{
    PINKY,
    OWLET,
    DUDE
}Skin;

typedef enum State{
    RUN,
    JUMP,
    HURT,
    DEAD
}State;

typedef struct{
    Texture2D texture;
    int framecount;
    float framewidth;
    float frameheight;
    Rectangle sourceRec;
}textureAnimation;

class Player{
    private:
        textureAnimation animation[3][4];
        Skin skin;
        State state;
        State last_state;
        Vector2 playerPosition;
        int delaycounter;
        int currentframe;
        int playerSpeed;
        float rotation;
        float scale;
        Vector2 origin;
        Rectangle dest_rec;
        float jumpspeed;
    
    public:
        Player();
        void initAnimation(textureAnimation& anim, const char* file, int frames);
        void update();
        void animate();
        void switch_skin();
        void toggle_center();
        ~Player();
};

#endif