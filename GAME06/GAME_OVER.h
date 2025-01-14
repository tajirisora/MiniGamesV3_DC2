#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06 
{
	class GAME_OVER :
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
		DATA GameOver;
	public:
		GAME_OVER(class GAME* game):SCENE(game){}
		~GAME_OVER(){}
		void create();
		void draw();
		void nextScene();
	};
}