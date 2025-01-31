#include "RANK_S.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_S::create() {
		RankS = game()->container()->data().rankS;
	}

	void RANK_S::draw() {
		clear(RankS.backScreenColor);
		game()->judgeList()->draw();
		fill(RankS.textColor1);
		textSize(RankS.textSize1);
		text(RankS.str1, RankS.textPos1.x, RankS.textPos1.y);
		fill(RankS.textColor2);
		textSize(RankS.textSize2);
		text(RankS.str2, RankS.textPos2.x, RankS.textPos2.y);
		fill(RankS.textColor3);
		textSize(RankS.textSize3);
		text((let)"‹L˜^F" + game()->collisionCounter() + "”­", RankS.textPos3.x, RankS.textPos3.y);
	}

	void RANK_S::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}