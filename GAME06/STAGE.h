#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06 
{
	class STAGE :
		public SCENE
	{
	public:
		struct DATA {
			COLOR backScreenColor;
			float timer = 0.0f;
			int curState = 0;
			VECTOR2 sPos;
			VECTOR2 ePos;
			VECTOR2 textPos1;
			VECTOR2 textPos2;
			VECTOR2 textPos3;
			VECTOR2 textPos4;
		};
	private:
		DATA Stage;
	public:
		enum STATE_ID {
			WAITING_FOR_DECIDING_TYPE_ID,
			UPDATING_CHARACTER_DATA_ID
		};
	private:
		//Rankä‘ÇÃã´äEê¸
		const int Line1 = 0;
		const int Line2 = 5;
		const int Line3 = 9;
	private:
		VECTOR2 Pos1 = { 796,540 };
		VECTOR2 Pos2 = { 1124,540 };
		float Angle = 0.0f;
		float Scale = 0.2f;
	public:
		STAGE(class GAME* game) :SCENE(game){}
		~STAGE(){}
		void create();
		void init();
		void update();
		void draw();
		void nextScene();
	};
}