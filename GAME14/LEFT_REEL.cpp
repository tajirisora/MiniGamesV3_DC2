#include "LEFT_REEL.h"
#include"GAME14.h"
#include"CONTAINER.h"
namespace GAME14 {
	void LEFT_REEL::create() {
		Reel = game()->container()->data().left;
	}
}