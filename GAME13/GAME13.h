#pragma once
#include "../MAIN/GAME_BASE.h"
#include<time.h>
namespace GAME13 {
    class GAME : public GAME_BASE {
    public:
        GAME(class MAIN* main) : GAME_BASE(main){}
        ~GAME() {}

        int create();
        void proc();
        void destroy();

    private:
        int score;          
        enum GameState {
            TITLE,
            PLAY,
            SUCCESS,
            OVER
        };
        GameState State = TITLE;
        void Init();
        void Title();
        void Play();
        void Success();
        void Over();
        int half;
    };
}
