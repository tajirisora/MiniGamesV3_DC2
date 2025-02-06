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
		rectMode(CORNER);	
		fill(128,128,128);
		rect(0, 0, Size * 10, Size * 4.5f);
		fill(0);
		textSize(Size);
		text("操作方法", 0, Size);
		text("上に移動する：Wキー", 0, Size * 2);
		text("下に移動する：Sキー", 0, Size * 3);
		text("弾を発射する：Kキー", 0, Size * 4);
		fill(0);
		textSize(30);
		text("ENTERキーでメニューに戻る", 0, height);
	}

	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::STAGE_ID);
			game()->stage()->init();
		}
	}
}