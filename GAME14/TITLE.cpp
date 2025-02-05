#include"CONTAINER.h"
#include "TITLE.h"
namespace GAME14 {
    TITLE::~TITLE(){}
    void TITLE::create(){
        Title = game()->container()->data().title;
    }
    void TITLE::init(){
    }
    void TITLE::update(){}
    void TITLE::draw(){
        clear(Title.backColor);
        fill(Title.strColor);
        textSize(Title.strSize);
        text(Title.str,Title.strPos.x,Title.strPos.y);
        fill(Title.msgColor);
        textSize(Title.msgSize);
        text(Title.msg, Title.msgPos.x, Title.msgPos.y);
        int adjust = (Title.msgSize * Title.msg2.length()) / 4;
        text(Title.msg2.c_str(), Title.msg2Pos.x-adjust, Title.msg2Pos.y);
    }
    void TITLE::nextScene(){
        if (isTrigger(MOUSE_LBUTTON)) {
            game()->changeScene(GAME::STAGE_ID);
        }
    }

}