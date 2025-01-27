#include "DIFFICULTYBUTTON.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "textFunc.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	DIFFICULTYBUTTON::DIFFICULTYBUTTON(class GAME* game) :
		BUTTON(game) {

	}
	DIFFICULTYBUTTON::~DIFFICULTYBUTTON() {

	}
	void DIFFICULTYBUTTON::create() {
		DifficultyButton = game()->container()->data().difficultyButtonData;
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
		textfMode(M_CENTER);
		VECTOR2 pos(Button.pos + Button.ofst);
		pos.y += DifficultyButton.numStrSize.y / 2;
		font("‚l‚r –¾’©");
		textfStrokeSize(2);
		fill(0);
		textfStroke(std::to_string(game()->songs()[game()->banner()->curNum()].difficulty[Difficulty]),
			pos, DifficultyButton.numStrSize);
		fill(255);
		textf(std::to_string(game()->songs()[game()->banner()->curNum()].difficulty[Difficulty]),
			pos, DifficultyButton.numStrSize);
		font("Arial");
	}
}