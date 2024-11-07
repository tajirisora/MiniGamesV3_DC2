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
			fill(0);
			if (Key.main != KEY_NONE) {
				if (Key.sub == KEY_NONE) {
					VECTOR2 ofst(0, Button.size.y / 2);
					textfMode(M_CENTER);
					textf(ButtonName[Key.main], Button.pos + Button.ofst + ofst, Button.size);
				}
				else {
					stroke(0);
					strokeWeight(5);
					VECTOR2 ofst(Button.size.x / 2, -Button.size.y / 2);
					VECTOR2 sp(Button.pos + Button.ofst + ofst);
					VECTOR2 ep(Button.pos + Button.ofst - ofst);
					line(sp.x, sp.y, ep.x, ep.y);
					ofst = VECTOR2(-Button.size.x / 2, 0);
					textfMode(M_LEFT);
					textf(ButtonName[Key.main], Button.pos + Button.ofst + ofst, Button.size / 2);
					ofst = VECTOR2(0, Button.size.y / 2);
					textfMode(M_LEFT);
					textf(ButtonName[Key.sub], Button.pos + Button.ofst + ofst, Button.size / 2);
				}
			}
		}
	}
}