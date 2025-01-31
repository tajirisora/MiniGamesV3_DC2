#pragma once
#include "BUTTON.h"

namespace GAME09 {
    class ADJUSTBUTTON :
        public BUTTON
    {
    public:
        enum IMG_KIND {
            PLUS,
            MINUS,
            RIGHT,
            LEFT,
            NUM_IMG_KIND
        };
        struct DATA {
            int imgs[NUM_IMG_KIND];

            float repeatStartTime;
            float repeatInterval;
        };
    private:
        DATA AdjustButton;

        bool TriggerStart;
        bool RepeatStart;
        float PressTime;
    public:
        ADJUSTBUTTON(class GAME* game);
        ~ADJUSTBUTTON();
        void create();
        void init();
        void update();

        void setImg(IMG_KIND img);
        void setPos(VECTOR2 pos);
    };
}