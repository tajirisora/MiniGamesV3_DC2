#include "DIFFICULTYSELECT.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "DIFFICULTYBUTTON.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"

namespace GAME09 {
	DIFFICULTYSELECT::DIFFICULTYSELECT(GAME* game) :
		GAME_OBJECT(game) {
	}
	DIFFICULTYSELECT::~DIFFICULTYSELECT() {
		//解放
		for (auto e : Buttons) {
			delete e;
		}
	}

	void DIFFICULTYSELECT::create() {
		DifficultySelect = game()->container()->data().difficultySelect;

		//ボタンの動的確保
		for (int i = 0; i < CHARTMANAGER::NUM_DIFFICULTY; i++) {
			Buttons[i] = new DIFFICULTYBUTTON(game());
			BUTTON::DATA Data = game()->container()->data().difficultyButton;
			Data.pos = DifficultySelect.buttonTf.pos + DifficultySelect.buttonTf.ofst * i;
			Data.debugFlag = false;

			Buttons[i]->create();
			Buttons[i]->setData(Data);
			Buttons[i]->setDifficulty((CHARTMANAGER::DIFFICULTY)i);
			Buttons[i]->init();
		}
	}

	void DIFFICULTYSELECT::init() {

	}

	void DIFFICULTYSELECT::update() {
		if (isTrigger(KEY_LEFT)) {
			if (CurDifficulty != CHARTMANAGER::EASY) {
				CurDifficulty = (CHARTMANAGER::DIFFICULTY)((int)CurDifficulty - 1);
			}
		}
		if (isTrigger(KEY_RIGHT)) {
			if (CurDifficulty != CHARTMANAGER::EXPART) {
				CurDifficulty = (CHARTMANAGER::DIFFICULTY)((int)CurDifficulty + 1);
			}
		}
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
		if (d == CHARTMANAGER::NUM_DIFFICULTY) {
			return DifficultySelect.Color[CurDifficulty];
		}
		else {
			return DifficultySelect.Color[d];
		}
	}
}