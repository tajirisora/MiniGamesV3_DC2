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
			OVER_ID,
		};
		int clearBgm;
		int overBgm;
		int resultImg[2];
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

