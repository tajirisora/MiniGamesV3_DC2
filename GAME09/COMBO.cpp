#include "COMBO.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	COMBO::COMBO(GAME* game) :
		GAME_OBJECT(game) {
	}
	COMBO::~COMBO() {
	}

	void COMBO::create() {
		Combo = game()->container()->data().combo;
	}

	void COMBO::init() {

	}

	void COMBO::update() {

	}

	void COMBO::draw(int combo, VECTOR2 pos, float ratio) {
		//ï∂éö
		VECTOR2 tPos = pos + Combo.strOfst * ratio;
		float size = Combo.strSize * ratio;
		image(Combo.strImg, tPos.x, tPos.y, 0, size);

		//êîéö
		std::string comboStr = std::to_string(combo);
		int comboDigit = comboStr.size();
		tPos = pos + Combo.numOfst * ratio;
		tPos.x -= Combo.digitSpace * (comboDigit - 1) / 2.0f * ratio;
		size = Combo.numSize * ratio;
		for (int i = 0; i < comboDigit; i++) {
			int num = (int)comboStr[i] - '0';
			image(Combo.numImgs[num], tPos.x + Combo.digitSpace * i * ratio, tPos.y, 0, size);
		}
	}
}