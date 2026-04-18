#include "player.hpp"

Player::Player()
{
    hp = 100;
    skin = PINKY;
    last_state = RUN;
    state = RUN;
    delaycounter = 0;
    currentframe = 0;
    Speed = 3;
    origin = {
        0.0f,
        0.0f
    };
    rotation = 0.0f;
    scale = 4;
    jumpspeed = 0;
    hitbox_shrink = 25.0f;

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

    position = {
        static_cast<float>(GetScreenWidth() / 4),
        GROUND
    };
}

void Player::update()
{
    if(IsKeyPressed(KEY_SPACE) && state != JUMP)
    {
        state = JUMP;
        jumpspeed = -23;
    }
    if(state == JUMP || (last_state == JUMP && position.y < GROUND))
    {
        position.y += jumpspeed;
        jumpspeed += GRAVITY;
        if (position.y >= GROUND)
        {
            toggle_ground();
            if(state == JUMP)
            {
                state = RUN;
                jumpspeed = 0;
            }
        }
    }
    if(IsKeyPressed(KEY_X))
    {
        switch_skin();
    }
    last_state = state;
}

bool Player::animate()
{
    if(state == HURT && currentframe >= animation[skin][state].framecount - 1)
    {
        state = RUN;
    }
    else if(state == DEAD && currentframe >= animation[skin][state].framecount - 1)
    {
        return true;
    }
    if(last_state != state)
    {
        delaycounter = 0;
        currentframe = 0;
    }
    dest_rec = {
        position.x,
        position.y - animation[skin][state].sourceRec.height * scale,
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
    DrawRectangleLinesEx(get_collision_rec(), 2, RED);
    DrawTexturePro(animation[skin][state].texture, animation[skin][state].sourceRec, dest_rec, origin, rotation, WHITE);
    return false;
}

void Player::switch_skin()
{
    skin = static_cast<PlayerSkin>((static_cast<int>(skin) + 1) % 3);
}

std::string Player::get_hp()
{
    return "HP: " + std::to_string(hp);
}

void Player::hurt()
{
    if(state != HURT)
    {
        hp -= 20;
        currentframe = 0;
        if(hp <= 0)
        {
            die();
        }
        else
        {
            state = HURT;
        }
    }
}

void Player::die()
{
    if(state == DEAD) return;

    state = DEAD;
    currentframe = 0;
    hp = 0;
}

void Player::reset()
{
    state = RUN;
    hp = 100;
    jumpspeed = 0;
    toggle_ground();
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