#pragma once
#include "../MAIN/GAME_BASE.h"
#include"DICE.h"
#include"Player.h"
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
        void Judge(DiceSync* sync);
        void Countreset();
        void Play();
        void Input();
        void Win();
        void Lose();

        int DiceImg[6] = { 0 };
        int BackImg = 0,
            TitleImg = 0,
            SeatImg = 0,
            RollCount = 0,

            YottoCnt = 0,
            FourDiceCnt = 0,
            FullHouseCnt = 0,
            Staraight4Cnt = 0,
            Staraight5Cnt = 0;

        

        float DicePx[6] = { 0.0f },
            DicePy[6] = { 0.0f };

        bool RollFlag = false;
        DiceSync* sync = 0;
        Player* p1 = 0;
        Player* p2 = 0;
        DiceSync* diceSync() { return sync; }
    };
}
