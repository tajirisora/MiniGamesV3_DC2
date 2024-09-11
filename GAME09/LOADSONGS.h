#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class LOADSONGS :
        public SCENE
    {
    public:
        struct DATA {
        };
    private:
        DATA LoadSongs;
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