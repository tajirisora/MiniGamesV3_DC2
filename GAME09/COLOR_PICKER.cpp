#include "COLOR_PICKER.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09 {
	COLOR_PICKER::COLOR_PICKER(GAME* game) :
		GAME_OBJECT(game) {
	}
	COLOR_PICKER::~COLOR_PICKER() {
	}

	void COLOR_PICKER::create() {
		ColorPicker = game()->container()->data().colorPicker;
		Sw = ColorPicker.size * ColorPicker.swRate;
	}

	void COLOR_PICKER::init() {

	}

	void COLOR_PICKER::update() {
		VECTOR2 mPos(mouseX, mouseY);
		VECTOR2 MtoPos = mPos - Pos;
		if (isTrigger(MOUSE_LBUTTON)) {
			if (ColorPicker.size * ColorPicker.innerSize < MtoPos.mag() && MtoPos.mag() < ColorPicker.size) {
				IsMoveH = true;
			}
			if (Pos.x - ColorPicker.size * ColorPicker.rectSize < mPos.x &&
				Pos.x + ColorPicker.size * ColorPicker.rectSize > mPos.x &&
				Pos.y - ColorPicker.size * ColorPicker.rectSize < mPos.y &&
				Pos.y + ColorPicker.size * ColorPicker.rectSize > mPos.y
				) {
				IsMoveSV = true;
			}
			if (CornerPos.x < mPos.x ||
				CornerPos.x - ColorPicker.areaSize.x > mPos.x ||
				CornerPos.y + ColorPicker.areaSize.y < mPos.y ||
				CornerPos.y > mPos.y
				) {
				IsApper = false;
				return;
			}
		}
		if (IsMoveH) {
			if (isPress(MOUSE_LBUTTON)) {
				Hue = Atan2(MtoPos.y, MtoPos.x) + 90;
				if (Hue < 0) Hue += 360;
			}
			else {
				IsMoveH = false;
			}
		}
		if (IsMoveSV) {
			if (isPress(MOUSE_LBUTTON)) {
				Satu = Map(MtoPos.x, -ColorPicker.size * ColorPicker.rectSize, ColorPicker.size * ColorPicker.rectSize, 0, 255);
				Value = Map(MtoPos.y, -ColorPicker.size * ColorPicker.rectSize, ColorPicker.size * ColorPicker.rectSize, 255, 0);
				if (Satu < 0) Satu = 0;
				if (Satu > 255) Satu = 255;
				if (Value < 0) Value = 0;
				if (Value > 255) Value = 255;
			}
			else {
				IsMoveSV = false;
			}
		}
	}

	void COLOR_PICKER::draw() {
		//背景
		rectMode(CORNER);
		fill(100,100,100,150);
		stroke(0);
		strokeWeight(5);
		rect(CornerPos.x - ColorPicker.areaSize.x, CornerPos.y, ColorPicker.areaSize.x, ColorPicker.areaSize.y);
		
		rectMode(CENTER);
		angleMode(DEGREES);
		colorMode(HSV);
		noStroke();
		float PI = 3.14159265f;
		int detailLevel = 360;
		float theta = 0;
		float w = PI * ColorPicker.size * 2 / detailLevel;
		float h = ColorPicker.size * (1 - ColorPicker.innerSize);
		float r = ColorPicker.size * ((1 - ColorPicker.innerSize) / 2 + ColorPicker.innerSize);
		for (int i = 0; i < detailLevel; i++) {
			theta = 360.0f / detailLevel * i;
			fill(theta, 255, 255);
			rect(Sin(theta) * r + Pos.x, -Cos(theta) * r + Pos.y, w, h, theta);
		}
		detailLevel = 50;
		rectMode(CORNER);
		r = ColorPicker.size * ColorPicker.rectSize * 2 / detailLevel;
		for (int y = 0; y < detailLevel; y++) {
			for (int x = 0; x < detailLevel; x++) {
				fill(Hue, 255.0f / detailLevel * x, 255.0f / detailLevel * (detailLevel - y));
				rect(Pos.x - ColorPicker.size * ColorPicker.rectSize + r * x, Pos.y - ColorPicker.size * ColorPicker.rectSize + r * y, r, r);
			}
		}

		rectMode(CENTER);
		stroke(0);
		strokeWeight(Sw);
		fill(0, 0, 0, 0);
		circle(Pos.x, Pos.y, ColorPicker.size * 2);
		circle(Pos.x, Pos.y, ColorPicker.size * ColorPicker.innerSize * 2);
		rect(Pos.x, Pos.y, ColorPicker.size * ColorPicker.rectSize * 2, ColorPicker.size * ColorPicker.rectSize * 2);

		r = ColorPicker.size * ((1 - ColorPicker.innerSize) / 2 + ColorPicker.innerSize);
		stroke(255);
		circle(Sin(Hue) * r + Pos.x, -Cos(Hue) * r + Pos.y, ColorPicker.size * ColorPicker.hPointerSize);
		circle(Pos.x + ColorPicker.size * ColorPicker.rectSize * Map(Satu, 0, 255, -1, 1),
			Pos.y + ColorPicker.size * ColorPicker.rectSize * Map(Value, 0, 255, 1, -1),
			ColorPicker.size * ColorPicker.svPointerSize);

		colorMode(RGB);
	}

	void COLOR_PICKER::apper(VECTOR2 pos, COLOR color) {
		CornerPos = pos;
		if (CornerPos.y + ColorPicker.areaSize.y + 50 >= height) {
			CornerPos.y -= ColorPicker.areaSize.y;
		}
		Pos.x = CornerPos.x - ColorPicker.areaSize.x / 2;
		Pos.y = CornerPos.y + ColorPicker.areaSize.y / 2;
		//RGBからHSVへの変換
		//最大最小値を求める
		COLOR_TAG maxTag = R;
		float min = color.r;
		float max = color.r;
		if (color.g < min) {
			min = color.g;
		}
		if (color.g > max) {
			max = color.g;
			maxTag = G;
		}
		if (color.b < min) {
			min = color.b;
		}
		if (color.b > max) {
			max = color.b;
			maxTag = B;
		}
		//色相を求める
		if (min == max) {
			Hue = 0;
		}
		else {
			switch (maxTag)
			{
			case R:
				Hue = 60 * ((color.g - color.b) / (max - min));
				break;
			case G:
				Hue = 60 * ((color.b - color.r) / (max - min)) + 120;
				break;
			case B:
				Hue = 60 * ((color.r - color.g) / (max - min)) + 240;
				break;
			}
		}
		if (Hue < 0) Hue += 360;
		//彩度を求める
		if (max == 0) {
			Satu = 0;
		}
		else {
			Satu = (max - min) / max * 255;
		}
		//明度を求める
		Value = max;
		//フラグを立てる
		IsApper = true;
	}

	COLOR COLOR_PICKER::getColor() {
		COLOR c;
		int max = Value;
		int min = max - ((Satu / 255.0f) * max);
		if (Hue >= 0 && Hue < 60) {
			c.r = max;
			c.g = (Hue / 60) * (max - min) + min;
			c.b = min;
		}
		else if (Hue >= 60 && Hue < 120) {
			c.r = ((120 - Hue) / 60) * (max - min) + min;
			c.g = max;
			c.b = min;
		}
		else if (Hue >= 120 && Hue < 180) {
			c.r = min;
			c.g = max;
			c.b = ((Hue - 120) / 60) * (max - min) + min;
		}
		else if (Hue >= 180 && Hue < 240) {
			c.r = min;
			c.g = ((240 - Hue) / 60) * (max - min) + min;
			c.b = max;
		}
		else if (Hue >= 240 && Hue < 300) {
			c.r = ((Hue - 240) / 60) * (max - min) + min;
			c.g = min;
			c.b = max;
		}
		else if (Hue >= 300 && Hue <= 360) {
			c.r = max;
			c.g = min;
			c.b = ((360 - Hue) / 60) * (max - min) + min;
		}
		return c;
	}
}