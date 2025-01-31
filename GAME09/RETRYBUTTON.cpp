#include "RETRYBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"

namespace GAME09 {
	RETRYBUTTON::RETRYBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	RETRYBUTTON::~RETRYBUTTON() {

	}
	void RETRYBUTTON::create() {
		Button = game()->container()->data().retryButton;
	}
	void RETRYBUTTON::init() {

	}
}