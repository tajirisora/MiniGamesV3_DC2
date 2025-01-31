#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME11.h"
#include"Player.h"
//一人用を作って二人用を作って仕上げまでしてCPUを作る
namespace GAME11
{
	int GAME::create()
	{
		sync = new DiceSync;
		
		/*p1 = new PLAYER;
		
		p2 = new PLAYER;*/

		State = TITLE;
		char str[100];
		for (int i = 0; i < 6; ++i) {
			sprintf_s(str, "..\\main\\assets\\game11\\dice\\%d.png", i + 1);
			DiceImg[i] = loadImage(str);
		}

		BackImg = loadImage("..\\main\\assets\\game11\\dice\\back.png");
		TitleImg = loadImage("..\\main\\assets\\game11\\dice\\title.png");
		SeatImg = loadImage("..\\main\\assets\\game11\\dice\\seat2.png");
		return 0;

	}

	void GAME::destroy()
	{
		delete sync;
		
		
	}
	void GAME::init() {
		for (int i = 0; i < 6; i++) {
			DicePx[i] = 300.0f + i * 200.0f;
		}
		
		RollCount = 0;
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
	void GAME::Judge(DiceSync* Dsync) {
		for (int i = 0; i < 5; i++) {
			if (sync->dice[i].num == 3);
		}
		
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
					}
				}
				if (isTrigger(KEY_S)) {
					State = INPUT;
					RollFlag = false;
				}
			}
			
			for (int i = 0; i < 5; i++) {

				image(DiceImg[sync->dice[i].rand], DicePx[i] - 100, Height / 2);
				
			}
			
	
		
	}
	void GAME::Input(){

		image(SeatImg, 1500, height/2);
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
		if (isTrigger(KEY_SPACE)) {
			State = PLAY;
		}
	}
	void GAME::Win() {

	}
	void GAME::Lose() {

	}
}
