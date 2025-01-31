#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class BUTTON :
        public GAME_OBJECT {
    public:
        struct DATA {
            int img = 0;
            float imgSize = 0.0f;
            VECTOR2 basePos = 0.0f;//基本位置
            COLOR areaColor = 0.0f;//当たり判定用色
            float r = 0.0f;//半径当たり判定用
            VECTOR2 areaSize = 0.0f;//当たり判定用
            COLOR filter = 0.0f;//合成色
            bool sistemFlag = false;//内部処理用(Trigger)
            bool drawFlag = false;//描画処理用(Press)
            bool filterFlag = false;
        };
    protected:
        DATA Button;
    public:
        BUTTON(class GAME* game):
            GAME_OBJECT(game){}
        virtual void create();
        virtual void init();
        virtual void update();
        virtual void draw();
        bool collisionCheck(VECTOR2 pos, float r);//円の当たり判定
        bool collisionCheck(VECTOR2 pos, VECTOR2 size);//四角の当たり判定
        virtual bool sistemFlag() { return Button.sistemFlag; }
        virtual bool sistemFlag(int buttonId) { return 0; }
        //void setSistemFlag(bool flag) { Button.sistemFlag = flag; }
    };
}

