#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "RANK_C.h"
#include "RANK_B.h"
#include "RANK_A.h"
#include "RANK_S.h"
#include "JUDGE_LIST.h"
#include "PLAYER.h"
#include "ENEMY.h"
namespace GAME06 
{
	class CONTAINER {
	public:
		struct DATA {
			TITLE::DATA title;
			STAGE::DATA stage;
			RANK_C::DATA rank_C;
			RANK_B::DATA rank_B;
			RANK_A::DATA rank_A;
			RANK_S::DATA rank_S;
			JUDGE_LIST::DATA judgeList;
			PLAYER::DATA player;
			ENEMY::DATA enemy;
		};
	private:
		DATA Data;
	public:
		void load();
		void setData();
		void loadGraphic();
		const DATA& data() { return Data; }
	};
}