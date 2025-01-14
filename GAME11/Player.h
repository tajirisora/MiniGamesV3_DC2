#include "GAME11.h"
#include"DICE.h"
namespace GAME11 {
	class PLAYER
	{
	public:
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
	private:
		int D1Num = 0,
			D2Num = 0,
			D3Num = 0,
			D4Num = 0,
			D5Num = 0,
			D6Num = 0,
			FourDiceNum = 0,
			FullHouseNum = 0,
			Straight4Num = 0,
			Straight5Num = 0,
			YottoNum = 0,
			ScoreNum = 0;


	};
}