#include "entity.hpp"
    
Entity::Entity()
{

}

void Entity::initAnimation(textureAnimation& anim, const char* file, int frames)
{
    anim.texture = LoadTexture(file);
    anim.framecount = frames;
    anim.framewidth = anim.texture.width / anim.framecount;
    anim.frameheight = anim.texture.height;
    anim.sourceRec = {0.0f, 0.0f, anim.framewidth, anim.frameheight};
}

Rectangle Entity::get_collision_rec()
{
    return {
        dest_rec.x + hitbox_shrink,
        dest_rec.y + hitbox_shrink,
        dest_rec.width - hitbox_shrink * 2,
        dest_rec.height - hitbox_shrink
    };
}

void Entity::toggle_ground()
{
    position.y = GROUND;
}

Entity::~Entity()
{
    
}