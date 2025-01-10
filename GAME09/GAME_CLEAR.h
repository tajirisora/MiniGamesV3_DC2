#pragma once
#include "GAME09.h"
#include "SCENE.h"
#include "ACHIEVEMENT.h"
#include "TRANSFORM.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09 {
    class GAME_CLEAR :
        public SCENE
    {
    public:
        struct DATA {
            TRANSFORM jacketTF;
            int     frameImg;
            VECTOR2 framePos;
            float   frameSize;
            VECTOR2 judgeImgPos;
            float   judgeImgSize;
            VECTOR2 judgeNumPos;
            float   judgeNumSize;
            VECTOR2 judgeNextOfst;
            VECTOR2 maxComboPos;
            float   maxComboSize;
            VECTOR2 scorePos;
            float   scoreSize;
            VECTOR2 highScoreStrPos;
            VECTOR2 highScoreOfst;
            VECTOR2 highScoreDiffOfst;
            VECTOR2 highScoreStrSize;
            VECTOR2 highScoreSize;
            VECTOR2 titlePos;
            float   titleSize;
            int     operationImg;
            VECTOR2 operationPos;
            float   operationSize;
            int     fastSlowImg;
            VECTOR2 fastSlowPos;
            float   fastSlowSize;
            VECTOR2 fastSlowGaugeOfst;
            VECTOR2 fastSlowGaugeSize;
            VECTOR2 fastSlowNumSize;
            VECTOR2 fastNumOfst;
            VECTOR2 slowNumOfst;
            COLOR   fastColor;
            COLOR   slowColor;
        };
    private:
        DATA Result;
        ACHIEVEMENT::ACHIEVEMENTS Achievement;
        GAME::SCENE_ID NextScene;
        int BeforeHighScore;

        void UpdateHighScore();
    public:
        GAME_CLEAR(class GAME* game);
        ~GAME_CLEAR();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}