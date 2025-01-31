#include "STARTBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"

namespace GAME09 {
	STARTBUTTON::STARTBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	STARTBUTTON::~STARTBUTTON() {

	}
	void STARTBUTTON::create() {
		Button = game()->container()->data().startButton;
	}
	void STARTBUTTON::init() {

	}
}