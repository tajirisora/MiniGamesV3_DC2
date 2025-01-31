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
            KAKURITU,
            PLAY,
            PUSH,
            SUCCESS,
            TENSUCCESS,
            OVER
        };
        GameState State = TITLE;
        void Init();
        void Title();
        void Kakuritu();
        void Play();
        void Push();
        void Success();
        void TenSuccess();
        void Over();
        int half;
        int SuccessCnt = 0;

        bool SuccFlag = false;
        bool OverFlag = false;
        bool TenSuccFlag = false;
    };
}
