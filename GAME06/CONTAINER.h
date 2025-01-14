#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
#include"ENEMY.h"
namespace GAME06 
{
	class CONTAINER {
	public:
		struct DATA {
			TITLE::DATA title;
			STAGE::DATA stage;
			GAME_CLEAR::DATA gameClear;
			GAME_OVER::DATA gameOver;
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