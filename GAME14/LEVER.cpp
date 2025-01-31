#include"GAME14.h"
#include"CONTAINER.h"
#include "LEVER.h"
#include"LOTTERY.h"
#include"CREDIT.h"
#include"BET.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/window.h"

namespace GAME14 {
    void LEVER::create(){
        Button = game()->container()->data().leverButton;
        Lever = game()->container()->data().lever;
        MoveDis = Lever.moveDis;
        CurTime = 0.0f;
    }
    void LEVER::init(){
        Button = game()->container()->data().leverButton;
        Lever = game()->container()->data().lever;
    }
    void LEVER::update(){
        CurTime += delta;
        if (collisionCheck(Button.basePos,Button.r)) {
            Button.filterFlag = true;
            if (isTrigger(MOUSE_LBUTTON) &&
                game()->bet()->canTurnBetNum()) {
                Button.sistemFlag = true;
                Button.filterFlag = false;
            }
            if (isPress(MOUSE_LBUTTON)) {
                Button.drawFlag = true;
                Button.filterFlag = false;
            }
            else {
                Button.drawFlag = false;
            }
        }
        else {
            Button.filterFlag = false;
            Button.drawFlag = false;

        }

        if (CurTime >= Lever.waitTime &&
            !game()->reel()->tellmovereel() &&
            Button.sistemFlag) {
            game()->bet()->resetBet();
            if (game()->bet()->replayFlag()) {
                game()->bet()->useReplay();
            }

            game()->lottery()->proc();
            game()->credit()->clearCurPayout();

            CurTime -= CurTime;
            i += 1;
            Button.sistemFlag = false;
        }

    }
    void LEVER::draw(){
        fill(Button.areaColor);
        Lever.moveDis = MoveDis * (float)Button.drawFlag;
        circle(Button.basePos.x,Button.basePos.y+Lever.moveDis, Button.r*2);
        if (Button.filterFlag) {
            fill(Button.filter);
            circle(Button.basePos.x, Button.basePos.y+Lever.moveDis, Button.r*2);
        }
        print(CurTime);
        print(i);
        print(Lever.waitTime);
        print("flag");
        print(Button.sistemFlag);
    }
}