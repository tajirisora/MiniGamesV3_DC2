#pragma once
#include"GAME10_GAME.h"
#include "../MAIN/GAME_BASE.h"
namespace GAME10
{
    class GAME :
        public GAME_BASE
    {
    private:
        class GAME10_GAME game;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
