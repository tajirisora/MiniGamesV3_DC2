#include "RESULT_S.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06 
{
	void RESULT_S::create() {
		ResultS = game()->container()->data().resultS;
	}

	void RESULT_S::draw() {
		clear(ResultS.backgroundColor);
		fill(ResultS.nameColor);
		textSize(ResultS.nameSize);
		text(ResultS.name, ResultS.namePos.x, ResultS.namePos.y);
		fill(ResultS.guidanceColor);
		textSize(ResultS.guidanceSize);
		text(ResultS.guidance, ResultS.guidancePos.x, ResultS.guidancePos.y);
	}

	void RESULT_S::nextScene() {
		if (isTrigger(KEY_S)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}