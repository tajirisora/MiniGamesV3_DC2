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
	void GAME::init() {
		for (int i = 0; i < 6; i++) {
			DicePx[i] = 300.0f + i * 200.0f;
		}
		
		RollCount = 2;
		RollFlag = false;
	}
	void GAME::proc()
	{
		if (State == TITLE)Title();
		if (State == PLAY)Play();
		if (State == INPUT)Input();
	}
	void GAME::Title() {
		rectMode(CENTER);
		image(BackImg, width / 2, height / 2);
		image(TitleImg, width / 2, height / 2);
		if (isTrigger(KEY_SPACE)) {
			clear();
			init();

			State = PLAY;
		}

	}
	void GAME::Judge(DiceSync * sync) {
		for (int i = 0; i < 4; i++) {
			if (sync->dice[i].num == sync->dice[i + 1].num) {
				YottoCnt++;
			}
			if (YottoCnt == 4)
				
				p1->yotto();
		}
		for (int i = 0; i < 4; i++) {
			if (sync->dice[i].num == sync->dice[i + 1].num) {
				FourDiceCnt++;
			}
			if (FourDiceCnt >= 3)
				p1->fourdice(sync);
		}

		p1->fullhouse(sync);

		for (int i = 0; i < 4; i++) {
			if (sync->dice[i].num == sync->dice[i + 1].num + 1) {
				Staraight4Cnt++;
			}
			if (Staraight4Cnt >= 3) {
				p1->straight4();
			}
		}
		for (int i = 0; i < 4; i++) {
			if (sync->dice[i].num == sync->dice[i + 1].num + 1) {
				Staraight5Cnt++;
			}
			if (Staraight5Cnt >= 4) {
				p1->straight5();
			}
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
		Staraight4Cnt = 0;
		Staraight5Cnt = 0;

		State = PLAY;
	}
	void GAME::Play() {
		hideCursor();
		image(BackImg, Width / 2, Height / 2);

			if (isTrigger(KEY_R) && RollFlag == false) {
					RollCount--;
					RollFlag = true;
			}
			if (RollFlag == true) {
				for (int i = 0; i < 5; i++) {
					if (sync->dice[i].setflag == false) {
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

				image(DiceImg[sync->dice[i].rand], DicePx[i] - 100, height / 2);
				
			}



			if (isTrigger(KEY_B)) {
				State = TITLE;
			}
	}
	void GAME::Input(){

		image(SeatImg, 1550, height / 2);
		if (RollFlag == false && RollCount <= 1) {
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
		

		if (isTrigger(KEY_A)) {
			p1->reset();
			p1->dice1(sync);

			init();
			Countreset();
		}
		if (isTrigger(KEY_S)) {
			p1->reset();
			p1->dice2(sync);

			init();
			Countreset();
		}
		if (isTrigger(KEY_D)) {
			p1->reset();
			p1->dice3(sync);

			init();
			Countreset();
		}
		if (isTrigger(KEY_F)) {
			p1->reset();
			p1->dice4(sync);

			init();
			Countreset();
		}
		if (isTrigger(KEY_G)) {
			p1->reset();
			p1->dice5(sync);

			init();
			Countreset();
		}
		if (isTrigger(KEY_H)) {
			p1->reset();
			p1->dice6(sync);
			
			init();
			Countreset();
		}
		if (isTrigger(KEY_J)) {
			p1->reset();
			p1->yotto();

			init();
			Countreset();
		}
		if (isTrigger(KEY_K)) {
			p1->reset();
			p1->fourdice(sync);

			init();
			Countreset();
		}
		if (isTrigger(KEY_L)) {
			p1->reset();
			p1->fullhouse(sync);

			init();
			Countreset();
		}
		if (isTrigger(KEY_Z)) {
			p1->reset();
			p1->straight4();
			
			init();
			Countreset();
		}
		if (isTrigger(KEY_X)) {
			p1->reset();
			p1->straight5();

			init();
			Countreset();
		}

		if (RollCount > 0) {
			if (isTrigger(KEY_SPACE)) {
				p1->reset();
				Countreset();
			}
		}
		
		text(p1->d1num(), 1510, 90);
		text(p1->d2num(), 1510, 185);
		text(p1->d3num(), 1510, 280);
		text(p1->d4num(), 1510, 375);
		text(p1->d5num(), 1510, 470);
		text(p1->d6num(), 1510, 570);
		text(p1->yottonum(), 1510, 660);
		text(p1->fourdicenum(), 1510, 750);
		text(p1->fullhousenum(), 1510, 845);
		text(p1->st4num(), 1510, 940);
		text(p1->st5num(),1510 ,1030 );
		


		for (int i = 0; i < 5; i++) {
			p1->sort(sync);
			text(sync->dice[i].num, 100.0, 100.0 + 100.0 * i);
		}
		text(p1->yottonum(), 500, 200);

		if (isTrigger(KEY_SPACE)) {
			YottoCnt = 0;
			FourDiceCnt = 0;
			FullHouseCnt = 0;
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
	void GAME::Win() {

	}
	void GAME::Lose() {

	}
}
