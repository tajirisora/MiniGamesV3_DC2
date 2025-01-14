#include "PLAYER.h"
namespace GAME11 {
	void PLAYER::yotto() {
		YottoNum = 50;
	}
	
	int PLAYER::fourdice(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			FourDiceNum += sync->dice[i].num;
		}
		return FourDiceNum;
	}
	
	int PLAYER::fullhouse(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			FullHouseNum += sync->dice[i].num;
		}
		return FullHouseNum;
	}

	void PLAYER::straight4() {
		Straight4Num = 20;
	}
	void PLAYER::straight5() {
		Straight5Num = 30;
	}

	int PLAYER::dice1(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			if (sync->dice[i].num == 1) {
				D1Num += 1;
			}
		}
		return D1Num;
	}
	int PLAYER::dice2(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			if (sync->dice[i].num == 2) {
				D2Num += 2;
			}
		}
		return D2Num;
	}
	int PLAYER::dice3(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			if (sync->dice[i].num == 3) {
				D3Num += 3;
			}
		}
		return D3Num;
	}
	int PLAYER::dice4(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			if (sync->dice[i].num == 4) {
				D4Num += 4;
			}
		}
		return D4Num;
	}
	int PLAYER::dice5(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			if (sync->dice[i].num == 5) {
				D5Num += 5;
			}
		}
		return D5Num;
	}
	int PLAYER::dice6(DiceSync* sync) {
		for (int i = 0; i < 5; i++) {
			if (sync->dice[i].num == 6) {
				D6Num += 6;
			}
		}
		return D6Num;
	}
}