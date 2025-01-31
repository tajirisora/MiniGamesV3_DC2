#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class MAX_BET_BUTTON :
        public BUTTON
    {
    public:
        struct DATA{
            float moveDis;//ˆÚ“®‹——£

        };
    private:
        DATA Max_bet;
        class BET* bet;
    public:
        MAX_BET_BUTTON(GAME* game);
        ~MAX_BET_BUTTON();
        void create();
        void init();
        void update();
        void draw();
    };

}

