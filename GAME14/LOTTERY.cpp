#include"GAME14.h"
#include"../../libOne/inc/window.h"
#include"CONTAINER.h"
#include"REEL_MANAGER.h"
#include "LOTTERY.h"
namespace GAME14 {
    void LOTTERY::create() {
        Lottery = game()->container()->data().lottery;
    }
    void LOTTERY::init() {
        CurTime = 0;
    }
    void LOTTERY::update(){
        if (LotteryFlag) {
            CurTime += delta;
        }
        if (CurTime > Lottery.waitTime) {
            LotteryFlag = false;
            CurTime = 0;
            game()->reelManager()->reelMove();
        }
    }
    void LOTTERY::debugdraw(){
        print(CurTime);
    }

}