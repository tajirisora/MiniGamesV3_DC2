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
		haikeiImg = loadImage("..\\main\\assets\\game00\\haikei.jpg");

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
		clear(11, 195, 54);

		rectMode(CORNER);
		image(haikeiImg,0,0);

		fill(0);
		textSize(200);
		textMode(BCENTER);
		text("ブラックジャック", 250, 540);

		fill(0);
		textSize(50);
		text("クリックしてスタート", 250, 840);
		text("ENTERで戻る", 250, 950);

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
		clear(11, 195, 54);
		image(haikeiImg, 0, 0);
		score = card1 + card2;
		enemyScore = eCard1 + eCard2;
		enemyDrawCount = 2;

		if (enemyScore <= 18) {
			EnemyDraw();
			enemyScore += eCard3;
			enemyDrawCount++;
		}
		if (enemyScore <= 18) {
			EnemyDraw2();
			enemyScore += eCard4;
			enemyDrawCount++;
		}

		DrawEnemyCards();

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
		clear(11, 195, 54);
		image(haikeiImg, 0, 0);
		DrawEnemyCards();
		Draw();
		Draw2();
		
		if (isTrigger(MOUSE_LBUTTON)) {
			State = PLAY3;
			score += card4;
		}
		if (isTrigger(KEY_ENTER)) {
			State = CLEAR;
		}
	}
	void GAME::Play3() {
		clear(11, 195, 54);
		image(haikeiImg, 0, 0);
		DrawEnemyCards();
		Draw();
		Draw2();
		Draw3();
		if (isTrigger(KEY_ENTER)) {
			State = CLEAR;
		}
	}
	void GAME::Draw()
	{
		fill(255, 255, 255);
		textSize(80);
		print("カードは4枚まで引ける");
		print("合計が21に近いほうが勝ち");
		print("カードがそろったらENTER");
		
		textSize(80);
		textMode(BCENTER);
		text("クリックしてカードを引く", 500, 1000);

		rectMode(CORNER);
		fill(255);
		rect(550, 600, 150, 220);
		fill(0);
		textSize(100);
		textMode(BCENTER);
		text(card1, 625, 720);

		rectMode(CORNER);
		fill(255);
		rect(750, 600, 150, 220);
		fill(0);
		textSize(100);
		textMode(BCENTER);
		text(card2, 825, 720);

		rectMode(CORNER);
		fill(255);
		rect(550, 200, 150, 220);
		fill(0);
		textSize(100);
		textMode(BCENTER);
		text(eCard1, 625, 320);

		fill(0);
		textSize(100);
		textMode(BCENTER);
		text(eCard2, 825, 320);

		image(card_backImg, 750, 200);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text("あなたの合計:", 500, 900);
		text(score, 1150, 900);

		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text("相手", 800, 100);

	}
	void GAME::Draw2()
	{
		rectMode(CORNER);
		fill(255);
		rect(950, 600, 150, 220);
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(card3, 1025, 720);
	}
	void GAME::Draw3()
	{
		rectMode(CORNER);
		fill(255);
		rect(1150, 600, 150, 220);
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(card4, 1225, 720);
	}
	void GAME::EnemyDraw()
	{
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(eCard3, 1025, 320);
		image(card_backImg, 950, 200);
	}
	void GAME::EnemyDraw2()
	{
		fill(240, 255, 16);
		textSize(100);
		textMode(BCENTER);
		text(eCard4, 1225, 320);
		image(card_backImg, 1150, 200);
	}
	void GAME::DrawEnemyCards() {
		if (enemyDrawCount >= 1) {

		}
		if (enemyDrawCount >= 2) {
			EnemyDraw();
		}
		if (enemyDrawCount >= 3) {
			EnemyDraw2();
		}
	}
	void GAME::Clear()
	{
		clear(0, 0, 128);

		image(haikeiImg, 0, 0);

		fill(240, 255, 16);
		textSize(300);
		textMode(BCENTER);
		text(score, 500, 500);

		fill(240, 255, 16);
		textSize(300);
		textMode(BCENTER);
		text(enemyScore, 1200, 500);

		fill(255);
		textSize(100);
		textMode(BCENTER);
		text("クリックしてタイトルに戻る",350,900);

		if (score > enemyScore) {
			if (score <= 21) {
				fill(240, 255, 16);
				textSize(200);
				textMode(BCENTER);
				text("勝ち", 800, 740);
			}
			else if (score >= 22) {
				fill(240, 255, 16);
				textSize(200);
				textMode(BCENTER);
				text("負け", 800, 740);

			}
		}
		else if (score < enemyScore) {
			if (enemyScore >= 22) {
				fill(240, 255, 16);
					textSize(100);
				textMode(BCENTER);
				text("勝ち", 800, 740);
			}
			else if (enemyScore <= 21) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("負け", 800, 740);
			}
		}
		else if (score == enemyScore) {
			if (score <= 22) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("引き分け", 800, 740);
			}
			else if (score >= 22) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("どっちも負け", 800, 740);
			}
		}
		else if (score >= 21) {
			if (enemyScore >= 21) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("どっちも負け", 800, 740);
			}
		}
		else if (enemyScore >= 21) {
			if (score >= 21) {
				fill(240, 255, 16);
				textSize(100);
				textMode(BCENTER);
				text("どっちも負け", 800, 740);
			}
		}

		
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}
}
