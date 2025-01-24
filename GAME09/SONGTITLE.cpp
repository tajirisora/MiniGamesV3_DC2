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
		image(SongTitle.bannerImg, pos.x, pos.y, 0, SongTitle.bannerImgSize * size);
		imageColor(game()->difficultySelect()->getColor());
		image(SongTitle.difficultyFrameImg, pos.x + SongTitle.difficultyFrameOfst.x * size,
			pos.y + SongTitle.difficultyFrameOfst.y * size, 0, SongTitle.difficultyFrameImgSize * size);
		imageColor(255);
		fill(0);
		textfMode(M_LEFT);
		VECTOR2 textPos = pos + SongTitle.titlePosOfst * size;
		textf(songInfo.title, textPos, SongTitle.titleStrSize * size);
		textPos = pos + SongTitle.artistPosOfst * size;
		textf(songInfo.artist, textPos, SongTitle.artistStrSize * size);
	}
}