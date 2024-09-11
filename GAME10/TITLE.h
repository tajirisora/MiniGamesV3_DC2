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
		enum SELECT_ID {
			START_ID,
			RANKING_ID
		};
	};
private:
	DATA Title;
public:
	TITLE(class GAME10_GAME* game);
	~TITLE();
	void create();
	void draw();
	void nextScene();
};

