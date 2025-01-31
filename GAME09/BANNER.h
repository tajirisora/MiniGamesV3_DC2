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
            VECTOR2 centerPos;
            VECTOR2 nextPosOfst;

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
        int curNum() { return BackGroundImageNum; }
    };
}