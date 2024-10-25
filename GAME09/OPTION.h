#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class OPTION :
        public SCENE
    {
    public:
        enum OPTION_KINDS {
            GENERAL,
            KEY_BIND,
            COLOR,
            NUM_KINDS
        };
        struct DATA {
            VECTOR2 optionStrPos;
            float optionStrSize;
            float optionUnderBar;
        };
    private:
        DATA Option;
        void DrawGeneral();
        void DrawKeyBind();
        void DrawColor();
    public:
        OPTION(class GAME* game);
        ~OPTION();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}