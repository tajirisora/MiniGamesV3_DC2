#pragma once
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/VECTOR2.h"

#define image drawCanvasImage
#define line drawCanvasLine

namespace GAME07 {
	void drawCanvasImage(int idx, float x, float y, float angle = 0, float size = 1);
	void drawCanvasLine(float sx, float sy, float ex, float ey);
	void setCornerPos(VECTOR2 pos);
	void addCornerPos(VECTOR2 ofst);
	void setMagnification(float value);
}