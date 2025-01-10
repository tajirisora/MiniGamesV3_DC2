#pragma once
#include "NOTE.h"

namespace GAME09 {
    class TAPNOTE :
        public NOTE
    {
    public:
        TAPNOTE(class GAME* game);
        ~TAPNOTE();
        void init();
        void update();
        void draw();
    };
}