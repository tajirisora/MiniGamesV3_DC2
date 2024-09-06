#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "TITLE.h"

namespace GAME09 {
	TITLE::TITLE(class GAME* game) :
		SCENE(game) {

	}
	TITLE::~TITLE() {

	}
	void TITLE::create() {
		Title = game()->container()->data().title;
	}
	void TITLE::init() {

	}
	void TITLE::update() {

	}
	void TITLE::draw() {
		clear(255);
		fill(0);
		print("title");
	}
	void TITLE::nextScene() {
		if (isTrigger(KEY_ENTER)) {
			game()->fade()->outStart();
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::SELECT_ID);
		}
	}
}