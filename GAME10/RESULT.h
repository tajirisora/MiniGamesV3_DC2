#pragma once
#include "SCENE.h"
#include "../../libOne/inc/libOne.h"
class RESULT :
    public SCENE
{
public:
	struct DATA {
		enum {
			CLEAR_ID,
			TIMEOVER_ID,
			HPOVER_ID,
			ID_NUM
		};
		int clearBgm;
		int timeOverImg;
		int hpOverImg;
		int overBgm;
		int resultImg[ID_NUM];
		VECTOR2 imgPos;
	};
private:
	DATA Result;
public:
	RESULT(class GAME10_GAME* game);
	~RESULT();
	void sound();
	void create();
	void draw();
	void nextScene();
};

