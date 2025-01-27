#include "SONGTITLE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "textFunc.h"

namespace GAME09 {
	SONGTITLE::SONGTITLE(GAME* game) :
		GAME_OBJECT(game) {
	}
	SONGTITLE::~SONGTITLE() {
	}

	void SONGTITLE::create() {
		SongTitle = game()->container()->data().songTitle;
	}

	void SONGTITLE::init() {

	}

	void SONGTITLE::update() {

	}

	void SONGTITLE::draw(SONGINFO& songInfo, VECTOR2 pos, float size) {
		//背景
		image(SongTitle.bannerImg, pos.x, pos.y, 0, SongTitle.bannerImgSize * size);
		//フレーム
		VECTOR2 framePos = pos + SongTitle.difficultyFrameOfst * size;
		imageColor(game()->difficultySelect()->getColor());
		image(SongTitle.difficultyFrameImg, framePos.x,
			framePos.y, 0, SongTitle.difficultyFrameImgSize * size);
		imageColor(255);
		//難易度
		framePos.y += SongTitle.numStrSize.y / 2;
		font("ＭＳ 明朝");
		textfMode(M_CENTER);
		textfStrokeSize(2);
		fill(0);
		textfStroke(std::to_string(songInfo.difficulty[game()->difficultySelect()->curDifficulty()]),
			framePos, SongTitle.numStrSize);
		fill(255);
		textf(std::to_string(songInfo.difficulty[game()->difficultySelect()->curDifficulty()]),
			framePos, SongTitle.numStrSize);
		font("Arial");
		//タイトル
		fill(0);
		textfMode(M_LEFT);
		VECTOR2 textPos = pos + SongTitle.titlePosOfst * size;
		textf(songInfo.title, textPos, SongTitle.titleStrSize * size);
		//アーティスト
		textPos = pos + SongTitle.artistPosOfst * size;
		textf(songInfo.artist, textPos, SongTitle.artistStrSize * size);
	}
}