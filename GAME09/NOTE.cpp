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
		float laneWidth = game()->lane()->laneWidth();
		float oneLaneWidth = (laneWidth / LaneNum);
		PosX = (Lane - (LaneNum - 1) / 2.0f) * oneLaneWidth + game()->lane()->lanePos().x;
		EdgeImgDist = oneLaneWidth / 2 - Note.edgeOfst;
		RectSize = VECTOR2(oneLaneWidth - Note.rectOfst * 2, Note.rectHeight);

		//Color = Note.color;
		float r = Color.r;
		float g = Color.g;
		float b = Color.b;
		r = 255 - (255 - r) * (1 - Note.highlightColorRatio);
		g = 255 - (255 - g) * (1 - Note.highlightColorRatio);
		b = 255 - (255 - b) * (1 - Note.highlightColorRatio);
		HighlightColor = COLOR(r, g, b);
		r = Color.r * Note.downColorRatio;
		g = Color.g * Note.downColorRatio;
		b = Color.b * Note.downColorRatio;
		DownColor = COLOR(r, g, b);
	}

	void NOTE::update() {
		Pos = SetPos(VisualBeat);
	}

	VECTOR2 NOTE::SetPos(double beat) {
		float y = game()->lane()->lanePos().y - (float)(beat - game()->rgCont()->visualBeat()) * Speed;
		return VECTOR2(PosX, y);
	}

	void NOTE::draw() {
		rectMode(CENTER);
		noStroke();
		fill(Color);
		rect(Pos.x, Pos.y, RectSize.x, RectSize.y);
		fill(DownColor);
		rect(Pos.x, Pos.y + RectSize.y / 4, RectSize.x, RectSize.y / 2);
		fill(HighlightColor);
		float ratio = Note.highlightHeightRatio;
		rect(Pos.x, Pos.y - RectSize.y / 2 + RectSize.y * ratio / 2, RectSize.x, RectSize.y * ratio);

		image(Note.centerUnderImg, Pos.x, Pos.y, 0, Note.imgSize);
		imageColor(Color);
		image(Note.rightUnderImg, Pos.x + EdgeImgDist, Pos.y, 0, Note.imgSize);
		image(Note.leftUnderImg, Pos.x - EdgeImgDist, Pos.y, 0, Note.imgSize);
		imageColor(HighlightColor);
		image(Note.centerUpperImg, Pos.x, Pos.y, 0, Note.imgSize);
		imageColor(255);
		image(Note.rightUpperImg, Pos.x + EdgeImgDist, Pos.y, 0, Note.imgSize);
		image(Note.leftUpperImg, Pos.x - EdgeImgDist, Pos.y, 0, Note.imgSize);
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
		Color = data.color;
	}
}