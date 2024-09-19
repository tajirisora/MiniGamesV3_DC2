#include "HP_GAUGE.h"
#include"GAME_OBJECT10.h"
#include"CONTAINER.h"
#include"GAME10_GAME.h"
HP_GAUGE::HP_GAUGE(class GAME10_GAME* game)
	:GAME_OBJECT10(game){}
HP_GAUGE::~HP_GAUGE() {}
void HP_GAUGE::create() {
	Gauge = game()->container()->gauge();
}
void HP_GAUGE::draw(int playerHp) {
	for (int i = 0; i < playerHp; i++) {
		fill(255);
		rect(Gauge.gaugePos.x + Gauge.gaugeMx * i, Gauge.gaugePos.y, Gauge.hpWidth, Gauge.hpHeight);
		image(Gauge.gaugeImg, Gauge.imgPos.x, Gauge.imgPos.y);
	}
}
