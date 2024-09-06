#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class MUSICSELECT :
        public SCENE
    {
    public:
        struct DATA {
            
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