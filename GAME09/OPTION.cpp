#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "OPTION.h"
#include "OPTION_RELATED_BUTTON.h"

namespace GAME09 {
	OPTION::OPTION(class GAME* game) :
		SCENE(game) {

	}
	OPTION::~OPTION() {

	}
	void OPTION::create() {
		Option = game()->container()->data().option;

		//ボタンの動的確保
		for (int i = 0; i < NUM_KINDS; i++) {
			KindButtons[i] = new OPTION_RELATED_BUTTON(game());
			BUTTON::DATA Data;
			Data.colliType = BUTTON::RECT;
			Data.pos = Option.kindButtonPos + Option.kindButtonOfst * i;
			Data.size = Option.kindButtonSize;
			Data.img = Option.optionButtonImgs[i];
			Data.imgSize = Option.optionButtonSize;
			//Data.debugFlag = false;

			KindButtons[i]->setData(Data);
		}
		for (int i = 0; i < KEYCONFIG::NUM_KEY_BIND_TYPE; i++) {
			BindTypeButtons[i] = new OPTION_RELATED_BUTTON(game());
			BUTTON::DATA Data;
			Data.colliType = BUTTON::RECT;
			Data.pos = Option.typeButtonPos + Option.typeButtonOfst * i;
			Data.size = Option.typeButtonSize;
			Data.img = Option.optionTypeImgs[i];
			Data.imgSize = Option.optionButtonSize;
			//Data.debugFlag = false;
			BindTypeButtons[i]->setData(Data);
		}
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 6; x++) {
				if (x < 6 - y) {
					KeyButtons[y][x] = new OPTION_RELATED_BUTTON(game());
					BUTTON::DATA Data;
					Data.colliType = BUTTON::RECT;
					Data.pos = VECTOR2(Option.keyButtonPos.x + (x - (5 - y) / 2.0f) * Option.keyButtonOfst.x,
						Option.keyButtonPos.y + Option.keyButtonOfst.y * y);
					Data.size = Option.keyButtonSize;
					Data.img = Option.keyButtonImg;
					Data.imgSize = Option.keyButtonImgSize;
					//Data.debugFlag = false;
					KeyButtons[y][x]->setData(Data);
				}
				else {
					KeyButtons[y][x] = nullptr;
				}
			}
		}
	}
	void OPTION::init() {
		OptionKind = GENERAL;
	}
	void OPTION::update() {
		game()->backButton()->update();
		int buttonNum = 0;
		for (auto e : KindButtons) {
			e->update();
			if (e->isClick()) {
				OptionKind = (OPTION_KINDS)buttonNum;
			}
			buttonNum++;
		}

		switch (OptionKind)
		{
		case GENERAL:
			UpdateGeneral();
			break;
		case KEY_BIND:
			UpdateKeyBind();
			break;
		case COLOR:
			UpdateColor();
			break;
		default:
			break;
		}
	}
	void OPTION::draw() {
		clear(255);
		//設定
		fill(0);
		stroke(0);
		strokeWeight(5);
		textSize(Option.optionStrSize);
		text("設定", Option.optionStrPos.x, Option.optionStrPos.y);
		//line(0, Option.optionUnderBar, width, Option.optionUnderBar);
		//項目切り替えボタン
		for (auto e : KindButtons) {
			e->draw();
		}
		stroke(0);
		strokeWeight(5);
		line(Option.kindBarX, Option.optionUnderBar, Option.kindBarX, height);

		switch (OptionKind)
		{
		case GENERAL:
			DrawGeneral();
			break;
		case KEY_BIND:
			DrawKeyBind();
			break;
		case COLOR:
			DrawColor();
			break;
		default:
			break;
		}

		game()->backButton()->draw();
	}
	void OPTION::DrawKeyButtons() {
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 6 - y; x++) {
				KeyButtons[y][x]->draw();
			}
		}
	}
	void OPTION::DrawGeneral() {
		fill(0);
		text("一般", 20, 400);
	}
	void OPTION::DrawKeyBind() {
		//タイプ切り替えボタン
		for (auto e : BindTypeButtons) {
			e->draw();
		}
		stroke(0);
		strokeWeight(5);
		DrawKeyButtons();
	}
	void OPTION::DrawColor() {
		fill(0);
		text("色", 20, 400);
	}
	void OPTION::UpdateKeyButtons() {
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 6 - y; x++) {
				KeyButtons[y][x]->update();
				KeyButtons[y][x]->setKey(game()->keyConfig()->getKeyConfig(6 - y, x));
			}
		}
	}
	void OPTION::UpdateGeneral() {
		
	}
	void OPTION::UpdateKeyBind() {
		int buttonNum = 0;
		for (auto e : BindTypeButtons) {
			e->update();
			if (e->isClick()) {
				game()->loadOption()->optionData().keyBindType = (KEYCONFIG::KEY_BIND_TYPE)buttonNum;
				game()->keyConfig()->setKeyConfig();
			}
			buttonNum++;
		}
		UpdateKeyButtons();
	}
	void OPTION::UpdateColor() {
		
	}
	void OPTION::nextScene() {
		if (game()->backButton()->isClick()) {
			game()->fade()->outStart();
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::SELECT_ID);
		}
	}
}