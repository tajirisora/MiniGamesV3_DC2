#pragma once
#include "GAME_OBJECT.h"
#include "SONGINFO.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class BACKGROUND :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 area;
        };
    private:
        DATA Back;
    public:
        BACKGROUND(class GAME* game);
        ~BACKGROUND();
        void create();
        void init();
        void update();
        void draw(const SONGINFO& songInfo);
    };
}