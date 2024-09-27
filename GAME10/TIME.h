#pragma once
#include "GAME10_GAME.h"
class TIME :public GAME_OBJECT10
{
public:
	struct DATA {
		int time = 0;
		int frame = 0;
		int rewindTime = 0;//アイテムをとった時の回復時間
		VECTOR2 Pos;
	};
private:
	DATA Time;
public:
	TIME(class GAME10_GAME* game);
	~TIME();
	void create();
	void init();
	void timeCount();
	void rewind();//アイテムを得たときに時間回復
	void draw();
};

