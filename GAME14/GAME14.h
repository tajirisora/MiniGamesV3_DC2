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
            HOME_ID,
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
        class REEL_MANAGER* ReelManager = nullptr;
        class REEL_CONTROL* ReelControl = nullptr;
        class LOTTERY* Lottery = nullptr;
    public:
        class BUTTON* stopButton() { return StopButton; }
        class LEVER* lever() { return Lever; }
        class REEL_MANAGER* reelManager() { return ReelManager; }
        class REEL_CONTROL* reelControl() { return ReelControl; }
        class LOTTERY* lottery() { return Lottery; }
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
