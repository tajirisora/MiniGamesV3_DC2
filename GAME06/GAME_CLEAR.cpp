#include"GAME_CLEAR.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"GAME06.h"
namespace GAME06 
{
	void GAME_CLEAR::create() {
		GameClear = game()->container()->data().gameClear;
	}

	void GAME_CLEAR::draw() {
		clear(GameClear.bgColor);
		fill(GameClear.textColor);
		textSize(GameClear.textSize);
		text(GameClear.str, GameClear.pos.x, GameClear.pos.y);
		fill(0);
		textSize(50);
		text("SPACEキーでタイトルに戻る", GameClear.pos.x + 50, GameClear.pos.y + 100);
	}

	void GAME_CLEAR::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}