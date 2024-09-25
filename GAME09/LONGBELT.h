#pragma once
#include "NOTE.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09 {
    class LONGBELT :
        public NOTE
    {
    public:
        struct DATA {
            COLOR color;
        };
    private:
        DATA LongBelt;
        int Img;
    public:
        LONGBELT(class GAME* game);
        ~LONGBELT();
        void create();
        void init();
        void update();
        void draw();
    };
}