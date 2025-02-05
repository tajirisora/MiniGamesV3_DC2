#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class END_BUTTON :
        public BUTTON
    {
    public:
        struct DATA {
            float stateMoveTime;//ステートを変えるのに必要な時間
        };
    private:
        DATA End_Button;
        float CurTime;
    public:
        END_BUTTON(GAME* game);
        ~END_BUTTON();
        void create();
        void init();
        void update();
        void draw();
    };
}

