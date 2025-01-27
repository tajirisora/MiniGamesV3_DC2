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
		fill(RankS.color1);
		textSize(RankS.size1);
		text(RankS.str1, RankS.pos1.x, RankS.pos1.y);
		fill(RankS.color2);
		textSize(RankS.size2);
		text(RankS.str2, RankS.pos2.x, RankS.pos2.y);
		fill(RankS.color3);
		textSize(RankS.size3);
		text((let)"‹L˜^F" + game()->recode() + "”­", RankS.pos3.x, RankS.pos3.y);
	}

	void RANK_S::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}