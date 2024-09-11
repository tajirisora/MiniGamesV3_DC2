#include "TITLE.h"
#include"CONTAINER.h"
#include"GAME10_GAME.h"
#include "../../libOne/inc/libOne.h"
TITLE::TITLE(class GAME10_GAME* game)
	:SCENE(game){
}
TITLE::~TITLE(){
}
void TITLE::create() {
	Title = game()->container()->title();
}
void TITLE::draw(){
	clear(255);
	image(Title.titleImg, Title.imgPos.x, Title.imgPos.y);
}
void TITLE::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME10_GAME::STAGE_ID);
	}
}