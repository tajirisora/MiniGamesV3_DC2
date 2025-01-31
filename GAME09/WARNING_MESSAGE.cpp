#include "WARNING_MESSAGE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"

namespace GAME09 {
	WARNING_MESSAGE::WARNING_MESSAGE(GAME* game) :
		GAME_OBJECT(game) {
	}
	WARNING_MESSAGE::~WARNING_MESSAGE() {
	}

	void WARNING_MESSAGE::create() {
		Warning = game()->container()->data().warning;
	}

	void WARNING_MESSAGE::init() {
		Time = 0;
	}

	void WARNING_MESSAGE::update() {
		Time -= delta;
	}

	void WARNING_MESSAGE::draw() {
		if (Time > 0) {
			if (Time < Warning.fadeTime) {
				float ratio = Time / Warning.fadeTime;
				COLOR c = { 255,255,255,255 * ratio };
				imageColor(c);
			}
			image(Warning.warningImg, Warning.warningTf.pos.x, Warning.warningTf.pos.y, 0, Warning.warningTf.size);
			imageColor(255);
		}
	}

	void WARNING_MESSAGE::apper() {
		Time = Warning.displayTime + Warning.fadeTime;
	}
}