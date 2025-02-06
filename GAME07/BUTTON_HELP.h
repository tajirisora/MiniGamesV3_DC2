#pragma once
#include "BUTTON.h"

namespace GAME07
{
    class BUTTON_HELP :
        public BUTTON
    {
    public:
        BUTTON_HELP(class GAME* game);
        ~BUTTON_HELP();
        void create();
    };
}