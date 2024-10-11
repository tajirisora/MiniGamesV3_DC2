#include "WEAPONS.h"
#include "../../libOne/inc/libOne.h"
WEAPONS::WEAPONS(class GAME10_GAME* game):GAME_OBJECT10(game){}
WEAPONS::~WEAPONS(){}
void WEAPONS::create() {}
void WEAPONS::init() {}
void WEAPONS::launch(VECTOR2 pos,int lane) {}
void WEAPONS::proc(){
	update();
	draw();
}
void WEAPONS::update(){}
void WEAPONS::draw(){}