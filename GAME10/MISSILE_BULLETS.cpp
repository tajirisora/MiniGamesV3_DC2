#include "MISSILE_BULLETS.h"
#include"CONTAINER.h"
MISSILE_BULLETS::MISSILE_BULLETS(class GAME10_GAME* game) :BULLETS(game) {}
void MISSILE_BULLETS::create() {
	SetBullets(game()->container()->missileBullet());
}
void MISSILE_BULLETS::launch(const VECTOR2& pos, int speed, int lane) {
	if (Bullet.curNum < Bullet.totalNum) {
		if (Bullet.BulletNum < 2) {
			int i = Bullet.curNum;
			Bullets[i].pos.x = pos.x + Bullet.ImgHalf;
			Bullets[i].pos.y = pos.y + Bullet.ImgHalf;
			Bullets[i].Lane = lane;
			Bullet.speed = speed;
			Bullet.upSpeed = Bullet.speed;
			Bullet.curNum++;
		}
	}
}
void MISSILE_BULLETS::update() {
	for (int i = Bullet.curNum - 1; i >= 0; i--) {
		Bullets[i].pos.x += Bullet.upSpeed;
		if (Bullet.upSpeed <= Bullet.maxSpeed) {//ŽO”{‚Ì‘¬“x‚ªãŒÀ‚Æ‚·‚é
			Bullet.upSpeed += Bullet.upSpeed;
		}
		if (Bullets[i].pos.x > width) {
			Bullet.upSpeed = Bullet.speed;
			kill(i);
		}
	}
}