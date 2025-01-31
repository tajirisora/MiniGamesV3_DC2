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
	if (game()->player()->playerHp() <= NULL
		|| game()->time()->nowTime() <= NULL) {
		image(Result.resultImg[Result.OVER_ID], Result.imgPos.x, Result.imgPos.y);
	}
	else {
		image(Result.resultImg[Result.CLEAR_ID], Result.imgPos.x, Result.imgPos.y);
	}
}
void RESULT::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME10_GAME::TITLE_ID);
	}
}