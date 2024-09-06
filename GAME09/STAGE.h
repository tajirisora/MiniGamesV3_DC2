#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class STAGE :
        public SCENE
    {
    public:
        enum CHOICES {
            RETRY,
            SELECT,
            NUM_CHOICES
        };
        struct DATA {
            
        };
    private:
        DATA Stage;
        CHOICES Choices;
    public:
        STAGE(class GAME* game);
        ~STAGE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}