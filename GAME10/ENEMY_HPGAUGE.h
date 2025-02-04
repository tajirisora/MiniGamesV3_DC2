#pragma once
#include "HP_GAUGE.h"
class ENEMY_HPGAUGE :public HP_GAUGE
{
public:
	struct DATA {
		int curHp = 0;//•\¦‚³‚ê‚éHP‚ÌŒÂ”
		int MaxNumHp = 0;//•\¦‚³‚ê‚éÅ‘å”
		int My;//“G‚Ì‰º‚Ì‚Ù‚¤‚É­‚µ‚¸‚ç‚·‚½‚ß‚Ì’l
		float increaseHp = 0;//HP‚Ì‘‚¦‚é•
		float hpWidth = 0;
		float hpHeight = 0;
	};
private:
	DATA EnemyGauge;
	float* NowHp;
	float* baseHp;
public:
	ENEMY_HPGAUGE(class GAME10_GAME* game);
	~ENEMY_HPGAUGE();
	void init();
	void appear(int hp, int Level);
	void create();
	void getDamage(float damage, int enemyKind,int weaponKind);
	void death(int i);
	void allDeath();
	void draw(VECTOR2 pos,int enemyKind);
	int GetHp(int i) { return NowHp[i]; }
};

