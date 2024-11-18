#include"STOP_BUTTON.h"
#include"LEVER.h"
#include"REEL_MANAGER.h"
#include "STAGE.h"
namespace GAME14 {
    STAGE::~STAGE(){}
    void STAGE::create(){}
    void STAGE::init(){
        game()->charaInit();
    }
    void STAGE::update(){
        game()->charaUpdate();
    }
    void STAGE::draw(){
        clear(255);
        fill(0, 0, 0);
        print("STAGE");
        rectMode(CORNER);
        image(img, pos.x,pos.y);
        game()->charaDraw();
    }
    void STAGE::nextScene(){
        if (isTrigger(KEY_Z)) {
            game()->changeScene(GAME::RESULT_ID);
        }

    }

}