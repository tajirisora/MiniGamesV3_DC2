#pragma once
#include "SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06
{
    class RANK_B :
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
            float recodeSize = 0.0f;
            COLOR recodeColor;
            VECTOR2 recodePos;
        };
    private:
        DATA RankB;
    public:
        RANK_B(class GAME* game) :SCENE(game) {}
        ~RANK_B() {}
        void create();
        void draw();
        void nextScene();
    };
}

