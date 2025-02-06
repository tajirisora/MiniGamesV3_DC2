#include "BUTTON_CONTINUE.h"
#include "GAME07.h"
#include "CONTAINER.h"

namespace GAME07
{
	BUTTON_CONTINUE::BUTTON_CONTINUE(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_CONTINUE::~BUTTON_CONTINUE()
	{
	}

	void BUTTON_CONTINUE::create()
	{
		Button = game()->container()->data().continueButton;
	}
}