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
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
