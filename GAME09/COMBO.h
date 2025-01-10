#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class COMBO :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int numImg;
            int numImgs[10];
            int strImg;
            VECTOR2 numOfst;
            VECTOR2 strOfst;
            float numSize;
            float strSize;
            float digitSpace;
        };
    private:
        DATA Combo;
    public:
        COMBO(class GAME* game);
        ~COMBO();
        void create();
        void init();
        void update();
        void draw(int combo, VECTOR2 pos, float ratio = 1.0f);
    };
}