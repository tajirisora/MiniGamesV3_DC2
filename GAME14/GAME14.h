#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME14
{
    class GAME :
        public GAME_BASE
    {
    public:
        enum SCENE_ID {
            TITLE_ID,
            STAGE_ID,
            RESULT_ID,
            NUM_SCENES
        };
    private://コンテナ
        class CONTAINER* Container = nullptr;
    public:
        class CONTAINER* container() { return Container; }
    private:
        //シーン
        class SCENE* Scenes[NUM_SCENES]{ nullptr };
        SCENE_ID CurSceneId = TITLE_ID;
    public:
        void changeScene(SCENE_ID sceneId);
    private://キャラクタ
        class BUTTON* StopButton = nullptr;
        class LEVER* Lever = nullptr;
        class LOTTERY* Lottery = nullptr;
        class REEL* Reel = nullptr;
        class REEL_MAP* ReelMap = nullptr;
        class CREDIT* Credit = nullptr;
        class BET* Bet = nullptr;
        class MAX_BET_BUTTON* Max_betButton = nullptr;
        class PLAYER* Player = nullptr;
        class BONUS_ANNOUNCE* Bonus_Announce = nullptr;
        class END_BUTTON* End_Button = nullptr;
    public:
        class BUTTON* stopButton() { return StopButton; }
        class LEVER* lever() { return Lever; }
        class LOTTERY* lottery() { return Lottery; }
        class REEL* reel() { return Reel; }
        class REEL_MAP* reelMap() { return ReelMap; }
        class CREDIT* credit() { return Credit; }
        class BET* bet() { return Bet; }
        class MAX_BET_BUTTON* max_betButton() { return Max_betButton; }
        class PLAYER* player() { return Player; }
        class BONUS_ANNOUNCE* bonus_Announce() { return Bonus_Announce; }
        class END_BUTTON* end_Button() { return End_Button; }
        void charaInit();
        void charaUpdate();
        void charaDraw();
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
