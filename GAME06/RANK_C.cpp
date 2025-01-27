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
		fill(RankC.color1);
		textSize(RankC.size1);
		text(RankC.str1, RankC.pos1.x, RankC.pos1.y);
		fill(RankC.color2);
		textSize(RankC.size2);
		text(RankC.str2, RankC.pos2.x, RankC.pos2.y);
		fill(RankC.color3);
		textSize(RankC.size3);
		text((let)"‹L˜^F" + game()->recode() + "”­", RankC.pos3.x, RankC.pos3.y);
	}

	void RANK_C::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}