#pragma once
#include "GAME_OBJECT.h"
#include "TRANSFORM.h"

namespace GAME09 {
    class WARNING_MESSAGE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int     warningImg;
            TRANSFORM warningTf;
            float displayTime;
            float fadeTime;
        };
    private:
        DATA Warning;
        float Time;
    public:
        WARNING_MESSAGE(class GAME* game);
        ~WARNING_MESSAGE();
        void create();
        void init();
        void update();
        void draw();
        void apper();
    };
}