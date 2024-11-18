#pragma once
#include "SCENE.h"
namespace GAME14 {
    class STAGE :
        public SCENE
    {
    private:
        VECTOR2 pos = 0;
        int img = loadImage("../MAIN\\assets\\game14\\テンプレート.png");
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

