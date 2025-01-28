#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "MUSICSELECT.h"
#include "textFunc.h"

namespace GAME09 {
	MUSICSELECT::MUSICSELECT(class GAME* game) :
		SCENE(game) {

	}
	MUSICSELECT::~MUSICSELECT() {
	}

	void MUSICSELECT::create() {
		Select = game()->container()->data().select;
	}
	void MUSICSELECT::init() {
		game()->banner()->init();
		game()->keyConfig()->init();
	}
	void MUSICSELECT::update() {
		if (game()->fade()->inEndFlag()) {
			game()->banner()->update();
			//game()->autoButton()->update();
			game()->optionButton()->update();
			game()->autoButton()->update();
			if (game()->autoButton()->isClick()) game()->judgeMNG()->autoRef() ^= 1;
			game()->difficultySelect()->update();
			game()->startButton()->update();
			game()->backButton()->update();
		}
	}
	void MUSICSELECT::draw() {
		clear(0);
		SONGINFO songInfo = game()->songs()[game()->banner()->curNum()];

		game()->backGround()->draw(songInfo);
		game()->banner()->draw();
		game()->jacket()->draw(songInfo, Select.jacketTf);
		game()->score()->draw(Select.scoreTf.pos, Select.scoreTf.size, songInfo.highScore[game()->difficultySelect()->curDifficulty()]);
		game()->achievement()->draw((ACHIEVEMENT::ACHIEVEMENTS)songInfo.achievement[game()->difficultySelect()->curDifficulty()],
			Select.achievementTf.pos, Select.achievementTf.size);
		game()->optionButton()->draw();
		game()->autoButton()->draw();
		game()->difficultySelect()->draw();
		game()->startButton()->draw();
		game()->backButton()->draw();

		rectMode(CENTER);
		fill(0);
		rect(Select.operationPos.x, Select.operationPos.y, Select.operationSize.x, Select.operationSize.y);
		fill(255);
		textfMode(M_RIGHT);
		textf(Select.operationStr, Select.operationPos + Select.operationSize / 2, Select.operationSize);

		//RHYTHM_GAME_CONTROLLER::SONGINFO songInfo = game()->banner()->curSongInfo();
		//if (Option) game()->option()->draw();
	}
	void MUSICSELECT::nextScene() {
		if (game()->startButton()->isClick()) {
			if (!game()->banner()->animeFlag()) {
				game()->fade()->outStart();
			}
			NextScene = GAME::LOADCHART_ID;
		}
		if (game()->optionButton()->isClick()) {
			if (!game()->banner()->animeFlag()) {
				game()->fade()->outStart();
			}
			NextScene = GAME::OPTION_ID;
		}
		if (game()->backButton()->isClick()) {
			if (!game()->banner()->animeFlag()) {
				game()->fade()->outStart();
			}
			NextScene = GAME::TITLE_ID;
		}
		if (game()->fade()->outEndFlag()) {
			game()->soundMNG()->stopMusic();
			game()->changeScene(NextScene);
		}
	}
}