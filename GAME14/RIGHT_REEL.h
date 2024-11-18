#pragma once
#include "REEL.h"
namespace GAME14 {
    class RIGHT_REEL :
        public REEL{
    public:
        RIGHT_REEL(class GAME* game):
            REEL(game){}
        void create();

    };
}

