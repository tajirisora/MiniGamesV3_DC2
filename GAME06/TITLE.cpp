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
		clear(Title.backScreenColor);
		fill(Title.color1);
		textSize(Title.size1);
		text(Title.str1, Title.pos1.x, Title.pos1.y);
		fill(Title.color2);
		textSize(Title.size2);
		text(Title.str2, Title.pos2.x, Title.pos2.y);
	}

	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::STAGE_ID);
			game()->stage()->init();
		}
	}
}