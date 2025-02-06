#include "Player.h"
namespace GAME11 {
	Player::Player() {}
	Player::~Player() {}

	void Player::init() {
		int DiceNum[11] = { 0 },//{0~5] = D1~D6,Flag[6~10]Yotto,FourDice,FullHouse,Staraight4,Staraight5,

			ScoreNum = 0,

			change = 0;

		bool DFlag[11] = { false };
	}

	void Player::reset() {
		for (int i = 0; i < 10; i++) {
			if (DFlag[i] == false) {
				DiceNum[i] = 0;
			}
		}
	}

	void Player::yotto() {
		if (DFlag[6] == false) {
			for (int i = 0; i < 5; i++) {
				DiceNum[6] = 50;
			}
		}
	}

	int Player::fourdice(DiceSync* sync) {
		if (DFlag[7] == false) {
			DiceNum[7] = sync->dice[0].num * 4;
		}
		return DiceNum[7];
	}


	
	int Player::fullhouse(DiceSync* sync) {
		if (DFlag[8] == false) {

			for (int i = 0; i < 5; i++) {
				DiceNum[8] += sync->dice[i].num;
			}
			return DiceNum[8];
		}
	}

	void Player::straight4() {
		if (DFlag[9] == false) {

			DiceNum[9] = 20;
		}
	}
	void Player::straight5() {
		if (DFlag[10] == false) {

			DiceNum[10] = 30;
		}
	}

	int Player::dice1(DiceSync* sync) {
		if (DFlag[0] == false) {

			for (int i = 0; i < 5; i++) {
				if (sync->dice[i].num == 1) {
					DiceNum[0] += 1;
				}
			}
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
			return DiceNum[5];
		}
	}

	void Player::chgflg0(){
		if (DFlag[0] == false) {
			DFlag[0] = true;
		}
		else DFlag[0] = false;
	}
	void Player::chgflg1(){
		if (DFlag[1] == false) {
			DFlag[1] = true;
		}
		else DFlag[1] = false;
	}
	void Player::chgflg2(){
		if (DFlag[2] == false) {
			DFlag[2] = true;
		}
		else DFlag[2] = false;
	}
	void Player::chgflg3(){
		if (DFlag[3] == false) {
			DFlag[3] = true;
		}
		else DFlag[3] = false;
	}
	void Player::chgflg4(){
		if (DFlag[4] == false) {
			DFlag[4] = true;
		}
		else DFlag[4] = false;
	}
	void Player::chgflg5(){
		if (DFlag[5] == false) {
			DFlag[5] = true;
		}
		else DFlag[5] = false;
	}
	void Player::chgflg6(){
		if (DFlag[6] == false) {
			DFlag[6] = true;
		}
		else DFlag[6] = false;
	}
	void Player::chgflg7(){
		if (DFlag[7] == false) {
			DFlag[7] = true;
		}
		else DFlag[7] = false;
	}
	void Player::chgflg8(){
		if (DFlag[8] == false) {
			DFlag[8] = true;
		}
		else DFlag[8] = false;
	}
	void Player::chgflg9(){
		if (DFlag[9] == false) {
			DFlag[9] = true;
		}
		else DFlag[9] = false;
	}
	void Player::chgflg10(){
		if (DFlag[10] == false) {
			DFlag[10] = true;
		}
		else DFlag[10] = false;
	}


	void Player::select(int i) {
		if (DFlag[i] == true) {
			fill(255, 0, 0);
		}
		else {
			fill(0);
		}
	}

	void Player::total() {
		for (int i = 0; i < 10; i++) {
			ScoreNum += DiceNum[i];
		}
	}
}