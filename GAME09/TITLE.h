#pragma once
#include "SCENE.h"
#include "TRANSFORM.h"

namespace GAME09 {
    class TITLE :
        public SCENE
    {
    public:
        struct DATA {
            int titleLogo;
            TRANSFORM titleTf;
            int pressEnterkey;
            TRANSFORM pressEnterkeyTf;
        };
    private:
        DATA Title;
    public:
        TITLE(class GAME* game);
        ~TITLE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}