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
		Scenes[OPTION_ID] = new OPTION(this);
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
		KeyConfig = new KEYCONFIG(this);
		JudgeMNG = new JUDGEMANAGER(this);
		OptionButton = new OPTIONBUTTON(this);
		BackButton = new BACKBUTTON(this);
		LoadOption = new LOADOPTION(this);
		ColorPicker = new COLOR_PICKER(this);
		Detail = new DETAIL_VIEW(this);
		Combo = new COMBO(this);
		Score = new SCORE(this);
		Achievement = new ACHIEVEMENT(this);
		AutoButton = new AUTOBUTTON(this);
		SongTitle = new SONGTITLE(this);
		StartButton = new STARTBUTTON(this);
		DifficultySelect = new DIFFICULTYSELECT(this);
		WarningMessage = new WARNING_MESSAGE(this);

		Container->load();
		LoadOption->create();

		Scenes[TITLE_ID]->create();
		Scenes[SELECT_ID]->create();
		Scenes[OPTION_ID]->create();
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
		KeyConfig->create();
		JudgeMNG->create();
		OptionButton->create();
		BackButton->create();
		ColorPicker->create();
		Detail->create();
		Combo->create();
		Score->create();
		Achievement->create();
		AutoButton->create();
		SongTitle->create();
		StartButton->create();
		DifficultySelect->create();
		WarningMessage->create();

		changeScene(TITLE_ID);
		EscapeKeyValid = false;
		return 0;
	}

	void GAME::destroy()
	{
		delete WarningMessage;
		delete DifficultySelect;
		delete StartButton;
		delete SongTitle;
		delete AutoButton;
		delete Achievement;
		delete Score;
		delete Combo;
		delete Detail;
		delete ColorPicker;
		delete LoadOption;
		delete BackButton;
		delete OptionButton;
		delete JudgeMNG;
		delete KeyConfig;
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

		EscapeKeyValid = true;
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

	void GAME::exit() {
		main()->backToMenu();
	}
}
