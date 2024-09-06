#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "MUSICSELECT.h"
//#include "ACHIEVEMENT.h"
//#include "BANNER.h"
//#include <filesystem>

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
		
	}
	void MUSICSELECT::update() {
		//if (game()->fade()->inEndFlag()) {
		//	if (Option) {
		//		game()->option()->update();
		//	}
		//	else {
		//		game()->banner()->update();
		//		game()->autoButton()->update();
		//		game()->optionButton()->update();
		//		if (isTrigger(KEY_ESCAPE)) game()->quit();
		//	}
		//}
	}
	void MUSICSELECT::draw() {
		clear(255);
		fill(0);
		print("select");
		//RHYTHM_GAME_CONTROLLER::SONGINFO songInfo = game()->banner()->curSongInfo();
		//game()->back()->draw(songInfo.backImageIdx, songInfo.backImageSize);
		//game()->banner()->draw();
		//game()->jacket()->draw(songInfo.jacketImageIdx, songInfo.jacketImageSize);
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