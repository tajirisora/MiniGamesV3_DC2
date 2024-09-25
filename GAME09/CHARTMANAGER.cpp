#include "CHARTMANAGER.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "TAPNOTE.h"
#include "LONGNOTE.h"
#include "LONGBELT.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include <fstream>
#include <algorithm>
#include "../../libOne/inc/stb_image_reader.h"
#include <filesystem>
#include <iostream>
#include "myFunc.h"

//#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)

namespace GAME09 {
	CHARTMANAGER::CHARTMANAGER(GAME* game) :
		GAME_OBJECT(game) {
		
	}
	CHARTMANAGER::~CHARTMANAGER() {

	}

	void CHARTMANAGER::create() {
		ChartMNG = game()->container()->data().chartMNG;
	}

	void CHARTMANAGER::init() {

	}

	int CHARTMANAGER::cntSongs() {
		int cnt = 0;
		//chartsフォルダのイテレーター
		std::filesystem::directory_iterator songsDirectory = std::filesystem::directory_iterator(ChartMNG.chartPath);
		//範囲forでchartsフォルダの中のすべてのフォルダを確認
		for (auto d : songsDirectory) {
			cnt++;
		}
		return cnt;
	}
	int CHARTMANAGER::cntRows(struct SONGINFO& songInfo) {
		int cnt = 0;
		std::ifstream file;
		file.open(songInfo.fileName, std::ios::in);
		std::string buffer;
		while (std::getline(file, buffer)) {
			cnt++;
		}
		return cnt;
	}

