#pragma once
#include "GAME_OBJECT.h"
#include "SONGINFO.h"
#include "TRANSFORM.h"

namespace GAME09 {
    class JACKET :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 areaSize;
            int areaBackImg;
        };
    private:
        DATA Jacket;
    public:
        JACKET(class GAME* game);
        ~JACKET();
        void create();
        void init();
        void update();
        void draw(const SONGINFO& songInfo, TRANSFORM tf);
    };
}