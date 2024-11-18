#pragma once
#include "GAME_OBJECT.h"
namespace GAME14 {
    class LOTTERY ://フラグ抽選クラス
        public GAME_OBJECT{
    public:
        struct DATA {
            float waitTime = 0.0f;

        };
    private:
        float CurTime = 0.0f;
        bool WaitFlag = false;
        bool LotteryFlag = false;
        DATA Lottery;
    public:
        LOTTERY(class GAME* game) :
            GAME_OBJECT(game) {}
        void create();
        void init();
        void update();
        void debugdraw();
        void LotteryStart() { LotteryFlag = true; }
    };
}

