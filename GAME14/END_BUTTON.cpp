#include"../../libOne/inc/window.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"REEL.h"
#include"BET.h"
#include"CREDIT.h"
#include "END_BUTTON.h"
namespace GAME14 {
    END_BUTTON::END_BUTTON(GAME* game):
        BUTTON(game){}
    END_BUTTON::~END_BUTTON(){}
    void END_BUTTON::create(){
        Button = game()->container()->data().endButton;
        End_Button = game()->container()->data().end;
    }
    void END_BUTTON::init(){
        Button.filterFlag = false;
        CurTime = 0;
    }
    void END_BUTTON::update(){
           
        if (collisionCheck(Button.basePos, Button.r)) {
            Button.filterFlag = true;
            if (isPress(MOUSE_LBUTTON)&&
                !game()->reel()->tellmovereel()&&
                !game()->bet()->replayFlag()&&
                !game()->credit()->payoutSistemFlag()
                ) {
                CurTime += delta;
            }
            else {
                CurTime = 0;
            }
        }
        else {
            Button.filterFlag = false;
        }

        if (CurTime > End_Button.stateMoveTime) {
            game()->bet()->betPayout();
            game()->changeScene(GAME::RESULT_ID);
        }
    }
    void END_BUTTON::draw(){
        fill(Button.areaColor);
        circle(Button.basePos.x, Button.basePos.y, Button.r * 2);
        if (Button.filterFlag) {
            fill(Button.filter);
            circle(Button.basePos.x, Button.basePos.y, Button.r * 2);
        }
    }

}

