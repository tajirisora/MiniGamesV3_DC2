#pragma once
#include "GAME10_GAME.h"
class TIME :public GAME_OBJECT10
{
public:
	struct DATA {
		int time = 0;
		int frame = 0;
		int rewindTimeE = 0;//敵を倒した時の回復時間(ストレス)
		int rewindTimeO = 0;//オブジェクトを倒した時の回復時間
		int rewindTimeG = 0;//goalしたときの時間加算
		COLOR dengerRed;
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
	void goalRewind();
	void rewind(int Enemytype);//敵を倒した時に時間回復
	void draw();
	int timeFlame() { return Time.frame; }
	int nowTime() { return Time.time; }
};

