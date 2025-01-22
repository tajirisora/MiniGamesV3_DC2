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
		Stage.curTimer = Stage.initTimer;
		Stage.hitCounter = 0;
		game()->player()->init();
		//game()->enemy()->init();
	}

	void STAGE::update() {
		Stage.curTimer -= delta;
		game()->player()->update();
		//game()->enemy()->update();
		if (isTrigger(KEY_Q))Stage.hitCounter++;
	}

	void STAGE::draw() {
		clear(Stage.backgroundColor);
		game()->player()->draw();
		//game()->enemy()->draw();
		fill(0);
		textSize(40);
		text("上に移動：Wキー", 0, 40);
		text("下に移動：Sキー", 0, 80);
		text("手動でカウントアップ（テスト用）:Qキー", 0, 120);
		text((let)"" + Stage.curTimer, 0, 160);
		text((let)"" + Stage.hitCounter,0,200);
	}

	void STAGE::nextScene() {
		if (Stage.curTimer <= 0.0f) {
			game()->setRecode(Stage.hitCounter);
			if (Stage.hitCounter <= Line1) {
				game()->changeScene(GAME::RANK_C_ID);
			}
			else if (Stage.hitCounter <= Line2) {
				game()->changeScene(GAME::RANK_B_ID);
			}
			else if (Stage.hitCounter <= Line3) {
				game()->changeScene(GAME::RANK_A_ID);
			}
			else {
				game()->changeScene(GAME::RANK_S_ID);
			}
		}
	}
}