#include "DIFFICULTYSELECT.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "DIFFICULTYBUTTON.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	DIFFICULTYSELECT::DIFFICULTYSELECT(GAME* game) :
		GAME_OBJECT(game) {
	}
	DIFFICULTYSELECT::~DIFFICULTYSELECT() {
	}

	void DIFFICULTYSELECT::create() {
		DifficultySelect = game()->container()->data().difficultySelect;

		//ボタンの動的確保
		for (int i = 0; i < CHARTMANAGER::NUM_DIFFICULTY; i++) {
			Buttons[i] = new DIFFICULTYBUTTON(game());
			BUTTON::DATA Data = game()->container()->data().difficultyButton;
			Data.pos = DifficultySelect.buttonTf.pos + DifficultySelect.buttonTf.ofst * i;
			Data.debugFlag = false;

			Buttons[i]->setData(Data);
			Buttons[i]->setDifficulty((CHARTMANAGER::DIFFICULTY)i);
			Buttons[i]->init();
		}
	}

	void DIFFICULTYSELECT::init() {

	}

	void DIFFICULTYSELECT::update() {
		for (auto e : Buttons) {
			e->update();
		}
	}

	void DIFFICULTYSELECT::draw() {
		for (auto e : Buttons) {
			e->draw();
		}
	}

	COLOR DIFFICULTYSELECT::getColor(CHARTMANAGER::DIFFICULTY d) {
		return DifficultySelect.Color[d];
	}
}