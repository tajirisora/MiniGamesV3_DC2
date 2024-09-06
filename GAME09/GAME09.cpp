#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
namespace GAME09
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[SELECT_ID] = new MUSICSELECT(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
		Fade = new FADE(this);

		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[SELECT_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[GAME_CLEAR_ID]->create();
		Fade->create();

		changeScene(TITLE_ID);
		return 0;
	}

	void GAME::destroy()
	{
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
		Fade->inStart();
	}
}
