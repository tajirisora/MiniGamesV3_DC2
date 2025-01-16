#pragma once
#include "SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06
{
    class RESULT_A :
        public SCENE
    {
    public:
        struct DATA {
            COLOR backgroundColor;
            float nameSize = 0.0f;
            COLOR nameColor;
            VECTOR2 namePos;
            const char* name = nullptr;
            float guidanceSize = 0.0f;
            COLOR guidanceColor;
            VECTOR2 guidancePos;
            const char* guidance = nullptr;
        };
    private:
        DATA ResultA;
    public:
        RESULT_A(class GAME* game):SCENE(game){}
        ~RESULT_A(){}
        void create();
        void draw();
        void nextScene();
    };
}
