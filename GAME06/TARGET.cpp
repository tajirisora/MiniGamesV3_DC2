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
		Target.img = Target.type1;
		Target.pos = { width - 300,height / 2 };
		Target.advSpeed = height / 4;
		Target.vec = 1;
	}

	void TARGET::update() {
		if (Target.pos.y > height - Target.limmitH && Target.vec > 0) {
			Target.vec *= -1;
		}
		else if (Target.pos.y < Target.limmitH && Target.vec < 0) {
			Target.vec *= -1;
		}
		Target.pos.y += Target.advSpeed * delta * Target.vec;
	}

	void TARGET::draw() {
		rectMode(CENTER);
		image(Target.img, Target.pos.x, Target.pos.y, Target.angle, Target.scale);
	}
}