#include"GAME14.h"
#include"CONTAINER.h"
#include"LOTTERY.h"
#include "BONUS_ANNOUNCE.h"
namespace GAME14 {
	BONUS_ANNOUNCE::BONUS_ANNOUNCE(GAME* game):
		GAME_OBJECT(game){}
	BONUS_ANNOUNCE::~BONUS_ANNOUNCE(){}
	void BONUS_ANNOUNCE::create(){
		Announce = game()->container()->data().bonus_announce;
	}
	void BONUS_ANNOUNCE::init(){
		CurPlayTimeforBonus = 0;
	}
	void BONUS_ANNOUNCE::draw(){
		textSize(Announce.textSize);
		
		if (CurPlayTimeforBonus >= Announce.announceMaxPlayTime ) {
			fill(Announce.announceColor);

		}
		else {
			fill(Announce.defaltColor);

		}
		text(Announce.announceText, Announce.drawPos.x, Announce.drawPos.y);
		for (int i = 0; i < NUM_BONUS; i++) {
			imageColor(Announce.imgDefaltColor);
			if (i + 1 == game()->lottery()->bonusResult() &&
				(CurPlayTimeforBonus >= Announce.announceMaxPlayTime + Announce.announceBonusTypeTime||
				game()->lottery()->stateBonus())) {
				imageColor(Announce.imgAnnounceColor);
			}
			image(Announce.bonusTypeImg[i], Announce.imgPos[i].x,Announce.imgPos[i].y, 0, Announce.imgSize);
		}
		
		imageColor(255,255,255);

	}

}