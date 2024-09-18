#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "MUSICSELECT.h"

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
	}
	void MUSICSELECT::update() {
		if (game()->fade()->inEndFlag()) {
			game()->banner()->update();
			//game()->autoButton()->update();
			//game()->optionButton()->update();
		}
	}
	void MUSICSELECT::draw() {
		clear(0);
		SONGINFO songInfo = game()->songs()[game()->banner()->curNum()];

		game()->backGround()->draw(songInfo);
		game()->banner()->draw();
		game()->jacket()->draw(songInfo, Select.jacketTf);

		rectMode(CORNER);
		rect(0, 1020, 1920, 60);

		//RHYTHM_GAME_CONTROLLER::SONGINFO songInfo = game()->banner()->curSongInfo();
		//game()->autoButton()->draw();
		//game()->optionButton()->draw();
		//game()->score()->draw(Select.scorePos, Select.scoreSize, songInfo.highScore);
		//game()->achievement()->draw((ACHIEVEMENT::ACHIEVEMENTS)songInfo.achievement, Select.achievementPos, Select.achievementSize);
		//if (Option) game()->option()->draw();
	}
	void MUSICSELECT::nextScene() {
		//if (isTrigger(KEY_ENTER)) {
		//	if (!Option && game()->banner()->ChangeScene()) {
		//		game()->fade()->outStart();
		//	}
		//}
		//if (game()->fade()->outEndFlag()) {
		//	game()->changeScene(GAME::STAGE_ID);
		//}
		if (isTrigger(KEY_ENTER)) {
			game()->fade()->outStart();
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::STAGE_ID);
		}
	}
}