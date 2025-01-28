#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "RANK_C.h"
#include "RANK_B.h"
#include "RANK_A.h"
#include "RANK_S.h"
#include "JUDGE_LIST.h"
#include "PLAYER.h"
#include "TARGET.h"
#include "BULLET.h"
namespace GAME06 
{
	class CONTAINER 
	{
	public:
		struct DATA {
			TITLE::DATA title;
			STAGE::DATA stage;
			RANK_C::DATA rankC;
			RANK_B::DATA rankB;
			RANK_A::DATA rankA;
			RANK_S::DATA rankS;
			JUDGE_LIST::DATA judgeList;
			PLAYER::DATA player;
			TARGET::DATA target;
			BULLET::DATA bullet;
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