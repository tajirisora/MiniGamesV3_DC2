#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class WEAPONS :public GAME_OBJECT10
{
public:
	WEAPONS(class GAME10_GAME* game);
	virtual ~WEAPONS();
	virtual void create();
	virtual void init();
	virtual void launch(VECTOR2 pos,int lane);
	virtual void proc();
	virtual void update();
	virtual void draw();
};

