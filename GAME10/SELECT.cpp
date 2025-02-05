#include "SELECT.h"
#include"STAGE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
SELECT::SELECT(class GAME10_GAME* game):SCENE(game){}
SELECT::~SELECT(){}
void SELECT::create(){
	Select = game()->container()->select();
}
void SELECT::init(){
	Select = game()->container()->select();
}
void SELECT::update(){
	if (isTrigger(KEY_W)) {
		playSound(Select.selectMoveSound);
		Select.SELECT_NOW--;
		if (Select.SELECT_NOW < false) {
			Select.SELECT_NOW = Select.MISSILE;
		}
	}
	if (isTrigger(KEY_S)) {
		playSound(Select.selectMoveSound);
		Select.SELECT_NOW++;
		if (Select.SELECT_NOW >= Select.SELECT_NUM) {
			Select.SELECT_NOW = Select.HANDGUN;
		}
	}
	if (isTrigger(KEY_SPACE)) {
		playSound(Select.selectSound);
		Select.selectFlag = true;
	}
}
void SELECT::draw(){
	game()->scenes(GAME10_GAME::STAGE_ID)->draw();
	image(Select.backImg, Select.ImgPos.x, Select.ImgPos.y);
	for (int i = 0; i < Select.SELECT_NUM; i++) {
		image(Select.weaponImg[i], Select.weaponImgPos.x, Select.weaponImgPos.y + Select.weaponImgMy * i);
	}
	for (int i = 0; i < Select.SELECT_NUM; i++) {
		textSize(50);
		if (Select.SELECT_NOW == i) {
			fill(Select.selectColor);
		}
		else {
			fill(Select.noSelectColor);
		}
		if(Select.getFlag[i] == false){
			text(Select.noGetMoji[i], Select.textPos.x, Select.textPos.y + Select.textMy * i);
		}
		else {
			text(Select.Moji[i],Select.textPos.x,Select.textPos.y + Select.textMy * i);
		}
	}
	fill(255);
	textSize(Select.spaceTextSize);
	text(Select.spaceText, Select.spacePos.x, Select.spacePos.y);
}
void SELECT::sound() {
	playSound(Select.upSound);
}
void SELECT::nextScene(){
	if (Select.selectFlag == true) {
		game()->changeScene(GAME10_GAME::STAGE_ID);
			if (Select.getFlag[Select.SELECT_NOW] == true) {
				game()->weapons(Select.SELECT_NOW)->levelUp();
			}
			else if (Select.getFlag[Select.SELECT_NOW] == false) {
				game()->player()->getWeapons(Select.SELECT_NOW);
				Select.getFlag[Select.SELECT_NOW] = true;
			}
			game()->enemies()->DestroyReset();
			game()->objects()->DestroyReset();
			game()->player()->doubleUp();
		Select.selectFlag = false;
	}
}