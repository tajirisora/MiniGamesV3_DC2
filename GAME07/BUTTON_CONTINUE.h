#pragma once
#include "BUTTON.h"

namespace GAME07
{
    class BUTTON_CONTINUE :
        public BUTTON
    {
    public:
        BUTTON_CONTINUE(class GAME* game);
        ~BUTTON_CONTINUE();
        void create();
    };
}