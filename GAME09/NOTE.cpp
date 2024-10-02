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
		float laneWidth = game()->lane()->laneWidth(); //あとでレーンクラスで定義したものに置き換える
		float oneLaneWidth = (laneWidth / LaneNum);
		PosX = (Lane - (LaneNum - 1) / 2.0f) * oneLaneWidth + game()->lane()->lanePos().x;
		EdgeImgDist = oneLaneWidth / 2 - Note.edgeOfst;
		RectSize = VECTOR2(oneLaneWidth - Note.rectOfst * 2, Note.rectHeight);
	}

	void NOTE::update() {
		Pos = SetPos(VisualBeat);
	}

	VECTOR2 NOTE::SetPos(double beat) {
		float y = game()->lane()->lanePos().y - (beat - game()->rgCont()->visualBeat()) * Speed;
		return VECTOR2(PosX, y);
	}

	void NOTE::draw() {
		rectMode(CENTER);
		noStroke();
		fill(Note.upColor);
		rect(Pos.x, Pos.y, RectSize.x, RectSize.y);
		fill(Note.downColor);
		rect(Pos.x, Pos.y + RectSize.y / 4, RectSize.x, RectSize.y / 2);
		fill(Note.highlightColor);
		float ratio = Note.highlightHeightRatio;
		rect(Pos.x, Pos.y - RectSize.y / 2 + RectSize.y * ratio / 2, RectSize.x, RectSize.y * ratio);

		image(Note.centerImg, Pos.x, Pos.y, 0, Note.imgSize);
		image(Note.rightImg, Pos.x + EdgeImgDist, Pos.y, 0, Note.imgSize);
		image(Note.leftImg, Pos.x - EdgeImgDist, Pos.y, 0, Note.imgSize);
	}

	void NOTE::setData(NOTE_DATA data) {
		LaneNum = data.laneNum;
		Lane = data.lane;
		Key = data.key;
		Speed = data.speed;
		Time = data.time;
		VisualBeat = data.visualBeat;
		TimeE = data.timeE;
		VisualBeatE = data.visualBeatE;
	}
}