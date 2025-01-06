#pragma once
#include "SCENE.h"
#include "KEYCONFIG.h"
#include "BUTTON_TF.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class OPTION :
        public SCENE
    {
    public:
        enum OPTION_KINDS {
            GENERAL,
            KEY_BIND,
            COLOR,
            NUM_KINDS
        };
        enum KEY_WAIT {
            NO,
            MAIN,
            SUB
        };
        struct DATA {
            VECTOR2 optionImgPos;
            float optionUnderBar;
            BUTTON_TF kindButtonTF;
            float kindBarX;
            BUTTON_TF typeButtonTF;
            BUTTON_TF keyButtonTF;
            BUTTON_TF colorTypeButtonTF;
            BUTTON_TF colorType1ButtonTF;

            int optionImg;
            float optionImgSize;
            int keyButtonImg;
            float keyButtonImgSize;
            int optionButtonImgs[NUM_KINDS];
            int optionTypeImgs[KEYCONFIG::NUM_KEY_BIND_TYPE];
            float optionButtonSize;
            int keyWait1Img;
            int keyWait2Img;
        };
    private:
        DATA Option;
        OPTION_KINDS OptionKind;
        KEY_WAIT KeyWait;
        VECTOR2 WaitKeyIdx;
        class OPTION_RELATED_BUTTON* KindButtons[NUM_KINDS];
        class OPTION_RELATED_BUTTON* BindTypeButtons[KEYCONFIG::NUM_KEY_BIND_TYPE];
        class OPTION_RELATED_BUTTON* KeyButtons[6][6];
        class OPTION_RELATED_BUTTON* ColorTypeButtons[KEYCONFIG::NUM_COLOR_TYPE];
        class OPTION_RELATED_BUTTON* ColorType1Buttons[6];
        void UpdateGeneral();
        void UpdateKeyBind();
        void UpdateColor();
        void UpdateKeyButtons();
        void DrawGeneral();
        void DrawKeyBind();
        void DrawColor();
        void DrawKeyButtons();
    public:
        OPTION(class GAME* game);
        ~OPTION();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}