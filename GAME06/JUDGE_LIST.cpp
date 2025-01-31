#include "JUDGE_LIST.h"
#include "GAME06.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
namespace GAME06
{
	void JUDGE_LIST::create() {
		JudgeList = game()->container()->data().judgeList;
	}

	void JUDGE_LIST::draw() {
		fill(JudgeList.textColor);
		textSize(JudgeList.textSize);
		text(JudgeList.str1, JudgeList.textPos1.x, JudgeList.textPos1.y);
		text(JudgeList.str2, JudgeList.textPos2.x, JudgeList.textPos2.y);
		text(JudgeList.str3, JudgeList.textPos3.x, JudgeList.textPos3.y);
		text(JudgeList.str4, JudgeList.textPos4.x, JudgeList.textPos4.y);
	}
}