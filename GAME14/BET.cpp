#include"../../libOne/inc/window.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include "BET.h"
namespace GAME14 {
    BET::BET(GAME* game):
        GAME_OBJECT(game){}
    BET::~BET(){}
    void BET::create(){
        Bet = game()->container()->data().bet;
        BetFlag = false;
    }
    void BET::init(){
        CurBet = 0;
        BetFlag = false;
        CurTime = 0;
    }
    void BET::update() {
        CurTime += delta;
        if (CurBet < Bet.maxBetNum &&
            CurTime >= Bet.oneBetTime &&
            (BetFlag||ReplayFlag)) {
            CurBet++;
            CurTime -= CurTime;
        }
        else if (CurBet >= Bet.maxBetNum) {
            BetFlag = false;
        }

    }
    void BET::draw(){
        textSize(Bet.strSize);
        for (int i = 0; i < Bet.maxBetNum; i++) {
            if (i < CurBet) {
                fill(Bet.betColor);
            }
            else {
                fill(Bet.noBetColor);
            }
            text(Bet.drawStr.c_str(), Bet.bacePos.x, Bet.bacePos.y - Bet.offsetPos * i);
        }
        print("BetFlag");
        print(BetFlag);
        print("CurTime");
        print(CurTime);
        print("CurBet");
        print(CurBet);
        print("ReplayFlag");
        print(ReplayFlag);
    }
    void BET::replay(){
        ReplayFlag = true;
    }
    void BET::maxBet() {
        BetFlag = true;
    }
}