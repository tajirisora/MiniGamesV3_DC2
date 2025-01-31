#include "GAME10_GAME.h"
#include"TITLE.h"
#include"TUTORIAL.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"CONTAINER.h"
#include"HANDGUN_BULLETS.h"
#include"SHOTGUN_BULLET.h"
#include"TIME.h"
#include"DISTANCE.h"
#include"HP_GAUGE.h"
#include"ENEMYS.h"
#include"HANDGUN.h"
#include"SHOTGUN.h"
GAME10_GAME::GAME10_GAME(){
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[TUTORIAL_ID] = new TUTORIAL(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[SELECT_ID] = new SELECT(this);
	Scenes[RESULT_ID] = new RESULT(this);

	Player = new PLAYER(this);
	HpGauge[PLAYERHP_ID] = new PLAYER_HP(this);
	HpGauge[ENEMYHP_ID] = new ENEMY_HPGAUGE(this);
	HpGauge[OBJECTHP_ID] = new OBJECT_HP(this);
	Bullets[HANDGUNBULLET_ID] = new HANDGUN_BULLETS(this);
	Bullets[SHOTGUNBULLET_ID] = new SHOTGUN_BULLET(this);
	Bullets[MISSILEBULLET_ID] = new MISSILE_BULLETS(this);

	Enemies = new ENEMYS(this);

	Objects = new OBJECT(this);

	Time = new TIME(this);
	Distance = new DISTANCE(this);
	Weapons[HANDGUN_ID] = new HANDGUN(this);
	Weapons[SHOTGUN_ID] = new SHOTGUN(this);
	Weapons[MISSILE_ID] = new MISSILE(this);

	CurSceneId = TITLE_ID;
	Container->load();
	Scenes[TITLE_ID]->create();
	Scenes[TUTORIAL_ID]->create();
	Scenes[STAGE_ID]->create();
	Scenes[SELECT_ID]->create();
	Scenes[RESULT_ID]->create();

	Weapons[HANDGUN_ID]->create();
	Weapons[SHOTGUN_ID]->create();
	Weapons[MISSILE_ID]->create();
	Bullets[HANDGUNBULLET_ID]->create();
	Bullets[SHOTGUNBULLET_ID]->create();
	Bullets[MISSILEBULLET_ID]->create();
}
GAME10_GAME::~GAME10_GAME(){
	delete Container;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	delete Player;
	for (int i = 0; i < NUM_HP; i++) {
		delete HpGauge[i];
	}
	delete Enemies;
	delete Objects;
	delete Time;
	delete Distance;
	for (int i = 0; i < NUM_WEAPON; i++) {
		delete Weapons[i];
	}
	for (int i = 0; i < BULLET_NUM; i++) {
		delete Bullets[i];
	}
}
void GAME10_GAME::run(){
	Scenes[CurSceneId]->proc();
}
void GAME10_GAME::changeScene(SCENE_ID SceneId) {
	if ((CurSceneId == STAGE_ID && SceneId == SELECT_ID)
		||( CurSceneId == SELECT_ID && SceneId == STAGE_ID)) {
		CurSceneId = SceneId;
	}
	else {
		if (CurSceneId == STAGE_ID
			&& SceneId == RESULT_ID) {
			for (int i = 0; i < NUM_WEAPON; i++) {//武器のリセット
				Weapons[i]->init();
			}
		}
		CurSceneId = SceneId;
		Scenes[CurSceneId]->init();
	}

	//if (CurSceneId != SELECT_ID
	//	||CurSceneId == STAGE_ID) {
	//	CurSceneId = SceneId;
	//	Scenes[CurSceneId]->init();//ここがセレクト時にリセットされる原因
	//	if (CurSceneId == STAGE_ID) {
	//		for (int i = 0; i < NUM_WEAPON; i++) {
	//			Weapons[i]->init();
	//		}
	//	}
	//}
	//else {
	//	CurSceneId = SceneId;
	//}
}