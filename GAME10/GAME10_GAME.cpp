#include "GAME10_GAME.h"
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"CONTAINER.h"
GAME10_GAME::GAME10_GAME(){
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[RESULT_ID] = new RESULT(this);
	Player = new PLAYER(this);
	CurSceneId = TITLE_ID;
	Container->load();
	Scenes[TITLE_ID]->create();
	Scenes[STAGE_ID]->create();
	Scenes[RESULT_ID]->create();
}
GAME10_GAME::~GAME10_GAME(){
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
}
void GAME10_GAME::run(){
	Scenes[CurSceneId]->proc();
}
void GAME10_GAME::changeScene(SCENE_ID SceneId) {
	CurSceneId = SceneId;
}