#pragma once
#include"GAME10_GAME.h"
class DISTANCE :public GAME_OBJECT10
{
public:
	struct DATA {
		float cntDist = 0;
		float sumDist = 0;
		float standardDist = 0;
		float clearDist = 0;
		VECTOR2 distPos = 0;
	};
private:
	DATA Dist;
public:
	DISTANCE(class GAME10_GAME* game);
	~DISTANCE();
	void init();
	void create();
	void setClearDist(int setClear);
	void distcnt();
	void draw();
	float sumDist() { return Dist.sumDist; }
};

