#pragma once
#include "SCENE.h"
#include "../../libOne/inc/libOne.h"
class TUTORIAL :public SCENE
{
public:
	struct DATA {
		VECTOR2 ImgPos;
		int tutoImg[3];
		enum {
			ONE_PAGE,
			TOW_PAGE,
			THREE_PAGE,
			NUM_PAGE
		};
		int NOW_PAGE;
	};
private:
	DATA Tutorial;
public:
	TUTORIAL(class GAME10_GAME* game);
	~TUTORIAL();
	void create();
	void init();
	void update();
		void selectMove();
	void draw();
	void nextScene();
};

