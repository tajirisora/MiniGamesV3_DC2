#include "JACKET.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	JACKET::JACKET(GAME* game) :
		GAME_OBJECT(game) {
	}
	JACKET::~JACKET() {
	}

	void JACKET::create() {
		Jacket = game()->container()->data().jacket;
	}

	void JACKET::init() {

	}

	void JACKET::update() {

	}

	void JACKET::draw(const SONGINFO& songInfo, TRANSFORM tf) {
		rectMode(CENTER);
		image(Jacket.areaBackImg, tf.pos.x, tf.pos.y, 0, tf.size);
		float wBaseSize = Jacket.areaSize.x / songInfo.jacketImageSize.x;
		float hBaseSize = Jacket.areaSize.y / songInfo.jacketImageSize.y;
		float imageSize = wBaseSize < hBaseSize ? wBaseSize : hBaseSize;
		image(songInfo.jacketImageIdx, tf.pos.x, tf.pos.y, 0, imageSize * tf.size);
	}
}