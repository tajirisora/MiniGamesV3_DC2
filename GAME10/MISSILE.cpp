#include "MISSILE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
MISSILE::MISSILE(class GAME10_GAME* game) :WEAPONS(game) {
}
MISSILE::~MISSILE() {
}
void MISSILE::create() {
	Missile = game()->container()->missile();
}
void MISSILE::init() {
	Missile = game()->container()->missile();
}
void MISSILE::proc() {
}
void MISSILE::launch(VECTOR2 pos, int lane) {
	if (Missile.intervalTime <= NULL) {
		game()->bullets(GAME10_GAME::MISSILE_ID)->launch(pos, Missile.speed, lane);
		Missile.intervalTime = Missile.ctIntervalTime;
	}
	else {
		Missile.intervalTime--;
	}
}
void MISSILE::levelUp() {
	Missile.Level++;
	game()->player()->levelUp();
	game()->enemies()->levelUp();
	game()->objects()->levelUp();
}
void MISSILE::draw() {
	image(Missile.GunsImg, Missile.Pos.x, Missile.Pos.y);
	text(Missile.Level, Missile.LPos.x, Missile.LPos.y);
}