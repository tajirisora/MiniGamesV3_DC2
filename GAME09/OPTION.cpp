#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "OPTION.h"

namespace GAME09 {
	OPTION::OPTION(class GAME* game) :
		SCENE(game) {

	}
	OPTION::~OPTION() {

	}
	void OPTION::create() {
		Option = game()->container()->data().option;
	}
	void OPTION::init() {

	}
	void OPTION::update() {
		game()->backButton()->update();
	}
	void OPTION::draw() {
		clear(255);
		fill(0);
		stroke(0);
		textSize(Option.optionStrSize);
		text("Ý’è", Option.optionStrPos.x, Option.optionStrPos.y);
		strokeWeight(5);
		line(0, Option.optionUnderBar, width, Option.optionUnderBar);

		game()->backButton()->draw();
	}
	void OPTION::nextScene() {
		if (game()->backButton()->isClick()) {
			game()->fade()->outStart();
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::SELECT_ID);
		}
	}
}