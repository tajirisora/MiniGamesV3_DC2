#pragma once
#include "HP_GAUGE.h"
class PLAYER_HP :public HP_GAUGE
{
public:
	struct DATA {
		int gaugeImg = 0;
		VECTOR2 imgPos = 0;
		VECTOR2 gaugePos = 0;
		int CurHp = 0;
		float gaugeMx = 0;
		float hpWidth = 0;
		float hpHeight = 0;
	};
private:
	DATA PlayerGauge;
public:
	PLAYER_HP(class GAME10_GAME* game);
	~PLAYER_HP();
	void setHp(int Hp);//セッター
	void create();
	void getDamage(int damage);
	void draw();
	int GetHp(int i) { return PlayerGauge.CurHp; };
};

