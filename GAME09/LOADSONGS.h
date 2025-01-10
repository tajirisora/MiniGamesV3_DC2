#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class LOADSONGS :
        public SCENE
    {
    public:
        struct DATA {
            int msgSize;
            VECTOR2 barPos;
            VECTOR2 barSize;
            VECTOR2 msgPos;
            VECTOR2 percentPos;
        };
    private:
        DATA LoadSongs;
        int NumSongs;
        int CurLoad;
    public:
        LOADSONGS(class GAME* game);
        ~LOADSONGS();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
        void loadingMsg(bool& stopFlag);
    };
}