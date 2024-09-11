#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class PLAYER :public GAME_OBJECT10
{
public:
	struct DATA {


	};
private:
	DATA Player;
public:
	PLAYER(class GAME10_GAME* game);
	~PLAYER();
	void init();
	void create();
	void update();
	void draw();
};

