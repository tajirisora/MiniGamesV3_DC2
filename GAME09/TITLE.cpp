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
		game()->backButton()->update();
	}
	void TITLE::draw() {
		clear(255);
		rectMode(CENTER);
		image(Title.titleLogo, Title.titleTf.pos.x, Title.titleTf.pos.y, 0, Title.titleTf.size);
		image(Title.pressEnterkey, Title.pressEnterkeyTf.pos.x, Title.pressEnterkeyTf.pos.y, 0, Title.pressEnterkeyTf.size);
		game()->backButton()->draw();
	}
	void TITLE::nextScene() {
		if (game()->backButton()->isClick()) {
			game()->exit();
		}
		if (isTrigger(KEY_ENTER)) {
			game()->fade()->outStart();
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::LOADSONGS_ID);
		}
	}
}