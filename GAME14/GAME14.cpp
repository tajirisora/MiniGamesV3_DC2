#include "../../libOne/inc/input.h"
#include "../MAIN/MAIN.h"
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"BUTTON.h"
#include"STOP_BUTTON.h"
#include"LEVER.h"
#include"LOTTERY.h"
#include"REEL.h"
#include"REEL_MAP.h"
#include"CONTAINER.h"
#include"CREDIT.h"
#include"BET.h"
#include"MAX_BET_BUTTON.h"
#include"PLAYER.h"
#include"BONUS_ANNOUNCE.h"
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
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[RESULT_ID] = new RESULT(this);
		for (int i = 0; i < NUM_SCENES; i++) {
			Scenes[i]->create();
		}
		Lever = new LEVER(this);
		StopButton = new STOP_BUTTON(this);
		Lottery = new LOTTERY(this);
		Reel = new REEL(this);
		ReelMap = new REEL_MAP(this);
		Credit = new CREDIT(this);
		Bet = new BET(this);
		Max_betButton = new MAX_BET_BUTTON(this);
		Player = new PLAYER(this);
		Bonus_Announce = new BONUS_ANNOUNCE(this);
		End_Button = new END_BUTTON(this);
		End_Button->create();
		Bonus_Announce->create();
		Player->create();
		Max_betButton->create();
		Bet->create();
		Credit->create();
		ReelMap->create();
		Reel->create();
		Lottery->create();
		StopButton->create();
		Lever->create();
		return 0;
	}

	void GAME::destroy()
	{
		delete End_Button;
		delete Bonus_Announce;
		delete Player;
		delete Max_betButton;
		delete Bet;
		delete Credit;
		delete ReelMap;
		delete Reel;
		delete Lottery;
		delete StopButton;
		delete Lever;
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		if (isTrigger(KEY_ENTER)&&
			(CurSceneId==TITLE_ID||CurSceneId == RESULT_ID)) {
			main()->backToMenu();
		}
	}
	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[sceneId]->init();
	}
	void GAME::charaInit() {
		Lottery->init();
		StopButton->init();
		Lever->init();
		ReelMap->init();
		Reel->init();
		Credit->init();
		Bet->init();
		Max_betButton->init();
		Player->init();
		Bonus_Announce->init();
		End_Button->init();
	}
	void GAME::charaUpdate() {
		Player->update();
		Lever->update();
		Reel->update();
		StopButton->update();
		Credit->update();
		Max_betButton->update();
		Bet->update();
		End_Button->update();
	}
	void GAME::charaDraw() {
		StopButton->draw();
		Lever->draw();
		//Reel->draw();
		//Reel->debagDraw();
		//Lottery->debugdraw();
		//Credit->debagdraw();
		Credit->draw();
		Bet->draw();
		Max_betButton->draw();
		//ReelMap->debagDraw();
		Player->draw();
		Bonus_Announce->draw();
		End_Button->draw();
	}
}
