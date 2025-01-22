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
		clear(RankS.backgroundColor);
		game()->judgeList()->draw();
		fill(RankS.nameColor);
		textSize(RankS.nameSize);
		text(RankS.name, RankS.namePos.x, RankS.namePos.y);
		fill(RankS.guidanceColor);
		textSize(RankS.guidanceSize);
		text(RankS.guidance, RankS.guidancePos.x, RankS.guidancePos.y);
		fill(RankS.recodeColor);
		textSize(RankS.recodeSize);
		text((let)"‹L˜^F" + game()->recode() + "”­", RankS.recodePos.x, RankS.recodePos.y);
	}

	void RANK_S::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}