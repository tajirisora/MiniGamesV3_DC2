#pragma once
#include "SCENE.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09 {
    class LOADCHART :
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
        DATA LoadChart;
        int NumRow;
        int CurRow;
    public:
        LOADCHART(class GAME* game);
        ~LOADCHART();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
        void loadingMsg(bool& stopFlag);
    };
}