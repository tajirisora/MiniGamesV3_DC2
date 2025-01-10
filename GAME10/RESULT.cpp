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
	printSize(200);
	game()->scenes(GAME10_GAME::STAGE_ID)->draw();
	if (game()->player()->playerData().hp <= NULL
		|| game()->time()->nowTime() <= NULL) {
		text("GAME OVER",width/2,height/2);
		text("SPACEでタイトルに戻る", 300, height / 2 + 200);
	}
	else {
		text("GAME CLEAR", width / 2, height / 2);
		text("SPACEでタイトルに戻る", 300, height / 2 + 200);
	}
}
void RESULT::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME10_GAME::TITLE_ID);
	}
}