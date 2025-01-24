#pragma once
#include "GAME_OBJECT.h"
#include "BUTTON_TF.h"
#include "CHARTMANAGER.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09 {
    class DIFFICULTYSELECT :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            BUTTON_TF buttonTf;
            COLOR Color[CHARTMANAGER::NUM_DIFFICULTY];
        };
    private:
        DATA DifficultySelect;
        class DIFFICULTYBUTTON* Buttons[CHARTMANAGER::NUM_DIFFICULTY];
        CHARTMANAGER::DIFFICULTY CurDifficulty = CHARTMANAGER::EXPART;
    public:
        DIFFICULTYSELECT(class GAME* game);
        ~DIFFICULTYSELECT();
        void create();
        void init();
        void update();
        void draw();

        COLOR getColor(CHARTMANAGER::DIFFICULTY d = CHARTMANAGER::NUM_DIFFICULTY);
        CHARTMANAGER::DIFFICULTY curDifficulty() { return CurDifficulty; }
        void setDifficulty(CHARTMANAGER::DIFFICULTY d) { CurDifficulty = d; }
    };
}