#include "RESULT_B.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06 
{
	void RESULT_B::create() {
		ResultB = game()->container()->data().resultB;
	}

	void RESULT_B::draw() {
		clear(ResultB.backgroundColor);
		fill(ResultB.nameColor);
		textSize(ResultB.nameSize);
		text(ResultB.name, ResultB.namePos.x, ResultB.namePos.y);
		fill(ResultB.guidanceColor);
		textSize(ResultB.guidanceSize);
		text(ResultB.guidance, ResultB.guidancePos.x, ResultB.guidancePos.y);
	}

	void RESULT_B::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}