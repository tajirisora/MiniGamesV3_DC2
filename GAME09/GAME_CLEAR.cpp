#include "GAME09.h"
#include "GAME_CLEAR.h"
#include "CONTAINER.h"
//#include "RHYTHM_GAME_CONTROLLER.h"
//#include "JUDGEMANAGER.h"
#include "../../libOne/inc/graphic.h"
#include <fstream>
//#include "textFunc.h"

namespace GAME09 {
	GAME_CLEAR::GAME_CLEAR(class GAME* game) :
		SCENE(game) {

	}
	GAME_CLEAR::~GAME_CLEAR() {

	}
	void GAME_CLEAR::create() {
		Result = game()->container()->data().gameClear;
	}
	void GAME_CLEAR::init() {
		//int* result = game()->rgCont()->judgeMNG()->judgeResult();
		//if (result[JUDGEMANAGER::MISS] == 0) {
		//	if (result[JUDGEMANAGER::GREAT] == 0) {
		//		Achievement = ACHIEVEMENT::ALLPERFECT;
		//	}
		//	else {
		//		Achievement = ACHIEVEMENT::FULLCOMBO;
		//	}
		//}
		//else {
		//	Achievement = ACHIEVEMENT::CLEAR;
		//}

		//UpdateHighScore();
	}
	void GAME_CLEAR::UpdateHighScore() {
		//RHYTHM_GAME_CONTROLLER::SONGINFO& songInfo = game()->banner()->curSongInfo();
		//BeforeHighScore = songInfo.highScore;

		//if (!*game()->rgCont()->autoPtr()) {
		//	if (songInfo.highScore < game()->score()->curScore()) {
		//		songInfo.highScore = game()->score()->curScore();
		//	}
		//	if (songInfo.achievement < Achievement) {
		//		songInfo.achievement = Achievement;
		//	}

		//	game()->banner()->updateHighScore(songInfo.highScore, songInfo.achievement);
		//}
	}

	void GAME_CLEAR::update() {

	}
	void GAME_CLEAR::draw() {
		clear(200);
		//RHYTHM_GAME_CONTROLLER::SONGINFO songInfo = game()->rgCont()->getSongInfo();
		////背景
		//game()->back()->draw(songInfo.backImageIdx, songInfo.backImageSize);
		////ジャケット
		//game()->jacket()->draw(songInfo.jacketImageIdx, songInfo.jacketImageSize, Result.jacketPos, Result.jacketSize);
		////リザルト表示する枠
		//rectMode(CENTER);
		//image(Result.frameImg, Result.framePos.x, Result.framePos.y, 0, Result.frameSize);
		////FCとかAPとかの表示
		//game()->achievement()->draw(Achievement);
		////それぞれの判定の数
		//JUDGEMANAGER::JUDGE_DATA* imgs = game()->rgCont()->judgeMNG()->judgeImgs();
		//int* result = game()->rgCont()->judgeMNG()->judgeResult();
		//VECTOR2 imgPos = Result.judgeImgPos;
		//VECTOR2 numPos = Result.judgeNumPos;
		//textSize(Result.judgeNumSize);
		//fill(0);
		//for (int i = 0; i < JUDGEMANAGER::NUM_JUDGE; i++) {
		//	image(imgs[i].img, imgPos.x, imgPos.y, 0, Result.judgeImgSize);
		//	float ofstX = std::to_string(result[i]).size() * Result.judgeNumSize / 2.0f;
		//	text(result[i], numPos.x - ofstX, numPos.y);
		//	imgPos += Result.judgeNextOfst;
		//	numPos += Result.judgeNextOfst;
		//}
		////最大コンボ
		//game()->combo()->draw(game()->rgCont()->judgeMNG()->maxCombo(), Result.maxComboPos, Result.maxComboSize);
		////スコア
		//game()->score()->draw(Result.scorePos, Result.scoreSize);
		////ハイスコア
		//fill(0);
		//VECTOR2 scorePos = Result.highScoreStrPos;
		//textfMode(M_LEFT);
		//textf("High Score", scorePos, Result.highScoreStrSize);
		//textfMode(M_RIGHT);
		//scorePos += Result.highScoreOfst;
		//textf(std::to_string(BeforeHighScore), scorePos, Result.highScoreSize);
		//if (!*game()->rgCont()->autoPtr()) {
		//	textfMode(M_LEFT);
		//	scorePos += Result.highScoreDiffOfst;
		//	int difference = game()->score()->curScore() - BeforeHighScore;
		//	if (difference < 0) {
		//		fill(255, 0, 0);
		//		textf(std::to_string(difference), scorePos, Result.highScoreSize);
		//	}
		//	else {
		//		fill(0, 255, 0);
		//		std::string temp = "+";
		//		temp += std::to_string(difference);
		//		textf(temp, scorePos, Result.highScoreSize);
		//	}
		//}
		////曲名、アーティスト
		//game()->songTitle()->draw(Result.titlePos, Result.titleSize);
		////操作方法
		//image(Result.operationImg, Result.operationPos.x, Result.operationPos.y, 0, Result.operationSize);
		////FAST,SLOWの数
		//int fastNum = game()->rgCont()->judgeMNG()->accuracy()[JUDGEMANAGER::FAST];
		//int slowNum = game()->rgCont()->judgeMNG()->accuracy()[JUDGEMANAGER::SLOW];
		//float ratio;
		//if (fastNum != 0 || slowNum != 0) {
		//	ratio = (float)fastNum / (fastNum + slowNum);
		//}
		//else {
		//	ratio = -1;
		//}
		//image(Result.fastSlowImg, Result.fastSlowPos.x, Result.fastSlowPos.y, 0, Result.fastSlowSize);
		//rectMode(CORNER);
		//noStroke();
		//if (ratio != -1) {
		//	VECTOR2 cornerPos = Result.fastSlowPos + Result.fastSlowGaugeOfst;
		//	fill(Result.fastColor);
		//	rect(cornerPos.x, cornerPos.y, Result.fastSlowGaugeSize.x * ratio, Result.fastSlowGaugeSize.y);
		//	cornerPos.x += Result.fastSlowGaugeSize.x * ratio;
		//	fill(Result.slowColor);
		//	rect(cornerPos.x, cornerPos.y, Result.fastSlowGaugeSize.x * (1 - ratio), Result.fastSlowGaugeSize.y);
		//}
		//fill(0);
		//textfMode(M_LEFT);
		//VECTOR2 FNumPos = Result.fastSlowPos + Result.fastNumOfst;
		//textf(std::to_string(fastNum), FNumPos, Result.fastSlowNumSize);
		//textfMode(M_RIGHT);
		//VECTOR2 SNumPos = Result.fastSlowPos + Result.slowNumOfst;
		//textf(std::to_string(slowNum), SNumPos, Result.fastSlowNumSize);
	}
	void GAME_CLEAR::nextScene() {
		//if (game()->fade()->inEndFlag()) {
		//	if (isTrigger(KEY_ENTER)) {
		//		NextScene = GAME::SELECT_ID;
		//		game()->fade()->outStart();
		//	}
		//	if (isTrigger(KEY_R)) {
		//		NextScene = GAME::STAGE_ID;
		//		game()->fade()->outStart();
		//	}
		//}
		//if (game()->fade()->outEndFlag()) {
		//	game()->changeScene(NextScene);
		//}
	}
}