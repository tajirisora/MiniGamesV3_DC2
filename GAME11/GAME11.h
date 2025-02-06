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
        void init2();
        void proc();


    private:

        enum STATE {TITLE,PLAY,INPUT,RESULT,WIN,LOSE};
        STATE State = TITLE;
        void Title();
        void Judge(DiceSync* sync);
        void Countreset();
        void Flagreset();
        void Dicelock(int i);
        void Play();
        void Input();
        void Result();
        void Win();
        void Lose();




        int DiceImg[6] = { 0 };
        int BackImg = 0,
            TitleImg = 0,
            SeatImg = 0,
            ResultImg = 0,
            RollCount = 0,

            YottoCnt = 0,
            FourDiceCnt = 0,
            FullHouseCnt = 0,
            FullHouseCnt2 = 0,
            Staraight4Cnt = 0,
            Staraight5Cnt = 0,

            FullHouseNum[5] = {0},

            FHFN[5] = {0},
            
            ClearCnt = 0,
            
            St5FlgCnt = 0,

            St4FlgCnt = 0;
        

        float DicePx[5] = { 0.0f },
            DicePy =  0.0f ,

            DiceKeyPx[5] = {0.0f},
            DiceKeyPy = 0.0f,


           
            TextPx = 0.0f,
            ScorePx = 0.0f;



        bool RollFlag = false,
            
            FullHouseFlag[5] = { false },
            
            St5Flag[6] = { false },
            
            St4Flag[6] = { false };


        DiceSync* sync = 0;
        Player* p1 = 0;
        Player* p2 = 0;
        DiceSync* diceSync() { return sync; }
    };
}
