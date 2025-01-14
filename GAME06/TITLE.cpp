#include"TITLE.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06 
{
	void TITLE::create() {
		Title = game()->container()->data().title;
	}

	void TITLE::draw() {
		clear(Title.bgColor);
		fill(Title.textColor);
		textSize(Title.textSize);
		text(Title.str, Title.pos.x, Title.pos.y);
		fill(Title.textColor2);
		textSize(Title.textSize2);
		text(Title.str2, Title.pos2.x, Title.pos2.y);
	}

	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::STAGE_ID);
			game()->stage()->init();
		}
	}
}