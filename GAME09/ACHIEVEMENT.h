#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class ACHIEVEMENT :
        public GAME_OBJECT
    {
    public:
        enum ACHIEVEMENTS {
            CLEAR,
            FULLCOMBO,
            ALLPERFECT,
            NUM_ACHIEVEMENTS
        };
        struct DATA {
            int     imgs[NUM_ACHIEVEMENTS];
            VECTOR2 pos;
            float   size;
        };
    private:
        DATA Achievement;
    public:
        ACHIEVEMENT(class GAME* game);
        ~ACHIEVEMENT();
        void create();
        void init();
        void update();
        void draw(ACHIEVEMENTS achievement);
        void draw(ACHIEVEMENTS achievement, VECTOR2& pos, float size);
    };
}