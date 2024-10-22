#include "BACKBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"

namespace GAME09 {
	BACKBUTTON::BACKBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	BACKBUTTON::~BACKBUTTON() {

	}
	void BACKBUTTON::create() {
		Button = game()->container()->data().backButton;
	}
	void BACKBUTTON::init() {

	}
}