#include "PLAYER_HP.h"
#include"GAME_OBJECT10.h"
#include"CONTAINER.h"
#include"GAME10_GAME.h"
PLAYER_HP::PLAYER_HP(class GAME10_GAME* game):HP_GAUGE(game) {}
PLAYER_HP::~PLAYER_HP() {}
void PLAYER_HP::create() {
	PlayerGauge = game()->container()->PlayerHpGauge();
}

void PLAYER_HP::setHp(int Hp) {
	PlayerGauge.CurHp = Hp;
}

void PLAYER_HP::getDamage(int damage) {
	PlayerGauge.CurHp -= damage;
}

void PLAYER_HP::draw() {
	for (int i = 0; i < PlayerGauge.CurHp; i++) {
		fill(255);
		rect(PlayerGauge.gaugePos.x+ PlayerGauge.gaugeMx * i, PlayerGauge.gaugePos.y, PlayerGauge.hpWidth, PlayerGauge.hpHeight);
		image(PlayerGauge.gaugeImg, PlayerGauge.imgPos.x, PlayerGauge.imgPos.y);
	}
}