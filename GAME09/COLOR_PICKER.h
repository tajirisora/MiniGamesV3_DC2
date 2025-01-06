#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09 {
    class COLOR_PICKER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 areaSize;   //背景のサイズ
            float size;		    //カラーピッカーのサイズ(半径)
            float swRate;	    //サイズに対するSwの比率
            float innerSize;	//サイズに対する内側の円の半径
            float rectSize;	    //サイズに対する四角形のサイズ

            float hPointerSize;
            float svPointerSize;
        };
    private:
        DATA ColorPicker;
        VECTOR2 CornerPos = { 500,500 };
        VECTOR2 Pos;
        float Sw;
        int Hue = 0;
        int Satu = 255;
        int Value = 255;
        bool IsMoveH = false;
        bool IsMoveSV = false;
    public:
        COLOR_PICKER(class GAME* game);
        ~COLOR_PICKER();
        void create();
        void init();
        void update();
        void draw();
    };
}