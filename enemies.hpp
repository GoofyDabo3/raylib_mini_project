#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include "entity.hpp"
#include "player.hpp"

typedef enum{
    WALK,
    ATTACK
}EnemyState;

class Enemy : public Entity{
    private:
        textureAnimation animation[2];
        EnemyState state;
        EnemyState last_state;
        int speed;
        double current_time, attack_time, cooldown;
        bool active;
    public:
        Enemy();
        void update();
        void animate();
        Rectangle get_collision_rec();
        void attack(Player &player);
        void reset();
        bool is_inactive();
        void activate();
        ~Enemy();
};

#endif