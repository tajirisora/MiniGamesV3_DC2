#pragma once
#include "SCENE.h"
#include "TRANSFORM.h"

namespace GAME09 {
    class MUSICSELECT :
        public SCENE
    {
    public:
        struct DATA {
            TRANSFORM jacketTf;
        };
    private:
        DATA Select;
    public:
        MUSICSELECT(class GAME* game);
        ~MUSICSELECT();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}