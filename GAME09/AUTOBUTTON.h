#pragma once
#include "BUTTON.h"

namespace GAME09 {
    class AUTOBUTTON :
        public BUTTON
    {
    public:
        struct DATA {
            int imgs[2];
        };
    private:
        DATA AutoButton;
    public:
        AUTOBUTTON(class GAME* game);
        ~AUTOBUTTON();
        void create();
        void init();
        void update();
    };
}