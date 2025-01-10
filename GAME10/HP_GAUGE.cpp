#include "HP_GAUGE.h"
#include"GAME_OBJECT10.h"
#include"CONTAINER.h"
#include"GAME10_GAME.h"
HP_GAUGE::HP_GAUGE(class GAME10_GAME* game)
	:GAME_OBJECT10(game){}
HP_GAUGE::~HP_GAUGE() {}
void HP_GAUGE::create() {
}
void HP_GAUGE::appear(int hp, int Level) {
}
void HP_GAUGE::setHp(int Hp) { 
}

void HP_GAUGE::getDamage(int damage) {
}

void HP_GAUGE::getDamage(float damage,int EnemyKind,int weaponKind) {
}

void HP_GAUGE::death(int i) {}

void HP_GAUGE::draw() {
}
void HP_GAUGE::draw(VECTOR2 pos,int EnemyKind) {
	
}
