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
		fill(RankA.color1);
		textSize(RankA.size1);
		text(RankA.str1, RankA.pos1.x, RankA.pos1.y);
		fill(RankA.color2);
		textSize(RankA.size2);
		text(RankA.str2, RankA.pos2.x, RankA.pos2.y);
		fill(RankA.color3);
		textSize(RankA.size3);
		text((let)"‹L˜^F" + game()->collisionCounter() + "”­", RankA.pos3.x, RankA.pos3.y);
	}

	void RANK_A::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}