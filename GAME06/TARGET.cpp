#include "TARGET.h"
#include "GAME06.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
namespace GAME06 
{
	void TARGET::create() {
		Target = game()->container()->data().target;
	}

	void TARGET::init() {
		const DATA& target = game()->container()->data().target;
		Target.img = Target.type1;
		Target.pos = target.pos;
		Target.speed = target.speed;
		Target.vec = target.vec;
		Target.collisionFlag = target.collisionFlag;
		Target.collisionTimer = target.collisionTimer;
	}

	void TARGET::update() {
		if (Target.pos.y > height - Target.limmitH && Target.vec > 0) {
			Target.vec *= -1;
		}
		else if (Target.pos.y < Target.limmitH && Target.vec < 0) {
			Target.vec *= -1;
		}
		Target.pos.y += Target.speed * delta * Target.vec;
		if (Target.collisionFlag == true) {
			Target.collisionTimer -= delta;
			if (Target.collisionTimer <= 0.0f) {
				const DATA& target = game()->container()->data().target;
				Target.collisionTimer = target.collisionTimer;
				Target.collisionFlag = false;
			}
		}
	}

	void TARGET::draw() {
		rectMode(CENTER);
		if (Target.collisionFlag == false) { Target.img = Target.type1; }
		else { Target.img = Target.type2; }
		image(Target.img, Target.pos.x, Target.pos.y, Target.angle, Target.scale);
	}
}