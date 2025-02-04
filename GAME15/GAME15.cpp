#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME15.h"
namespace GAME15
{
	int GAME::create()
	{
		return 0;
	}

	void GAME::destroy()
	{
	}

	void GAME::draw()
	{
		print(delta);
	}

	void GAME::proc()
	{
		clear(0, 0, 64);

		draw();

		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
