#pragma once
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"
#include <string>

namespace GAME09 {
	enum TEXTF_MODE {
		M_LEFT,
		M_CENTER,
		M_RIGHT
	};
	void textfMode(TEXTF_MODE mode);
	void textfStrokeSize(float size);

	void textf(std::string str, VECTOR2 pos, VECTOR2 size);
	void textfStroke(std::string str, VECTOR2 pos, VECTOR2 size);
}