#include "enemies.hpp"

Enemy::Enemy()
{
    delaycounter = 0;
    currentframe = 0;
    Speed = 3;
    origin = {
        0.0f,
        0.0f
    };
    rotation = 0.0f;
    scale = 1;
    last_state = WALK;
    state = WALK;
    speed = 5;
    hitbox_shrink = 30.0f;
    cooldown = 2.0f;
    attack_time = -cooldown;
    active = false;

    initAnimation(animation[WALK],"resources/enemy/RedSlime_Walk.png", 8);
    initAnimation(animation[ATTACK],"resources/enemy/RedSlime_Attack.png", 4);

    position = {
        static_cast<float>(GetScreenWidth()),
        GROUND
    };

    dest_rec = {
        position.x,
        position.y - animation[state].sourceRec.height * scale,
        animation[state].sourceRec.width * scale, 
        animation[state].sourceRec.height * scale
    };
}

void Enemy::update()
{
    if(active)
    {
        position.x -= speed;
        if(position.x < -dest_rec.width)
        {
            active = false;
        }
    }
}

void Enemy::animate()
{
    dest_rec = {
        position.x,
        position.y - animation[state].sourceRec.height * scale,
        animation[state].sourceRec.width * scale, 
        animation[state].sourceRec.height * scale
    };

    ++delaycounter;
    if(delaycounter >= DELAYSPEED)
    {
        delaycounter = 0;
        ++currentframe;
        currentframe%= animation[state].framecount;
        animation[state].sourceRec.x = animation[state].framewidth * currentframe;
    }
    DrawRectangleLinesEx(get_collision_rec(), 2, RED);
    DrawTexturePro(animation[state].texture, animation[state].sourceRec, dest_rec, origin, rotation, WHITE);
}

Rectangle Enemy::get_collision_rec()
{
    return {
        dest_rec.x + hitbox_shrink,
        dest_rec.y + hitbox_shrink * 3,
        dest_rec.width - hitbox_shrink * 2,
        dest_rec.height - hitbox_shrink * 3
    };
}

void Enemy::attack(Player &player)
{
    current_time = GetTime();
    if(current_time - attack_time >= cooldown)
    {
        attack_time = current_time;
        player.hurt();
    }
}

void Enemy::reset()
{
    delaycounter = 0;
    currentframe = 0;
    state = WALK;
    position = {
        static_cast<float>(GetScreenWidth()),
        GROUND
    };
}

bool Enemy::is_inactive()
{
    return !active;
}

void Enemy::activate()
{
    active = true;
}

Enemy::~Enemy()
{
    UnloadTexture(this->animation[WALK].texture);
    UnloadTexture(this->animation[ATTACK].texture);
}