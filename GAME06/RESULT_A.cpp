#include "RESULT_A.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06 
{
	void RESULT_A::create() {
		ResultA = game()->container()->data().resultA;
	}

	void RESULT_A::draw() {
		clear(ResultA.backgroundColor);
		game()->judgeList()->draw();
		fill(ResultA.nameColor);
		textSize(ResultA.nameSize);
		text(ResultA.name, ResultA.namePos.x, ResultA.namePos.y);
		fill(ResultA.guidanceColor);
		textSize(ResultA.guidanceSize);
		text(ResultA.guidance, ResultA.guidancePos.x, ResultA.guidancePos.y);
	}

	void RESULT_A::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}