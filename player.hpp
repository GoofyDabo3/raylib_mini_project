#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

const int DELAYSPEED = 7;

typedef enum Skin{
    PINKY,
    OWLET,
    DUDE
}Skin;

typedef struct{
    Texture2D texture;
    int framecount;
    float framewidth;
    float frameheight;
    Rectangle sourceRec;
}textureAnimation;

class Player{
    private:
        textureAnimation animation[3];
        Skin skin;
        Vector2 playerPosition;
        int delaycounter;
        int currentframe;
        int playerSpeed;
        Vector2 origin;
        float rotation;
        float scale;
        Rectangle dest_rec;
    
    public:
        Player();
        void initAnimation(textureAnimation& anim, const char* file, int frames);
        void animate();
        void switch_skin();
        void toggle_center();
        ~Player();
};

#endif