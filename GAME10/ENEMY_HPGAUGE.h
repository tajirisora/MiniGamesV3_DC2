#pragma once
#include "HP_GAUGE.h"
class ENEMY_HPGAUGE :public HP_GAUGE
{
private:
	DATA Hp;
public:
	ENEMY_HPGAUGE(class GAME10_GAME* game);
	~ENEMY_HPGAUGE();
	void draw();
};

