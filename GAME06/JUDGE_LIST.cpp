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
		text(JudgeList.str1, JudgeList.pos1.x, JudgeList.pos1.y);
		text(JudgeList.str2, JudgeList.pos2.x, JudgeList.pos2.y);
		text(JudgeList.str3, JudgeList.pos3.x, JudgeList.pos3.y);
		text(JudgeList.str4, JudgeList.pos4.x, JudgeList.pos4.y);
	}
}