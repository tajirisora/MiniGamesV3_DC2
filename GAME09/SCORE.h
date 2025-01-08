#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class SCORE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int     backImg;
            float   backImgSize;
            VECTOR2 backImgPos;
            VECTOR2 scoreNumSize;
            VECTOR2 scoreNumPosOfst;
            float   scoreAnimeTime;
        };
    private:
        DATA Score;
        int GoalScore;
        int CurScore;
        int BeforeScore;
        float AnimeTime;
    public:
        SCORE(class GAME* game);
        ~SCORE();
        void create();
        void init();
        void update();
        void draw();
        void draw(VECTOR2& pos, float size);
        void draw(VECTOR2& pos, float size, int score);

        int curScore() { return CurScore; }
    };
}