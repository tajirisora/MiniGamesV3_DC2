#include"../../libOne/inc/graphic.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include "PLAYER.h"
namespace GAME14 {
    PLAYER::PLAYER(GAME* game):
        GAME_OBJECT(game){
    }
    PLAYER::~PLAYER(){}
    void PLAYER::create(){
        Player = game()->container()->data().player;
    }
    void PLAYER::init(){
        CurMedal = 0;
        CurPlayTime = 0;
        PlayTimeForBonus = 0;
        CurBBTime = 0;
        CurREGTime = 0;
        CurNumStatus = 0;

    }
    void PLAYER::update() {

    }
    void PLAYER::draw(){
        fill(Player.statusDrawAreaColor);
        rect(Player.statusDrawAreaPos.x, Player.statusDrawAreaPos.y, Player.statusDrawAreaSize.x, Player.statusDrawAreaSize.y);
    
        drawStatus(CurPlayTime, Player.textCurPlayTimeName, Player.curPlayTimeNameColor);
        drawStatus(PlayTimeForBonus, Player.textplayTimeForBonusName, Player.playTimeForBonusNameColor);
        drawStatus(CurMedal, Player.textCurMedalName, Player.curMedalNameColor);
        drawStatus(CurBBTime, Player.textCurBBTimeName, Player.curBBTimeNameColor);
        drawRatio(CurBBTime, Player.textBBRatioName, Player.BBRatioNameColor);
        drawStatus(CurREGTime, Player.textCurREGTimeName, Player.curREGTimeNameColor);
        drawRatio(CurREGTime, Player.textREGRatioName, Player.REGRatioNameColor);
        drawRatio(CurBBTime + CurREGTime, Player.textBonusRatioName, Player.BonusRatioNameColor);
    
    }
    void PLAYER::drawStatus(int curNum,const char* name, COLOR nameColor) {

        float offsetStatus = (Player.oneStatusSize * CurNumStatus);
        float namePosY = Player.nameDrawStartPos.y + offsetStatus;
        textSize(Player.nameSize);
        fill(nameColor);
        text(name, Player.nameDrawStartPos.x, namePosY);

        float adjust = (Player.drawNumSize * (std::to_string(curNum).length() - 1)) / 2;
        textSize(Player.drawNumSize);
        fill(Player.drawNumColor);
        text(curNum, Player.drawNumPosX - adjust, namePosY + Player.offsetForName);



        CurNumStatus++;
        CurNumStatus = CurNumStatus % Player.numStatus;
    }
    void PLAYER::drawRatio(int curNum, const char* name, COLOR nameColor) {
        float offsetStatus = (Player.oneStatusSize * CurNumStatus);
        float namePosY = Player.nameDrawStartPos.y + offsetStatus;
        textSize(Player.nameSize);
        fill(nameColor);
        text(name, Player.nameDrawStartPos.x, namePosY);

        float adjust = (Player.drawNumSize * (std::to_string(curNum).length() - 1)) / 2;
        textSize(Player.drawNumSize);
        fill(Player.drawNumColor);
        std::string str;
        if (curNum) {
            str = "1/";
            int ratio = floor(CurPlayTime / curNum);
            str += std::to_string(ratio);
        }
        else {
            str = "---";
        }
        text(str.c_str(), Player.drawNumPosX - adjust, namePosY + Player.offsetForName);

        CurNumStatus++;
        CurNumStatus = CurNumStatus % Player.numStatus;

    }

}