#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include<time.h>
#include<cstdlib>
#include "GAME00.h"

namespace GAME00
{
	int GAME::create()
	{
		card_backImg = loadImage("..\\main\\assets\\game00\\card_back.png");

		return 0;
	}

	void GAME::destroy()
	{
	}

	void GAME::proc()
	{
		if (State == TITLE)Titel();
		else if (State == PLAY)Play();
		else if (State == PLAY2)Play2();
		else if (State == PLAY3)Play3();
		else if (State == CLEAR)Clear();
	}
	void GAME::Titel()
	{
		clear(0, 0, 128);
		fill(255, 255, 255);
		textSize(80);
		print("タイトル");
		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			State = PLAY;
			return;
		}
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::Init()
	{
		card1 = random() % 10 + 1;
		card2 = random() % 10 + 1;
		card3 = random() % 10 + 1;
		card4 = random() % 10 + 1;

		eCard1 = random() % 10 + 1;
		eCard2 = random() % 10 + 1;
		eCard3 = random() % 10 + 1;
		eCard4 = random() % 10 + 1;
	}
	void GAME::Play()
	{
		clear(0, 0, 128);
		fill(255, 255, 255);
		textSize(80);
		print("プレイ");

		score = card1 + card2;
		enemyScore = eCard1 + eCard2;

		if (enemyScore <= 18) {
			EnemyDraw();
			enemyScore += eCard3;
		}
		if (isTrigger(MOUSE_LBUTTON)) {
			State = PLAY2;
			score += card3;
		};
		Draw();

		if (isTrigger(KEY_ENTER)) {
			State = CLEAR;
		}
	}
	void GAME::Play2() {
		clear(0, 0, 128);
		Draw();
		Draw2();
		EnemyDraw();
		if (enemyScore <= 18) {
			enemyScore += eCard4;
			EnemyDraw2();
		}
		if (isTrigger(MOUSE_LBUTTON)) {
			State = PLAY3;
			score += card4;
		}
		if (isTrigger(KEY_ENTER)) {
			State = CLEAR;
		}
	}
	void GAME::Play3() {
		clear(0, 0, 128);
		Draw();
		Draw2();
		Draw3();
		EnemyDraw();
		EnemyDraw2();
		if (isTrigger(KEY_ENTER)) {
			State = CLEAR;
		}
	}
	void GAME::Draw()
	{
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(card1, 500, 600);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(card2, 650, 600);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(eCard1, 500, 200);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(eCard2, 650, 200);

		//image(card_backImg, 650, 200);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(score, 600, 800);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(enemyScore, 600, 100);

	}
	void GAME::Draw2()
	{
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(card3, 750, 600);
	}
	void GAME::Draw3()
	{
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(card4, 850, 600);
	}
	void GAME::EnemyDraw()
	{
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(eCard3, 750, 200);
		//image(card_backImg, 750, 200);
	}
	void GAME::EnemyDraw2()
	{
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(eCard4, 850, 200);
		//image(card_backImg, 850, 200);
	}
	void GAME::Clear()
	{
		clear(0, 0, 128);
		fill(255, 255, 255);
		textSize(80);
		print("クリア");

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(score, 500, 300);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(enemyScore, 700, 300);
		if (score > enemyScore) {
			if (score <= 21) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("君の勝ち", 500, 540);
			}
			else if (score >= 22) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("君の負け", 500, 540);

			}
		}
		else if (score < enemyScore) {
			if (enemyScore >= 22) {
				fill(240, 255, 16);
					textSize(100);
				textMode(BCENTER);
				text("君の勝ち", 500, 540);
			}
			else if (enemyScore <= 21) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("君の負け", 500, 540);
			}
		}
		else if (score == enemyScore) {
			if (score <= 22) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("引き分け", 500, 540);
			}
			else if (score >= 22) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("どっちも負け", 500, 540);
			}
		}
		else if (score >= 21) {
			if (enemyScore >= 21) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("どっちも負け", 500, 540);
			}
		}
		else if (enemyScore >= 21) {
			if (score >= 21) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("どっちも負け", 500, 540);
			}
		}
		
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}
}
