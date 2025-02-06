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
		Stage.curState = UPDATING_CHARACTER_DATA_ID;
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
		fill(0,88,45);
		rect(Stage.sPos.x, Stage.sPos.y, Stage.ePos.x, Stage.ePos.y);
		fill(255);
		textSize(30);
		text("ENTERキーでメニューに戻る", 0, height);
		rectMode(CENTER);
		if (Stage.curState == WAITING_FOR_DECIDING_TYPE_ID) {
			image(game()->player()->type1(), Pos1.x, Pos1.y, Angle, Scale);
			image(game()->player()->type2(), Pos2.x, Pos2.y, Angle, Scale);
			textSize(25);
			if (game()->player()->img() == game()->player()->type1()) {
				fill(255,0,0);
				text("Type1", Stage.textPos1.x, Stage.textPos1.y);
				fill(0);
				text("Type2", Stage.textPos2.x, Stage.textPos2.y);
			}
			else if (game()->player()->img() == game()->player()->type2()) {
				fill(0);
				text("Type1", Stage.textPos1.x, Stage.textPos1.y);
				fill(255,0,0);
				text("Type2", Stage.textPos2.x, Stage.textPos2.y);
			}
			fill(0);
			textSize(50);
			text("見た目を選んでください", Stage.textPos3.x, Stage.textPos3.y);
			textSize(40);
			text("左右キーで選択、SPACEキーで開始", Stage.textPos4.x, Stage.textPos4.y);
		}
		else if (Stage.curState == UPDATING_CHARACTER_DATA_ID) {
			game()->player()->draw();
			game()->target()->draw();
			if (game()->player()->triggerFlag() == true)game()->bullet()->draw();
			if ((int)Stage.timer > 5)fill(0);
			else fill(255,0,0);
			textSize(50);
			text((let)"残り時間：" + (int)Stage.timer + "秒", 100, 50);
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