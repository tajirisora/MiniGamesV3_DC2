#pragma once
#include "BUTTON.h"

namespace GAME07
{
    class BUTTON_RETRY_RESULT :
        public BUTTON
    {
    public:
        BUTTON_RETRY_RESULT(class GAME* game);
        ~BUTTON_RETRY_RESULT();
        void create();
    };
}