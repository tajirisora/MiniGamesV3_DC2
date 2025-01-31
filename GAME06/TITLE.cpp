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
		fill(Title.textColor1);
		textSize(Title.textSize1);
		text(Title.str1, Title.textPos1.x, Title.textPos1.y);
		fill(Title.textColor2);
		textSize(Title.textSize2);
		text(Title.str2, Title.textPos2.x, Title.textPos2.y);
		COLOR grey = { 128,128,128 };
		COLOR brack = { 0,0,0 };
		float size = 40;
		rectMode(CORNER);
		fill(grey);
		rect(0, 0, size * 10, size * 4.5f);
		fill(brack);
		textSize(size);
		text("操作方法", 0, size);
		text("上に移動する：Wキー", 0, size * 2);
		text("下に移動する：Sキー", 0, size * 3);
		text("弾を発射する：Kキー", 0, size * 4);
	}

	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::STAGE_ID);
			game()->stage()->init();
		}
	}
}