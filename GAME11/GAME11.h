#pragma once
#include "../MAIN/GAME_BASE.h"
#include"DICE.h"
#include<time.h>
#include<string.h>
namespace GAME11
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void destroy();
        void init();
        void proc();
    private:

        enum STATE {TITLE,PLAY,INPUT,WIN,LOSE};
        STATE State = TITLE;
        void Title();
        void Judge(DiceSync* Dsync);
        void Play();
        void Input();
        void Win();
        void Lose();

        int DiceImg[6] = { 0 };
        int BackImg = 0,
            TitleImg = 0,
            SeatImg = 0,
            RollCount = 0;

        float DicePx[6] = { 0.0f },
            DicePy[6] = { 0.0f };

        bool RollFlag = false;
        DiceSync* sync = 0;
       /* PLAYER* p1 = 0;
        PLAYER* p2 = 0;*/
    };
}
