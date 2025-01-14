#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06 
{
	class TITLE :
		public SCENE{
	public:
		struct DATA {
			COLOR bgColor;
			float textSize;
			COLOR textColor;
			VECTOR2 pos;
			const char* str;
			float textSize2;
			COLOR textColor2;
			VECTOR2 pos2;
			const char* str2;
		};
	private:
		DATA Title;
	public:
		TITLE(class GAME* game):SCENE(game){}
		~TITLE(){}
		void create();
		void draw();
		void nextScene();
	};
}