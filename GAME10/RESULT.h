#pragma once
#include "SCENE.h"
#include "../../libOne/inc/libOne.h"
class RESULT :
    public SCENE
{
public:
	struct DATA {
		int resultImg = 0;
		VECTOR2 imgPos;
	};
private:
	DATA Result;
public:
	RESULT(class GAME10_GAME* game);
	~RESULT();
	void create();
	void draw();
	void nextScene();
};

