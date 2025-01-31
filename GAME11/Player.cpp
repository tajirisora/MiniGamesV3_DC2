#include "Player.h"
namespace GAME11 {
	Player::Player(){}
	Player::~Player(){}


	
	void Player::reset() {
		for (int i = 0; i < 10; i++) {
			if (DFlag[i] == false) {
				DiceNum[i] = 0;
			}
		}
	}

	void Player::yotto() {
		if (DFlag[6] == false) {
			DiceNum[6] = 50;
			DFlag[6] = true;
		}
	}
	
	int Player::fourdice(DiceSync* sync) {
		if (DFlag[7] == false) {
			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == sync->dice[i + 1].num) {
					DiceNum[7] += sync->dice[i].num;
				}
			}
			DFlag[7] = true;
			return DiceNum[7];
		}
	
	}
	
	int Player::fullhouse(DiceSync* sync) {
		if (DFlag[8] == false) {

			for (int i = 0; i < 5; i++) {
				DiceNum[8] += sync->dice[i].num;
			}
			DFlag[8] = true;
			return DiceNum[8];
		}
	}

	void Player::straight4() {
		if (DFlag[9] == false) {

			DiceNum[9] = 20;
			DFlag[9] = true;
		}
	}
	void Player::straight5() {
		if (DFlag[10] == false) {

			DiceNum[10] = 30;
			DFlag[10] = true;
		}
	}

	int Player::dice1(DiceSync* sync) {
		if (DFlag[0] == false) {

			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == 1) {
					DiceNum[0] += 1;
				}
			}
			DFlag[0] = true;
			return DiceNum[0];
		}
	}
	int Player::dice2(DiceSync* sync) {
		if (DFlag[1] == false) {
			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == 2) {
					DiceNum[1] += 2;
				}
			}
			DFlag[1] = true;
			return DiceNum[1];
		}
	}
	int Player::dice3(DiceSync* sync) {
		if (DFlag[2] == false) {

			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == 3) {
					DiceNum[2] += 3;
				}
			}

			DFlag[2] = true;
			return DiceNum[2];
		}
	}
	int Player::dice4(DiceSync* sync) {
		if (DFlag[3] == false) {

			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == 4) {
					DiceNum[3] += 4;
				}
			}
			DFlag[3] = true;
			return DiceNum[3];
		}
	}
	int Player::dice5(DiceSync* sync) {
		if (DFlag[4] == false) {

			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == 5) {
					DiceNum[4] += 5;
				}
			}
			DFlag[4] = true;
			return DiceNum[4];
		}
	}
	int Player::dice6(DiceSync* sync) {
		if (DFlag[5] == false) {

			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == 6) {
					DiceNum[5] += 6;
				}
			}
			DFlag[5] = true;
			return DiceNum[5];
		}
	}

	void Player::ChgFlg0(){
		if (DFlag[0] == false) {
			DFlag[0] = true;
		}
		else DFlag[0] = false;
	}
	void Player::ChgFlg1(){}
	void Player::ChgFlg2(){}
	void Player::ChgFlg3(){}
	void Player::ChgFlg4(){}
	void Player::ChgFlg5(){}
	void Player::ChgFlg6(){}
	void Player::ChgFlg7(){}
	void Player::ChgFlg8(){}
	void Player::ChgFlg9(){}
	void Player::ChgFlg10(){}


}