#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include <string>

namespace GAME09 {
    class BANNER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int bannerImg;
            float imgSize;
            VECTOR2 centerPos;
            VECTOR2 nextPosOfst;
            VECTOR2 titlePosOfst;
            VECTOR2 artistPosOfst;
            VECTOR2 titleStrSize;
            VECTOR2 artistStrSize;

            float moveAnimeTime;
        };
    private:
        DATA Banner;
        int CurNum;
        int MoveNum;
        float AnimeNum;
        float AnimeTime;
        bool AnimeFlag;
        bool PlayDemoMusic;
        int BackGroundImageNum;
    public:
        BANNER(class GAME* game);
        ~BANNER();
        void create();
        void init();
        void update();
        void draw();

        bool animeFlag() { return AnimeFlag; }
    };
}