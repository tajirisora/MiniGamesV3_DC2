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
		clear(RankB.backgroundColor);
		game()->judgeList()->draw();
		fill(RankB.nameColor);
		textSize(RankB.nameSize);
		text(RankB.name, RankB.namePos.x, RankB.namePos.y);
		fill(RankB.guidanceColor);
		textSize(RankB.guidanceSize);
		text(RankB.guidance, RankB.guidancePos.x, RankB.guidancePos.y);
		fill(RankB.recodeColor);
		textSize(RankB.recodeSize);
		text((let)"‹L˜^F" + game()->recode() + "”­", RankB.recodePos.x, RankB.recodePos.y);
	}

	void RANK_B::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}