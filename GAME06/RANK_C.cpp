#include "RANK_C.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06
{
	void RANK_C::create() {
		Rank_C = game()->container()->data().rank_C;
	}

	void RANK_C::draw() {
		clear(Rank_C.backgroundColor);
		game()->judgeList()->draw();
		fill(Rank_C.nameColor);
		textSize(Rank_C.nameSize);
		text(Rank_C.name, Rank_C.namePos.x, Rank_C.namePos.y);
		fill(Rank_C.guidanceColor);
		textSize(Rank_C.guidanceSize);
		text(Rank_C.guidance, Rank_C.guidancePos.x, Rank_C.guidancePos.y);
	}

	void RANK_C::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}