#include "player.hpp"
    
Player::Player()
{
    playerPosition = {
        static_cast<float>(GetScreenWidth() / 4),
        static_cast<float>(GetScreenHeight() - 300) 
    };
    delaycounter = 0;
    currentframe = 0;
    playerSpeed = 3;
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

    initAnimation(animation[PINKY][RUN],"resources/Pinky_Run.png", 6);
    initAnimation(animation[PINKY][JUMP],"resources/Pinky_Jump.png", 8);
    initAnimation(animation[PINKY][HURT],"resources/Pinky_Hurt.png", 4);
    initAnimation(animation[PINKY][DEAD],"resources/Pinky_Dead.png", 8);

    initAnimation(animation[OWLET][RUN],"resources/Owlet_Run.png", 6);
    initAnimation(animation[OWLET][JUMP],"resources/Owlet_Jump.png", 8);
    initAnimation(animation[OWLET][HURT],"resources/Owlet_Hurt.png", 4);
    initAnimation(animation[OWLET][DEAD],"resources/Owlet_Dead.png", 8);

    initAnimation(animation[DUDE][RUN],"resources/Dude_Run.png", 6);
    initAnimation(animation[DUDE][JUMP],"resources/Dude_Jump.png", 8);
    initAnimation(animation[DUDE][HURT],"resources/Dude_Hurt.png", 4);
    initAnimation(animation[DUDE][DEAD],"resources/Dude_Dead.png", 8);
}

void Player::initAnimation(textureAnimation& anim, const char* file, int frames)
{
    anim.texture = LoadTexture(file);
    anim.framecount = frames;
    anim.framewidth = anim.texture.width / anim.framecount;
    anim.frameheight = anim.texture.height;
    anim.sourceRec = {0.0f, 0.0f, anim.framewidth, anim.frameheight};
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
        playerPosition.y += jumpspeed;
        jumpspeed += GRAVITY;
        if(playerPosition.y > GROUND)
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
        playerPosition.x,
        playerPosition.y,
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
    skin = static_cast<Skin>((static_cast<int>(skin) + 1) % 3);
}

void Player::toggle_center()
{
    playerPosition = {
        static_cast<float>(GetScreenWidth() / 4),
        static_cast<float>(GROUND) 
    };
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