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
		clear(RankA.backgroundColor);
		game()->judgeList()->draw();
		fill(RankA.nameColor);
		textSize(RankA.nameSize);
		text(RankA.name, RankA.namePos.x, RankA.namePos.y);
		fill(RankA.guidanceColor);
		textSize(RankA.guidanceSize);
		text(RankA.guidance, RankA.guidancePos.x, RankA.guidancePos.y);
		fill(RankA.recodeColor);
		textSize(RankA.recodeSize);
		text((let)"‹L˜^F" + game()->recode() + "”­", RankA.recodePos.x, RankA.recodePos.y);
	}

	void RANK_A::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}