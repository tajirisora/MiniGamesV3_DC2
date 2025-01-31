#include "TUTORIAL.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
TUTORIAL::TUTORIAL(class GAME10_GAME* game):SCENE(game){}
TUTORIAL::~TUTORIAL(){}
void TUTORIAL::create(){
	Tutorial = game()->container()->tutorial();
}
void TUTORIAL::init() {
	Tutorial = game()->container()->tutorial();
}
void TUTORIAL::update(){
	selectMove();
}
void TUTORIAL::selectMove(){
	if (isTrigger(KEY_A)) {
		if(Tutorial.NOW_PAGE != Tutorial.ONE_PAGE){
			Tutorial.NOW_PAGE--;
		}
	}
	if (isTrigger(KEY_D)) {
		Tutorial.NOW_PAGE++;
	}
}
void TUTORIAL::draw(){
	image(Tutorial.tutoImg[Tutorial.NOW_PAGE], Tutorial.ImgPos.x, Tutorial.ImgPos.y);
}
void TUTORIAL::nextScene(){
	if (Tutorial.NOW_PAGE == Tutorial.NUM_PAGE) {
		game()->changeScene(GAME10_GAME::TITLE_ID);
		game()->scenes(GAME10_GAME::TITLE_ID)->init();
	}
	
}