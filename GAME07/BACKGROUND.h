#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME07
{
    class BACKGROUND :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            float imgSize;
            VECTOR2 pos;
        };
    private:
        DATA BackG;
    public:
        BACKGROUND(class GAME* game);
        ~BACKGROUND();
        void create();
        void update();
        void draw();
    };
}
