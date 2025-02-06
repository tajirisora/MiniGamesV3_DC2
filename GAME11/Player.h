#include"DICE.h"
#include "../../libOne/inc/libOne.h"
namespace GAME11 {
	class Player
	{
	public:
		Player ();
		~Player();

		void init();

		void reset();
		void yotto();

		int fourdice(DiceSync* sync);

		int fullhouse(DiceSync* sync);

		void straight4();
		void straight5();

		int dice1(DiceSync* sync);
		int dice2(DiceSync* sync);
		int dice3(DiceSync* sync);
		int dice4(DiceSync* sync);
		int dice5(DiceSync* sync);
		int dice6(DiceSync* sync);

		int d1num() { return DiceNum[0]; }
		int d2num() { return DiceNum[1]; }
		int d3num() { return DiceNum[2]; }
		int d4num() { return DiceNum[3]; }
		int d5num() { return DiceNum[4]; }
		int d6num() { return DiceNum[5]; }

	    const int yottonum() { return DiceNum[6]; }

		const int fourdicenum() { return DiceNum[7]; }

		const int fullhousenum() { return DiceNum[8]; }

	    const int st4num() { return DiceNum[9]; }

	    const int st5num() { return DiceNum[10]; }

		const int scorenum() { return ScoreNum; }
		

		void chgflg0();
		void chgflg1();
		void chgflg2();
		void chgflg3();
		void chgflg4();
		void chgflg5();
		void chgflg6();
		void chgflg7();
		void chgflg8();
		void chgflg9();
		void chgflg10();

		
		bool dflag(int i) { return DFlag[i]; }

		void select(int i);

		void total();



	private:
		
		int DiceNum[11] = { 0 },//{0~5] = D1~D6,Flag[6~10]Yotto,FourDice,FullHouse,Staraight4,Staraight5,

			ScoreNum = 0,

			change = 0;

		bool DFlag[11] = { false };

	};
}