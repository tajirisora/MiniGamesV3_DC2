#include "HANDGUN.h"
#include "GAME10_GAME.h"
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
void HANDGUN::update(){

}
void HANDGUN::draw(){
	image(Handgun.GunsImg, Handgun.Pos.x, Handgun.Pos.y);
}