	void CHARTMANAGER::loadChart(struct SONGINFO& songInfo, int& curRow){

		//音声オフセットを反映
		songInfo.offset += AudioOffset / 1000.0f;
		songInfo.offset += VisualOffset / 1000.0f;
		songInfo.offsetB = -songInfo.offset / (60.0f / songInfo.bpm);
		songInfo.offset -= VisualOffset / 1000.0f;

		std::vector<NOTE*>& notes = game()->notes();
		std::vector<CHANGEDATA>& changeDatas = game()->changeDatas();
		std::vector<LANE::CHANGEDATA>& changeLaneDatas = game()->lane()->changeLaneData();
		
		safe_clear(notes);
		changeDatas.clear();
		changeLaneDatas.clear();
		NOTE::NOTE_DATA data;
		CHANGEDATA changeData;
		LANE::CHANGEDATA changeLaneData;
		std::vector<NOTE::NOTE_DATA*> longData;
		std::vector< std::vector<NOTE::NOTE_DATA*>* > longBeltData;
		const int maxLane = game()->lane()->maxLaneNum();
		for (int i = 0; i < maxLane; i++) {
			longData.emplace_back(nullptr);
			longBeltData.emplace_back(new std::vector<NOTE::NOTE_DATA*>);
		}
		//LaneChangeコマンドは、その次読み込む行のレーン数は変更しない
		int nextLane = songInfo.lanes.size(); //次の行を読み込んだ後にレーン数が何になるか
		int curLane = songInfo.lanes.size();

		std::ifstream file;
		file.open(songInfo.fileName, std::ios::in);
		std::string buffer;
		std::vector<std::string> bar;
		bool notesTag = false;

		double offset = songInfo.offset;
		double offsetB = songInfo.offsetB;
		double bpm = songInfo.bpm;
		VECTOR2 measure = songInfo.measure;
		int curBar = 0;
		float speed = 0;
		double tempTime = 0;       //bpmなどが変わったときにその時点の時間を記録しておく
		double curTime = 0;        //現在の時間
		double tempVisualBeat = 0; //bpmなどが変わったときにその時点の見た目上の拍数を記録しておく
		double visualBeat = 0;     //現在の見た目上の拍数
		double endTime = 0;        //最後のノーツの時間

		while (std::getline(file, buffer)) {
			curRow++;
			//空白の行なら飛ばす
			if (std::all_of(buffer.begin(), buffer.end(), [](unsigned char c) { return std::isspace(c); })) {
				continue;
			}
			if (!notesTag) {
				std::string t = "#NOTES";
				if (buffer.size() >= t.size() &&
					buffer.find(t) != std::string::npos) {
					notesTag = true;
					for (int i = 0; i < 4; i++) {   //余計な情報4行分を飛ばす
						std::getline(file, buffer);
						curRow++;
					}
				}
			}
			else {
				if (buffer.find(ChartMNG.commandStr[BPMCHANGE]) != std::string::npos) { //BPMコマンド
					tempTime += (60.0 / bpm / (measure.y / 4) * measure.x) * curBar;
					tempVisualBeat += (measure.x * 4 / measure.y) * curBar;
					curBar = 0;

					int conS = buffer.find(':') + 1;
					int conE = buffer.find_last_of(';');
					std::string content = buffer.substr(conS, conE - conS);
					bpm = std::stof(content);

					changeData.time = tempTime - offset;
					changeData.visualBeat = tempVisualBeat + offsetB;
					changeData.bpm = bpm;
					changeData.measure = measure;
					game()->changeDatas().emplace_back(changeData);
				}
				else if (buffer.find(ChartMNG.commandStr[MEASURECHANGE]) != std::string::npos) { //MEASUREコマンド
					tempTime += (60.0 / bpm / (measure.y / 4) * measure.x) * curBar;
					tempVisualBeat += (measure.x * 4 / measure.y) * curBar;
					curBar = 0;

					int conS = buffer.find(':') + 1;
					int conE = buffer.find_last_of(';');
					std::string content = buffer.substr(conS, conE - conS);
					int n = std::stoi(content.substr(0, content.find('/')));
					int d = std::stoi(content.substr(content.find('/') + 1));
					measure = VECTOR2(n, d);

					changeData.time = tempTime - offset;
					changeData.visualBeat = tempVisualBeat + offsetB;
					changeData.bpm = bpm;
					changeData.measure = measure;
					game()->changeDatas().emplace_back(changeData);
				}
				else {
					//一小節分の情報を一度に読む
					bar.clear();
					bar.emplace_back(buffer);
					bool end = false; //一小節の終わりのフラグ
					int divisionNum = 0; //一小節の分割数(何分音符か)
					if (buffer.find(ChartMNG.commandStr[LANECHANGE]) == std::string::npos) divisionNum++;

					while (!end) {
						std::getline(file, buffer);
						curRow++; //ロード状況のカウント
						if (buffer.find(ChartMNG.commandStr[LANECHANGE]) != std::string::npos) {
							bar.emplace_back(buffer);
						}
						else if (buffer.find(',') != std::string::npos ||
							buffer.find(';') != std::string::npos) {
							end = true; //,か;が見つかったら小節の終了
						}
						else {
							bar.emplace_back(buffer);
							divisionNum++; //分割数を増やす
						}
					}
					int j = 0; //一小節の何番目を見ているか
					for (auto it = bar.begin(); it != bar.end(); ++it) {
						visualBeat = tempVisualBeat + (measure.x * 4 / measure.y) * (curBar + (float)j / divisionNum) + offsetB;
						curTime = tempTime + (60.0 / bpm / (measure.y / 4) * measure.x) * (curBar + (float)j / divisionNum) - offset;
						speed = game()->rgCont()->speed() * (game()->rgCont()->rawSpeed() / songInfo.bpm);

						if ((*it).find(ChartMNG.commandStr[LANECHANGE]) != std::string::npos) { //LANEコマンド
							int conS = (*it).find(':') + 1;
							int conE = (*it).find_last_of(';');
							std::string content = (*it).substr(conS, conE - conS);
							std::string lanes = content.substr(0, content.find('/'));
							double beat = std::stof(content.substr(content.find('/') + 1));

							changeLaneData.lane.clear();
							auto offset = std::string::size_type(0);
							while (1) {
								auto pos = lanes.find(",", offset);
								if (pos == std::string::npos) {
									changeLaneData.lane.emplace_back(std::stoi(lanes.substr(offset)));
									break;
								}
								changeLaneData.lane.emplace_back(std::stoi(lanes.substr(offset, pos - offset)));
								offset = pos + 1;
							}
							nextLane = (int)changeLaneData.lane.size();
							changeLaneData.beatS = visualBeat;
							changeLaneData.beatE = visualBeat + beat;
							changeLaneDatas.emplace_back(changeLaneData);
							j--;
						}
						else {
							for (int i = 0; i < curLane; i++) {
								if ((*it)[i] == '1') {
									notes.emplace_back(new TAPNOTE(game()));
									notes.back()->create();
									data.laneNum = curLane;
									data.lane = i;
									data.speed = speed;
									data.time = curTime;
									data.visualBeat = visualBeat;
									notes.back()->setData(data);
									notes.back()->init();
									endTime = curTime;
								}
								else if (std::toupper((*it)[i]) == 'A') {
									if (longData[i] == nullptr) {
										longData[i] = new NOTE::NOTE_DATA;
										longData[i]->laneNum = curLane;
										longData[i]->lane = i;
										longData[i]->speed = speed;
										longData[i]->time = curTime;
										longData[i]->visualBeat = visualBeat;

										longBeltData[i]->emplace_back(new NOTE::NOTE_DATA);
										longBeltData[i]->back()->laneNum = curLane;
										longBeltData[i]->back()->lane = i;
										longBeltData[i]->back()->speed = speed;
										longBeltData[i]->back()->time = curTime;
										longBeltData[i]->back()->visualBeat = visualBeat;
									}
								}
								else if (std::toupper((*it)[i]) == 'C') {
									if (longData[i] != nullptr) {
										longData[i]->timeE = curTime;
										longData[i]->visualBeatE = visualBeat;
										longBeltData[i]->back()->timeE = curTime;
										longBeltData[i]->back()->visualBeatE = visualBeat;
										endTime = curTime;

										notes.emplace_back(new LONGNOTE(game()));
										notes.back()->create();
										notes.back()->setData(*longData[i]);
										notes.back()->init();
										((LONGNOTE*)notes.back())->setBelts(*longBeltData[i]);

										delete longData[i];
										longData[i] = nullptr;
										safe_clear(*longBeltData[i]);
									}
								}
							}
							curLane = nextLane;
						}
						j++;
					}
					curBar++;
				}
			}
		}
		file.close();
		longData.clear();
		safe_clear(longBeltData);

		//音声オフセットの値が毎回足されるのを防ぐためにここで減らす
		songInfo.offset -= AudioOffset / 1000.0f;
	}

