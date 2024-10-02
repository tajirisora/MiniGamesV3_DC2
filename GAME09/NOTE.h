#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/input.h"

namespace GAME09 {
    class NOTE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int leftImg;
            int centerImg;
            int rightImg;
            float edgeOfst; //ノーツの端っこの座標から左右端の画像表示位置までのオフセット
            float rectOfst; //ノーツの真ん中の四角形の端っこの座標
            float rectHeight; //ノーツの真ん中の四角形の高さ
            float imgSize;
            float highlightHeightRatio;
            COLOR highlightColor;
            COLOR upColor;
            COLOR downColor;
        };
        struct NOTE_DATA {
            int laneNum;
            int lane;
            INPUT_CODE key;
            float speed;
            double time;
            double visualBeat;
            double timeE;
            double visualBeatE;
        };
        enum NOTE_NAME {
            TAP,
            LONG,
            BELT,
            NUM_NAME
        };
    protected:
        DATA Note;
        NOTE_NAME Name = TAP;

        VECTOR2 Pos;
        VECTOR2 PosE;
        float PosX;
        float EdgeImgDist;
        VECTOR2 RectSize;

        int LaneNum = 0;
        int Lane = 0;
        INPUT_CODE Key = KEY_NONE;
        float Speed = 0;
        double Time = 0;
        double VisualBeat = 0;
        double TimeE = 0;
        double VisualBeatE = 0;

        bool Sound = false;

        VECTOR2 SetPos(double beat);
    public:
        NOTE(class GAME* game);
        virtual ~NOTE();
        virtual void create();
        virtual void init();
        virtual void update();
        virtual void draw();

        void setData(NOTE_DATA data);
        double getTime() { return Time; }
        double getTimeE() { return TimeE; }
        int getLane() { return Lane; }
        INPUT_CODE getKey() { return Key; }
        NOTE_NAME noteName() { return Name; }
    };
}