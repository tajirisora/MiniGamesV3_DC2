#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/COLOR.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "OPTION.h"
#include "OPTION_RELATED_BUTTON.h"

namespace GAME09 {
	OPTION::OPTION(class GAME* game) :
		SCENE(game) {

	}
	OPTION::~OPTION() {
		//解放
		for (auto e : KindButtons) {
			delete e;
		}
		for (auto e : BindTypeButtons) {
			delete e;
		}
		for (auto e : ColorTypeButtons) {
			delete e;
		}
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 6; x++) {
				if (KeyButtons[y][x] != nullptr)delete KeyButtons[y][x];
			}
		}
		for (auto e : ColorType1Buttons) {
			delete e;
		}
		for (auto e : ColorType2Buttons) {
			delete e;
		}
		for (auto e : Adjust) {
			delete e;
		}
	}
	void OPTION::create() {
		Option = game()->container()->data().option;

		//ボタンの動的確保
		for (int i = 0; i < NUM_KINDS; i++) {
			KindButtons[i] = new OPTION_RELATED_BUTTON(game());
			BUTTON::DATA Data;
			Data.colliType = BUTTON::RECT;
			Data.pos = Option.kindButtonTF.pos + Option.kindButtonTF.ofst * i;
			Data.size = Option.kindButtonTF.size;
			Data.img = Option.optionButtonImgs[i];
			Data.imgSize = Option.optionButtonSize;
			Data.debugFlag = false;

			KindButtons[i]->setData(Data);
		}
		for (int i = 0; i < KEYCONFIG::NUM_KEY_BIND_TYPE; i++) {
			BindTypeButtons[i] = new OPTION_RELATED_BUTTON(game());
			BUTTON::DATA Data;
			Data.colliType = BUTTON::RECT;
			Data.pos = Option.typeButtonTF.pos + Option.typeButtonTF.ofst * i;
			Data.size = Option.typeButtonTF.size;
			Data.img = Option.optionTypeImgs[i];
			Data.imgSize = Option.optionButtonSize;
			Data.debugFlag = false;
			BindTypeButtons[i]->setData(Data);
		}
		for (int i = 0; i < KEYCONFIG::NUM_COLOR_TYPE; i++) {
			ColorTypeButtons[i] = new OPTION_RELATED_BUTTON(game());
			BUTTON::DATA Data;
			Data.colliType = BUTTON::RECT;
			Data.pos = Option.colorTypeButtonTF.pos + Option.colorTypeButtonTF.ofst * i;
			Data.size = Option.colorTypeButtonTF.size;
			if (i == KEYCONFIG::NUM_COLOR_TYPE - 1) {
				Data.img = Option.optionTypeImgs[i+1];
			}
			else {
				Data.img = Option.optionTypeImgs[i];
			}
			Data.imgSize = Option.optionButtonSize;
			Data.debugFlag = false;
			ColorTypeButtons[i]->setData(Data);
		}
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 6; x++) {
				if (x < 6 - y) {
					KeyButtons[y][x] = new OPTION_RELATED_BUTTON(game());
					BUTTON::DATA Data;
					Data.colliType = BUTTON::RECT;
					Data.pos = VECTOR2(Option.keyButtonTF.pos.x + (x - (5 - y) / 2.0f) * Option.keyButtonTF.ofst.x,
						Option.keyButtonTF.pos.y + Option.keyButtonTF.ofst.y * y);
					Data.size = Option.keyButtonTF.size;
					Data.img = Option.keyButtonImg;
					Data.imgSize = Option.keyButtonImgSize;
					Data.debugFlag = false;
					KeyButtons[y][x]->setData(Data);
					KeyButtons[y][x]->setChoice(true);
				}
				else {
					KeyButtons[y][x] = nullptr;
				}
			}
		}
		for (int i = 0; i < 6; i++) {
			ColorType1Buttons[i] = new OPTION_RELATED_BUTTON(game());
			BUTTON::DATA Data;
			Data.colliType = BUTTON::RECT;
			Data.pos = Option.colorType1ButtonTF.pos + Option.colorType1ButtonTF.ofst * i;
			Data.size = Option.colorType1ButtonTF.size;
			Data.img = Option.keyButtonImg;
			Data.imgSize = Option.keyButtonImgSize;
			Data.debugFlag = false;
			ColorType1Buttons[i]->setData(Data);
			ColorType1Buttons[i]->setChoice(true);
		}
		for (int i = 0; i < 2; i++) {
			ColorType2Buttons[i] = new OPTION_RELATED_BUTTON(game());
			BUTTON::DATA Data;
			Data.colliType = BUTTON::RECT;
			Data.pos = Option.colorType2ButtonTF.pos + Option.colorType2ButtonTF.ofst * i;
			Data.size = Option.colorType2ButtonTF.size;
			Data.img = Option.keyButtonImg;
			Data.imgSize = Option.keyButtonImgSize;
			Data.debugFlag = false;
			ColorType2Buttons[i]->setData(Data);
			ColorType2Buttons[i]->setChoice(true);
		}
		for (int i = 0; i < LOADOPTION::KEY_BIND_TYPE; i++) {
			Adjust[i] = new ADJUST(game());
			ADJUST::SETDATA Data;
			Data = Option.adjustData[i];
			Data.pos = Option.adjustTF.pos + Option.adjustTF.ofst * i;
			switch (i)
			{
			case LOADOPTION::SPEED:
				Data.valueF = &game()->loadOption()->optionData().speed;
				break;
			case LOADOPTION::SOUND_EFFECT:
				Data.valueB = &game()->loadOption()->optionData().soundEffect;
				break;
			case LOADOPTION::AUDIO_OFFSET:
				Data.valueI = &game()->loadOption()->optionData().audioOffset;
				break;
			case LOADOPTION::VISUAL_OFFSET:
				Data.valueI = &game()->loadOption()->optionData().visualOffset;
				break;
			default:
				break;
			}
			Adjust[i]->create();
			Adjust[i]->setData(Data);
		}
	}
	void OPTION::init() {
		OptionKind = GENERAL;
		KeyWait = NO;
	}
	void OPTION::update() {
		if (!game()->colorPicker()->isApper()) {
			//戻るボタン
			game()->backButton()->update();
			//設定項目切り替えボタン
			int buttonNum = 0;
			for (auto e : KindButtons) {
				e->update();
				if (e->isClick()) {
					OptionKind = (OPTION_KINDS)buttonNum;
				}
				buttonNum++;
			}
			for (int i = 0; i < NUM_KINDS; i++) {
				KindButtons[i]->setChoice(i == (int)OptionKind);
			}
		}
		//それぞれの設定項目ごとのアップデート
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
		rectMode(CORNER);
		image(Option.optionImg, Option.optionImgPos.x, Option.optionImgPos.y, 0, Option.optionImgSize);
		//line(0, Option.optionUnderBar, width, Option.optionUnderBar);
		//項目切り替えボタン
		for (auto e : KindButtons) {
			e->draw();
		}
		stroke(0);
		strokeWeight(5);
		line(Option.kindBarX, Option.optionUnderBar, Option.kindBarX, height);
		//それぞれの設定項目ごとのdraw
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
		//戻るボタン
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
		for (auto e : Adjust) {
			e->draw();
		}
	}
	void OPTION::DrawKeyBind() {
		//タイプ切り替えボタン
		for (auto e : BindTypeButtons) {
			e->draw();
		}
		stroke(0);
		strokeWeight(5);
		DrawKeyButtons();
		//キー入力待ち
		rectMode(CORNER);
		if (KeyWait == MAIN) {
			image(Option.keyWait1Img, 0, 0);
		}
		else if (KeyWait == SUB) {
			image(Option.keyWait2Img, 0, 0);
		}
	}
	void OPTION::DrawColor() {
		//タイプ切り替えボタン
		for (auto e : ColorTypeButtons) {
			e->draw();
		}
		stroke(0);
		strokeWeight(5);
		DrawKeyButtons();
		//タイプごとの色変更ボタン
		switch (game()->loadOption()->optionData().colorType)
		{
		case KEYCONFIG::C_TYPE1:
			for (auto e : ColorType1Buttons) {
				e->draw();
			}
			break;
		case KEYCONFIG::C_TYPE2:
			for (auto e : ColorType2Buttons) {
				e->draw();
			}
			break;
		default:
			break;
		}
		//カラーピッカー
		if (game()->colorPicker()->isApper()) {
			game()->colorPicker()->draw();
		}
	}
	void OPTION::UpdateKeyButtons() {
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 6 - y; x++) {
				KeyButtons[y][x]->update();
				KeyButtons[y][x]->setKey(game()->keyConfig()->getKeyConfig(6 - y, x));
				if (OptionKind == COLOR) {
					KeyButtons[y][x]->setColor(game()->keyConfig()->getColorConfig(6 - y, x));
				}
				else {
					KeyButtons[y][x]->setColor({255,255,255});
				}
			}
		}
	}
	void OPTION::UpdateGeneral() {
		for (auto e : Adjust) {
			e->update();
		}
	}
	void OPTION::UpdateKeyBind() {
		//通常時
		if (KeyWait == NO) {
			//キーバインドタイプ更新
			int buttonNum = 0;
			for (auto e : BindTypeButtons) {
				e->update();
				if (e->isClick()) {
					game()->loadOption()->optionData().keyBindType = (KEYCONFIG::KEY_BIND_TYPE)buttonNum;
					game()->keyConfig()->setKeyConfig();
				}
				buttonNum++;
			}
			for (int i = 0; i < KEYCONFIG::NUM_KEY_BIND_TYPE; i++) {
				BindTypeButtons[i]->setChoice(i == (int)game()->loadOption()->optionData().keyBindType);
			}
			UpdateKeyButtons();
			//キーが押されたとき
			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 6 - y; x++) {
					if (KeyButtons[y][x]->isClick()) {
						WaitKeyIdx = VECTOR2(y, x);
						KeyWait = MAIN;
						break;
					}
				}
				if (game()->loadOption()->optionData().keyBindType != KEYCONFIG::B_CUSTOM) {
					break;
				}
			}
		}
		if (KeyWait == MAIN) {
			if (game()->backButton()->isClick()) {
				KeyWait = NO;
				game()->backButton()->resetClick();
			}
			else {
				auto key = getPressedKeyCode();
				if (key != KEY_NONE) {
					game()->loadOption()->optionData().keyConfig[(int)WaitKeyIdx.x][(int)WaitKeyIdx.y].main = key;
					game()->loadOption()->optionData().keyConfig[(int)WaitKeyIdx.x][(int)WaitKeyIdx.y].sub = KEY_NONE;
					KeyWait = SUB;
					game()->keyConfig()->setKeyConfig();
					UpdateKeyButtons();
				}
			}
		}
		else if (KeyWait == SUB) {
			if (game()->backButton()->isClick()) {
				KeyWait = NO;
				game()->backButton()->resetClick();
			}
			else {
				auto key = getPressedKeyCode();
				if (key != KEY_NONE && key != game()->loadOption()->optionData().keyConfig[(int)WaitKeyIdx.x][(int)WaitKeyIdx.y].main) {
					game()->loadOption()->optionData().keyConfig[(int)WaitKeyIdx.x][(int)WaitKeyIdx.y].sub = key;
					KeyWait = NO;
					game()->keyConfig()->setKeyConfig();
				}
			}
		}
	}
	void OPTION::UpdateColor() {
		//カラータイプ更新
		int buttonNum = 0;
		for (auto e : ColorTypeButtons) {
			e->update();
			if (e->isClick() && !game()->colorPicker()->isApper()) {
				game()->loadOption()->optionData().colorType = (KEYCONFIG::COLOR_TYPE)buttonNum;
				game()->keyConfig()->setColorConfig();
			}
			buttonNum++;
		}
		for (int i = 0; i < KEYCONFIG::NUM_COLOR_TYPE; i++) {
			ColorTypeButtons[i]->setChoice(i == (int)game()->loadOption()->optionData().colorType);
		}
		//タイプごとの色変更ボタン
		switch (game()->loadOption()->optionData().colorType)
		{
		case KEYCONFIG::C_TYPE1:
			for (int i = 0; i < 6; i++) {
				ColorType1Buttons[i]->update();
				if (ColorType1Buttons[i]->isClick()) {
					if (!game()->colorPicker()->isApper()) {
						game()->colorPicker()->apper(VECTOR2(mouseX, mouseY), game()->loadOption()->optionData().color1Config[i]);
						WaitColor = &game()->loadOption()->optionData().color1Config[i];
					}
				}
				ColorType1Buttons[i]->setColor(game()->loadOption()->optionData().color1Config[i]);
			}
			break;
		case KEYCONFIG::C_TYPE2:
			for (int i = 0; i < 2; i++) {
				ColorType2Buttons[i]->update();
				if (ColorType2Buttons[i]->isClick()) {
					if (!game()->colorPicker()->isApper()) {
						game()->colorPicker()->apper(VECTOR2(mouseX, mouseY), game()->loadOption()->optionData().color2Config[i]);
						WaitColor = &game()->loadOption()->optionData().color2Config[i];
					}
				}
				ColorType2Buttons[i]->setColor(game()->loadOption()->optionData().color2Config[i]);
			}
			break;
		default:
			break;
		}
		//キーが押されたとき
		UpdateKeyButtons();
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 6 - y; x++) {
				if (KeyButtons[y][x]->isClick()) {
					if (!game()->colorPicker()->isApper()) {
						if (game()->loadOption()->optionData().colorType != KEYCONFIG::C_CUSTOM) {
							game()->loadOption()->optionData().colorDifferentConfig[y][x] ^= 1;
							game()->keyConfig()->setColorConfig();
							UpdateKeyButtons();
							break;
						}
						else {
							game()->colorPicker()->apper(VECTOR2(mouseX, mouseY), game()->loadOption()->optionData().colorCustomConfig[y][x]);
							WaitColor = &game()->loadOption()->optionData().colorCustomConfig[y][x];
						}
					}
				}
			}
		}
		//カラーピッカー
		if (game()->colorPicker()->isApper()) {
			game()->colorPicker()->update();
			*WaitColor = game()->colorPicker()->getColor();
			game()->keyConfig()->setColorConfig();
		}
	}
	void OPTION::nextScene() {
		if (game()->backButton()->isClick() && KeyWait == NO) {
			game()->fade()->outStart();
		}
		if (game()->fade()->outEndFlag()) {
			game()->loadOption()->writeOption();
			game()->changeScene(GAME::SELECT_ID);
		}
	}
}