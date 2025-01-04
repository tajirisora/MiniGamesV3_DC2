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
            COLOR_TYPE,
            COLOR_1_CONFIG,
            COLOR_2_CONFIG,
            COLOR_DIFFERENT_CONFIG,
            COLOR_CUSTOM_CONFIG,
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
            KEYCONFIG::KEY_BIND_TYPE keyBindType = KEYCONFIG::B_TYPE1;
            KC_MAINSUB** keyConfig = nullptr;
            KEYCONFIG::COLOR_TYPE colorType = KEYCONFIG::C_TYPE1;
            COLOR* color1Config = nullptr;
            COLOR* color2Config = nullptr;
            bool** colorDifferentConfig = nullptr;
            COLOR** colorCustomConfig = nullptr;
        };
    private:
        DATA LoadOption;
        OPTION_DATA OptionData;

        COLOR StoColor(std::string str);
    public:
        LOADOPTION(class GAME* game);
        ~LOADOPTION();
        void create();
        void init();

        void loadOption();
        void writeOption();

        OPTION_DATA& optionData() { return OptionData; }
    };
}