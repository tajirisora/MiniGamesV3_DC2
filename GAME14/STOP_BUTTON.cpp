#include"CONTAINER.h"
#include"GAME14.h"
#include"REEL.h"
#include "STOP_BUTTON.h"
namespace GAME14 {
    STOP_BUTTON::~STOP_BUTTON(){
        delete[] StopButton;
    }
    void STOP_BUTTON::create(){
        Button = game()->container()->data().stopButton;
        StopButtons = game()->container()->data().stop;
        StopButton = new STOP_BUTTONS[StopButtons.numButton];
        for (int i = 0; i < StopButtons.numButton; i++) {
            StopButton[i].pos.x = Button.basePos.x - StopButtons.offset * (i - 1);
            StopButton[i].pos.y = Button.basePos.y;
            StopButton[i].drawFlag = false;
            StopButton[i].sistemFlag = false;
        }
    }
    void STOP_BUTTON::init(){
        Button = game()->container()->data().stopButton;
        StopButtons = game()->container()->data().stop;
        for (int i = 0; i < StopButtons.numButton; i++) {
            StopButton[i].buttonId = i;
            StopButton[i].pos.x = Button.basePos.x + StopButtons.offset * (i - 1);
            StopButton[i].pos.y = Button.basePos.y;
            StopButton[i].drawFlag = false;
            StopButton[i].sistemFlag = false;

        }

    }
    void STOP_BUTTON::update(){
        if (!Button.sistemFlag) {
            for (int i = 0; i < StopButtons.numButton; i++) {
                if (collisionCheck(StopButton[i].pos, Button.r)) {
                    if (isTrigger(MOUSE_LBUTTON)) {
                        if (game()->reel()->tellmovereel(i)) {
                            game()->reel()->stop(i);
                        }
                        StopButton[i].sistemFlag = true;
                    }
                    if (isPress(MOUSE_LBUTTON)) {
                        StopButton[i].drawFlag = true;
                    }
                    else {
                        StopButton[i].drawFlag = false;
                    }
                }

            }
        }

    }
    void STOP_BUTTON::draw(){
        
        for (int i = 0; i < StopButtons.numButton; i++) {
            fill(Button.areaColor);
            circle(StopButton[i].pos.x, Button.basePos.y, Button.r*2);
            if (collisionCheck(StopButton[i].pos, Button.r)) {
               fill(Button.filter);
               circle(StopButton[i].pos.x, Button.basePos.y, Button.r*2);
            }
        }
    }
    /*bool STOP_BUTTON::sistemFlag(int buttonId) {
        for (int i = 0; i < StopButtons.numButton; i++) {
            if (StopButton[i].buttonId == buttonId) {
                return StopButton[i].sistemFlag;
            }
        }
    }
    */
}