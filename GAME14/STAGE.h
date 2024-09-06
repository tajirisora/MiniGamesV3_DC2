#pragma once
#include "SCENE.h"
namespace GAME14 {
    class STAGE :
        public SCENE
    {
    public:
        STAGE(GAME* game) :SCENE(game) {}
        ~STAGE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();

    };
}

