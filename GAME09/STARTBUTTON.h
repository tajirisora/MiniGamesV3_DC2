#pragma once
#include "BUTTON.h"

namespace GAME09 {
    class STARTBUTTON :
        public BUTTON
    {
    public:
        STARTBUTTON(class GAME* game);
        ~STARTBUTTON();
        void create();
        void init();
    };
}