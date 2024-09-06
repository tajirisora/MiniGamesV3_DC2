#include "STAGE.h"
namespace GAME14 {
    STAGE::~STAGE(){}
    void STAGE::create(){}
    void STAGE::init(){}
    void STAGE::update(){}
    void STAGE::draw(){
        clear(255);
        fill(0, 0, 0);
        print("STAGE");

    }
    void STAGE::nextScene(){
        if (isTrigger(KEY_Z)) {
            game()->changeScene(GAME::RESULT_ID);
        }

    }

}