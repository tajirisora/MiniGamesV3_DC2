#include "RESULT.h"
namespace GAME14 {
    RESULT::~RESULT(){}
    void RESULT::create(){}
    void RESULT::init(){}
    void RESULT::update(){}
    void RESULT::draw(){
        clear(255);
        fill(0, 0, 0);
        print("RESULT");

    }
    void RESULT::nextScene(){
        if (isTrigger(KEY_Z)) {
            game()->changeScene(GAME::HOME_ID);
        }

    }

}