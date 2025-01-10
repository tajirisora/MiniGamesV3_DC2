#include "FADE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"

namespace GAME09 {
	FADE::FADE(GAME* game) :
		GAME_OBJECT(game) {

	}
	FADE::~FADE() {

	}

	void FADE::create() {
		Fade = game()->container()->data().fade;
		State = IN_END;
	}

	void FADE::proc() {
		if (State == IN_END || State == OUT_END) return;
		//フェードイン
		if (State == IN_START) {
			Fade.alpha -= Fade.speed * delta;
			if (Fade.alpha <= 0) {
				Fade.alpha = 0;
				State = IN_END;
			}
		}
		//フェードアウト
		if (State == OUT_START) {
			Fade.alpha += Fade.speed * delta;
			if (Fade.alpha >= 255) {
				Fade.alpha = 255;
				State = OUT_END;
			}
		}
		//描画
		noStroke();
		rectMode(CORNER);
		colorMode(RGB);
		fill(Fade.color.r, Fade.color.g, Fade.color.b, Fade.alpha);
		rect(0, 0, width, height);
	}

	void FADE::inStart()
	{
		if (State == OUT_END) {
			State = IN_START;
		}
	}

	bool FADE::inEndFlag()
	{
		return State == IN_END;
	}

	void FADE::outStart()
	{
		if (State == IN_END) {
			State = OUT_START;
		}
	}

	bool FADE::outEndFlag()
	{
		return State == OUT_END;
	}
}