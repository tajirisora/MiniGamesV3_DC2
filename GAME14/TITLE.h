#pragma once
#include "SCENE.h"
#include<string>
namespace GAME14 {
    class TITLE :
        public SCENE{
    public:
        struct DATA {
            COLOR backColor = 0.0f;
            const char* str = nullptr;
            float strSize = 0.0f;
            COLOR strColor = 0.0f;
            VECTOR2 strPos = 0.0f;
            const char* msg = nullptr;
            float msgSize = 0.0f;
            COLOR msgColor = 0.0f;
            VECTOR2 msgPos = 0.0f;
            std::string msg2;
            VECTOR2 msg2Pos = 0.0f;

            int i = 0;
            int j = 0;
        };

    private:
        DATA Title;
    public:
        TITLE(GAME* game):SCENE(game){}
        ~TITLE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}

