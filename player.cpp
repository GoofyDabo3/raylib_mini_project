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

    initAnimation(animation[PINKY],"resources/Pinky_Run.png", 6);
    initAnimation(animation[OWLET],"resources/Owlet_Run.png", 6);
    initAnimation(animation[DUDE],"resources/Dude_Run.png", 6);
}

void Player::initAnimation(textureAnimation& anim, const char* file, int frames)
{
    anim.texture = LoadTexture(file);
    anim.framecount = frames;
    anim.framewidth = anim.texture.width / anim.framecount;
    anim.frameheight = anim.texture.height;
    anim.sourceRec = {0.0f, 0.0f, anim.framewidth, anim.frameheight};
}

/* void Player::update()
{
    skin = PINKY;
    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT))
    {
        skin = OWLET;
        if(IsKeyDown(KEY_LEFT_SHIFT))
        {
            skin = DUDE;
        }
    }
    

    if(IsKeyDown(KEY_RIGHT)){
        animation[skin].sourceRec.width = animation[skin].framewidth;
        playerPosition.x+= playerSpeed;
        if(skin == DUDE)
        {
            playerPosition.x+= playerSpeed;
        }
        animation[PINKY].sourceRec.width = animation[PINKY].framewidth;
    }else if(IsKeyDown(KEY_LEFT)){
        animation[skin].sourceRec.width = -animation[skin].framewidth;
        playerPosition.x-= playerSpeed;
        if(skin == DUDE)
        {
            playerPosition.x-= playerSpeed;
        }

        animation[PINKY].sourceRec.width = -animation[PINKY].framewidth;
    }

} */

void Player::animate()
{
    dest_rec = {
        playerPosition.x,
        playerPosition.y,
        animation[skin].sourceRec.width * scale, 
        animation[skin].sourceRec.height * scale
    };

    ++delaycounter;
    if(delaycounter >= DELAYSPEED)
    {
        delaycounter = 0;
        ++currentframe;
        currentframe%= animation[skin].framecount;
        animation[skin].sourceRec.x = animation[skin].framewidth * currentframe;
    }

    DrawTexturePro(animation[skin].texture, animation[skin].sourceRec, dest_rec, origin, rotation, WHITE);
}

void Player::switch_skin()
{
    skin = static_cast<Skin>((static_cast<int>(skin) + 1) % 3);
}

void Player::toggle_center()
{
    playerPosition = {
        static_cast<float>(GetScreenWidth() / 4),
        static_cast<float>(GetScreenHeight() - 300) 
    };
}

Player::~Player()
{
    UnloadTexture(this->animation[PINKY].texture);
    UnloadTexture(this->animation[OWLET].texture);
    UnloadTexture(this->animation[DUDE].texture);
}