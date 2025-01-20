#include "RANK_S.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_S::create() {
		Rank_S = game()->container()->data().rank_S;
	}

	void RANK_S::draw() {
		clear(Rank_S.backgroundColor);
		game()->judgeList()->draw();
		fill(Rank_S.nameColor);
		textSize(Rank_S.nameSize);
		text(Rank_S.name, Rank_S.namePos.x, Rank_S.namePos.y);
		fill(Rank_S.guidanceColor);
		textSize(Rank_S.guidanceSize);
		text(Rank_S.guidance, Rank_S.guidancePos.x, Rank_S.guidancePos.y);
	}

	void RANK_S::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}