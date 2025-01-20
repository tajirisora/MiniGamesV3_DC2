#pragma once
#include "GAME_OBJECT.h"
#include "SONGINFO.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class SONGTITLE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int bannerImg;
            int difficultyFrameImg;
            float bannerImgSize;
            float difficultyFrameImgSize;
            VECTOR2 difficultyFrameOfst;
            VECTOR2 titlePosOfst;
            VECTOR2 artistPosOfst;
            VECTOR2 titleStrSize;
            VECTOR2 artistStrSize;
        };
    private:
        DATA SongTitle;
    public:
        SONGTITLE(class GAME* game);
        ~SONGTITLE();
        void create();
        void init();
        void update();
        void draw(SONGINFO& songInfo, VECTOR2 pos, float size);
    };
}