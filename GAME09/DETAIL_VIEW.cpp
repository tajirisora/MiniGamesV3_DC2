#include "DETAIL_VIEW.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "textFunc.h"

namespace GAME09 {
	DETAIL_VIEW::DETAIL_VIEW(GAME* game) :
		GAME_OBJECT(game) {
	}
	DETAIL_VIEW::~DETAIL_VIEW() {
	}

	void DETAIL_VIEW::create() {
		Detail = game()->container()->data().detail;
	}

	void DETAIL_VIEW::init() {

	}

	void DETAIL_VIEW::update() {

	}

	void DETAIL_VIEW::draw(float ratio) {
		SONGINFO& s = game()->songs()[game()->banner()->curNum()];
		rectMode(CORNER);
		COLOR c = Detail.backColor;
		c.a *= ratio;
		fill(c);
		noStroke();
		rect(0, 0, width, height);
		imageColor(255, 255, 255, 255 * ratio);
		game()->jacket()->draw(s, { Detail.jacketPos, 0.8f });
		imageColor(255);
		rectMode(CORNER);
		fill(255, 255, 255, 255 * ratio);
		textfMode(M_CENTER);
		//title
		textf(s.title, Detail.titlePos, Detail.titleSize);
		//artist
		textf(s.artist, Detail.artistPos, Detail.otherSize);
		//chart
		textf(s.credit, Detail.chartPos, Detail.otherSize);

		VECTOR2 pos;
		textSize(Detail.otherStrSize);
		pos = Detail.artistPos + Detail.otherStrOfst;
		pos.x -= Detail.otherStrSize * 1.5f;
		text("artist", pos.x, pos.y);
		pos = Detail.chartPos + Detail.otherStrOfst;
		pos.x -= Detail.otherStrSize * 2.5f;
		text("ïàñ êªçÏé“", pos.x, pos.y);
	}
}