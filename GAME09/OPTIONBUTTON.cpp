#include "OPTIONBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"

namespace GAME09 {
	OPTIONBUTTON::OPTIONBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	OPTIONBUTTON::~OPTIONBUTTON() {

	}
	void OPTIONBUTTON::create() {
		Button = game()->container()->data().optionButton;
	}
	void OPTIONBUTTON::init() {

	}
}