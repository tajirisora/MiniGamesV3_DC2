#pragma once
#include "BUTTON.h"

namespace GAME07
{
    class BUTTON_RETRY_PAUSE :
        public BUTTON
    {
    public:
        BUTTON_RETRY_PAUSE(class GAME* game);
        ~BUTTON_RETRY_PAUSE();
        void create();
    };
}