#include "GAME09.h"
#include "LONGNOTE.h"
#include "LANE.h"
#include "RHYTHM_GAME_CONTROLLER.h"
#include "../../libOne/inc/graphic.h"
#include "myFunc.h"

//#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)

namespace GAME09 {
	LONGNOTE::LONGNOTE(class GAME* game) :
		NOTE(game) {
	}
	LONGNOTE::~LONGNOTE() {
		safe_clear(Belts);
	}

	void LONGNOTE::init() {
		NOTE::init();
		IsPress = false;
	}

	void LONGNOTE::update() {
		Pos = SetPos(VisualBeat);
		if (Time - game()->rgCont()->curTime() < 0) {
			//if (!Sound) {
			//	SoundMNG->tapSound();
			//	Sound = true;
			//}
			if (TimeE - game()->rgCont()->curTime() < 0) {
				Pos = SetPos(VisualBeatE);
			}
			else {
				Pos.y = game()->lane()->lanePos().y;
			}
		}
		for (auto it = Belts.begin(); it != Belts.end(); ++it) {
			(*it)->update();
		}
	}

	void LONGNOTE::draw() {
		for (auto it = Belts.begin(); it != Belts.end(); ++it) {
			(*it)->draw();
		}
		NOTE::draw();
	}

	void LONGNOTE::setBelts(std::vector<NOTE::NOTE_DATA*> belts) {
		for (auto it = belts.begin(); it != belts.end(); ++it) {
			Belts.emplace_back(new LONGBELT(game()));
			Belts.back()->create();
			Belts.back()->setData(**it);
			Belts.back()->init();
		}
	}
}