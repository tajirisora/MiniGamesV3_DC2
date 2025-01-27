#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06 
{
	class TITLE :
		public SCENE
	{
	public:
		struct DATA {
			COLOR backScreenColor;
			float size1 = 0.0f;
			COLOR color1;
			VECTOR2 pos1;
			const char* str1 = nullptr;
			float size2 = 0.0f;
			COLOR color2;
			VECTOR2 pos2;
			const char* str2 = nullptr;
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