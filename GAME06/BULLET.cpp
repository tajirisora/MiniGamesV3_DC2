#include "BULLET.h"
#include "GAME06.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"
#include "../../libOne/inc/window.h"
namespace GAME06
{
	void BULLET::create() {
		Bullet = game()->container()->data().bullet;
	}

	void BULLET::init() {
		Bullet.pos = game()->player()->pos();
	}

	void BULLET::update() {
		Bullet.pos.x += Bullet.speed * delta;
		if (game()->collision(game()->bullet(),game()->target())) {
			game()->collisionCounter()++;
			game()->target()->collisionFlag() = true;
			game()->player()->triggerFlag() = false;
		}
		else if (game()->bullet()->pos().x > Bullet.limmitW) {
			game()->player()->triggerFlag() = false;
		}
	}

	void BULLET::draw() {
		rectMode(CENTER);
		angleMode(DEGREES);
		image(Bullet.img, Bullet.pos.x, Bullet.pos.y, Bullet.angle, Bullet.scale);
	}
}