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
			float definedTime = 0.0f;
			int curState = 0;
		};
	private:
		DATA Stage;
	public:
		enum STATE_ID {
			CHOOSING_TYPE_ID,
			MAIN_ID
		};
	private:
		const int Line1 = 4;
		const int Line2 = 9;
		const int Line3 = 14;
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