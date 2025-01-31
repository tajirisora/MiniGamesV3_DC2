#pragma once
#include "SCENE.h"
namespace GAME14 {
    class RESULT :
        public SCENE
    {
    public:
        RESULT(GAME* game) :SCENE(game) {}
        ~RESULT();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();

    };
}

