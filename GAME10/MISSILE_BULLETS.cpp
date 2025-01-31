#include "MISSILE_BULLETS.h"
#include"CONTAINER.h"
MISSILE_BULLETS::MISSILE_BULLETS(class GAME10_GAME* game) :BULLETS(game) {}
void MISSILE_BULLETS::create() {
	SetBullets(game()->container()->missileBullet());
}
void MISSILE_BULLETS::launch(const VECTOR2& pos, float speed, int lane) {
	if (Bullet.curNum < Bullet.totalNum) {
		if (game()->objects()->objectNum() != NULL
			|| game()->enemies()->EnemiesNum() != NULL) {
			int i = Bullet.curNum;
			Bullets[i].pos.x = pos.x + Bullet.ImgHalf + Bullet.BulletSmx;

			int nearDist = width;
			int nearLane = NULL;
			int nearHeight = NULL;
			for (int objectNum = 0; objectNum < game()->objects()->objectNum(); objectNum++) {
				if (NULL>game()->player()->playerPos().x - game()->objects()->objectPos(objectNum).x
					&& nearDist >= game()->objects()->objectPos(objectNum).x) {
					nearDist = game()->objects()->objectPos(objectNum).x;
					nearHeight = game()->objects()->objectPos(objectNum).y;
					nearLane = game()->objects()->ObjectsLane(objectNum);
				}
			}
			if (nearHeight != NULL) {//敵がいた場合
				Bullets[i].Lane = lane;
				Bullets[i].pos.y = pos.y + Bullet.ImgHalf;
				Bullets[i].nearLane = nearLane;
				Bullets[i].my = -((game()->player()->playerPos().y + Bullet.ImgHalf) - nearHeight);//動かないといけない向きを決める
				Bullets[i].nearEy = nearHeight -Bullet.EPGap;//敵とプレイヤーの高さの差を引く
			}
			else {//敵がいなかった場合
				Bullets[i].Lane = lane;
				Bullets[i].pos.y = pos.y + Bullet.ImgHalf;
				Bullets[i].nearLane = lane;
				Bullets[i].my = NULL;//動かないといけない向きを決める
				Bullets[i].nearEy = pos.y;
			}
			Bullet.speed = speed;
			Bullet.upSpeed = Bullet.speed;
			Bullet.curNum++;
		}

		else {//敵もオブジェクトもなかった場合
			int i = Bullet.curNum;
			Bullets[i].pos.x = pos.x + Bullet.ImgHalf + Bullet.BulletSmx;
			Bullets[i].Lane = lane;
			Bullets[i].pos.y = pos.y + Bullet.ImgHalf;
			Bullets[i].nearLane = lane;
			Bullets[i].my = NULL;//動かないといけない向きを決める
			Bullets[i].nearEy = pos.y;
			Bullet.speed = speed;
			Bullet.upSpeed = Bullet.speed;
			Bullet.curNum++;
		}
	}
}
void MISSILE_BULLETS::update() {
	for (int i = Bullet.curNum - 1; i >= 0; i--) {
		if (Bullets[i].pos.y != Bullets[i].nearEy + Bullet.ImgHalf) {
			if (Bullets[i].my < NULL){
				Bullets[i].pos.y -= Bullet.upSpeed;
				Bullets[i].pos.x -= Bullet.upSpeed;
				if (Bullets[i].nearEy + Bullet.ImgHalf > Bullets[i].pos.y) {//ミサイルが向かう場所が上の場合
					Bullets[i].pos.y = Bullets[i].nearEy + Bullet.ImgHalf;
					Bullets[i].Lane = Bullets[i].nearLane;
				}
			}
			else if (Bullets[i].my > NULL){
				Bullets[i].pos.y += Bullet.upSpeed;
				Bullets[i].pos.x -= Bullet.upSpeed;
				if (Bullets[i].nearEy + Bullet.ImgHalf< Bullets[i].pos.y) {//ミサイルが向かう場所が下の場合
					Bullets[i].pos.y = Bullets[i].nearEy + Bullet.ImgHalf;
					Bullets[i].Lane = Bullets[i].nearLane;
				}
			}
		}
		else{
			Bullets[i].pos.x += Bullet.upSpeed;
		}

		if (Bullet.upSpeed <= Bullet.maxSpeed
			&& Bullet.upFlame <= Bullet.nowFlame) {//スピードアップ
			Bullet.upSpeed += Bullet.upSpeed;
			Bullet.nowFlame = 0;
		}
		Bullet.nowFlame++;
		if (Bullets[i].pos.x > width) {//弾消失
			Bullet.upSpeed = Bullet.speed;
			kill(i);
		}
	}
}