#include "HOME.h"
namespace GAME14 {
    HOME::~HOME(){}
    void HOME::create(){}
    void HOME::init(){}
    void HOME::update(){}
    void HOME::draw(){
        clear(255);
        fill(0, 0, 0);
        print("HOME");

    }
    void HOME::nextScene(){
        if (isTrigger(KEY_Z)) {
            game()->changeScene(GAME::STAGE_ID);
        }

    }


}