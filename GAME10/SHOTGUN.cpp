#include "SHOTGUN.h"
#include"CONTAINER.h"
SHOTGUN::SHOTGUN(class GAME10_GAME* game):WEAPONS(game){}
SHOTGUN::~SHOTGUN(){}
void SHOTGUN::create(){
	ShotGun = game()->container()->shotgun();
}
void SHOTGUN::init(){
	ShotGun = game()->container()->shotgun();
}
void SHOTGUN::proc(){}
void SHOTGUN::launch(VECTOR2 pos, int lane){
	if (ShotGun.intervalTime <= 0) {
		game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->launch(pos, ShotGun.speed, lane);
		ShotGun.intervalTime = ShotGun.ctIntervalTime;
	}
	else {
		ShotGun.intervalTime--;
	}

}
void SHOTGUN::levelUp() {
	ShotGun.Level++;
	game()->player()->levelUp();
	game()->enemies()->levelUp();
	game()->objects()->levelUp();
}
void SHOTGUN::draw(){
	image(ShotGun.GunsImg, ShotGun.Pos.x, ShotGun.Pos.y);
	text(ShotGun.Level, ShotGun.LPos.x, ShotGun.LPos.y);
}