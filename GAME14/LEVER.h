#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include "BUTTON.h"
namespace GAME14 {
    class LEVER :
        public BUTTON{
    public:
        struct DATA {
            float moveDis;//ˆÚ“®‹——£
            float waitTime = 0.0f;


        };
    private:
        DATA Lever;
        float MoveDis;
        float CurTime;
        int i = 0;
    public:
        LEVER(GAME* game):
            BUTTON(game){}
        void create();
        void init();
        void update();
        void draw();

    };
}

