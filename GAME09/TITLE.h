#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class TITLE :
        public SCENE
    {
    public:
        struct DATA {
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