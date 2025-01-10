#pragma once
#include "SCENE.h"
namespace GAME14 {
    class HOME :
        public SCENE
    {
    public:
        HOME(GAME* game) :SCENE(game) {}
        ~HOME();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();

    };
}

