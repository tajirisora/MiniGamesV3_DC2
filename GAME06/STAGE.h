#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
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