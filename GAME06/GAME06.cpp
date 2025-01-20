#include "../../libOne/inc/input.h"
#include "../MAIN//MAIN.h"
#include "TITLE.h"
#include "STAGE.h"
#include "RESULT_C.h"
#include "RESULT_B.h"
#include "RESULT_A.h"
#include "RESULT_S.h"
#include "JUDGE_LIST.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "GAME06.h"
//仕様
//タイトル「射撃(仮)」
//ステージ
//　プレイヤー　「上下の移動」と「弾の発射」弾は一発発射したらその弾が消えるまで発射不可能にする　発射された弾は的に当たるか画面外に出たら消す
//　敵(的) 　「上下の移動」と「速度の変化」
//　制限時間　30秒
//リザルト　的に当たった数に応じてC～Sランクを表示する　C～Sランクの判定基準を左上に表示する

namespace GAME06
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[RESULT_C_ID] = new RESULT_C(this);
		Scenes[RESULT_B_ID] = new RESULT_B(this);
		Scenes[RESULT_A_ID] = new RESULT_A(this);
		Scenes[RESULT_S_ID] = new RESULT_S(this);
		JudgeList = new JUDGE_LIST(this);
		CurSceneId = TITLE_ID;
		Player = new PLAYER(this);
		Enemy = new ENEMY(this);
		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[RESULT_C_ID]->create();
		Scenes[RESULT_B_ID]->create();
		Scenes[RESULT_A_ID]->create();
		Scenes[RESULT_S_ID]->create();
		JudgeList->create();
		Player->create();
		Enemy->create();
		return 0;
	}

	void GAME::destroy()
	{
		delete Enemy;
		delete Player;
		delete JudgeList;
		for (int i = 0; i < TOTAL_SCENES_ID; ++i) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::changeScene(SCENE_ID nextSceneId) {
		CurSceneId = nextSceneId;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