	void CHARTMANAGER::loadCharts(int& curLoad) {
		std::vector<SONGINFO>& Songs = game()->songs();
		Songs.clear();
		//chartsフォルダのイテレーター
		std::filesystem::directory_iterator songsDirectory = std::filesystem::directory_iterator(ChartMNG.chartPath);
		//範囲forでchartsフォルダの中のすべてのフォルダを確認
		for (auto d : songsDirectory) {
			std::string chartPath = d.path().string();
			//楽曲フォルダのイテレーター
			std::filesystem::directory_iterator chartDirectory = std::filesystem::directory_iterator(chartPath);
			bool isLoadChart = false;
			bool isLoadScore = false;
			Score = 0;
			Achievement = -1;
			//ハイスコアを保存するファイルのパス
			std::string scorePath = chartPath + "\\high_score.txt";
			//範囲forで楽曲フォルダの中のすべてのファイルを確認
			for (auto chart : chartDirectory) {
				//テキストファイルが見つかったら
				if (chart.path().extension().string() == ".txt") {
					//ハイスコアを保存するファイルであればハイスコアを読み込む
					if (chart.path().string() == scorePath) {
						loadHiscore(scorePath);
						isLoadScore = true;
					}
					//譜面が読み込まれてなければ読み込む
					else if (!isLoadChart) {
						Songs.emplace_back();
						Songs.back().fileName = chart.path().string();
						Songs.back().scorePath = scorePath;
						loadChartInfo(chart.path().string().c_str(), Songs.back());
						//楽曲ファイルを読み込んでインデックスを格納
						std::string musicFile = chartPath + "\\" + Songs.back().music;
						//Songs.back().musicIdx = game()->soundMNG()->loadMusic(musicFile.c_str(), Songs.back().volume);
						//背景画像ファイルを読み込んでインデックスを格納
						loadChartImage(chartPath, Songs.back().backGround, Songs.back().backImageIdx, Songs.back().backImageSize);
						//ジャケ絵ファイルを読み込んでインデックスを格納
						loadChartImage(chartPath, Songs.back().banner, Songs.back().jacketImageIdx, Songs.back().jacketImageSize);
						isLoadChart = true;
					}
				}
				//譜面とハイスコアがともに読み込まれたら抜ける
				if (isLoadChart && isLoadScore) {
					break;
				}
			}
			Songs.back().highScore = Score;
			Songs.back().achievement = Achievement;
			curLoad++;
		}
	}

