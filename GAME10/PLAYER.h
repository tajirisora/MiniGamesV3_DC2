#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class PLAYER :public GAME_OBJECT10
{
public:
	struct DATA {
		VECTOR2 Opos =0;
		VECTOR2 Pos = 0;
		float Pmy = 0;
		int playerImg = 0;
		float maxSpeed = 0;
		float minSpeed = 0;
		float gearSpeed = 0;//ïœë¨
		float speed = 0;
		float hp = 0;
		int nowLane = 0;
		int LaneMax = 0;
		VECTOR2 Tpos = 0;
		int timeImage = 0;
		int timeLimit = 0;
		//ïêäÌ
		int weaponHaveNum = 0;
		int weaponNum = 0;
		int* weaponKind = nullptr;
	};
private:
	DATA Player;
public:
	PLAYER(class GAME10_GAME* game);
	~PLAYER();
	void init();
	void stageGoal();
	void create();
	void update();
	void draw();
	void playerMove();
	DATA const playerData(){ return Player; }
};

