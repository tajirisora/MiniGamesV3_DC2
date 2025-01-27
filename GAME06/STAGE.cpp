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
		Stage.timer = Stage.timeToInit;
		Stage.collisionCounter = 0;
		Stage.curState = WAITING_ID;
		game()->player()->init();
		game()->target()->init();
		//game()->enemy()->init();
	}

	void STAGE::update() {
		if (Stage.curState == WAITING_ID) {
			class PLAYER* player = game()->player();
			if (isTrigger(KEY_LEFT)) {
				player->img() = player->type1();
			}
			else if (isTrigger(KEY_RIGHT)) {
				player->img() = player->type2();
			}
			if (isTrigger(KEY_SPACE)) {
				Stage.curState = MAIN_ID;
			}
		}
		else if (Stage.curState == MAIN_ID) {
			Stage.timer -= delta;
			game()->player()->update();
			game()->target()->update();
			//game()->enemy()->update();
			if (isTrigger(KEY_Q))Stage.collisionCounter++;
		}
	}

	void STAGE::draw() {
		clear(Stage.backScreenColor);
		if (Stage.curState == WAITING_ID) {
			rectMode(CENTER);
			class PLAYER* player = game()->player();
			image(player->type1(), width / 2 - 164, height / 2, 0.0f, 0.2f);
			image(player->type2(), width / 2 + 164, height / 2, 0.0f, 0.2f);
			textSize(25);
			COLOR brack = { 0,0,0 };
			COLOR red = { 255,0,0 };
			if (player->img() == player->type1()) {
				fill(red);
				text("Type1", width / 2 - 279, height / 2 + 143);
				fill(brack);
				text("Type2", width / 2 + 49, height / 2 + 143);
			}
			else if (player->img() == player->type2()) {
				fill(brack);
				text("Type1", width / 2 - 279, height / 2 + 143);
				fill(red);
				text("Type2", width / 2 + 49, height / 2 + 143);
			}
			fill(0);
			textSize(40);
			text("左右キーで選択、SPACEキーで開始", width / 2 - 360, height - 150);
		}
		else if (Stage.curState == MAIN_ID) {
			game()->player()->draw();
			game()->target()->draw();
			//game()->enemy()->draw();
			fill(0);
			textSize(40);
			text("上に移動：Wキー", 0, 40);
			text("下に移動：Sキー", 0, 80);
			text("カウントアップ（テスト用）:Qキー", 0, 120);
			text((let)"" + Stage.timer, 0, 160);
			text((let)"" + Stage.collisionCounter, 0, 200);
		}
	}

	void STAGE::nextScene() {
		if (Stage.timer <= 0.0f) {
			game()->setRecode(Stage.collisionCounter);
			if (Stage.collisionCounter <= Line1) {
				game()->changeScene(GAME::RANK_C_ID);
			}
			else if (Stage.collisionCounter <= Line2) {
				game()->changeScene(GAME::RANK_B_ID);
			}
			else if (Stage.collisionCounter <= Line3) {
				game()->changeScene(GAME::RANK_A_ID);
			}
			else {
				game()->changeScene(GAME::RANK_S_ID);
			}
		}
	}
}