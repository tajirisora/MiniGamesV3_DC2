#include "OBJECT_HP.h"
#include"GAME_OBJECT10.h"
#include"PLAYER.h"
#include"CONTAINER.h"
#include"GAME10_GAME.h"
OBJECT_HP::OBJECT_HP(class GAME10_GAME* game) :HP_GAUGE(game) {}
OBJECT_HP::~OBJECT_HP() {
	delete[] NowHp;
	delete[] baseHp;
}
void OBJECT_HP::init() {
	ObjectGauge = game()->container()->objectHpGauge();
	if (NowHp != nullptr) {
		delete[] NowHp;
	}
	if (baseHp != nullptr) {
		delete[] baseHp;
	}
	NowHp = new float[ObjectGauge.MaxNumHp];
	baseHp = new float[ObjectGauge.MaxNumHp];
}
void OBJECT_HP::create() {
	ObjectGauge = game()->container()->objectHpGauge();
	NowHp = new float[ObjectGauge.MaxNumHp];
	baseHp = new float[ObjectGauge.MaxNumHp];
}
void OBJECT_HP::appear(int hp, int level) {
	NowHp[ObjectGauge.curHp] = (float)hp + ObjectGauge.increaseHp * (level - 1);
	baseHp[ObjectGauge.curHp] = NowHp[ObjectGauge.curHp];
	ObjectGauge.curHp++;
}
void OBJECT_HP::getDamage(float damage, int objectKind,int weaponKind) {
	if (game()->player()->PlayerWeaponKind(weaponKind) == GAME10_GAME::MISSILEBULLET_ID) {
		NowHp[objectKind] -= damage * 3;
	}
	else if(game()->player()->PlayerWeaponKind(weaponKind) == GAME10_GAME::HANDGUN_ID){
		NowHp[objectKind] -= damage / 2;
	}
	else {
		NowHp[objectKind] -= damage;
	}
}

void OBJECT_HP::death(int i) {
	ObjectGauge.curHp--;
	NowHp[i] = NowHp[ObjectGauge.curHp];
	baseHp[i] = baseHp[ObjectGauge.curHp];
}

void OBJECT_HP::draw(VECTOR2 pos, int objectKind) {
	fill(0);
	rect(pos.x, pos.y + ObjectGauge.My, ObjectGauge.hpWidth, ObjectGauge.hpHeight);
	fill(0, 255, 0);
	rect(pos.x, pos.y + ObjectGauge.My, ObjectGauge.hpWidth * (NowHp[objectKind] / baseHp[objectKind]), ObjectGauge.hpHeight);
}