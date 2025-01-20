#include "RANK_B.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_B::create() {
		Rank_B = game()->container()->data().rank_B;
	}

	void RANK_B::draw() {
		clear(Rank_B.backgroundColor);
		game()->judgeList()->draw();
		fill(Rank_B.nameColor);
		textSize(Rank_B.nameSize);
		text(Rank_B.name, Rank_B.namePos.x, Rank_B.namePos.y);
		fill(Rank_B.guidanceColor);
		textSize(Rank_B.guidanceSize);
		text(Rank_B.guidance, Rank_B.guidancePos.x, Rank_B.guidancePos.y);
	}

	void RANK_B::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}