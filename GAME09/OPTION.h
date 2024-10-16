#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class OPTION :
        public SCENE
    {
    public:
        struct DATA {
            VECTOR2 optionStrPos;
            float optionStrSize;
            float optionUnderBar;
        };
    private:
        DATA Option;
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