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
		text(JudgeList.str_S, JudgeList.pos_S.x, JudgeList.pos_S.y);
		text(JudgeList.str_A, JudgeList.pos_A.x, JudgeList.pos_A.y);
		text(JudgeList.str_B, JudgeList.pos_B.x, JudgeList.pos_B.y);
		text(JudgeList.str_C, JudgeList.pos_C.x, JudgeList.pos_C.y);
	}
}