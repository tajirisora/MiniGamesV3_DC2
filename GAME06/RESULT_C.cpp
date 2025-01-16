#include "RESULT_C.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06 
{
	void RESULT_C::create() {
		ResultC = game()->container()->data().resultC;
	}

	void RESULT_C::draw() {
		clear(ResultC.backgroundColor);
		fill(ResultC.nameColor);
		textSize(ResultC.nameSize);
		text(ResultC.name, ResultC.namePos.x, ResultC.namePos.y);
		fill(ResultC.guidanceColor);
		textSize(ResultC.guidanceSize);
		text(ResultC.guidance, ResultC.guidancePos.x, ResultC.guidancePos.y);
	}

	void RESULT_C::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}