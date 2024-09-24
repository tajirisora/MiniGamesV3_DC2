#include "LONGBELT.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "RHYTHM_GAME_CONTROLLER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09 {
	LONGBELT::LONGBELT(class GAME* game) :
		NOTE(game) {
	}
	LONGBELT::~LONGBELT() {
	}

	void LONGBELT::create() {
		NOTE::create();
		LongBelt = game()->container()->data().longBelt;
	}

	void LONGBELT::init() {
		NOTE::init();
	}

	void LONGBELT::update() {
		Pos = SetPos(VisualBeat);
		PosE = SetPos(VisualBeatE);
		if (Time - game()->rgCont()->curTime() < 0) {
			if (TimeE - game()->rgCont()->curTime() < 0) {
				Pos = SetPos(VisualBeatE);
			}
			else {
				Pos.y = game()->lane()->lanePos().y;
			}
		}
	}

	void LONGBELT::draw() {
		rectMode(CENTER);
		noStroke();
		fill(Color);
		rect(Pos.x, (Pos.y + PosE.y) / 2.0f, RectSize.x, Abs(PosE.y - Pos.y));
		//int divisionNum = ceil((Pos.y - PosE.y - LongBelt.beltHeight / 2.0f) / LongBelt.beltHeight);
		//float startY = PosE.y + (divisionNum - 0.5f) * LongBelt.beltHeight;
		//for (int i = 0; i < divisionNum; i++) {
		//	float y = startY - LongBelt.beltHeight * i;
		//	if (y < -LongBelt.beltHeight * i) break;
		//	image(Img, Pos.x, y, 0, Note.imgSize);
		//}
	}
}