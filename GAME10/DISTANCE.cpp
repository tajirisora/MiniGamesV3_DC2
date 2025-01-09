#include "DISTANCE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
DISTANCE::DISTANCE(class GAME10_GAME* game) :GAME_OBJECT10(game) {
}
DISTANCE::~DISTANCE(){}
void DISTANCE::init(){
	Dist = game()->container()->distance();
}
void DISTANCE::create(){
	Dist = game()->container()->distance();
}
void DISTANCE::setClearDist(int setClear) {
	Dist.clearDist = Dist.standardDist + Dist.standardDist * setClear;
}
void DISTANCE::distcnt(){
	Dist.sumDist += Dist.cntDist;
}
void DISTANCE::draw(){
	text((int)Dist.sumDist, Dist.distPos.x, Dist.distPos.y);
}