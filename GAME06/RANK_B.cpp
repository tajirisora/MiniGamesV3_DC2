#include "RANK_B.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_B::create() {
		RankB = game()->container()->data().rankB;
	}

	void RANK_B::draw() {
		clear(RankB.backScreenColor);
		game()->judgeList()->draw();
		fill(RankB.textColor1);
		textSize(RankB.textSize1);
		text(RankB.str1, RankB.textPos1.x, RankB.textPos1.y);
		fill(RankB.textColor2);
		textSize(RankB.textSize2);
		text(RankB.str2, RankB.textPos2.x, RankB.textPos2.y);
		fill(RankB.textColor3);
		textSize(RankB.textSize3);
		text((let)"記録：" + game()->collisionCounter() + "発", RankB.textPos3.x, RankB.textPos3.y);
		fill(0);
		textSize(30);
		text("ENTERキーでメニューに戻る", 0, height);
	}

	void RANK_B::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}