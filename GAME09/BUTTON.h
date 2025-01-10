#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/input.h"

namespace GAME09 {
    class BUTTON :
        public GAME_OBJECT
    {
    public:
        enum ColliType {
            CIRCLE,
            RECT,
            DIAMOND
        };

        struct DATA {
            int img = -1;
            float imgSize = 1;
            VECTOR2 pos;
            ColliType colliType;
            VECTOR2 ofst;
            float radius;
            VECTOR2 size;
            INPUT_CODE key = KEY_NONE;
            bool debugFlag = false;
        };
    protected:
        DATA Button;
        bool IsClick;
    public:
        BUTTON(class GAME* game);
        ~BUTTON();
        virtual void create();
        virtual void init();
        virtual void update();
        virtual void draw();
        virtual void setData(DATA& data);
        virtual bool isClick() { return IsClick; }
        virtual void resetClick() { IsClick = false; }
    protected:
        virtual bool collision();
    };
}