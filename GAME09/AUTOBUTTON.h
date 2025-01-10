#pragma once
#include "BUTTON.h"

namespace GAME09 {
    class AUTOBUTTON :
        public BUTTON
    {
    public:
        AUTOBUTTON(class GAME* game);
        ~AUTOBUTTON();
        void create();
        void init();
    };
}