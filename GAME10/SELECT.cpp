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
		Select.SELECT_NOW--;
		if (Select.SELECT_NOW < false) {
			Select.SELECT_NOW = Select.SKIP;
		}
	}
	if (isTrigger(KEY_S)) {
		Select.SELECT_NOW++;
		if (Select.SELECT_NOW >= Select.SELECT_NUM) {
			Select.SELECT_NOW = Select.HANDGUN;
		}
	}
	if (isTrigger(KEY_SPACE)) {
		Select.selectFlag = true;
	}
}
void SELECT::draw(){
	game()->scenes(GAME10_GAME::STAGE_ID)->draw();
	image(Select.backImg, Select.ImgPos.x, Select.ImgPos.y);
	for (int i = 0; i < Select.SELECT_NUM - 1; i++) {
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
		if (Select.SKIP == i) {
			textSize(Select.skipTextSize);
			text(Select.Moji[i], Select.skipPos.x, Select.skipPos.y);
		}
		else {
			if(Select.getFlag[i] == false){
				text(Select.noGetMoji[i], Select.textPos.x, Select.textPos.y + Select.textMy * i);
			}
			else {
				text(Select.Moji[i],Select.textPos.x,Select.textPos.y + Select.textMy * i);
			}
		}
	}
}
void SELECT::nextScene(){
	if (Select.selectFlag == true) {
		game()->changeScene(GAME10_GAME::STAGE_ID);
			if (Select.SELECT_NOW != Select.SKIP) {
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
			}
		Select.selectFlag = false;
	}
}