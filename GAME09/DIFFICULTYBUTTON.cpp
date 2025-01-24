#include "DIFFICULTYBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	DIFFICULTYBUTTON::DIFFICULTYBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	DIFFICULTYBUTTON::~DIFFICULTYBUTTON() {

	}
	void DIFFICULTYBUTTON::create() {

	}
	void DIFFICULTYBUTTON::init() {
		Color = game()->difficultySelect()->getColor(Difficulty);
	}
	void DIFFICULTYBUTTON::update() {
		BUTTON::update();
		if (isClick()) {
			game()->difficultySelect()->setDifficulty(Difficulty);
		}
	}
	void DIFFICULTYBUTTON::draw() {
		float ratio;
		if (game()->difficultySelect()->curDifficulty() == Difficulty) {
			ratio = 1;
		}
		else {
			ratio = 0.6f;
		}
		imageColor(Color * ratio);
		BUTTON::draw();
		imageColor(255);
	}
}