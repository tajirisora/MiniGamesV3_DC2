#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME08
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void init();
        void proc();
        void destroy();
        void title();
        void play();
        void result();
        void draw();

    private:
        enum {
            TITLE,
            PLAY,
            RESULT
        };

        enum {
            SCENE1,
            SCENE2,
            SCENE3,
            SCENE4,
            SCENE5
        };
        int TitleImg;
        int FrameImg;

        int BackImg, BasicImg[10], AnomalyImg[10];
        int RightImg;
        int PlayerImg;
        int NumberImg[6];

        struct PLAYER {
            float px, py;
            float vx;
        };

        PLAYER player;

        int ClearNum;
        int GameClearImg;
        int AnomalyTypeFlag;

        int BeforeAnomaly;

        bool AnomalyFlag;

        bool firstFlag;
        bool onceAnomalyFlag;
        bool AnomalyClearFlag;



        int SCENE = SCENE1;
        int STATE = TITLE;

    };
}
