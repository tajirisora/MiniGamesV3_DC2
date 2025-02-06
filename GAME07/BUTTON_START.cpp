#include "BUTTON_START.h"
#include "GAME07.h"
#include "CONTAINER.h"

namespace GAME07
{
	BUTTON_START::BUTTON_START(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_START::~BUTTON_START()
	{
	}

	void BUTTON_START::create()
	{
		Button = game()->container()->data().startButton;
	}
}