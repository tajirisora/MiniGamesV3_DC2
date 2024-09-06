#include "../../libOne/inc/input.h"
#include "../MAIN/MAIN.h"
#include"TITLE.h"
#include"HOME.h"
#include"STAGE.h"
#include"RESULT.h"
#include"CONTAINER.h"
#include "GAME14.h"
namespace GAME14
{
	//ShowCousor(0)は使わない
	//showCursor(),hideCursor()を使う
	//メモリリークさせない
	int GAME::create()
	{
		Container = new CONTAINER();
		Container->load();
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[HOME_ID] = new HOME(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[RESULT_ID] = new RESULT(this);
		for (int i = 0; i < NUM_SCENES; i++) {
			Scenes[i]->create();
		}
		return 0;
	}

	void GAME::destroy()
	{
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[sceneId]->init();
	}

}
