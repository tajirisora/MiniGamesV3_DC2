#include "ACHIEVEMENT.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	ACHIEVEMENT::ACHIEVEMENT(GAME* game) :
		GAME_OBJECT(game) {
	}
	ACHIEVEMENT::~ACHIEVEMENT() {
	}

	void ACHIEVEMENT::create() {
		Achievement = game()->container()->data().achievement;
	}

	void ACHIEVEMENT::init() {

	}

	void ACHIEVEMENT::update() {

	}

	void ACHIEVEMENT::draw(ACHIEVEMENTS achievement) {
		draw(achievement, Achievement.pos, 1);
	}

	void ACHIEVEMENT::draw(ACHIEVEMENTS achievement, VECTOR2& pos, float size) {
		if (achievement < 0 || achievement >= NUM_ACHIEVEMENTS) return;
		rectMode(CENTER);
		image(Achievement.imgs[achievement], pos.x, pos.y, 0, Achievement.size * size);
	}
}