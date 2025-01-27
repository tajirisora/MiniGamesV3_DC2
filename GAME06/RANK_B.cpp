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
		fill(RankB.color1);
		textSize(RankB.size1);
		text(RankB.str1, RankB.pos1.x, RankB.pos1.y);
		fill(RankB.color2);
		textSize(RankB.size2);
		text(RankB.str2, RankB.pos2.x, RankB.pos2.y);
		fill(RankB.color3);
		textSize(RankB.size3);
		text((let)"‹L˜^F" + game()->recode() + "”­", RankB.pos3.x, RankB.pos3.y);
	}

	void RANK_B::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}