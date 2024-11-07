#pragma once
#include "BUTTON.h"
#include "KC_MAINSUB.h"
#include "../../libOne/inc/COLOR.h"
#include <string>

namespace GAME09 {
    class OPTION_RELATED_BUTTON :
        public BUTTON
    {
    private:
        COLOR MainColor = { 0,0,0,0 };
        KC_MAINSUB Key;
    public:
        OPTION_RELATED_BUTTON(class GAME* game);
        ~OPTION_RELATED_BUTTON();
        void create();
        void init();
        void draw();
        void setColor(COLOR color) { MainColor = color; }
        void setKey(KC_MAINSUB key) { Key = key; }
    };
}