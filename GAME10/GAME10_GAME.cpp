#include "GAME10_GAME.h"
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"CONTAINER.h"
#include"HANDGUN_BULLETS.h"
#include"TIME.h"
#include"HP_GAUGE.h"
#include"ENEMYS.h"
#include"HANDGUN.h"
GAME10_GAME::GAME10_GAME(){
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[RESULT_ID] = new RESULT(this);

	Player = new PLAYER(this);
	HpGauge[PLAYERHP_ID] = new PLAYER_HP(this);
	HpGauge[ENEMYHP_ID] = new ENEMY_HPGAUGE(this);
	HandgunBullets = new HANDGUN_BULLETS(this);
	
	Enemies = new ENEMYS(this);

	Time = new TIME(this);
	Weapons[HANDGUN_ID] = new HANDGUN(this);

	CurSceneId = TITLE_ID;
	Container->load();
	Scenes[TITLE_ID]->create();
	Scenes[STAGE_ID]->create();
	Scenes[RESULT_ID]->create();

	Weapons[HANDGUN_ID]->create();
	HandgunBullets->create();
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
	delete HandgunBullets;
	delete Enemies;
	delete Time;
	for (int i = 0; i < NUM_WEAPON; i++) {
		delete Weapons[i];
	}
}
void GAME10_GAME::run(){
	Scenes[CurSceneId]->proc();
}
void GAME10_GAME::changeScene(SCENE_ID SceneId) {
	CurSceneId = SceneId;
	Scenes[CurSceneId]->init();
	if (CurSceneId == STAGE_ID) {
		for (int i = 0; i < NUM_WEAPON; i++) {
			Weapons[i]->init();
		}
	}
}