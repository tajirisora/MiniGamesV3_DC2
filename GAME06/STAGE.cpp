#include"STAGE.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06 
{
	void STAGE::create() {
		Stage = game()->container()->data().stage;
	}

	void STAGE::init() {
		game()->player()->init();
		//game()->enemy()->init();
	}

	void STAGE::update() {
		game()->player()->update();
		//game()->enemy()->update();
	}

	void STAGE::draw() {
		clear(Stage.bgColor);
		game()->player()->draw();
		//game()->enemy()->draw();
		fill(0);
		textSize(50);
		text("上に移動：Wキー", 0, 50);
		text("下に移動：Sキー", 0, 100);
	}

	void STAGE::nextScene() {
		if (isTrigger(KEY_UP)) {
			game()->changeScene(GAME::GAME_CLEAR_ID);
		}
		else if(isTrigger(KEY_DOWN)){
			game()->changeScene(GAME::GAME_OVER_ID);
		}
	}
}