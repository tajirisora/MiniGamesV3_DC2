#include "RANK_A.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_A::create() {
		Rank_A = game()->container()->data().rank_A;
	}

	void RANK_A::draw() {
		clear(Rank_A.backgroundColor);
		game()->judgeList()->draw();
		fill(Rank_A.nameColor);
		textSize(Rank_A.nameSize);
		text(Rank_A.name, Rank_A.namePos.x, Rank_A.namePos.y);
		fill(Rank_A.guidanceColor);
		textSize(Rank_A.guidanceSize);
		text(Rank_A.guidance, Rank_A.guidancePos.x, Rank_A.guidancePos.y);
	}

	void RANK_A::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}