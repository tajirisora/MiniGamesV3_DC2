#include"GAME_OVER.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"GAME06.h"
namespace GAME06 
{
	void GAME_OVER::create() {
		GameOver = game()->container()->data().gameOver;
	}

	void GAME_OVER::draw() {
		clear(GameOver.bgColor);
		fill(GameOver.textColor);
		textSize(GameOver.textSize);
		text(GameOver.str, GameOver.pos.x, GameOver.pos.y);
		fill(0);
		textSize(50);
		text("SPACEキーでタイトルに戻る", GameOver.pos.x + 50, GameOver.pos.y + 100);
	}

	void GAME_OVER::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}