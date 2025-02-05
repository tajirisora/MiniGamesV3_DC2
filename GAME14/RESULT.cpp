#include"GAME14.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include "RESULT.h"
namespace GAME14 {
    RESULT::~RESULT(){}
    void RESULT::create(){
        Result = game()->container()->data().result;
    }
    void RESULT::init(){
        ResultNum = game()->player()->result();
    }
    void RESULT::update(){}
    void RESULT::draw(){
        clear(Result.backColor);

        fill(Result.textColor);
        textSize(Result.textSize);
        int adjust = (Result.textSize * (Result.text.length() - 1)) / 4;
        text(Result.text.c_str(), Result.textPos.x-adjust, Result.textPos.y);
        
        std::string str = Result.resultNumText;
        str += std::to_string(ResultNum)+"–‡";
        fill(Result.resultNumColor);
        textSize(Result.resultNumSize);
        adjust = (Result.resultNumSize * (str.length() - 1)) / 4;
        text(str.c_str(), Result.resultNumPos.x-adjust, Result.resultNumPos.y);

        str = Result.resultText;
        if (ResultNum >= 0) {
            fill(Result.resultWinColor);
            str += "+";
        }
        else {
            fill(Result.resultLossColor);
        }
        textSize(Result.resultSize);
        str+= std::to_string(ResultNum*Result.rato) + "‰~";
        adjust = (Result.resultSize * (str.length() - 1)) / 4;
        text(str.c_str(), Result.resultPos.x - adjust, Result.resultPos.y);

        textSize(Result.messageSize);
        fill(Result.messageColor);
        adjust = (Result.messageSize * (Result.message.length()-1)) / 4;
        text(Result.message.c_str(), Result.messagePos.x-adjust, Result.messagePos.y);
        adjust = (Result.messageSize * (Result.message2.length())) / 4;
        text(Result.message2.c_str(), Result.message2Pos.x - adjust, Result.message2Pos.y);
    }
    void RESULT::nextScene(){
        if (isTrigger(KEY_Z)) {
            game()->changeScene(GAME::TITLE_ID);
        }

    }

}