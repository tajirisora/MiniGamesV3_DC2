#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09 {
    class FADE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            float speed;
            COLOR color;
            float alpha;
        };
    private:
        DATA Fade;
        enum STATE {
            IN_START, IN_END,
            OUT_START, OUT_END
        };
        STATE State;
    public:
        FADE(class GAME* game);
        ~FADE();
        void create();
        void proc();
        void inStart();
        bool inEndFlag();
        void outStart();
        bool outEndFlag();
    };
}