#include"../../libOne/inc/window.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"REEL_MAP.h"
#include "REEL.h"
namespace GAME14 {
    REEL::REEL(class GAME* game):
        GAME_OBJECT(game){}
    REEL::~REEL(){
        delete[] Reel;
    }
    void REEL::create(){
        Reels = game()->container()->data().reel;
        Reel = new REELS[Reels.cellNum];
        init();
    }
    void REEL::init(){
        for (int i = 0; i < Reels.reelNum; i++) {
            Reel[i].reelId = i;
            Reel[i].beforeNum = 0;
            Reel[i].afterNum = 0;
            Reel[i].curNum = 0.0f;
            Reel[i].animeFlag = false;
            Reel[i].stopFlag = false;
            Reel[i].setAfter = false;
        }


    }
    void REEL::update(){

        //抽選が終わったらかつウェイト時間を満たしていたら回転させる
        if (MoveFlag) {
            for (int i = 0; i < Reels.reelNum;i++) {
                Reel[i].animeFlag = true;
            }
            AnimeTime = 0.0f;
            MoveFlag = false;
            Reels.animeFlag = true;
        }
        if (Reels.animeFlag) {
            AnimeTime += delta;
            for (int i = 0; i < Reels.reelNum; i++) {
                if (Reel[i].animeFlag) {//そのリールが動いているか
                                                           //進んだコマ数//
                    Reel[i].curNum = Reel[i].beforeNum + AnimeTime / Reels.NeedTime;
                    
                    if (Reel[i].stopFlag) {//止まるときの処理
                        if (!Reel[i].setAfter) {//止まる場所の指定
                            StopCunt++;
                            StopCell = ceil(Reel[i].curNum);
                            StopCell = StopCell % Reels.cellNum;
                            
                            Reel[i].afterNum = StopCell+game()->reelMap()->tellStopCell(StopCell,Reel[i].reelId);
                            Reel[i].setAfter = true;
                        }
                        else {
                            if (Reel[i].curNum > Reel[i].afterNum) {//止まる場所まで来た時の処理
                                Reel[i].beforeNum = Reel[i].afterNum % Reels.cellNum;
                                Reel[i].curNum = Reel[i].beforeNum;
                                Reel[i].setAfter = false;
                                Reel[i].animeFlag = false;
                                Reel[i].stopFlag = false;
                                if (StopCunt >= Reels.reelNum) {
                                    Reels.animeFlag = false;
                                    StopCunt = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
    void REEL::draw(){
        fill(0);
        textSize(50);
        for (int i = 0; i <  Reels.reelNum; i++) {
            int startIdx = round(Reel[i].curNum) -1;//表示し始めるコマcurNumは下段
            for (int j = 0; j <  Reels.drawNum; j++) {
                float dist = Reel[i].curNum - startIdx - j;//表示し始めるコマからどれくらい離れているか
                int cellNum = (startIdx + j + Reels.cellNum) % Reels.cellNum;//0から20に収まるように
                VECTOR2 pos = VECTOR2(Reels.imgPos.x+(Reels.reelSize.x*i), Reels.imgPos.y);//表示位置の決定
                pos.y += Reels.cellSize.y * dist;//y軸の調整
                int imgIdx = game()->reelMap()->textureNum(Reel[i].reelId, cellNum);//(reelId)行(cellNum)列目の画像インデックスを取得
                image(Reels.img[imgIdx], pos.x,pos.y,0,Reels.imgSize);
            }
        }
    }
    void REEL::debagDraw() {
        print("止めたコマ数");
        print(StopCell);
        print("現在のコマ数");
        print(StopCell);
    }
}