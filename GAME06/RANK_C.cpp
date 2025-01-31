#include "RANK_C.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_C::create() {
		RankC = game()->container()->data().rankC;
	}

	void RANK_C::draw() {
		clear(RankC.backScreenColor);
		game()->judgeList()->draw();
		fill(RankC.textColor1);
		textSize(RankC.textSize1);
		text(RankC.str1, RankC.textPos1.x, RankC.textPos1.y);
		fill(RankC.textColor2);
		textSize(RankC.textSize2);
		text(RankC.str2, RankC.textPos2.x, RankC.textPos2.y);
		fill(RankC.textColor3);
		textSize(RankC.textSize3);
		text((let)"‹L˜^F" + game()->collisionCounter() + "”­", RankC.textPos3.x, RankC.textPos3.y);
	}

	void RANK_C::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}