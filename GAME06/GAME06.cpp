#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "../MAIN//MAIN.h"
#include "TITLE.h"
#include "STAGE.h"
#include "RANK_C.h"
#include "RANK_B.h"
#include "RANK_A.h"
#include "RANK_S.h"
#include "JUDGE_LIST.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "TARGET.h"
#include "BULLET.h"
#include "GAME06.h"

namespace GAME06
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[RANK_C_ID] = new RANK_C(this);
		Scenes[RANK_B_ID] = new RANK_B(this);
		Scenes[RANK_A_ID] = new RANK_A(this);
		Scenes[RANK_S_ID] = new RANK_S(this);
		JudgeList = new JUDGE_LIST(this);
		CurSceneID = TITLE_ID;
		Player = new PLAYER(this);
		Target = new TARGET(this);
		Bullet = new BULLET(this);
		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[RANK_C_ID]->create();
		Scenes[RANK_B_ID]->create();
		Scenes[RANK_A_ID]->create();
		Scenes[RANK_S_ID]->create();
		JudgeList->create();
		Player->create();
		Target->create();
		Bullet->create();
		return 0;
	}

	void GAME::destroy()
	{
		delete Bullet;
		delete Target;
		delete Player;
		delete JudgeList;
		for (int i = 0; i < NUMBER_OF_SCENES_ID; ++i) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::changeScene(SCENE_ID nextSceneId) {
		CurSceneID = nextSceneId;
	}

	bool GAME::collision(class BULLET* bullet, class TARGET* target) {
		float dx = target->pos().x - bullet->pos().x;
		float dy = target->pos().y - bullet->pos().y;
		float distance = Sqrt(dx * dx + dy * dy);
		if (distance > 60.0f)return false;
		else return true;
	}

	void GAME::proc()
	{
		Scenes[CurSceneID]->proc();
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
