#pragma once
namespace GAME05 {
	struct PlayingCard {
		int num;
		char suit;
		int img;
	};
	struct Card {
		PlayingCard CARD[52];
	};
}