#pragma once
#include "GAME_OBJECT10.h"
class SCENE :public GAME_OBJECT10
{
public:
	SCENE(class GAME10_GAME* game);
	virtual ~SCENE();
	virtual void create();
	virtual void init();
	virtual void proc();
	virtual void update();
	virtual void draw();
	virtual void nextScene();
	virtual void sound();
	virtual int speed();
};

