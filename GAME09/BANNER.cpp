#include "BANNER.h"
#include "GAME09.h"
#include "CONTAINER.h"
//#include "RHYTHM_GAME_CONTROLLER.h"
#include "CHARTMANAGER.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "textFunc.h"

namespace GAME09 {
	BANNER::BANNER(GAME* game) :
		GAME_OBJECT(game) {
	}

	BANNER::~BANNER() {

	}

	void BANNER::create() {
		Banner = game()->container()->data().banner;
		CurNum = 0;
		BackGroundImageNum = CurNum;
	}

	void BANNER::init() {
		PlayDemoMusic = true;
	}

	void BANNER::update() {
		if (AnimeFlag) {
			float ratio = AnimeTime / Banner.moveAnimeTime;
			AnimeNum = CurNum + MoveNum * ratio;
			AnimeTime += delta;
			if (AnimeTime > Banner.moveAnimeTime) {
				CurNum = (CurNum + MoveNum + game()->songs().size()) % game()->songs().size();
				if (isPress(KEY_DOWN)) {
					AnimeTime -= Banner.moveAnimeTime;
					MoveNum = 1;
				}
				else if (isPress(KEY_UP)) {
					AnimeTime -= Banner.moveAnimeTime;
					MoveNum = -1;
				}
				else {
					AnimeFlag = false;
					PlayDemoMusic = true;
					AnimeNum = CurNum;
					BackGroundImageNum = CurNum;
				}
			}
		}
		else {
			if (PlayDemoMusic) {
				//game()->rgCont()->soundMNG()->playMusic(Songs[CurNum].musicIdx);
				PlayDemoMusic = false;
			}
			if (isPress(KEY_DOWN)) {
				AnimeFlag = true;
				AnimeTime = 0;
				MoveNum = 1;
			}
			else if (isPress(KEY_UP)) {
				AnimeFlag = true;
				AnimeTime = 0;
				MoveNum = -1;
			}
		}
	}

	void BANNER::draw() {
		rectMode(CENTER);
		//image(Banner.backImg, Banner.centerPos.x, Banner.centerPos.y, 0, Banner.imgSize);
		const int drawBannerNum = 9;
		const int startBannerIdx = Round(AnimeNum) - (drawBannerNum / 2);
		for (int i = 0; i < drawBannerNum; i++) {
			float dist = startBannerIdx + i - AnimeNum;
			int bannerNum = (startBannerIdx + i) % game()->songs().size();
			if (bannerNum < 0) bannerNum += game()->songs().size();

			VECTOR2 pos = Banner.centerPos;
			if (dist < 0) {
				pos.x -= Banner.nextPosOfst.x * dist;
				pos.y += Banner.nextPosOfst.y * dist;
			}
			else {
				pos += Banner.nextPosOfst * dist;
			}
			//image(Banner.bannerImg, pos.x, pos.y, 0, Banner.imgSize);
			fill(255);
			rect(pos.x, pos.y, 600, 120);
			fill(255,0,0);
			rect(pos.x - 300, pos.y, 100, 100, 45);
			fill(0);
			textfMode(M_LEFT);
			VECTOR2 textPos = pos + Banner.titlePosOfst;
			textf(game()->songs()[bannerNum].title, textPos, Banner.titleStrSize);
			textPos = pos + Banner.artistPosOfst;
			textf(game()->songs()[bannerNum].artist, textPos, Banner.artistStrSize);
		}
	}

}