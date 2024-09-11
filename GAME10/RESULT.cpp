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
	clear(255);
	printSize(200);
	print("RESULT");
}
void RESULT::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME10_GAME::TITLE_ID);
	}
}