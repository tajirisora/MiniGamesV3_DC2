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
	}
	void AUTOBUTTON::init() {

	}
}