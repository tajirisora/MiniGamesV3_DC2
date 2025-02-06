#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
namespace GAME06 
{
    class TARGET :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img = 0;
            int type1 = 0;
            int type2 = 0;
            VECTOR2 pos;
            float angle = 0.0f;
            float scale = 0.0f;
            float speed = 0.0f;
            int vec = 0;
            float limmitH = 0.0f;
            bool collisionFlag = false;
            float collisionDirectionTimer = 0.0f;
        };
    private:
        DATA Target;
    public:
        const VECTOR2& pos() { return Target.pos; }
        bool& collisionFlag() { return Target.collisionFlag; }
    public:
        TARGET(class GAME* game):GAME_OBJECT(game){}
        ~TARGET(){}
        void create();
        void init();
        void update();
        void draw();
    };
}
