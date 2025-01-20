#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME06
{
    class GAME :
        public GAME_BASE
    {
    //コンテナ
    private:
        class CONTAINER* Container = nullptr;
    public:
        class CONTAINER* container() { return Container; }
    //シーン
    public:
        enum SCENE_ID {
            TITLE_ID,
            STAGE_ID,
            RANK_C_ID,
            RANK_B_ID,
            RANK_A_ID,
            RANK_S_ID,
            TOTAL_SCENES_ID
        };
    private:
        class SCENE* Scenes[TOTAL_SCENES_ID]{};
        SCENE_ID CurSceneId = TITLE_ID;
    public:
        void changeScene(SCENE_ID nextSceneId);
        class SCENE* stage() { return Scenes[STAGE_ID]; }
    private:
        class JUDGE_LIST* JudgeList = nullptr;
    public:
        class JUDGE_LIST* judgeList() { return JudgeList; }
    //キャラクタ
    private:
        class PLAYER* Player = nullptr;
        class ENEMY* Enemy = nullptr;
    public:
        class PLAYER* player() { return Player; }
        class ENEMY* enemy() { return Enemy; }
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
