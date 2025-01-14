#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06 
{
	class GAME_CLEAR :
		public SCENE{
	public:
		struct DATA {
			COLOR bgColor;
			float textSize;
			COLOR textColor;
			VECTOR2 pos;
			const char* str;
		};
	private:
		DATA GameClear;
	public:
		GAME_CLEAR(class GAME* game):SCENE(game){}
		~GAME_CLEAR(){}
		void create();
		void draw();
		void nextScene();
	};
}