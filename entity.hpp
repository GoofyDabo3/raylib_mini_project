#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <raylib.h>

const int DELAYSPEED = 6;
const float GRAVITY = 1.1;
const int GROUND = 1080 - 230;


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
        void toggle_ground();
        ~Entity();
};

#endif