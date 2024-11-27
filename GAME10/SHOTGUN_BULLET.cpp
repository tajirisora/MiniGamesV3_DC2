#include "SHOTGUN_BULLET.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
SHOTGUN_BULLET::SHOTGUN_BULLET(class GAME10_GAME* game)
	:BULLETS(game) {
}
void SHOTGUN_BULLET::create() {
	SetBullets(game()->container()->shotgunBullet());
}