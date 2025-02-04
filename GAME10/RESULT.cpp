#include "RESULT.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
RESULT::RESULT(class GAME10_GAME* game)
	:SCENE(game) {
}
RESULT::~RESULT() {
}
void RESULT::create() {
	Result = game()->container()->result();
}
void RESULT::draw() {
	game()->scenes(GAME10_GAME::STAGE_ID)->draw();
	if (game()->player()->playerHp() <= NULL) {
		image(Result.resultImg[Result.HPOVER_ID], Result.imgPos.x, Result.imgPos.y);
	}
	else if (game()->time()->nowTime() <= NULL) {
		image(Result.resultImg[Result.TIMEOVER_ID], Result.imgPos.x, Result.imgPos.y);
	}
	else {
		image(Result.resultImg[Result.CLEAR_ID], Result.imgPos.x, Result.imgPos.y);
	}
}
void RESULT::sound() {
	if ((game()->distance()->clearDist() <= game()->distance()->sumDist()
		&& game()->player()->playerPos().x >= width)) {
		playSound(Result.clearBgm);
	}
	else if (game()->time()->nowTime() <= NULL
		|| game()->player()->playerHp() <= NULL) {
		playSound(Result.overBgm);
	}
}
void RESULT::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME10_GAME::TITLE_ID);
		stopSound(Result.clearBgm);
		game()->scenes(GAME10_GAME::TITLE_ID)->sound();
	}
}