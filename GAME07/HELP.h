#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME07
{
    class HELP :
        public SCENE
    {
    public:
        enum PAGES{
            OPERATION,
            RULE,
            KINDS,
            NUM_PAGES
        };
        struct DATA {
            int Imgs[NUM_PAGES];
            VECTOR2 imgPos;
            float imgSize;

            int operationImg;
            VECTOR2 operationImgPos;
            float operationImgSize;
        };
    private:
        DATA Help;
        PAGES CurPage;
    public:
        HELP(class GAME* game);
        ~HELP();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
    };
}