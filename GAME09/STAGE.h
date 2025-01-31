#pragma once
#include "SCENE.h"
#include "SONGINFO.h"
#include "TRANSFORM.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class STAGE :
        public SCENE
    {
    public:
        enum CHOICES {
            RETRY,
            SELECT,
            NUM_CHOICES
        };
        struct DATA {
            TRANSFORM songTitleTF;
            TRANSFORM jacketTF;
        };
    private:
        DATA Stage;
        SONGINFO SongInfo;
        CHOICES Choices;
    public:
        STAGE(class GAME* game);
        ~STAGE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}