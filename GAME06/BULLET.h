#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
namespace GAME06
{
    class BULLET :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img = 0;
            VECTOR2 pos;
            float angle = 0.0f;
            float scale = 0.0f;
            float speed = 0.0f;
        };
    private:
        DATA Bullet;
    public:
        const VECTOR2& pos() { return Bullet.pos; }
    public:
        BULLET(class GAME* game):GAME_OBJECT(game){}
        ~BULLET(){}
        void create();
        void init();
        void update();
        void draw();
    };
}
