#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include <string>

namespace GAME09 {
    class ADJUST :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 strSize;
            VECTOR2 leftButtonOfst;
            VECTOR2 rightButtonOfst;
            VECTOR2 valueOfst;
            VECTOR2 valueSize;
        };
        struct SETDATA {
            VECTOR2 pos;
            bool* valueB = nullptr;
            float* valueF = nullptr;
            int* valueI = nullptr;
            std::string str;
            float valueMax = 0;
            float valueMin = 0;
            float changeValue = 0;
        };
    private:
        DATA Adjust;

        SETDATA Data;

        class ADJUSTBUTTON* LButton;
        class ADJUSTBUTTON* RButton;
    public:
        ADJUST(class GAME* game);
        ~ADJUST();
        void create();
        void init();
        void update();
        void draw();

        void setData(SETDATA& data);
    };
}