#include "entities.hpp"
    
Entity::Entity()
{

}

Entity::~Entity()
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

void Entity::toggle_center()
{
    Position = {
        static_cast<float>(GetScreenWidth() / 4),
        static_cast<float>(GROUND) 
    };
}

Player::Player()
{
    Position = {
        static_cast<float>(GetScreenWidth() / 4),
        static_cast<float>(GetScreenHeight() - 300) 
    };
    delaycounter = 0;
    currentframe = 0;
    Speed = 3;
    origin = {
        0.0f,
        0.0f
    };
    rotation = 0.0f;
    scale = 4;
    skin = PINKY;
    last_state = RUN;
    state = RUN;
    jumpspeed = 0;

    initAnimation(animation[PINKY][RUN],"resources/player/Pinky_Run.png", 6);
    initAnimation(animation[PINKY][JUMP],"resources/player/Pinky_Jump.png", 8);
    initAnimation(animation[PINKY][HURT],"resources/player/Pinky_Hurt.png", 4);
    initAnimation(animation[PINKY][DEAD],"resources/player/Pinky_Dead.png", 8);

    initAnimation(animation[OWLET][RUN],"resources/player/Owlet_Run.png", 6);
    initAnimation(animation[OWLET][JUMP],"resources/player/Owlet_Jump.png", 8);
    initAnimation(animation[OWLET][HURT],"resources/player/Owlet_Hurt.png", 4);
    initAnimation(animation[OWLET][DEAD],"resources/player/Owlet_Dead.png", 8);

    initAnimation(animation[DUDE][RUN],"resources/player/Dude_Run.png", 6);
    initAnimation(animation[DUDE][JUMP],"resources/player/Dude_Jump.png", 8);
    initAnimation(animation[DUDE][HURT],"resources/player/Dude_Hurt.png", 4);
    initAnimation(animation[DUDE][DEAD],"resources/player/Dude_Dead.png", 8);
}

void Player::update()
{
    if(IsKeyPressed(KEY_SPACE) && state != JUMP)
    {
        state = JUMP;
        jumpspeed = -23;
    }
    if(state == JUMP)
    {
        Position.y += jumpspeed;
        jumpspeed += GRAVITY;
        if(Position.y > GROUND)
        {
            state = RUN;
            jumpspeed = 0;
            toggle_center();
        }
    }
    if(IsKeyPressed(KEY_X))
    {
        switch_skin();
    }
    last_state = state;
}

void Player::animate()
{
    if(last_state != state)
    {
        delaycounter = 0;
        currentframe = 0;
    }
    dest_rec = {
        Position.x,
        Position.y,
        animation[skin][state].sourceRec.width * scale, 
        animation[skin][state].sourceRec.height * scale
    };

    ++delaycounter;
    if(delaycounter >= DELAYSPEED)
    {
        delaycounter = 0;
        ++currentframe;
        currentframe%= animation[skin][state].framecount;
        animation[skin][state].sourceRec.x = animation[skin][state].framewidth * currentframe;
    }

    DrawTexturePro(animation[skin][state].texture, animation[skin][state].sourceRec, dest_rec, origin, rotation, WHITE);
}

void Player::switch_skin()
{
    skin = static_cast<PlayerSkin>((static_cast<int>(skin) + 1) % 3);
}

Player::~Player()
{
    UnloadTexture(this->animation[PINKY][RUN].texture);
    UnloadTexture(this->animation[PINKY][JUMP].texture);
    UnloadTexture(this->animation[PINKY][HURT].texture);
    UnloadTexture(this->animation[PINKY][DEAD].texture);

    UnloadTexture(this->animation[OWLET][RUN].texture);
    UnloadTexture(this->animation[OWLET][JUMP].texture);
    UnloadTexture(this->animation[OWLET][HURT].texture);
    UnloadTexture(this->animation[OWLET][DEAD].texture);

    UnloadTexture(this->animation[DUDE][RUN].texture);
    UnloadTexture(this->animation[DUDE][JUMP].texture);
    UnloadTexture(this->animation[DUDE][HURT].texture);
    UnloadTexture(this->animation[DUDE][DEAD].texture);
}

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

    initAnimation(animation[WALK],"resources/enemy/RedSlime_Walk.png", 8);
    initAnimation(animation[ATTACK],"resources/enemy/RedSlime_Attack.png", 4);

    Position = {
        GetScreenWidth() - animation[WALK].framewidth * scale,
        static_cast<float>(GetScreenHeight() - 300) 
    };
}

void Enemy::update()
{
    Position.x -= speed;

}

void Enemy::animate()
{
    dest_rec = {
        Position.x,
        Position.y,
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

    DrawTexturePro(animation[state].texture, animation[state].sourceRec, dest_rec, origin, rotation, WHITE);
}

Enemy::~Enemy()
{
    UnloadTexture(this->animation[WALK].texture);
    UnloadTexture(this->animation[ATTACK].texture);
}