#include "AUTOBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"

namespace GAME09 {
	AUTOBUTTON::AUTOBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	AUTOBUTTON::~AUTOBUTTON() {

	}
	void AUTOBUTTON::create() {
		Button = game()->container()->data().autoButton;
		AutoButton = game()->container()->data().autoButtonImg;
		Button.img = AutoButton.imgs[0];
	}
	void AUTOBUTTON::init() {

	}
	void AUTOBUTTON::update() {
		Button.img = AutoButton.imgs[game()->judgeMNG()->autoRef()];
		BUTTON::update();
	}
}