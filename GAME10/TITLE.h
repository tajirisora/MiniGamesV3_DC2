#pragma once
#include "SCENE.h"
#include "../../libOne/inc/libOne.h"
class TITLE :public SCENE
{
public:
	struct DATA {
		VECTOR2 imgPos = 0;
		int selectNumb = 0;
		int titleImg = 0;
		int selectMy = 0;
		int selectX = 0;
		int selectY = 0;
		VECTOR2 crPos = 0;
		int rad = 0;
		int textSize = 0;
		enum SELECT_ID {
			T_ID,//2000m
			F_ID,//4000m
			S_ID,//6000m
			STATE_NUM
		};
		int SELECTSTATE = T_ID;
	};
private:
	DATA Title;
public:
	TITLE(class GAME10_GAME* game);
	~TITLE();
	void create();
	void update();
		void selectMove();
	void draw();
	void nextScene();
};

