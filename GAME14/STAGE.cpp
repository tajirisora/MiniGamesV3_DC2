#include"GAME14.h"
#include"CONTAINER.h"
#include"REEL.h"
#include "STAGE.h"
namespace GAME14 {
    STAGE::~STAGE(){}
    void STAGE::create(){
        Stage = game()->container()->data().stage;
    }
    void STAGE::init(){
        game()->charaInit();
    }
    void STAGE::update(){
        game()->charaUpdate();
    }
    void STAGE::draw(){
        clear(0);
        rectMode(CORNER);
        //image(img, pos.x,pos.y);
        fill(Stage.textColor);
        textSize(Stage.textSize);
        for (int i = 0; i < Stage.numText; i++) {
            text(Stage.text[i], Stage.startPos.x, Stage.startPos.y + Stage.offsetPosY * i);
        }
        //リール
        strokeWeight(10);
        fill(Stage.reelColor);
        for (int i = 0; i < Stage.numReel; i++) {
            rect(Stage.reelStartPos.x+Stage.reelSize.x*i, Stage.reelStartPos.y, Stage.reelSize.x, Stage.reelSize.y);
        }
        game()->reel()->draw();
        //筐体本体
        noStroke();
        fill(Stage.kyoutaiColor);
        rect(Stage.kyoutaiPos1.x, Stage.kyoutaiPos1.y, Stage.kyoutaiSize1.x, Stage.kyoutaiSize1.y);
        rect(Stage.kyoutaiPos2.x, Stage.kyoutaiPos2.y, Stage.kyoutaiSize2.x, Stage.kyoutaiSize2.y);
        rect(Stage.kyoutaiPos3.x, Stage.kyoutaiPos3.y, Stage.kyoutaiSize1.x, Stage.kyoutaiSize1.y);
        rect(Stage.kyoutaiPos4.x, Stage.kyoutaiPos4.y, Stage.kyoutaiSize2.x, Stage.kyoutaiSize2.y);
        strokeWeight(1);
        
        //停止ボタンなどがある場所
        fill(Stage.buttonAreaColor);
        rect(Stage.buttonAreaPos.x, Stage.buttonAreaPos.y, Stage.buttonAreaSize.x, Stage.buttonAreaSize.y);
        fill(Stage.buttonAreaTopColor);
        rect(Stage.buttonAreaTopPos.x, Stage.buttonAreaTopPos.y, Stage.buttonAreaTopSize.x, Stage.buttonAreaTopSize.y);
        //フレーム
        fill(Stage.frameColor);
        rect(Stage.leftFramePos.x, Stage.leftFramePos.y, Stage.frameSize.x, Stage.frameSize.y);
        rect(Stage.rightFramePos.x, Stage.rightFramePos.y, Stage.frameSize.x, Stage.frameSize.y);
        strokeWeight(1);
        //リール番号の背景
        fill(Stage.reelBangoColor);
        for (int i = 0; i < 3; i++) {
            rect(Stage.reelBangoPos.x, Stage.reelBangoPos.y+Stage.reelBangoOffset*i, Stage.reelBangoSize.x, Stage.reelBangoSize.y);
        }
        //ボーナス告知ランプ
        noStroke();
        fill(Stage.kokutiranpuColor);
        circle(Stage.kokutiranpuPos.x, Stage.kokutiranpuPos.y, Stage.kokutiranpuR);
        rect(Stage.kokutiBonusranpuPos1.x, Stage.kokutiBonusranpuPos1.y, Stage.kokutiBonusranpuSize.x, Stage.kokutiBonusranpuSize.y);
        rect(Stage.kokutiBonusranpuPos2.x, Stage.kokutiBonusranpuPos2.y, Stage.kokutiBonusranpuSize.x, Stage.kokutiBonusranpuSize.y);
        rect(Stage.kokutiBonusranpuPos3.x, Stage.kokutiBonusranpuPos3.y, Stage.kokutiBonusranpuSize.x, Stage.kokutiBonusranpuSize.y);
        strokeWeight(1);
        //BBの残り払い出し枚数
        fill(Stage.creditColor);
        rect(Stage.creditPos.x, Stage.creditPos.y, Stage.creditSize.x, Stage.creditSize.y);
        //払い出し
        fill(Stage.payoutColor);
        rect(Stage.payoutPos.x, Stage.payoutPos.y, Stage.payoutSize.x, Stage.payoutSize.y);

        font("ＭＳ 明朝");
        textSize(Stage.text2Size);
        fill(Stage.text2Color);
        int adjust = (Stage.text2Size * Stage.text2.length()) / 4;
        text(Stage.text2.c_str(), Stage.text2Pos.x-adjust, Stage.text2Pos.y);
        font("Arial");
        game()->charaDraw();
    }
    void STAGE::nextScene(){
    }

}