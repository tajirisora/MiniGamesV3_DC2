#pragma once
#include "GAME_OBJECT.h"
#include "KC_MAINSUB.h"
#include <vector>

namespace GAME09 {
    class KEYCONFIG :
        public GAME_OBJECT
    {
    public:
        struct KEY_TRIGGER {
            INPUT_CODE Key;
            bool trigger;
            bool press;
        };
        struct DATA {
            
        };
    private:
        DATA Data;
        KC_MAINSUB KeyConfig[6][6];

        std::vector<KEY_TRIGGER> Triggers;

        void SetTriggers();
    public:
        KEYCONFIG(class GAME* game);
        ~KEYCONFIG();
        void create();
        void init();
        void update();
        void draw();

        std::vector<KEY_TRIGGER>& triggers() { return Triggers; }
        KC_MAINSUB getKeyConfig(int numLane, int lane);
        bool keyTrigger(INPUT_CODE key);
        bool keyPress(INPUT_CODE key);
        void setTrigger(INPUT_CODE key, bool value);
    };
}