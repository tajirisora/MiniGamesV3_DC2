#include "LOADOPTION.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include <fstream>

namespace GAME09 {
	LOADOPTION::LOADOPTION(GAME* game) :
		GAME_OBJECT(game) {
	}
	LOADOPTION::~LOADOPTION() {
	}

	void LOADOPTION::create() {
		LoadOption = game()->container()->data().loadOption;
	}

	void LOADOPTION::init() {
		OptionData.keyConfig[0][0].main = KEY_D;
		OptionData.keyConfig[0][1].main = KEY_F;
		OptionData.keyConfig[0][2].main = KEY_G;
		OptionData.keyConfig[0][3].main = KEY_H;
		OptionData.keyConfig[0][4].main = KEY_J;
		OptionData.keyConfig[0][5].main = KEY_K;
		OptionData.keyConfig[1][0].main = KEY_D;
		OptionData.keyConfig[1][1].main = KEY_F;
		OptionData.keyConfig[1][2].main = KEY_G;
		OptionData.keyConfig[1][2].sub = KEY_H;
		OptionData.keyConfig[1][3].main = KEY_J;
		OptionData.keyConfig[1][4].main = KEY_K;
		OptionData.keyConfig[2][0].main = KEY_F;
		OptionData.keyConfig[2][1].main = KEY_G;
		OptionData.keyConfig[2][2].main = KEY_H;
		OptionData.keyConfig[2][3].main = KEY_J;
		OptionData.keyConfig[3][0].main = KEY_F;
		OptionData.keyConfig[3][1].main = KEY_G;
		OptionData.keyConfig[3][1].sub = KEY_H;
		OptionData.keyConfig[3][2].main = KEY_J;
		OptionData.keyConfig[4][0].main = KEY_G;
		OptionData.keyConfig[4][1].main = KEY_H;
		OptionData.keyConfig[5][0].main = KEY_G;
		OptionData.keyConfig[5][0].sub = KEY_H;
		writeOption();
	}

	void LOADOPTION::loadOption() {

	}

	void LOADOPTION::writeOption() {
		std::ofstream file;
		file.open(LoadOption.fileName, std::ios::out);
		std::string text = "";

		for (int i = 0; i < NUM_OPTIONS; i++) {
			text += LoadOption.optionStr[i];
			text += ":";
			switch (i) {
			case SPEED:
				text += std::to_string(OptionData.speed);
				break;
			case SOUND_EFFECT:
				if (OptionData.soundEffect) {
					text += "1";
				}
				else {
					text += "0";
				}
				break;
			case AUDIO_OFFSET:
				text += std::to_string(OptionData.audioOffset);
				break;
			case VISUAL_OFFSET:
				text += std::to_string(OptionData.visualOffset);
				break;
			case KEY_BIND_TYPE:
				text += std::to_string((int)OptionData.keyBindType);
				break;
			case KEY_CONFIG:
				for (int j = 0; j < 2; j++) {
					for (int y = 0; y < 6; y++) {
						text += "\n";
						for (int x = 0; x < 6; x++) {
							int d = 0;
							if (j == 0) {
								d = (int)OptionData.keyConfig[y][x].main;
							}
							else {
								d = (int)OptionData.keyConfig[y][x].sub;
							}
							text += std::to_string(d);
							if (x < 5) {
								text += ",";
							}
						}
					}
				}
				text += "\n";
				break;
			default:
				break;
			}
			text += ";\n";
		}

		file << text.c_str();
		file.close();
	}
}