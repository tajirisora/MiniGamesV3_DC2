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
		clear(Title.backgroundColor);
		fill(Title.nameColor);
		textSize(Title.nameSize);
		text(Title.name, Title.namePos.x, Title.namePos.y);
		fill(Title.guidanceColor);
		textSize(Title.guidanceSize);
		text(Title.guidance, Title.guidancePos.x, Title.guidancePos.y);
	}

	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::STAGE_ID);
			game()->stage()->init();
		}
	}
}