#pragma once
#include"GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"
namespace GAME06 
{
	class PLAYER :
		public GAME_OBJECT{
	public:
		struct DATA {
			VECTOR2 pos;
			float radius = 0.0f;
			float advSpeed = 0.0f;
			COLOR fillColor;
			int hp = 0;
			//launchVec
			/*VECTOR2 launchVec;
			float triggerErapsedTime;
			float triggerInterval;*/
		};
	private:
		DATA Player;
	public:
		PLAYER(class GAME* game):GAME_OBJECT(game){}
		~PLAYER(){}
		void create();
		void init();
		void update();
		void draw();
	};
}