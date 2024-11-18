#pragma once
#include "REEL.h"
namespace GAME14 {
    class LEFT_REEL :
        public REEL{
    public:
        LEFT_REEL(class GAME* game):
            REEL(game){}
        void create();
    };
}

