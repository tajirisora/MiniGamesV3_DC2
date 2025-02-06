#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME11.h"
//一人用を作って二人用を作って仕上げまでしてCPUを作る
namespace GAME11
{
	int GAME::create()
	{
		sync = new DiceSync;
		
		p1 = new Player;
		
		p2 = new Player;

		State = TITLE;
		char str[100];
		for (int i = 0; i < 6; ++i) {
			sprintf_s(str, "..\\main\\assets\\game11\\dice\\%d.png", i + 1);
			DiceImg[i] = loadImage(str);
		}

		ResultImg = loadImage("..\\main\\assets\\game11\\dice\\result.png");
		BackImg = loadImage("..\\main\\assets\\game11\\dice\\back.png");
		TitleImg = loadImage("..\\main\\assets\\game11\\dice\\title.png");
		SeatImg = loadImage("..\\main\\assets\\game11\\dice\\seat3.png");
		return 0;

	}

	void GAME::destroy()
	{

		delete sync;

		delete p1;

		delete p2;
		
		
	}
	void GAME::init2() {
		YottoCnt = 0,
		FourDiceCnt = 0,
		FullHouseCnt = 0,
		FullHouseCnt2 = 0,
		Staraight4Cnt = 0,			
		Staraight5Cnt = 0,
	

		ClearCnt = 0,

		St5FlgCnt = 0,

		St4FlgCnt = 0;


		RollFlag = false,

		p1->init();
	}
	void GAME::init() {




		for (int i = 0; i < 5; i++) {
			DicePx[i] = 250.0f + i * 200.0f;
			DiceKeyPx[i] = DicePx[i] - 130.0f;
		}
		DicePy = height / 2;
		DiceKeyPy = DicePy - 100.0f;

		ScorePx = 1510;
		TextPx = 1080;


		RollCount = 2;
		RollFlag = false;
	}
	void GAME::proc()
	{
		if (State == TITLE)Title();
		if (State == PLAY)Play();
		if (State == INPUT)Input();
		if (State == RESULT)Result();
		if (State == WIN)Win();
		if (State == LOSE)Lose();

	}
	void GAME::Title() {
		init2();
		textSize(40);
		rectMode(CENTER);
		fill(0);
		image(BackImg, width / 2, height / 2);
		image(TitleImg, width / 2, height / 2);
		if (isTrigger(KEY_SPACE)) {
			clear();
			init();
			State = PLAY;
		}
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}
	void GAME::Judge(DiceSync* sync) {
		for (int i = 0; i < 4; i++) {
			if (sync->dice[i].num == sync->dice[i + 1].num) {
				YottoCnt++;
			}
			if (YottoCnt == 4)
				p1->yotto();
		}

		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				if (sync->dice[i].num == sync->dice[j].num) {
					FourDiceCnt++;
				}
			}
			if (FourDiceCnt >= 6) {
				p1->fourdice(sync);
			}
		}

		FullHouseFlag[0] = true;
		for (int i = 1; i < 5; i++) {
			FullHouseFlag[i] = false;
		}
		for (int i = 0; i < 5; i++) {
			FHFN[i] = 0;
		}

		for (int i = 1; i < 5; i++) {//12212>1  1がTrue, 22 2がFalse
			if (sync->dice[0].num == sync->dice[i].num && FullHouseCnt < 2) {
				FullHouseFlag[i] = true;
				FullHouseCnt++;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (FullHouseFlag[i] == false) {
				FHFN[i] = sync->dice[i].num;
			}
		}	
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				if (FHFN[i] == FHFN[j] && FHFN[i] != FHFN[0] && FullHouseCnt2 < 2) {
					FullHouseCnt2++;
				}
			}
		}
		if (FullHouseCnt + FullHouseCnt2 >= 3) {
			p1->fullhouse(sync);
		}


		if (sync->dice[0].num == sync->dice[1].num + 1 == sync->dice[2].num + 1 == sync->dice[3].num + 1 ||
			sync->dice[1].num == sync->dice[2].num + 1 == sync->dice[3].num + 1 == sync->dice[4].num + 1) {
			p1->straight4();
		}
	
		


		p1->dice1(sync);
		p1->dice2(sync);
		p1->dice3(sync);
		p1->dice4(sync);
		p1->dice5(sync);
		p1->dice6(sync);
		
	}
	void GAME::Countreset() {
		YottoCnt = 0;
		FourDiceCnt = 0;
		FullHouseCnt = 0;
		FullHouseCnt2 = 0;
		Staraight4Cnt = 0;
		Staraight5Cnt = 0;

		State = PLAY;

	}

	void GAME::Flagreset() {
		ClearCnt = 0;
		for (int i = 0; i < 5; i++) {
			sync->dice[i].setflag = false;
		}
		
		for (int i = 0; i < 10; i++) {//全部の役を使っていたらStateをリザルトに変える
			if (p1->dflag(i)) {
				ClearCnt++;
			}
		}
		if (ClearCnt >= 10) {
			p1->total();
			State = RESULT;
		}
	}

	void GAME::Dicelock(int i) {
		if(sync->dice[i].setflag){
			fill(255, 0, 0);
		}
		else {
			fill(0);
		}
	}

	void GAME::Play() {
		hideCursor();
		clear();
		image(BackImg, Width / 2, Height / 2);
		text("R:サイコロを回す",200,900);
		text("ENTER:サイコロを止める", 600, 900);
		text("SPACE:サイコロを振りなおす",300 , 1000);
			if (isTrigger(KEY_R) && RollFlag == false) {
					RollCount--;
					RollFlag = true;
			}
			if (RollFlag) {// = RollFlag == true
				for (int i = 0; i < 5; i++) {
					if (sync->dice[i].setflag == false) {//サイコロが固定化されているか
						sync->dice[i].rand = rand() % 6;
						sync->dice[i].num = sync->dice[i].rand + 1;
					}
				}
			
				if (isTrigger(KEY_ENTER)) {
					RollFlag = false;
					
					Judge(sync);
					State = INPUT;

				}
			}
			
			for (int i = 0; i < 5; i++) {
				image(DiceImg[sync->dice[i].rand], DicePx[i] - 100, DicePy);
			}


			if (isTrigger(KEY_B)) {
				State = TITLE;
			}
	}
	void GAME::Input(){

		image(SeatImg, 1550, height / 2);
		if (RollFlag == false) {
			if (isTrigger(KEY_Y)) {
				if (sync->dice[0].setflag == false) {
					sync->dice[0].setflag = true;
				}
				else sync->dice[0].setflag = false;
			}
			if (isTrigger(KEY_U)) {
				if (sync->dice[1].setflag == false) {
					sync->dice[1].setflag = true;
				}
				else sync->dice[1].setflag = false;
			}
			if (isTrigger(KEY_I)) {
				if (sync->dice[2].setflag == false) {
					sync->dice[2].setflag = true;
				}
				else sync->dice[2].setflag = false;
			}
			if (isTrigger(KEY_O)) {
				if (sync->dice[3].setflag == false) {
					sync->dice[3].setflag = true;
				}
				else sync->dice[3].setflag = false;
			}
			if (isTrigger(KEY_P)) {
				if (sync->dice[4].setflag == false) {
					sync->dice[4].setflag = true;
				}
				else sync->dice[4].setflag = false;
			}
		}
	
		if (p1->dflag(0) == false) {
			if (isTrigger(KEY_A)) {
				p1->reset();
				p1->dice1(sync);

				init();
				Countreset();
				Flagreset();
				p1->chgflg0();
			}
		}
		
		if (p1->dflag(1) == false) {
			if (isTrigger(KEY_S)) {
				p1->reset();
				p1->dice2(sync);

				init();
				Countreset();
				Flagreset();
				p1->chgflg1();
			}
		}

		if (p1->dflag(2) == false) {
			if (isTrigger(KEY_D)) {
				p1->reset();
				p1->dice3(sync);

				init();
				Countreset();
				Flagreset();
				p1->chgflg2();
			}
		}
		if (p1->dflag(3) == false) {
			if (isTrigger(KEY_F)) {
				p1->reset();
				p1->dice4(sync);

				init();
				Countreset();
				Flagreset();
				p1->chgflg3();
			}
		}
		if (p1->dflag(4) == false) {
			if (isTrigger(KEY_G)) {
				p1->reset();
				p1->dice5(sync);

				init();
				Countreset();
				Flagreset();
				p1->chgflg4();
			}
		}
		if (p1->dflag(5) == false) {
			if (isTrigger(KEY_H)) {
				p1->reset();
				p1->dice6(sync);

				init();
				Countreset();
				Flagreset();
				p1->chgflg5();
			}
		}
		if (p1->dflag(6) == false) {//ここから役
			if (isTrigger(KEY_J)) {
				p1->reset();
				if (YottoCnt == 4) {
					p1->yotto();
				}
				init();
				Countreset();
				Flagreset();
				p1->chgflg6();
			}
		}
		if (p1->dflag(7) == false) {
			if (isTrigger(KEY_K)) {
				p1->reset();
				for (int i = 0; i < 5; i++) {
					for (int j = i + 1; j < 5; j++) {
						if (sync->dice[i].num == sync->dice[j].num) {
							FourDiceCnt++;
						}
					}
					if (FourDiceCnt >= 6) {
						p1->fourdice(sync);
					}


				}
				init();
				Countreset();
				Flagreset();
				p1->chgflg7();
			}
		
		}
		if (p1->dflag(8) == false) {
			if (isTrigger(KEY_L)) {
				p1->reset();
				FullHouseFlag[0] = true;
				for (int i = 1; i < 5; i++) {
					FullHouseFlag[i] = false;
				}
				for (int i = 0; i < 5; i++) {
					FHFN[i] = 0;
				}

				for (int i = 1; i < 5; i++) {//12212>1  1がTrue, 22 2がFalse
					if (sync->dice[0].num == sync->dice[i].num && FullHouseCnt < 2) {
						FullHouseFlag[i] = true;
						FullHouseCnt++;
					}
				}
				for (int i = 0; i < 5; i++) {
					if (FullHouseFlag[i] == false) {
						FHFN[i] = sync->dice[i].num;
					}
				}
				for (int i = 0; i < 5; i++) {
					for (int j = i + 1; j < 5; j++) {
						if (FHFN[i] == FHFN[j] && FHFN[i] != FHFN[0] && FullHouseCnt2 < 2) {
							FullHouseCnt2++;
						}
					}
				}
				if (FullHouseCnt + FullHouseCnt2 >= 3) {
					p1->fullhouse(sync);
				}

				init();
				Countreset();
				Flagreset();
				p1->chgflg8();
			}
		}
		if (p1->dflag(9) == false) {
			if (isTrigger(KEY_Z)) {
				p1->reset();
				//p1->straight4();

				init();
				Countreset();
				Flagreset();
				p1->chgflg9();
			}
		}
		if (p1->dflag(10) == false) {
			if (isTrigger(KEY_X)) {
				p1->reset();
				//p1->straight5();

				init();
				Countreset();
				Flagreset();
				p1->chgflg10();
			}
		}

		if (RollCount > 0) {
			if (isTrigger(KEY_SPACE)) {
				p1->reset();
				Countreset();
			}
		}
		
		p1->select(0);
		text(p1->d1num(), ScorePx, 90);
		p1->select(1);
		text(p1->d2num(), ScorePx, 185);
		p1->select(2);
		text(p1->d3num(), ScorePx, 280);
		p1->select(3);
		text(p1->d4num(), ScorePx, 375);
		p1->select(4);
		text(p1->d5num(), ScorePx, 470);
		p1->select(5);
		text(p1->d6num(), ScorePx, 570);
		p1->select(6);
		text(p1->yottonum(), ScorePx, 660);
		p1->select(7);
		text(p1->fourdicenum(), ScorePx, 750);
		p1->select(8);
		text(p1->fullhousenum(), ScorePx, 845);
		p1->select(9);
		text(p1->st4num(), ScorePx, 940);
		p1->select(10);
		text(p1->st5num(), ScorePx, 1030);
		fill(0);


		text("(A)", TextPx, 90);
		text("(S)", TextPx, 185);
		text("(D)", TextPx, 280);
		text("(F)", TextPx, 375);
		text("(G)", TextPx, 470);
		text("(H)", TextPx, 570);
		text("(J)", TextPx, 660);
		text("(K)", TextPx, 750);
		text("(L)", TextPx, 845);
		text("(Z)", TextPx, 940);
		text("(X)", TextPx, 1030);

		Dicelock(0);
		text("(Y)", DiceKeyPx[0], DiceKeyPy);
		Dicelock(1);
		text("(U)", DiceKeyPx[1], DiceKeyPy);
		Dicelock(2);
		text("(I)", DiceKeyPx[2], DiceKeyPy);
		Dicelock(3);
		text("(O)", DiceKeyPx[3], DiceKeyPy);
		Dicelock(4);
		text("(P)", DiceKeyPx[4], DiceKeyPy);
		fill(0);
	

		if (isTrigger(KEY_SPACE)) {
			YottoCnt = 0;
			FourDiceCnt = 0;
			FullHouseCnt = 0;
			FullHouseCnt2 = 0;
			Staraight4Cnt = 0;
			Staraight5Cnt = 0;
			if (RollCount > 0) {
				State = PLAY;
			}
			else if (RollCount <= 0) {
				init();
			}
		}
	}


	void GAME::Result(){
		
		clear(255);
		image(ResultImg, 300, height / 2);
		textSize(150);
		text(p1->scorenum(), width / 2 - 100, height / 2);
		text("RESULT", width / 2 - 300, height / 2 - 300);
		text("SPACE:タイトルに戻る", 200, 800);
		if (isTrigger(KEY_SPACE)) {
			State = TITLE;
		}
		}
	void GAME::Win() {
		clear();
		State = TITLE;
	}
	void GAME::Lose() {

	}
}
