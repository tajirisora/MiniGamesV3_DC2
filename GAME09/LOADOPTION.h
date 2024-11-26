#pragma once
#include "GAME_OBJECT.h"
#include "KC_MAINSUB.h"
#include "OPTION.h"
#include <string>

namespace GAME09 {
    class LOADOPTION :
        public GAME_OBJECT
    {
    public:
        enum OPTIONS {
            SPEED,
            SOUND_EFFECT,
            AUDIO_OFFSET,
            VISUAL_OFFSET,
            KEY_BIND_TYPE,
            KEY_CONFIG,
            NUM_OPTIONS
        };
        struct DATA {
            std::string fileName;
            std::string optionStr[NUM_OPTIONS];
        };
        struct OPTION_DATA {
            float speed = 1;
            bool soundEffect = true;
            float audioOffset = 0;
            float visualOffset = 0;
            OPTION::KEY_BIND_TYPE keyBindType = OPTION::B_TYPE1;
            KC_MAINSUB keyConfig[6][6];
        };
    private:
        DATA LoadOption;
        OPTION_DATA OptionData;

    public:
        LOADOPTION(class GAME* game);
        ~LOADOPTION();
        void create();
        void init();

        void loadOption();
        void writeOption();

        const OPTION_DATA& optionData() { return OptionData; }
    };
}