#include "OPTION_RELATED_BUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "textFunc.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	OPTION_RELATED_BUTTON::OPTION_RELATED_BUTTON(class GAME* game) :
		BUTTON(game) {

	}
	OPTION_RELATED_BUTTON::~OPTION_RELATED_BUTTON() {

	}
	void OPTION_RELATED_BUTTON::create() {
		Button = game()->container()->data().optionButton;
	}
	void OPTION_RELATED_BUTTON::init() {

	}
	void OPTION_RELATED_BUTTON::draw() {
		BUTTON::draw();
		if (Button.colliType == RECT) {
			rectMode(CENTER);
			noStroke();
			fill(MainColor);
			rect(Button.pos.x + Button.ofst.x, Button.pos.y + Button.ofst.y, Button.size.x, Button.size.y);
			textfMode(M_CENTER);
			textf(Str, Button.pos + Button.ofst, Button.size);
		}
	}
}