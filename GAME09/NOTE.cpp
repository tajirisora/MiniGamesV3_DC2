#include "NOTE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"

namespace GAME09 {
	NOTE::NOTE(class GAME* game) :
		GAME_OBJECT(game) {
		
	}

	NOTE::~NOTE() {

	}

	void NOTE::create() {
		Note = game()->container()->data().note;
	}

	void NOTE::init() {
		float laneWidth = 700;
		float oneLaneWidth = (laneWidth / LaneNum);
		PosX = (Lane - (LaneNum - 1) / 2.0f) * oneLaneWidth + width / 2;
		EdgeImgDist = oneLaneWidth / 2 - Note.edgeOfst;
		RectSize = VECTOR2(oneLaneWidth - Note.rectOfst * 2, Note.rectHeight);
	}

	void NOTE::update() {
		Pos = SetPos(VisualBeat);
	}

	VECTOR2 NOTE::SetPos(double beat) {
		//float y = Cont->judgePos(Lane).y - (beat - Cont->visualBeat()) * Speed;
		return VECTOR2(PosX, 0);
	}

	void NOTE::draw() {
		rectMode(CENTER);
		fill(0, 255, 255);
		//image(Img, Pos.x, Pos.y, 0, Note.imgSize);
		rect(Pos.x, Pos.y, RectSize.x, RectSize.y);
	}

	void NOTE::setData(NOTE_DATA data) {
		LaneNum = data.laneNum;
		Lane = data.lane;
		Speed = data.speed;
		Time = data.time;
		VisualBeat = data.visualBeat;
		TimeE = data.timeE;
		VisualBeatE = data.visualBeatE;
	}
}