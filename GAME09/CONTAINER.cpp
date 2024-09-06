#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
namespace GAME09
{
	void CONTAINER::load() {
		setData();
		loadGraphic();
		loadSounds();
	}
	void CONTAINER::setData() {

		Data.fade.alpha = 0;
		Data.fade.color = COLOR(0, 0, 0);
		Data.fade.speed = 700;
	}
	void CONTAINER::loadGraphic() {

	}
	void CONTAINER::loadSounds() {

	}
}