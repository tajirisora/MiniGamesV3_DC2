#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09 {
    class DETAIL_VIEW :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 jacketPos;
            float   jacketSize;
            VECTOR2 titleSize;
            VECTOR2 otherSize;
            float   otherStrSize;
            VECTOR2 titlePos;
            VECTOR2 artistPos;
            VECTOR2 chartPos;
            VECTOR2 otherStrOfst;
            COLOR   backColor;
        };
    private:
        DATA Detail;
    public:
        DETAIL_VIEW(class GAME* game);
        ~DETAIL_VIEW();
        void create();
        void init();
        void update();
        void draw(float ratio = 1.0f);
    };
}