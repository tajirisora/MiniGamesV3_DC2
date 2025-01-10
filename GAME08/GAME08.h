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
        void proc();
        void destroy();
        void title();
        void init();
        void play();
        void result();
        void draw();

    private:
        enum {
            TITLE,
            PLAY,
            RESULT
        };

        int BackImg, TitleImg;
        int PlayGameImg[15];


        int STATE = TITLE;

    };
}
