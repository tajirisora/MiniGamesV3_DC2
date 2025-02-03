#include"DICE.h"
namespace GAME11 {
	class Player
	{
	public:
		Player ();
		~Player();

		
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

	    int yottonum() { return DiceNum[6]; }

		int fourdicenum() { return DiceNum[7]; }

		int fullhousenum() { return DiceNum[8]; }

	    int st4num() { return DiceNum[9]; }

	    int st5num() { return DiceNum[10]; }

		void sort(DiceSync* sync) {
			int change = 0;
			for (int i = 0; i < 5 - 1; i++) {  // ”z—ñ‚Ì’·‚³-1‰ñ‚Ìƒ‹[ƒv
				for (int j = 0; j < 5 - 1 - i; j++) {  // —×Ú‚·‚é—v‘f‚ð”äŠr
					if (sync->dice[j].num > sync->dice[j + 1].num) {
						// —v‘f‚ðŒðŠ·
						change = sync->dice[j].num;
						sync->dice[j].num = sync->dice[j + 1].num;
						sync->dice[j + 1].num = change;
					}
				}
			}
		}


		void ChgFlg0();
		void ChgFlg1();
		void ChgFlg2();
		void ChgFlg3();
		void ChgFlg4();
		void ChgFlg5();
		void ChgFlg6();
		void ChgFlg7();
		void ChgFlg8();
		void ChgFlg9();
		void ChgFlg10();



	private:
		
		int DiceNum[11] = {0},//{0~5] = D1~D6,Flag[6~10]Yotto,FourDice,FullHouse,Staraight4,Staraight5,

			ScoreNum = 0,
			
			Sort[5] = {0};

		bool DFlag[11] = { false };

	};
}