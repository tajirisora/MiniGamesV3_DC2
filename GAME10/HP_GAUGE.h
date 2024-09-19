#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class HP_GAUGE :public GAME_OBJECT10
{
public:
	struct DATA {
		int gaugeImg = 0;
		VECTOR2 imgPos = 0;
		VECTOR2 gaugePos = 0;
		float gaugeMx = 0;
		float hpWidth = 0;
		float hpHeight = 0;
	};
private:
	DATA Gauge;
public:
	HP_GAUGE(class GAME10_GAME* game);
	~HP_GAUGE();
	void create();
	void draw(int playerHp);
};

