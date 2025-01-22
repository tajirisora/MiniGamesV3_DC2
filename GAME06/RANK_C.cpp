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
		clear(RankC.backgroundColor);
		game()->judgeList()->draw();
		fill(RankC.nameColor);
		textSize(RankC.nameSize);
		text(RankC.name, RankC.namePos.x, RankC.namePos.y);
		fill(RankC.guidanceColor);
		textSize(RankC.guidanceSize);
		text(RankC.guidance, RankC.guidancePos.x, RankC.guidancePos.y);
		fill(RankC.recodeColor);
		textSize(RankC.recodeSize);
		text((let)"‹L˜^F" + game()->recode() + "”­", RankC.recodePos.x, RankC.recodePos.y);
	}

	void RANK_C::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}