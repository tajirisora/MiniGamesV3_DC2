#include "textFunc.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	TEXTF_MODE TextMode = M_CENTER;

	void textfMode(TEXTF_MODE mode) {
		TextMode = mode;
	}

	void textf(std::string str, VECTOR2 pos, VECTOR2 size) {
		textMode(BOTTOM);
		VECTOR2 strPos = pos;
		float strSize = size.x / str.size() * 2.0f;
		if (strSize > size.y) {
			strSize = size.y;
		}
		textSize(strSize);
		switch (TextMode)
		{
		case M_LEFT:
			strPos.y -= (size.y - strSize) / 2.0f;
			break;
		case M_CENTER:
			strPos.x -= strSize * str.size() / 4.0f;
			strPos.y -= (size.y - strSize) / 2.0f;
			break;
		case M_RIGHT:
			strPos.x -= strSize * str.size() / 2.0f;
			strPos.y -= (size.y - strSize) / 2.0f;
			break;
		default:
			break;
		}
		text(str.c_str(), strPos.x, strPos.y);
	}
}