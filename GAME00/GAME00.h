#pragma once
#include "../MAIN/GAME_BASE.h"
#include<vector>
#include<sstream>
namespace GAME00
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void destroy();
        void Titel(); 
        void proc();
        void Init();
        void Play();
        void Play2();
        void Play3();
        void Draw();
        void Draw2();
        void Draw3();
        void EnemyDraw();
        void EnemyDraw2();
        void Clear();

        int card_backImg = 0;

        float card1 = 0;
        float card2 = 0;
        float card3 = 0;
        float card4 = 0;

        float eCard1 = 0;
        float eCard2 = 0;
        float eCard3 = 0;
        float eCard4 = 0;
        
        float score = 0;
        float enemyScore = 0;
      
    private:
        enum STATE{ TITLE,PLAY,PLAY2,PLAY3,CLEAR};
        STATE State = TITLE;
    };
}
