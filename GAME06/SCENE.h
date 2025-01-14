#pragma once
#include"GAME_OBJECT.h"
namespace GAME06 
{
	class SCENE :
		public GAME_OBJECT{
	public:
		SCENE(class GAME* game):GAME_OBJECT(game){}
		virtual ~SCENE(){}
		virtual void create(){}
		virtual void init(){}
		virtual void update(){}
		virtual void draw(){}
		virtual void nextScene(){}
		void proc() {
			update();
			draw();
			nextScene();
		}
	};
}