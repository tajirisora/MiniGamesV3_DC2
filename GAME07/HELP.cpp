#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME07.h"
#include "HELP.h"

namespace GAME07
{
	HELP::HELP(class GAME* game) :
		SCENE(game) {

	}
	HELP::~HELP() {
	}
	void HELP::create() {
		Help = game()->container()->data().help;
	}
	void HELP::init() {
		CurPage = OPERATION;
	}
	void HELP::update() {
		if (isTrigger(KEY_D) || isTrigger(KEY_RIGHT)) {
			if (CurPage < NUM_PAGES - 1) {
				CurPage = (PAGES)(CurPage + 1);
				game()->soundMNG()->playSE(SOUNDMNG::STICK);
			}
		}
		if (isTrigger(KEY_A) || isTrigger(KEY_LEFT)) {
			if (CurPage > OPERATION) {
				CurPage = (PAGES)(CurPage - 1);
				game()->soundMNG()->playSE(SOUNDMNG::STICK);
			}
		}
	}
	void HELP::draw() {
		game()->backGround()->draw();
		image(Help.Imgs[CurPage], Help.imgPos.x, Help.imgPos.y, 0, Help.imgSize);
		image(Help.operationImg, Help.operationImgPos.x, Help.operationImgPos.y, 0, Help.operationImgSize);
	}
	void HELP::nextScene() {
		if (isTrigger(KEY_X)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}