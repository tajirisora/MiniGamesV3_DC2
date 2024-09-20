#include "LANE.h"
#include "GAME09.h"
#include "CONTAINER.h"

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
		
	}

	void LANE::update() {
		
	}

	void LANE::draw() {
		
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