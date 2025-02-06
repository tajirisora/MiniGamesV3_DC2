#include "FRUITS.h"
#include "GAME07.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME07
{
	FRUITS::FRUITS(GAME* game, VECTOR2 pos, FRUITS_KINDS kinds, bool inflate) :
		GAME_OBJECT(game) {
		Pos_current = pos;
		Pos_old = pos;
		Kinds = kinds;
		Inflate = inflate;
	}
	FRUITS::~FRUITS() {

	}

	void FRUITS::create() {
		Fruits = game()->container()->data().fruits;
	}

	void FRUITS::init() {
		Acc = VECTOR2(0, 0);
		Omega = 0;
		Theta = 0;
		float rate = Pow(Fruits.nextFruitsSizeRate, Kinds);
		MaxRadius = Fruits.cherryRadius * rate;
		if (!Inflate) Radius = MaxRadius;
		ImgSize = Fruits.cherryImgSize * rate;
		InflateTime = 0;
		Last = false;
	}

	void FRUITS::update(float dt) {
		if (Vibe) {
			VibeAnimeTime += dt;
		}
		else {
			if (Inflate && InflateTime < Fruits.inflateMaxTime) {
				InflateTime += dt;
				if (InflateTime < Fruits.inflateMaxTime) {
					float ratio = InflateTime / Fruits.inflateMaxTime;
					Radius = MaxRadius * (Fruits.initValue + (1 - Fruits.initValue) * ratio);
				}
				else {
					Radius = MaxRadius;
				}
			}

			VECTOR2 Vel = Pos_current - Pos_old;
			if (Touch) {
				Vel *= Fruits.attenuationRate;
				Omega = Vel.mag() / Radius;
				if (Vel.x == 0) Omega *= 0;
				if (Vel.x < 0) Omega *= -1;
			}
			Pos_old = Pos_current;
			Pos_current = Pos_current + Vel + Acc * dt * dt;
			Theta += Omega;
			Acc *= 0;
			Touch = false;
		}
	}
	void FRUITS::accelerate(VECTOR2 acc) {
		Acc += acc;
	}
	bool FRUITS::gameOverJudge() {
		if (!TouchedAny) return false;
		if (Pos_current.y - Radius < game()->box()->up()) {
			return true;
		}
		else {
			return false;
		}
	}
	void FRUITS::draw() {
		strokeWeight(4);
		stroke(0,180,0);
		if (TouchedAny) {
			fill(255, 0, 0, 200);
		}
		else {
			fill(0, 255, 0, 200);
		}
		angleMode(RADIANS);
		if (Vibe) {
			VECTOR2 ofst(Fruits.vibeMaxDist * Cos(Theta), Fruits.vibeMaxDist * Sin(Theta));
			VECTOR2 pos = Pos_current + ofst * Sin(VibeAnimeTime * Fruits.vibeSpeed);
			image(Fruits.imgs[Kinds], pos.x, pos.y, Theta, ImgSize);
		}
		else {
			image(Fruits.imgs[Kinds], Pos_current.x, Pos_current.y, Theta, ImgSize);
		}
		//circle(Pos_current.x, Pos_current.y, Radius * 2);
		//line(Pos_current.x, Pos_current.y, Pos_current.x + Radius * cos(Theta), Pos_current.y + Radius * sin(Theta));
	}

	void FRUITS::setTouch(bool touch) {
		Touch = touch;
		if (!TouchedAny) {
			TouchedAny = true;
		}
	}
	void FRUITS::setVibe(bool vibe) {
		Vibe = vibe;
		VibeAnimeTime = 0;
	}
}