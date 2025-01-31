#include "SCORE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "JUDGEMANAGER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "textFunc.h"

namespace GAME09 {
	SCORE::SCORE(GAME* game) :
		GAME_OBJECT(game) {
	}
	SCORE::~SCORE() {
	}

	void SCORE::create() {
		Score = game()->container()->data().score;
	}

	void SCORE::init() {
		GoalScore = 0;
		CurScore = 0;
		BeforeScore = 0;
	}

	void SCORE::update() {
		int* judgeNum = game()->judgeMNG()->judgeResult();
		int allNotes = game()->chartMNG()->allNotesNum();
		if (allNotes == 0)return;
		float hitNotes = 0;
		for (int i = 0; i < JUDGEMANAGER::NUM_JUDGE; i++) {
			if (i == JUDGEMANAGER::PERFECT) {
				hitNotes += judgeNum[i] * 1.0f;
			}
			else if (i == JUDGEMANAGER::GREAT) {
				hitNotes += judgeNum[i] * 0.5f;
			}
			else if (i == JUDGEMANAGER::MISS) {
				hitNotes += judgeNum[i] * 0.0f;
			}
		}
		int score = hitNotes / allNotes * 10000000;
		if (GoalScore != score) {
			BeforeScore = CurScore;
			GoalScore = score;
			AnimeTime = 0;
		}
		if (AnimeTime < Score.scoreAnimeTime) {
			AnimeTime += delta;
			if (AnimeTime > Score.scoreAnimeTime) {
				AnimeTime = Score.scoreAnimeTime;
			}
			float ratio = AnimeTime / Score.scoreAnimeTime;
			CurScore = BeforeScore + (GoalScore - BeforeScore) * ratio;
		}
	}

	void SCORE::draw() {
		draw(Score.backImgPos, 1);
	}

	void SCORE::draw(VECTOR2& pos, float size) {
		draw(pos, size, CurScore);
	}

	void SCORE::draw(VECTOR2& pos, float size, int score) {
		rectMode(CENTER);
		image(Score.backImg, pos.x, pos.y, 0, Score.backImgSize * size);
		textfMode(M_RIGHT);
		fill(0);
		VECTOR2 textPos = pos + Score.scoreNumPosOfst * size;
		VECTOR2 textSize = Score.scoreNumSize * size;
		textf(std::to_string(score), textPos, textSize);
	}
}