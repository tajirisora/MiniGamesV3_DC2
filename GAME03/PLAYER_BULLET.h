#pragma once
#include "CHARACTER.h"
namespace GAME03 {
    class PLAYER_BULLET :public CHARACTER{
    public:
        struct DATA{
            float damageTime = 0;
            float damageInterval = 0;
        };
    private:
        DATA Player_Bullet;
    public:
        PLAYER_BULLET(class GAME* game) :CHARACTER(game) {}
        void create();
        void appear(float wx, float wy, float vx, float vy);
        void update();
        void damage();
        int op_option = false;
    };
}

