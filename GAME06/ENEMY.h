#pragma once
#include"GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME06 
{
	class ENEMY :
		public GAME_OBJECT{
	public:
		struct DATA {
			VECTOR2 pos;
			float radius = 0.0f;
			COLOR fillColor;
			int hp = 0;
		};
	private:
		DATA Enemy;
	public:
		ENEMY(class GAME* game):GAME_OBJECT(game){}
		~ENEMY(){}
		void create();
		void init();
		void update();
		void draw();
	};
}