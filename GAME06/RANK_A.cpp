#include "RANK_A.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_A::create() {
		RankA = game()->container()->data().rankA;
	}

	void RANK_A::draw() {
		clear(RankA.backScreenColor);
		game()->judgeList()->draw();
		fill(RankA.textColor1);
		textSize(RankA.textSize1);
		text(RankA.str1, RankA.textPos1.x, RankA.textPos1.y);
		fill(RankA.textColor2);
		textSize(RankA.textSize2);
		text(RankA.str2, RankA.textPos2.x, RankA.textPos2.y);
		fill(RankA.textColor3);
		textSize(RankA.textSize3);
		text((let)"記録：" + game()->collisionCounter() + "発", RankA.textPos3.x, RankA.textPos3.y);
		fill(0);
		textSize(30);
		text("ENTERキーでメニューに戻る", 0, height);
	}

	void RANK_A::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}