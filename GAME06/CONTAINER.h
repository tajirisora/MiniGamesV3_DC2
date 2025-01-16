#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT_C.h"
#include"RESULT_B.h"
#include"RESULT_A.h"
#include"RESULT_S.h"
#include"PLAYER.h"
#include"ENEMY.h"
namespace GAME06 
{
	class CONTAINER {
	public:
		struct DATA {
			TITLE::DATA title;
			STAGE::DATA stage;
			RESULT_C::DATA resultC;
			RESULT_B::DATA resultB;
			RESULT_A::DATA resultA;
			RESULT_S::DATA resultS;
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