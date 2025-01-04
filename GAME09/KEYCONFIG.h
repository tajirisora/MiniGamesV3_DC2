#pragma once
#include "GAME_OBJECT.h"
#include "KC_MAINSUB.h"
#include "../../libOne/inc/COLOR.h"
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
        enum KEY_BIND_TYPE {
            B_TYPE1,
            B_TYPE2,
            B_TYPE3,
            B_CUSTOM,
            NUM_KEY_BIND_TYPE
        };
        enum COLOR_TYPE {
            C_TYPE1,
            C_TYPE2,
            C_CUSTOM,
            NUM_COLOR_TYPE
        };
    private:
        DATA Data;
        KC_MAINSUB** CustomKeyConfig = nullptr;
        KC_MAINSUB KeyConfig[6][6];
        const KEY_BIND_TYPE* KeyBindType;
        COLOR* Color1Config = nullptr;
        COLOR* Color2Config = nullptr;
        bool** ColorDifferentConfig = nullptr;
        COLOR** ColorCustomConfig = nullptr;
        COLOR ColorConfig[6][6];
        const COLOR_TYPE* ColorType;

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
        void setKeyConfig();
        void setTrigger(INPUT_CODE key, bool value);
        void setColorConfig();
    };
}