#include "TITLE.h"
#include"STAGE.h"
#include"CONTAINER.h"
#include"GAME10_GAME.h"
#include "../../libOne/inc/libOne.h"
TITLE::TITLE(class GAME10_GAME* game)
	:SCENE(game){
}
TITLE::~TITLE(){
}
void TITLE::update() {
	selectMove();
}
void TITLE::selectMove() {
	if (isTrigger(KEY_S)) {
		Title.SELECTSTATE = (Title.SELECTSTATE + 1) % Title.STATE_NUM;
	}
	if (isTrigger(KEY_W)) {
		Title.SELECTSTATE = Title.SELECTSTATE - 1;
		if (Title.SELECTSTATE <= -1) {
			Title.SELECTSTATE = Title.STATE_NUM - 1;
		}
	}
}
void TITLE::create() {
	Title = game()->container()->title();
}
void TITLE::draw(){
	clear(255);
  	image(Title.titleImg, Title.imgPos.x, Title.imgPos.y);
	fill(255, 0, 0);
	circle(Title.crPos.x, Title.crPos.y + Title.selectMy * Title.SELECTSTATE, Title.rad);
	fill(255);
	textSize(Title.textSize);
	text("2000m", Title.selectX, Title.selectY);
	text("4000m", Title.selectX, Title.selectY + Title.selectMy * Title.F_ID);
	text("6000m", Title.selectX, Title.selectY + Title.selectMy * Title.S_ID);
	text("à–¾", Title.selectX, Title.selectY + Title.selectMy * Title.TUTORIAL_ID);
}
void TITLE::nextScene(){
	if (isTrigger(KEY_SPACE) && Title.TUTORIAL_ID != Title.SELECTSTATE) {
		game()->changeScene(GAME10_GAME::STAGE_ID);
		game()->scenes(GAME10_GAME::STAGE_ID)->init();
		game()->distance()->setClearDist(Title.SELECTSTATE);
	}
	else if(isTrigger(KEY_SPACE) && Title.TUTORIAL_ID == Title.SELECTSTATE){
		game()->changeScene(GAME10_GAME::TUTORIAL_ID);
		game()->scenes(GAME10_GAME::TUTORIAL_ID)->init();
	}
}