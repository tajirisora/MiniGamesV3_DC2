#include "CONTAINER.h"
#include "GAME09.h"
#include "LOADSONGS.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"
#include <thread>

namespace GAME09 {
	LOADSONGS::LOADSONGS(class GAME* game) :
		SCENE(game) {

	}
	LOADSONGS::~LOADSONGS() {

	}
	void LOADSONGS::create() {
		//LoadSongs = game()->container()->data().title;
	}
	void LOADSONGS::init() {

	}
	void LOADSONGS::update() {
		bool stopFlag = false;
		// メンバ関数をスレッドで呼び出す際にthisポインタを渡す
		// ChatGPTは神　みんな使おう
		std::thread msg(&LOADSONGS::loadingMsg, this, std::ref(stopFlag));

		//譜面ファイルの読み込み処理
		game()->chartMNG()->loadCharts();
		//std::this_thread::sleep_for(std::chrono::seconds(3));

		//スレッドを止める
		stopFlag = true;
		msg.join();
	}
	void LOADSONGS::loadingMsg(bool& stopFlag) {
		float angle = 0;
		rectMode(CENTER);
		angleMode(DEGREES);
		while (!stopFlag) {
			angle += 1;
			clear();
			fill(100, 100, 100);
			rect(width / 2, height / 2, 200, 200, angle);
			fill(255);
			textSize(100);
			text("NowLoding...", width / 2, height / 2);
			present();
		}
	}
	void LOADSONGS::draw() {
		
	}
	void LOADSONGS::nextScene() {
		//フリーズしてた時間を解除
		setDeltaTime();
		setDeltaTime();
		game()->changeScene(GAME::SELECT_ID);
	}
}