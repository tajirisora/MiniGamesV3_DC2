#include "BACKGROUND.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	BACKGROUND::BACKGROUND(GAME* game) :
		GAME_OBJECT(game) {
	}
	BACKGROUND::~BACKGROUND() {
	}

	void BACKGROUND::create() {
		Back = game()->container()->data().back;
	}

	void BACKGROUND::init() {

	}

	void BACKGROUND::update() {

	}

	void BACKGROUND::draw(const SONGINFO& songInfo) {
		rectMode(CENTER);
		imageColor(200);
		float wBaseSize = Back.area.x / songInfo.backImageSize.x;
		float hBaseSize = Back.area.y / songInfo.backImageSize.y;
		float imageSize = wBaseSize > hBaseSize ? wBaseSize : hBaseSize;
		image(songInfo.backImageIdx, width / 2, height / 2, 0, imageSize);
		imageColor(255);
	}
}