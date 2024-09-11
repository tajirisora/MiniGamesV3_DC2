#include "STAGE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
#include"GAME10_GAME.h"
STAGE::STAGE(GAME10_GAME* game) :SCENE(game) {}
STAGE::~STAGE() {
}
void STAGE::init() {
	
}
void STAGE::update() {
	
}
void STAGE::create() {
	
}
void STAGE::draw() {
	clear(255);
	printSize(200);
	print("STAGE");
}
void STAGE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME10_GAME::RESULT_ID);
	}
}