#pragma once
#include "SCENE.h"
#include "../../libOne/inc/libOne.h"
class STAGE:public SCENE
{
public:
	struct DATA {
		VECTOR2 imgPos;
		int backImg = 0;
		int opy;
		int opx;
		struct LANE {
			int LaneImg ;
			VECTOR2 Pos;
			int LaneNumber;
		};
		LANE Lanes[4];
		int My;
	};
private:
	DATA Stage;
public:
	STAGE(class GAME10_GAME* game);
	~STAGE();
	void init();
	void update();
	void create();
	void draw();
	void nextScene();
};

