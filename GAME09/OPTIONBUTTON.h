#pragma once
#include "BUTTON.h"

namespace GAME09 {
    class OPTIONBUTTON :
        public BUTTON
    {
    public:
        OPTIONBUTTON(class GAME* game);
        ~OPTIONBUTTON();
        void create();
        void init();
    };
}