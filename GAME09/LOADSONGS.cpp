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
		LoadSongs = game()->container()->data().loadSongs;
	}
	void LOADSONGS::init() {

	}
	void LOADSONGS::update() {
		bool stopFlag = false;
		NumSongs = game()->chartMNG()->cntSongs();
		CurLoad = 0;
		// メンバ関数をスレッドで呼び出す際にthisポインタを渡す
		// ChatGPTは神　みんな使おう
		std::thread msg(&LOADSONGS::loadingMsg, this, std::ref(stopFlag));

		//譜面ファイルの読み込み処理
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
		game()->chartMNG()->loadCharts(CurLoad);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		//スレッドを止める
		stopFlag = true;
		msg.join();
	}
	void LOADSONGS::loadingMsg(bool& stopFlag) {
		rectMode(CENTER);
		while (!stopFlag) {
			clear();

			int percent = (CurLoad * 100) / NumSongs;
			char str[128];
			sprintf_s(str, 128, "%3d％", percent);

			textSize(LoadSongs.msgSize);
			fill(255);
			text("NowLoding...", LoadSongs.msgPos.x, LoadSongs.msgPos.y);
			text(str, LoadSongs.percentPos.x, LoadSongs.percentPos.y);
			fill(100);
			rect(LoadSongs.barPos.x, LoadSongs.barPos.y, LoadSongs.barSize.x, LoadSongs.barSize.y);
			fill(0, 200, 255);
			rect(LoadSongs.barPos.x - LoadSongs.barSize.x / 200 * (100 - percent), LoadSongs.barPos.y, 
				LoadSongs.barSize.x / 100 * percent, LoadSongs.barSize.y);
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