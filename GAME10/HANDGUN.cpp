#include "HANDGUN.h"
#include "GAME10_GAME.h"
#include"HANDGUN_BULLETS.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
HANDGUN::HANDGUN(class GAME10_GAME* game):WEAPONS(game) {
}
HANDGUN::~HANDGUN(){
}
void HANDGUN::create() {
	Handgun = game()->container()->handgun();
}
void HANDGUN::init(){
	Handgun = game()->container()->handgun();
}
void HANDGUN::proc(){
}
void HANDGUN::launch(VECTOR2 pos,int lane){
	if(Handgun.intervalTime <= NULL){
		game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->launch(pos, Handgun.speed, lane);
		Handgun.intervalTime = Handgun.ctIntervalTime;
	}
	else {
		Handgun.intervalTime--;
	}
}
void HANDGUN::draw(){
	image(Handgun.GunsImg, Handgun.Pos.x, Handgun.Pos.y);
}