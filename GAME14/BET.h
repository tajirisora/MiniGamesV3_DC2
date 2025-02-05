#pragma once
#include<string>
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class BET :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int maxBetNum;
            float oneBetTime;
            int turnBetNum;

            std::string drawStr;
            float strSize;
            VECTOR2 bacePos;
            float offsetPos;
            COLOR noBetColor;
            COLOR betColor;
            

        };
    private:
        DATA Bet;
        int CurBet;
        float CurTime;
        bool BetFlag;
        bool ReplayFlag;

    public:
        BET(GAME* game);
        ~BET();
        void create();
        void init();
        void update();
        void draw();
        void debagdraw();
        void replay();
        void maxBet();

        bool betTellVacancy() {
            if (CurBet >= Bet.maxBetNum) { return false; }
                                           return true;
        }
        bool canTurnBetNum() {
            if (CurBet == Bet.turnBetNum) { return true; }
            return false;
        }
        bool replayFlag() { return ReplayFlag; }
        void resetBet() { CurBet = 0; }
        void useReplay() { ReplayFlag = false; }
        void betPayout();
    };
}

