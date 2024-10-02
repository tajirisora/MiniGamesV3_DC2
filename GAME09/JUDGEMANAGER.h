#pragma once
#include "GAME_OBJECT.h"
#include "NOTE.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/input.h"
#include <vector>
#include <string>

namespace GAME09 {
    class JUDGEMANAGER :
        public GAME_OBJECT
    {
    public:
        struct JUDGE_DATA {
            double time;
            int img;
        };
        enum JUDGE {
            PERFECT,
            GREAT,
            MISS,
            NUM_JUDGE
        };
        enum ACCURACY {
            NONE,
            FAST,
            SLOW,
            NUM_ACCURACY
        };
        struct DATA {
            JUDGE_DATA judge[NUM_JUDGE];
            int fastImg;
            int slowImg;
            VECTOR2 pos;
            float imgSize;
            float imgSizeMin;
            VECTOR2 accOfst;
            float accImgSizeRate;
            float appearAnimeTime;
            float activeTime;
            VECTOR2 comboPos;
            float comboSizeMinRate;
        };
    private:
        DATA JudgeMNG;
        float AnimeTime = 0;
        JUDGE Judge;
        ACCURACY Acc;
        std::vector<bool> IsTrigger;
        std::vector<bool> IsPress;

        class RHYTHM_GAME_CONTROLLER* Cont;
        class SOUNDMANAGER* Sound;

        int JudgeResult[NUM_JUDGE];
        int Combo;
        int MaxCombo;
        int Accuracy[NUM_ACCURACY];
        void AccCnt(ACCURACY acc);

    public:
        JUDGEMANAGER(class GAME* game);
        ~JUDGEMANAGER();
        void create();
        void init();
        void update();
        void draw();

        void judgeNotes(std::vector<NOTE*>& notes);
        void autoPlay();
        int* judgeResult() { return JudgeResult; }
        JUDGE_DATA* judgeImgs() { return JudgeMNG.judge; }
        void resetCombo();
        int maxCombo() { return MaxCombo; }
        int* accuracy() { return Accuracy; }
    };
}