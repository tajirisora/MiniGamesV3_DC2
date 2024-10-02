#include "TAPNOTE.h"

namespace GAME09 {
	TAPNOTE::TAPNOTE(class GAME* game) :
		NOTE(game) {
	}
	TAPNOTE::~TAPNOTE() {
	}

	void TAPNOTE::init() {
		NOTE::init();
		Name = TAP;
	}

	void TAPNOTE::update() {
		NOTE::update();
	}

	void TAPNOTE::draw() {
		NOTE::draw();
	}
}