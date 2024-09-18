#include "RHYTHM_GAME_CONTROLLER.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/rand.h"
#include "myFunc.h"

//#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)

namespace GAME09 {
	RHYTHM_GAME_CONTROLLER::RHYTHM_GAME_CONTROLLER(GAME* game) :
		GAME_OBJECT(game) {

	}

	RHYTHM_GAME_CONTROLLER::~RHYTHM_GAME_CONTROLLER() {

	}

	void RHYTHM_GAME_CONTROLLER::create() {
		RGCont = game()->container()->data().rgCont;
	}

	void RHYTHM_GAME_CONTROLLER::init() {
		State = DETAIL_VIEW;
		Finish = false;
		AnimeTime = 0;
		TempTime = 0;
		CurTime = -RGCont.BeforePlayTime;
		TempVisualBeat = 0;
		VisualBeat = 0;
	}

	void RHYTHM_GAME_CONTROLLER::update() {
		if (State != DETAIL_VIEW) {
			CurTime += delta;
		}

		if (State == DETAIL_VIEW) {
			AnimeTime += delta;
			if (AnimeTime > RGCont.detailViewTime) {
				State = BEFORE_PLAY;
				AnimeTime = 0;
			}
		}
		else if (State == BEFORE_PLAY) {
			AnimeTime += delta;
			if (AnimeTime > RGCont.detailViewDisappearTime) {
				AnimeTime = RGCont.detailViewDisappearTime;
			}
			if (CurTime > 0) {
				CurTime = 0;
				//Sound->playMusic(SongInfo.musicIdx);
				State = PLAY;
			}
		}
		else if (State == PLAY) {
			//for (auto it = ChangeDatas.begin(); it != ChangeDatas.end();) {
			//	if ((*it).time < CurTime) {
			//		TempTime = (*it).time;
			//		TempVisualBeat = (*it).visualBeat;
			//		BPM = (*it).bpm;
			//		Measure = (*it).measure;
			//		it = ChangeDatas.erase(it);
			//	}
			//	else {
			//		it++;
			//	}
			//}
			if (CurTime > EndTime) {
				State = AFTER_PLAY;
			}
		}
		else if (State == AFTER_PLAY) {
			if (CurTime > EndTime + 2) {
				Finish = true;
				//Sound->stopMusic();
			}
		}
		else {

		}

		float beatTime = 60.0f / BPM;// / (Measure.y / 4);
		VisualBeat = TempVisualBeat + (CurTime - TempTime) / beatTime;
	}

	void RHYTHM_GAME_CONTROLLER::draw() {
		//‹È‚ÌÚ×‚ð•\Ž¦
		//if (State == DETAIL_VIEW) {
		//	game()->detail()->draw();
		//}
		//else if (State == BEFORE_PLAY) {
		//	float ratio = 1.0f - AnimeTime / RGCont.detailViewDisappearTime;
		//	game()->detail()->draw(ratio);
		//}
	}
}