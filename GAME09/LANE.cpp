#include "LANE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	LANE::LANE(GAME* game) :
		GAME_OBJECT(game) {
	}

	LANE::~LANE() {

	}

	void LANE::create() {
		Lane = game()->container()->data().lane;
	}

	void LANE::init() {
		Lanes.clear();

		SONGINFO songInfo = game()->songs()[game()->banner()->curNum()];
		for (auto it = songInfo.lanes.begin(); it != songInfo.lanes.end(); it++) {
			Lanes.emplace_back(LANEDATA{ *it,STAY,1 });
		}

		BeatS = 0;
		BeatE = 0;
	}

	void LANE::update() {
		//レーンの切り替え処理
		for (auto it = ChangeLaneData.begin(); it != ChangeLaneData.end(); ) {
			if ((*it).beatS > game()->rgCont()->visualBeat()) {
				break;
			}
			else {
				//動いてる途中の場合は動き終わった状態に遷移
				//一度すべてのステートをENDに
				for (auto it2 = Lanes.begin(); it2 != Lanes.end();) {
					switch (it2->state) {
					case START:
						it2->state = END;
						it2->laneWidth = 1;
						it2++;
						break;
					case STAY:
						it2->state = END;
						it2++;
						break;
					case END:
						it2 = Lanes.erase(it2);
						break;
					default:
						it2++;
						break;
					}
				}
				//init
				BeatS = (*it).beatS;
				BeatE = (*it).beatE;
				//レーンステートを設定
				std::vector<int>& data = (*it).lane;
				int size = data.size();
				int index = 0;
				for (int i = 0; i < size; i++) {
					index = SearchLaneNum(data[i]);
					if (index == -1) {
						Lanes.emplace_back(LANEDATA{ data[i],START,0 });
					}
					else {
						Lanes[index].state = STAY;
					}
				}
				SortLane();
				it = ChangeLaneData.erase(it);
			}
		}

		//レーンの状態を変更
		float ratio = 0;
		double beat = game()->rgCont()->visualBeat();
		if (BeatS < beat) {
			if (BeatE < beat) {
				ratio = 1;
			}
			else {
				ratio = (beat - BeatS) / (BeatE - BeatS);
			}
		}
		for (auto it = Lanes.begin(); it != Lanes.end();) {
			if (ratio == 1 && it->state == END) {
				it = Lanes.erase(it);
			}
			else {
				it->setWidth(ratio);
				it++;
			}
		}
	}

	void LANE::draw() {
		rectMode(CENTER);
		fill(0, 0, 0, 150);
		noStroke();
		rect(Lane.pos.x, height / 2, Lane.laneWidth, height);

		stroke(255);
		strokeWeight(4);
		float laneWidth = LaneWidthSum();
		float x = Lane.pos.x - Lane.laneWidth / 2;
		line(x, 0, x, height);
		for (auto it = Lanes.begin(); it != Lanes.end(); it++) {
			x += (*it).laneWidth / laneWidth * Lane.laneWidth;
			line(x, 0, x, height);
		}
	}

	void LANE::LANEDATA::setWidth(float ratio) {
		switch (state)
		{
		case START:
			laneWidth = ratio;
			break;
		case STAY:
			laneWidth = 1;
			break;
		case END:
			laneWidth = 1 - ratio;
			break;
		default:
			break;
		}
	}
	float LANE::LaneWidthSum() {
		float sum = 0;
		for (auto it = Lanes.begin(); it != Lanes.end(); it++) {
			sum += (*it).laneWidth;
		}
		return sum;
	}
	int LANE::SearchLaneNum(int num) {
		for (int i = 0; i < Lanes.size(); i++) {
			if (Lanes[i].laneNo == num) {
				return i;
			}
		}
		return -1;
	}
	void LANE::SortLane() {
		LANEDATA temp;
		for (int i = 0; i < Lanes.size() - 1; i++) {
			for (int j = 0; j < Lanes.size() - 1 - i; j++) {
				if (Lanes[j].laneNo > Lanes[j + 1].laneNo) {
					temp = Lanes[j];
					Lanes[j] = Lanes[j + 1];
					Lanes[j + 1] = temp;
				}
			}
		}
	}
}