#include "ENEMY_HPGAUGE.h"
#include"GAME_OBJECT10.h"
#include"CONTAINER.h"
#include"GAME10_GAME.h"
ENEMY_HPGAUGE::ENEMY_HPGAUGE(class GAME10_GAME* game) :HP_GAUGE(game) {}
ENEMY_HPGAUGE::~ENEMY_HPGAUGE() {
	delete[] NowHp;
	delete[] baseHp;
}
void ENEMY_HPGAUGE::init() {
	EnemyGauge = game()->container()->EnemyHpGauge();
	if (NowHp != nullptr) {
		delete[] NowHp;
	}
	if (baseHp != nullptr) {
		delete[] baseHp;
	}
	NowHp = new float[EnemyGauge.MaxNumHp];
	baseHp = new float[EnemyGauge.MaxNumHp];
}
void ENEMY_HPGAUGE::create() {
	EnemyGauge = game()->container()->EnemyHpGauge();
	NowHp = new float[EnemyGauge.MaxNumHp];
	baseHp = new float[EnemyGauge.MaxNumHp];
}
void ENEMY_HPGAUGE::appear(int hp, int level) {
	NowHp[EnemyGauge.curHp] = (float)hp + EnemyGauge.increaseHp * (level - 1);
	baseHp[EnemyGauge.curHp] = NowHp[EnemyGauge.curHp];
	EnemyGauge.curHp++;
}
void ENEMY_HPGAUGE::getDamage(float damage,int enemyKind,int weaponKind) {
	NowHp[enemyKind] -= damage;
}

void ENEMY_HPGAUGE::death(int i) {
	EnemyGauge.curHp--;
	NowHp[i] = NowHp[EnemyGauge.curHp];
	baseHp[i] = baseHp[EnemyGauge.curHp];
}

void ENEMY_HPGAUGE::draw(VECTOR2 pos,int enemyKind) {
	fill(0);
	rect(pos.x, pos.y + EnemyGauge.My, EnemyGauge.hpWidth, EnemyGauge.hpHeight);
	fill(0, 255, 0);
	rect(pos.x, pos.y + EnemyGauge.My, EnemyGauge.hpWidth * (NowHp[enemyKind] / baseHp[enemyKind]), EnemyGauge.hpHeight);
}

