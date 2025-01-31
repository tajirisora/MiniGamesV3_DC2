#include"STAGE.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
namespace GAME06 
{
	void STAGE::create() {
		Stage = game()->container()->data().stage;
	}

	void STAGE::init() {
		const DATA& stage = game()->container()->data().stage;
		Stage.timer = stage.timer;
		Stage.curState = WAITING_FOR_DECIDING_TYPE_ID;
		game()->collisionCounter() = 0;
		game()->player()->init();
		game()->target()->init();
		game()->bullet()->init();
	}

	void STAGE::update() {
		if (Stage.curState == WAITING_FOR_DECIDING_TYPE_ID) {
			if (isTrigger(KEY_LEFT)) {
				game()->player()->img() = game()->player()->type1();
			}
			else if (isTrigger(KEY_RIGHT)) {
				game()->player()->img() = game()->player()->type2();
			}
			if (isTrigger(KEY_SPACE)) {
				Stage.curState = UPDATING_CHARACTER_DATA_ID;
			}
		}
		else if (Stage.curState == UPDATING_CHARACTER_DATA_ID) {
			Stage.timer -= delta;
			game()->player()->update();
			game()->target()->update();
			if (game()->player()->triggerFlag() == true)game()->bullet()->update();
		}
	}

	void STAGE::draw() {
		clear(Stage.backScreenColor);
		rectMode(CORNER);
		COLOR darkGreen = { 0,88,45 };
		VECTOR2 sPos = { 100,0 };
		VECTOR2 ePos = { width - 200,height };
		fill(darkGreen);
		rect(sPos.x, sPos.y, ePos.x, ePos.y);
		rectMode(CENTER);
		if (Stage.curState == WAITING_FOR_DECIDING_TYPE_ID) {
			VECTOR2 pos1 = { width / 2 - 164,height / 2 };
			VECTOR2 pos2 = { width / 2 + 164,height / 2 };
			float angle = 0.0f;
			float scale = 0.2f;
			image(game()->player()->type1(), pos1.x, pos1.y, angle, scale);
			image(game()->player()->type2(), pos2.x, pos2.y, angle, scale);
			float size = 25;
			textSize(size);
			COLOR brack = { 0,0,0 };
			COLOR red = { 255,0,0 };
			VECTOR2 textPos1 = { width / 2 - 279,height / 2 + 143 };
			VECTOR2 textPos2 = { width / 2 + 49,height / 2 + 143 };
			if (game()->player()->img() == game()->player()->type1()) {
				fill(red);
				text("Type1", textPos1.x, textPos1.y);
				fill(brack);
				text("Type2", textPos2.x, textPos2.y);
			}
			else if (game()->player()->img() == game()->player()->type2()) {
				fill(brack);
				text("Type1", textPos1.x, textPos1.y);
				fill(red);
				text("Type2", textPos2.x, textPos2.y);
			}
			VECTOR2 textPos = { width / 2 - 360,height - 150 };
			size = 40;
			fill(brack);
			textSize(size);
			text("左右キーで選択、SPACEキーで開始", textPos.x, textPos.y);
		}
		else if (Stage.curState == UPDATING_CHARACTER_DATA_ID) {
			game()->player()->draw();
			game()->target()->draw();
			if (game()->player()->triggerFlag() == true)game()->bullet()->draw();
			COLOR red = { 255,0,0 };
			COLOR brack = { 0,0,0 };
			float size = 50;
			VECTOR2 pos = { 100,size };
			if ((int)Stage.timer > 5)fill(brack);
			else fill(red);
			textSize(size);
			text((let)"残り時間：" + (int)Stage.timer + "秒", pos.x, pos.y);
		}
	}

	void STAGE::nextScene() {
		if (Stage.timer <= 0.0f) {
			if (game()->collisionCounter() <= Line1) {
				game()->changeScene(GAME::RANK_C_ID);
			}
			else if (game()->collisionCounter() <= Line2) {
				game()->changeScene(GAME::RANK_B_ID);
			}
			else if (game()->collisionCounter() <= Line3) {
				game()->changeScene(GAME::RANK_A_ID);
			}
			else {
				game()->changeScene(GAME::RANK_S_ID);
			}
		}
	}
}