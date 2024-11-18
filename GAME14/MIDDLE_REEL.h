#pragma once
#include "REEL.h"
namespace GAME14 {
    class MIDDLE_REEL :
        public REEL{
    public:
        MIDDLE_REEL(class GAME* game):
            REEL(game){}
        void create();
    };
}