	void CHARTMANAGER::loadChartInfo(std::string fileName, struct SONGINFO& songInfo) {
		std::ifstream file;
		file.open(fileName, std::ios::in);
		std::string buffer;
		bool notes = false;

		while (std::getline(file, buffer) && !notes) {
			for (int i = 0; i < NUM_INFOS; i++) {
				std::string t = ChartMNG.infoStartStr[i];
				if (buffer.size() >= t.size() &&
					buffer.find(t) != std::string::npos) {
					int conS = buffer.find(':') + 1;
					int conE = buffer.find_last_of(';');
					std::string content = buffer.substr(conS, conE - conS);
					switch (i) {
					case TITLE:
						songInfo.title = content;
						break;
					case ARTIST:
						songInfo.artist = content;
						break;
					case CREDIT:
						songInfo.credit = content;
						break;
					case MUSIC:
						songInfo.music = content;
						break;
					case BANNER:
						songInfo.banner = content;
						break;
					case BACKGROUND:
						songInfo.backGround = content;
						break;
					case OFFSET:
						songInfo.offset = std::stof(content);
						break;
					case BASEBPM:
						songInfo.bpm = std::stof(content);
						break;
					case MEASURE: {
						int n = std::stoi(content.substr(0, content.find('/')));
						int d = std::stoi(content.substr(content.find('/') + 1));
						songInfo.measure = VECTOR2(n, d);
					}
						break;
					case VOLUME:
						songInfo.volume = std::stof(content);
						break;
					case LANES: {
						auto offset = std::string::size_type(0);
						while (1) {
							auto pos = content.find(",", offset);
							if (pos == std::string::npos) {
								songInfo.lanes.emplace_back(std::stoi(content.substr(offset)));
								break;
							}
							songInfo.lanes.emplace_back(std::stoi(content.substr(offset, pos - offset)));
							offset = pos + 1;
						}
					}
						break;
					case NOTES:
						notes = true;
						break;
					default:
						break;
					}
				}
			}
		}

		//songInfo.offsetB = -songInfo.offset / (60.0f / songInfo.bpm);
	}

	void CHARTMANAGER::loadHiscore(std::string fileName) {
		std::ifstream file;
		file.open(fileName, std::ios::in);
		std::string buffer;

		while (std::getline(file, buffer)) {
			for (int i = 0; i < NUM_SCORE_DATAS; i++) {
				std::string t = ChartMNG.scoreDataStr[i];
				if (buffer.size() >= t.size() &&
					buffer.find(t) != std::string::npos) {
					int conS = buffer.find(':') + 1;
					int conE = buffer.find_last_of(';');
					std::string content = buffer.substr(conS, conE - conS);
					switch (i) {
					case SCORE:
						Score = std::stoi(content);
						break;
					case ACHIEVEMENT:
						Achievement = std::stoi(content);
						break;
					default:
						break;
					}
				}
			}
		}
	}

	void CHARTMANAGER::loadChartImage(std::string chartPath, std::string fileName, int& idx, VECTOR2& size) {
		if (fileName == "") {
			idx = ChartMNG.tempImage;
			size = VECTOR2(100, 100);
		}
		else {
			std::string imageFile = chartPath + "\\" + fileName;
			idx = loadImage(imageFile.c_str());
			int w, h, p;
			unsigned char* pixels = 0;
			pixels = stbi_load(imageFile.c_str(), &w, &h, &p, 4); //使い方違うけどこれで高さと幅を取得
			size = VECTOR2(w, h);
			stbi_image_free(pixels);
		}
	}
}