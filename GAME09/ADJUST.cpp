#include "ADJUST.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "textFunc.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	ADJUST::ADJUST(GAME* game) :
		GAME_OBJECT(game) {
	}
	ADJUST::~ADJUST() {
		delete LButton;
		delete RButton;
	}

	void ADJUST::create() {
		Adjust = game()->container()->data().adjust;
	}

	void ADJUST::init() {

	}

	void ADJUST::update() {
		LButton->update();
		RButton->update();

		if (LButton->isClick()) {
			if (Data.valueF != nullptr) {
				*Data.valueF -= Data.changeValue;
				if (*Data.valueF < Data.valueMin) {
					*Data.valueF = Data.valueMin;
				}
			}
			else if (Data.valueI != nullptr) {
				*Data.valueI -= Data.changeValue;
				if (*Data.valueI < Data.valueMin) {
					*Data.valueI = Data.valueMin;
				}
			}
			else if (Data.valueB != nullptr) {
				*Data.valueB ^= 1;
			}
		}
		if (RButton->isClick()) {
			if (Data.valueF != nullptr) {
				*Data.valueF += Data.changeValue;
				if (*Data.valueF > Data.valueMax) {
					*Data.valueF = Data.valueMax;
				}
			}
			else if (Data.valueI != nullptr) {
				*Data.valueI += Data.changeValue;
				if (*Data.valueI > Data.valueMax) {
					*Data.valueI = Data.valueMax;
				}
			}
			else if (Data.valueB != nullptr) {
				*Data.valueB ^= 1;
			}
		}
	}

	void ADJUST::draw() {
		fill(0);
		textfMode(M_CENTER);
		textf(Data.str, Data.pos + VECTOR2(0, Adjust.strSize.y / 2), Adjust.strSize);

		if (Data.valueF != nullptr) {
			char buffer[128];
			sprintf_s(buffer, "%.1f", *Data.valueF);
			textf(buffer, Data.pos + Adjust.valueOfst + VECTOR2(0, Adjust.strSize.y / 2), Adjust.valueSize);
		}
		else if (Data.valueI != nullptr) {
			textf(std::to_string(*Data.valueI), Data.pos + Adjust.valueOfst + VECTOR2(0, Adjust.strSize.y / 2), Adjust.valueSize);
		}
		else if (Data.valueB != nullptr) {
			textf(*Data.valueB ? "‚ ‚è" : "‚È‚µ", Data.pos + Adjust.valueOfst + VECTOR2(0, Adjust.strSize.y / 2), Adjust.valueSize);
		}

		LButton->draw();
		RButton->draw();
	}

	void ADJUST::setData(SETDATA& data) {
		Data = data;
		LButton = new ADJUSTBUTTON(game());
		LButton->create();
		if (Data.valueB == nullptr) {
			LButton->setImg(ADJUSTBUTTON::MINUS);
		}
		else {
			LButton->setImg(ADJUSTBUTTON::LEFT);
		}
		LButton->setPos(Data.pos + Adjust.leftButtonOfst);
		RButton = new ADJUSTBUTTON(game());
		RButton->create();
		if (Data.valueB == nullptr) {
			RButton->setImg(ADJUSTBUTTON::PLUS);
		}
		else {
			RButton->setImg(ADJUSTBUTTON::RIGHT);
		}
		RButton->setPos(Data.pos + Adjust.rightButtonOfst);
	}
}