#include "ADJUSTBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	ADJUSTBUTTON::ADJUSTBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	ADJUSTBUTTON::~ADJUSTBUTTON() {

	}
	void ADJUSTBUTTON::create() {
		Button = game()->container()->data().adjustButton;
		AdjustButton = game()->container()->data().adjustButtonImg;
	}
	void ADJUSTBUTTON::init() {

	}
	void ADJUSTBUTTON::update() {
		if (TriggerStart) {
			if (collision() && isPress(MOUSE_LBUTTON)) {
				IsClick = false;
				PressTime += delta;
				if (RepeatStart) {
					if (PressTime > AdjustButton.repeatInterval) {
						IsClick = true;
						PressTime -= AdjustButton.repeatInterval;
					}
				}
				else {
					if (PressTime > AdjustButton.repeatStartTime) {
						RepeatStart = true;
						IsClick = true;
						PressTime -= AdjustButton.repeatStartTime;
					}
				}
			}
			else {
				TriggerStart = false;
				PressTime = 0;
				RepeatStart = false;
				IsClick = false;
			}
		}
		if (collision() && isTrigger(MOUSE_LBUTTON)) {
			IsClick = true;
			TriggerStart = true;
		}
	}
	void ADJUSTBUTTON::setImg(IMG_KIND img) {
		Button.img = AdjustButton.imgs[img];
	}
	void ADJUSTBUTTON::setPos(VECTOR2 pos) {
		Button.pos = pos;
	}
}