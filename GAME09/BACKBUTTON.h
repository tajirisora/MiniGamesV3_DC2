#pragma once
#include "BUTTON.h"

namespace GAME09 {
    class BACKBUTTON :
        public BUTTON
    {
    public:
        BACKBUTTON(class GAME* game);
        ~BACKBUTTON();
        void create();
        void init();
    };
}