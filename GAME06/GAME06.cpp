#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../MAIN//MAIN.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"ENEMY.h"
#include "GAME06.h"
//仕様
//タイトル「射撃(仮)」
//ステージ
//＜
//プレイヤー　「上下の移動」と「弾の発射」
//敵(的) 　「上下の移動」と「速度の変化※1」と「方向の急な変更※2」※1は乱数で、※2はタイマーとif文で実現する
//制限時間　30秒
//＞
//リザルト　的に当たった数に応じてC～Sランクを当たった数と一緒に表示する

namespace GAME06
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
		Scenes[GAME_OVER_ID] = new GAME_OVER(this);
		CurSceneId = TITLE_ID;
		Player = new PLAYER(this);
		Enemy = new ENEMY(this);
		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[GAME_CLEAR_ID]->create();
		Scenes[GAME_OVER_ID]->create();
		Player->create();
		Enemy->create();
		return 0;
	}

	void GAME::destroy()
	{
		delete Enemy;
		delete Player;
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
