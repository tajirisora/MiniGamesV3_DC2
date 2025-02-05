#pragma once
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include "SCENE.h"
namespace GAME14 {
    class STAGE :
        public SCENE
    {
    public:
        struct DATA {
            VECTOR2 startPos;
            float textSize;
            COLOR textColor;
            float offsetPosY;

            const char* text[80];

            VECTOR2 kyoutaiPos1;
            VECTOR2 kyoutaiSize1;
            VECTOR2 kyoutaiPos2;
            VECTOR2 kyoutaiSize2;
            VECTOR2 kyoutaiPos3;
            VECTOR2 kyoutaiPos4;
            COLOR kyoutaiColor;
            VECTOR2 leftFramePos;
            VECTOR2 rightFramePos;
            VECTOR2 frameSize;
            COLOR frameColor;
            VECTOR2 reelStartPos;
            VECTOR2 reelSize;
            COLOR reelColor;
            VECTOR2 buttonAreaPos;
            VECTOR2 buttonAreaSize;
            COLOR buttonAreaColor;
            VECTOR2 buttonAreaTopPos;
            VECTOR2 buttonAreaTopSize;
            COLOR buttonAreaTopColor;
            VECTOR2 reelBangoPos;
            VECTOR2 reelBangoSize;
            COLOR reelBangoColor;
            float reelBangoOffset;
            VECTOR2 kokutiranpuPos;
            float   kokutiranpuR;
            VECTOR2 kokutiBonusranpuPos1;
            VECTOR2 kokutiBonusranpuPos2;
            VECTOR2 kokutiBonusranpuPos3;
            VECTOR2 kokutiBonusranpuSize;
            COLOR kokutiranpuColor;
            VECTOR2 creditPos;
            VECTOR2 creditSize;
            COLOR creditColor;
            VECTOR2 payoutPos;
            VECTOR2 payoutSize;
            COLOR payoutColor;


        };
    private:
        DATA Stage;
        VECTOR2 pos = 0;
        int img = loadImage("../MAIN\\assets\\game14\\テンプレート.png");
    public:
        STAGE(GAME* game) :SCENE(game) {}
        ~STAGE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();

    };
}

