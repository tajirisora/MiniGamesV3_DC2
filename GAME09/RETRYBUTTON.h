#pragma once
#include "BUTTON.h"

namespace GAME09 {
    class RETRYBUTTON :
        public BUTTON
    {
    public:
        RETRYBUTTON(class GAME* game);
        ~RETRYBUTTON();
        void create();
        void init();
    };
}