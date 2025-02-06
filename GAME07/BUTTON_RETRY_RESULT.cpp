#include "BUTTON_RETRY_RESULT.h"
#include "GAME07.h"
#include "CONTAINER.h"

namespace GAME07
{
	BUTTON_RETRY_RESULT::BUTTON_RETRY_RESULT(GAME* game)
		: BUTTON(game) {
	}
	BUTTON_RETRY_RESULT::~BUTTON_RETRY_RESULT()
	{
	}

	void BUTTON_RETRY_RESULT::create()
	{
		Button = game()->container()->data().resultRetryButton;
	}
}