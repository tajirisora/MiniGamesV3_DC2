#include "HANDGUN_BULLETS.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
HANDGUN_BULLETS::HANDGUN_BULLETS(class GAME10_GAME* game)
	:BULLETS(game){
}
void HANDGUN_BULLETS::create(){
	SetBullets(game()->container()->handgunBullet());
}