#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"
namespace GAME06
{
    class JUDGE_LIST :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            COLOR textColor;
            float textSize = 0.0f;
            VECTOR2 pos_S;
            VECTOR2 pos_A;
            VECTOR2 pos_B;
            VECTOR2 pos_C;
            const char* str_S = nullptr;
            const char* str_A = nullptr;
            const char* str_B = nullptr;
            const char* str_C = nullptr;
        };
    private:
        DATA JudgeList;
    public:
        JUDGE_LIST(class GAME* game) :GAME_OBJECT(game) {}
        ~JUDGE_LIST() {}
        void create();
        void draw();
    };
}

