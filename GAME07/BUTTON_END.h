#pragma once
#include "BUTTON.h"

namespace GAME07
{
    class BUTTON_END :
        public BUTTON
    {
    public:
        BUTTON_END(class GAME* game);
        ~BUTTON_END();
        void create();
    };
}