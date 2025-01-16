#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME06 
{
	class STAGE :
		public SCENE{
	public:
		struct DATA {
			COLOR backgroundColor;
			float curTimer = 0.0f;
			float initTimer = 0.0f;
			int hitCounter = 0;
		};
	private:
		DATA Stage;
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