#include"../../libOne/inc/graphic.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"BET.h"
#include"REEL.h"
#include "MAX_BET_BUTTON.h"
namespace GAME14 {
    MAX_BET_BUTTON::MAX_BET_BUTTON( GAME* game):
        BUTTON(game){}
    MAX_BET_BUTTON::~MAX_BET_BUTTON(){}
    void MAX_BET_BUTTON::create(){
        Button = game()->container()->data().max_bet_Button;
        Max_bet = game()->container()->data().max_betButton;
        bet = game()->bet();
    }
    void MAX_BET_BUTTON::init(){}
    void MAX_BET_BUTTON::update(){
        
        if (collisionCheck(Button.basePos, Button.areaSize)) {
            if (isTrigger(MOUSE_LBUTTON)&&
                bet->betTellVacancy()&&
                !game()->reel()->tellmovereel()
                ) {
                bet->maxBet();

            }
            if (isPress(MOUSE_LBUTTON)) {
                Button.drawFlag = true;
            }
            else {
                Button.drawFlag = false;
            }
        }
        else {
            Button.drawFlag = false;
        }
    }
    void MAX_BET_BUTTON::draw(){
        float adjustPosY = Max_bet.moveDis * Button.drawFlag;
        fill(Button.areaColor);
        rect(Button.basePos.x, Button.basePos.y+adjustPosY, Button.areaSize.x, Button.areaSize.y);
        if (collisionCheck(Button.basePos, Button.areaSize)) {
            fill(Button.filter);
            rect(Button.basePos.x, Button.basePos.y+adjustPosY, Button.areaSize.x, Button.areaSize.y);

        }
    }

}