#pragma once
#include "../MAIN/GAME_BASE.h"
#include"TRAMP.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRAMP_NUM (ONEMARK_NUM * TRAMP_MARK)
#define ONEMARK_NUM 13
#define TRAMP_MARK 4
namespace GAME05
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
    private:
        enum STATE { TITLE, CHANGEBETCOIN, JOB, RULE, RULEPAGE, RULEPAGE2, GACHA, PLAY, SHOW, WIN, STRAIGHTWIN, LOSE, DRAW, RESULT, RESULT2, BOX, PROB};
        STATE State = TITLE;
        Card* deck = nullptr;
        void Init();
        void initialCards(Card* deck);
        void shuffleCards(Card* deck);
        void Title();
        void ChangeBetCoin();
        void Job();
        void Rule();
        void RulePage();
        void RulePage2();
        void Play(Card* deck);
        void Show();
        void Win();
        void StraightWin();
        void Lose();
        void Draw();
        void Init2();
        void Gacha();
        void Result();
        void Result2();
        void Box();
        void Prob();
        void draw();

        int DaiyaImg[ONEMARK_NUM] = { 0 };
        int HeartImg[ONEMARK_NUM] = { 0 };
        int CloverImg[ONEMARK_NUM] = { 0 };
        int SpadeImg[ONEMARK_NUM] = { 0 };
        int SetImg[2] = { 0 };
        int SetNum[2] = { 0 };
        int HaimenImg = 0;
        int TrampImg = 0;
        int TamagoImg = 0;
        int GachaImg = 0;
        int Egg1Img = 0;
        int Egg2Img = 0;
        int Egg3Img = 0;
        int Egg4Img = 0;
        int Egg5Img = 0;
        int Egg6Img = 0;
        int Egg7Img = 0;
        int Egg8Img = 0;
        int Egg9Img = 0;
        int Egg10Img = 0;
        int Egg11Img = 0;
        int WhiteImg = 0;
        int ChipImg = 0;
        int Chip_2Img = 0;
        int WinImg = 0;
        int RuleImg = 0;
        int Rule2Img = 0;
        int Rule3Img = 0;
        int ChikettoImg = 0;
        int Chiketto2Img = 0;
        int SeggImg = 0;
        int SresultImg = 0;
        int Sresult2Img = 0;
        int ReggImg = 0;
        int RresultImg = 0;
        int Rresult2Img = 0;

        int DrawSnd = 0;
        int WinSnd = 0;
        int LoseSnd = 0;
        int BackSnd = 0;
        int straightWinSnd = 0;
        int PakaSnd = 0;
        int KakuteiSnd = 0;
        int GetSnd = 0;

        int WinCnt = 0;
        int BetCoins = 100;
        int GetCoins = BetCoins * 2;
        int straightWinCnt = 0;
        int freeCnt = 0;
        int PlayCnt = 0;
        char chara = 0;
        int playerCoins = 1000000;
        int confirm = 0;
        int confirm1 = 0;
        int confirm2 = 0;
        int confirm3 = 0;
        int confirm4 = 0;
        int confirm5 = 0;
        int confirm6 = 0;
        int confirm7 = 0;
        int confirm8 = 0;
        int confirm9 = 0;
        int confirm10 = 0;
        int confirm11 = 0;
        int Count = 0;
        int CountDown = 0;
        int PageCnt = 1;
        int ChikettoCnt = 0;

        float CardSetPx[2] = { 0.0f };
        float CardSetPy[2] = { 0.0f };
        float HaimenPx = 0.0f;
        float HaimenPy = 0.0f;
        float sFrameCnt = 0.0f;
        float rFrameCnt = 0.0f;

        bool loopSnd = true;
        bool winFlag = false;
        bool loseFlag = false;
        bool drawFlag = false;
        bool jobFlag = false;
        bool straightWinFlag = false;
        bool ChikettoFlag = false;

        int s0 = 0;
        int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0,
            r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, 
            r11 = 0;

        int rare4Total = 0; int rare5Total = 0;
        int rare6Total = 0; int rare7Total = 0;

        int randrare4 = 0; int randrare5 = 0;
        int randrare6 = 0; int randrare7 = 0;

        int randrare4_1 = 0; int randrare5_1 = 0;
        int randrare6_1 = 0; int randrare7_1 = 0;

        int randrare4_2 = 0; int randrare5_2 = 0;
        int randrare6_2 = 0; int randrare7_2 = 0;

        int randrare4_3 = 0; int randrare5_3 = 0;
        int randrare6_3 = 0; int randrare7_3 = 0;

        int randrare4_4 = 0; int randrare5_4 = 0;
        int randrare6_4 = 0; int randrare7_4 = 0;

        int randrare4_5 = 0; int randrare5_5 = 0;
        int randrare6_5 = 0; int randrare7_5 = 0;

        int randrare4_6 = 0; int randrare5_6 = 0;
        int randrare6_6 = 0; int randrare7_6 = 0;

        int randrare4_7 = 0; int randrare5_7 = 0;
        int randrare6_7 = 0; int randrare7_7 = 0;

        int randrare4_8 = 0; int randrare5_8 = 0;
        int randrare6_8 = 0; int randrare7_8 = 0;

        int randrare4_9 = 0; int randrare5_9 = 0;
        int randrare6_9 = 0; int randrare7_9 = 0;

        int randrare4_10 = 0; int randrare5_10 = 0;
        int randrare6_10 = 0; int randrare7_10 = 0;

        int randrare4_11 = 0; int randrare5_11 = 0;
        int randrare6_11 = 0; int randrare7_11 = 0;

        float sPx = 0, sPy = 0;

        float r1Px = 0;
        float r1Py = 0;
        float r2Px = 0;
        float r3Px = 0;
        float r4Py = 0;
        float r7Py = 0;
        float r10Px = 0;
        float r10Py = 0;
        float r11Px = 0;

        float TotalProb5 = 0.0f;
        float TotalProb6 = 0.0f;
        float TotalProb7 = 0.0f;

        struct CHARA {
            const char name[10];
            int star;
            int getCnt;
        };
        struct CHARA rare4[10]{
            {"‰ÌìLd", 4, 0},{"ƒo ƒX ƒR", 4, 0},{"Ã Œä ‘O", 4, 0},{"‚¨‚è‚å‚¤", 4, 0},{"‚™Wì", 4, 0},
            {"–¾’qŒõG", 4, 0},{"‘O“cŒcŸ", 4, 0},{"•s“®–¾‰¤", 4, 0},{"ˆ¢ C —…", 4, 0},{"“¿ì‰ÆŒõ", 4, 0},
        };
        struct CHARA rare5[9]{
            {"•½ ´ ·", 5, 0},{"“¿ìŒcŠì", 5, 0},{"ƒKƒŠƒŒƒI", 5, 0},{"‡ ® •”", 5, 0},{"´­”[Œ¾", 5, 0},
            {"ƒXƒTƒmƒI", 5, 0},{"Œ¹ ‹` Œo", 5, 0},{"ˆÀ”{°–¾", 5, 0},{"ƒ}ƒ[ƒ‰ƒ“", 5, 0}
        };
        struct CHARA rare6[8]{
            {"D“cM’·", 6, 0},{"“¿ì‰ÆN", 6, 0},{"–LbG‹g", 6, 0},{"ƒCƒUƒiƒ~", 6, 0},
            {"ƒCƒUƒiƒM", 6, 0},{"ƒGƒWƒ\ƒ“", 6, 0},{"“V‘l˜Y", 6, 0},{"”Ú –í ŒÄ", 6, 0}
        };
        struct CHARA rare7[7]{
            {"Œb ”ä õ", 7, 0},{"‘å • “V", 7, 0},{"•Ÿ ˜\ õ", 7, 0},{"”ù¹–å“V", 7, 0},
            {"•z ‘Ü ‘¸", 7, 0},{"õ ˜V l", 7, 0},{"•Ù à “V", 7, 0}
        };
    };
}