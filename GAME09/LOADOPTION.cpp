#include "LOADOPTION.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include <fstream>

namespace GAME09 {
	LOADOPTION::LOADOPTION(GAME* game) :
		GAME_OBJECT(game) {
	}
	LOADOPTION::~LOADOPTION() {
		for (int i = 0; i < 6; i++) {
			delete[] OptionData.keyConfig[i];
		}
		delete[] OptionData.keyConfig;
	}

	void LOADOPTION::create() {
		LoadOption = game()->container()->data().loadOption;

		//“®“IŠm•Û
		OptionData.keyConfig = new KC_MAINSUB*[6];
		for (int i = 0; i < 6; i++) {
			OptionData.keyConfig[i] = new KC_MAINSUB[6];
		}
		OptionData.color1Config = new COLOR[6];
		OptionData.color2Config = new COLOR[2];
		OptionData.colorDifferentConfig = new bool*[6];
		for (int i = 0; i < 6; i++) {
			OptionData.colorDifferentConfig[i] = new bool[6];
		}
		OptionData.colorCustomConfig = new COLOR* [6];
		for (int i = 0; i < 6; i++) {
			OptionData.colorCustomConfig[i] = new COLOR[6];
		}
		loadOption();
	}

	void LOADOPTION::init() {
		/*OptionData.keyConfig[0][0].main = KEY_D;
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
		writeOption();*/
	}
	
	void LOADOPTION::loadOption() {
		std::ifstream file;
		file.open(LoadOption.fileName, std::ios::in);
		std::string buffer;

		while (std::getline(file, buffer)) {
			for (int i = 0; i < NUM_OPTIONS; i++) {
				std::string t = LoadOption.optionStr[i];
				if (buffer.size() >= t.size() &&
					buffer.find(t) != std::string::npos) {
					int conS = buffer.find(':') + 1;
					int conE = buffer.find_last_of(';');
					std::string content = buffer.substr(conS, conE - conS);
					switch (i) {
					case SPEED:
						OptionData.speed = std::stof(content);
						break;
					case SOUND_EFFECT:
						if (content == "1") {
							OptionData.soundEffect = true;
						}
						else {
							OptionData.soundEffect = false;
						}
						break;
					case AUDIO_OFFSET:
						OptionData.audioOffset = std::stof(content);
						break;
					case VISUAL_OFFSET:
						OptionData.visualOffset = std::stof(content);
						break;
					case KEY_BIND_TYPE:
						OptionData.keyBindType = (KEYCONFIG::KEY_BIND_TYPE)std::stoi(content);
						break;
					case KEY_CONFIG: {
						auto offset = std::string::size_type(0);
						std::string temp;
						for (int j = 0; j < 2; j++) {
							for (int y = 0; y < 6; y++) {
								for (int x = 0; x < 6; x++) {
									auto pos = content.find(",", offset);
									if (pos == std::string::npos) {
										temp = content.substr(offset);
									}
									else {
										temp = content.substr(offset, pos - offset);
									}
									if (j == 0) {
										OptionData.keyConfig[y][x].main = (INPUT_CODE)std::stoi(temp);
									}
									else {
										OptionData.keyConfig[y][x].sub = (INPUT_CODE)std::stoi(temp);
									}
									offset = pos + 1;
								}
							}
						}
					}
						break;
					default:
						break;
					}
				}
			}
		}
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
						for (int x = 0; x < 6; x++) {
							int d = 0;
							if (j == 0) {
								d = (int)OptionData.keyConfig[y][x].main;
							}
							else {
								d = (int)OptionData.keyConfig[y][x].sub;
							}
							text += std::to_string(d);
							text += ",";
						}
					}
				}
				text.pop_back();
				break;
			case COLOR_TYPE:
				text += std::to_string((int)OptionData.colorType);
				break;
			case COLOR_1_CONFIG:
				for (int i = 0; i < 6; i++) {
					text += std::to_string((int)OptionData.color1Config[i].r);
					text += ",";
					text += std::to_string((int)OptionData.color1Config[i].g);
					text += ",";
					text += std::to_string((int)OptionData.color1Config[i].b);
					text += "/";
				}
				text.pop_back();
				break;
			case COLOR_2_CONFIG:
				for (int i = 0; i < 2; i++) {
					text += std::to_string((int)OptionData.color2Config[i].r);
					text += ",";
					text += std::to_string((int)OptionData.color2Config[i].g);
					text += ",";
					text += std::to_string((int)OptionData.color2Config[i].b);
					text += "/";
				}
				text.pop_back();
				break;
			case COLOR_DIFFERENT_CONFIG:
				for (int y = 0; y < 6; y++) {
					for (int x = 0; x < 6; x++) {
						text += OptionData.colorDifferentConfig[y][x] ? "1," : "0,";
					}
				}
				text.pop_back();
				break;
			case COLOR_CUSTOM_CONFIG:
				for (int y = 0; y < 6; y++) {
					for (int x = 0; x < 6; x++) {
						text += std::to_string((int)OptionData.colorCustomConfig[y][x].r);
						text += ",";
						text += std::to_string((int)OptionData.colorCustomConfig[y][x].g);
						text += ",";
						text += std::to_string((int)OptionData.colorCustomConfig[y][x].b);
						text += "/";
					}
				}
				text.pop_back();
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