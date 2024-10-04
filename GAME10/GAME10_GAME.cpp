#include "GAME10_GAME.h"
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"CONTAINER.h"
#include"HANDGUN_BULLETS.h"
#include"TIME.h"
#include"HP_GAUGE.h"
#include"HANDGUN.h"
GAME10_GAME::GAME10_GAME(){
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[RESULT_ID] = new RESULT(this);

	Player = new PLAYER(this);
	PlayerHpGauge = new HP_GAUGE(this);
	HandgunBullets = new HANDGUN_BULLETS(this);
	
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
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	for (int i = 0; i < NUM_WEAPON; i++) {
		delete Weapons[i];
	}
	delete Container;
	delete Player;
	delete PlayerHpGauge;
	delete Time;
	delete HandgunBullets;
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