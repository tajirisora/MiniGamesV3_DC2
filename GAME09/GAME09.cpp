#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "LOADSONGS.h"
namespace GAME09
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[SELECT_ID] = new MUSICSELECT(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
		Scenes[LOADSONGS_ID] = new LOADSONGS(this);
		Scenes[LOADCHART_ID] = new LOADCHART(this);
		Fade = new FADE(this);
		ChartMNG = new CHARTMANAGER(this);
		Banner = new BANNER(this);
		Jacket = new JACKET(this);
		BackGround = new BACKGROUND(this);
		RGCont = new RHYTHM_GAME_CONTROLLER(this);
		Lane = new LANE(this);
		SoundMNG = new SOUNDMANAGER(this);

		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[SELECT_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[GAME_CLEAR_ID]->create();
		Scenes[LOADSONGS_ID]->create();
		Scenes[LOADCHART_ID]->create();
		Fade->create();
		ChartMNG->create();
		Banner->create();
		Jacket->create();
		BackGround->create();
		RGCont->create();
		Lane->create();
		SoundMNG->create();

		changeScene(TITLE_ID);
		return 0;
	}

	void GAME::destroy()
	{
		delete SoundMNG;
		delete Lane;
		delete RGCont;
		delete BackGround;
		delete Jacket;
		delete Banner;
		delete ChartMNG;
		delete Fade;
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		Fade->proc();
	}

	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
		if (CurSceneId == LOADSONGS_ID ||
			CurSceneId == LOADCHART_ID) {
			clear(0);
		}
		else {
			Fade->inStart();
		}
	}
}
