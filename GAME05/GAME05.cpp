#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include"GAME05.h"
#include"TRAMP.h"
#include "../../libOne/inc/graphic.h"
#include"time.h"
namespace GAME05
{
	int GAME::create()
	{
		deck = new Card;

		char str[100];
		for (int i = 0; i <= 12; ++i) {
			sprintf_s(str, "..\\main\\assets\\game05\\TRAMP\\D%d.png", i + 1);
			DaiyaImg[i] = loadImage(str);
			sprintf_s(str, "..\\main\\assets\\game05\\TRAMP\\H%d.png", i + 1);
			HeartImg[i] = loadImage(str);
			sprintf_s(str, "..\\main\\assets\\game05\\TRAMP\\C%d.png", i + 1);
			CloverImg[i] = loadImage(str);
			sprintf_s(str, "..\\main\\assets\\game05\\TRAMP\\S%d.png", i + 1);
			SpadeImg[i] = loadImage(str);
		}

		HaimenImg = loadImage("..\\main\\assets\\game05\\haimen.png");
		TrampImg = loadImage("..\\main\\assets\\game05\\tramp.png");
		ChipImg = loadImage("..\\main\\assets\\game05\\chip.png");
		Chip_2Img = loadImage("..\\main\\assets\\game05\\chip_2.png");
		TamagoImg = loadImage("..\\main\\assets\\game05\\tamago.png");
		Egg1Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg2Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg3Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg4Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg5Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg6Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg7Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg8Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg9Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg10Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		Egg11Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
		WhiteImg = loadImage("..\\main\\assets\\game05\\white.png");
		GachaImg = loadImage("..\\main\\assets\\game05\\gacha.png");
		WinImg = loadImage("..\\main\\assets\\game05\\win.png");

		DrawSnd = loadSound("..\\main\\assets\\game05\\draw.wav");
		WinSnd = loadSound("..\\main\\assets\\game05\\ジャジャーン.wav");
		straightWinSnd = loadSound("..\\main\\assets\\game05\\win.wav");
		LoseSnd = loadSound("..\\main\\assets\\game05\\lose.wav");
		BackSnd = loadSound("..\\main\\assets\\game05\\back.wav");
		PakaSnd = loadSound("..\\main\\assets\\game05\\パカ.wav");
		KakuteiSnd = loadSound("..\\main\\assets\\game05\\シャキーン.wav");
		GetSnd = loadSound("..\\main\\assets\\game05\\金額表示.wav");

		return 0;
	}

	void GAME::proc()
	{
		if (State == TITLE)Title();
		else if (State == CHANGEBETCOIN)ChangeBetCoin();
		else if (State == JOB)Job();
		else if (State == RULE)Rule();
		else if (State == PLAY)Play(deck);
		else if (State == SHOW)Show();
		else if (State == WIN)Win();
		else if (State == STRAIGHTWIN)StraightWin();
		else if (State == LOSE)Lose();
		else if (State == DRAW)Draw();
		else if (State == GACHA)Gacha();
		else if (State == RESULT)Result();
		else if (State == RESULT2)Result2();
		else if (State == BOX)Box();
		else if (State == PROB)Prob();
	}

	void GAME::destroy() {
		if (deck != nullptr) {
			delete deck;
			deck = nullptr;
		}
	}

	void GAME::initialCards(Card* deck)
	{
		int index = 0;
		for (int number = 1; number <= 13; ++number) {
			deck->CARD[index].num = number;
			deck->CARD[index].suit = 'H';
			deck->CARD[index].img = HeartImg[number - 1];
			++index;
		}
		for (int number = 1; number <= 13; ++number) {
			deck->CARD[index].num = number;
			deck->CARD[index].suit = 'D';
			deck->CARD[index].img = DaiyaImg[number - 1];
			++index;
		}
		for (int number = 1; number <= 13; ++number) {
			deck->CARD[index].num = number;
			deck->CARD[index].suit = 'S';
			deck->CARD[index].img = SpadeImg[number - 1];
			++index;
		}
		for (int number = 1; number <= 13; ++number) {
			deck->CARD[index].num = number;
			deck->CARD[index].suit = 'C';
			deck->CARD[index].img = CloverImg[number - 1];
			++index;
		}
	}

	void GAME::shuffleCards(Card* deck)
	{
		srand(time(NULL));
		for (int i = 0; i < 52; ++i) {
			int j = rand() % (i + 1);
			PlayingCard temp = deck->CARD[i];
			deck->CARD[i] = deck->CARD[j];
			deck->CARD[j] = temp;
		}
	}

	void GAME::Init()
	{
		straightWinCnt = 10;
		WinCnt = 0;
		Count = 0;
		CountDown = 100;
		SetImg[1] = HaimenImg;

		initialCards(deck);
		shuffleCards(deck);
		SetImg[0] = deck->CARD[0].img;
		SetNum[0] = deck->CARD[0].num;

		CardSetPx[0] = 955.0f;
		CardSetPy[0] = 225.0f;

		CardSetPx[1] = 955.0;
		CardSetPy[1] = 900.0f;

		HaimenPx = 1400.0f;
		HaimenPy = 200.0f;
	}

	void GAME::Title()
	{
		clear(15, 140, 34);
		fill(255, 0 ,0);
		hideCursor();
		textSize(200);
		text("HIGH", 450, 580);
		fill(255);
		text("＆", 850, 580);
		fill(0, 0, 255);
		text("LOW", 1080, 580);
		fill(255);
		textSize(100);
		text("S:ゲームスタート", 550, 780);
		fill(255);
		textSize(50);
		text("bet:" + (let)BetCoins + "コイン", 0, 300);
		text("C:賭けコイン変更", 0, 900);
		text("R:遊び方", 0, 400);
		text("ゲームプレイ数:" + (let)PlayCnt, 0, 200);
		text("ENTERキーでメニューに戻る", 0, 1080);
		//text("J:所持コインが0になったときに押してください", 660, 1080);
		text("G:ガチャ(ゲームを3回以上遊ぶと回せます。※無料分は引けます。)", 0, 1000);
		rectMode(CENTER);
		image(ChipImg, 50, 70);
		if (playerCoins >= 999999) {
			text("999999+", 80, 95);
		}
		else {
			text((let)playerCoins, 80, 95);
		}

		if (isTrigger(KEY_C)) {
			State = CHANGEBETCOIN;
		}

		if (isTrigger(KEY_S) && playerCoins >= BetCoins) {
			Init();
			playSound(DrawSnd);
			showCursor();
			playerCoins -= BetCoins;
			State = PLAY;
		}

		if (loopSnd) {
			playLoopSound(BackSnd);
			loopSnd = false;
		}

		if (isTrigger(KEY_R)) {
			State = RULE;
		}

		/*if (isTrigger(KEY_J) && playerCoins == 0) {
			Init();
			State = JOB;
		}*/

		if (isTrigger(KEY_G)) {
			Init2();
			State = GACHA;
		}

		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}

	void GAME::ChangeBetCoin()
	{
		clear(15, 140, 34);
		textSize(100);
		text("賭けコインを決めてください。", 300, 300);
		textSize(120);
		text("賭けるコイン数:", 50, 570);
		text("コイン", 1340, 570);
		textSize(200);
		text((let)BetCoins, 950, 600);

		textSize(80);
		text("U,↑:+100", 700, 800);
		text("D,↓:-100", 700, 920);
		text("S:ゲームスタート", 600, 1050);
		if (isTrigger(KEY_U)) {
			BetCoins += 100;
			if (playerCoins > 5000) {
				if (BetCoins > 5000) {
					BetCoins = 5000;
				}
			}
			else {
				if (BetCoins > playerCoins) {
					BetCoins = playerCoins;
				}
			}
		}

		if (isPress(KEY_UP)) {
			BetCoins += 100;
			if (playerCoins > 5000) {
				if (BetCoins > 5000) {
					BetCoins = 5000;
				}
			}
			else {
				if (BetCoins > playerCoins) {
					BetCoins = playerCoins;
				}
			}
		}

		if (isPress(KEY_DOWN)) {
			BetCoins -= 100;
			if (BetCoins < 100) {
				BetCoins = 100;
			}
		}

		if (isTrigger(KEY_D)) {
			BetCoins -= 100;
			if (BetCoins < 100) {
				BetCoins = 100;
			}
		}

		if (isTrigger(KEY_S) && playerCoins >= BetCoins) {
			Init();
			playSound(DrawSnd);
			showCursor();
			playerCoins -= BetCoins;
			GetCoins = BetCoins;
			State = PLAY;
		}
	}

	void GAME::Job()
	{
		clear(255);
		fill(0);
		textSize(50);
		if (Count == 1000) {
			image(Chip_2Img, 600, 450);
			textSize(200);
			text("×" + (let)Count + "枚", 750, 550);
			textSize(150);
			text("獲得しました。", 500, 750);
			if (CountDown > 0) {
				CountDown--;
			}
			else{
				playLoopSound(BackSnd);
				playSound(GetSnd);
				playerCoins += 1000;
				BetCoins = 100;
				GetCoins = BetCoins;
				State = TITLE;
			}
		}
		else{
			text("所持コインが無くなりました...", 600, 100);
			text("ENTERを10回押してコインを1000枚ゲット", 500, 200);
			image(Chip_2Img, 600, 450);
			textSize(200);
			text("×" + (let)Count, 750, 550);
			if (isTrigger(KEY_ENTER)) {
				Count += 100;
			}
		}
	}

	void GAME::Rule()
	{
		rectMode(CENTER);
		clear(15, 140, 34);
		text("遊び方", 880, 50);
		fill(0);
		text("1,Sキーを押してゲームスタート!", 500, 150);
		text("2,ゲーム画面に来たらHキーまたはLキーを押す", 500, 250);
		text("3,相手の数字よりも大きかったら勝ち", 500, 350);
		text("  相手の数字よりも小さかったら負け", 500, 420);
		text("← 小さい", 400, 500);
		text("大きい →", 1200,500);
		image(TrampImg, 900, 800);
		textSize(50);
		text("ENTERキーでタイトルへ", 0, 100);
		if (isTrigger(KEY_ENTER)) {
			WinCnt = 0;
			State = TITLE;
		}
	}

	void GAME::Play(Card* deck)
	{
		clear(15, 140, 34);
		textSize(100);
		fill(255, 0, 0);
		text("H", 500, 580);
		fill(0);
		text("か", 550, 580);
		fill(0, 0, 255);
		text("L", 650, 580);
		fill(0);
		text("を押してください", 700, 580);

		//画像切替
		if ((isTrigger(KEY_H)) || (isTrigger(KEY_L))) {
			playSound(DrawSnd);
			SetImg[1] = deck->CARD[1].img;
			SetNum[1] = deck->CARD[1].num;

			//相手の数字より自分の数字が大きいとき
			if (isTrigger(KEY_H) && SetNum[0] < SetNum[1] ||
				isTrigger(KEY_L) && SetNum[0] > SetNum[1]) {
				winFlag = true;
				State = SHOW;
			}

			//相手の数字より自分の数字が小さいとき
			if (playerCoins > 0 && isTrigger(KEY_H) && SetNum[0] > SetNum[1] ||
				isTrigger(KEY_L) && SetNum[0] < SetNum[1]) {
				loseFlag = true;
				State = SHOW;
			}

			//相手の数字と自分の数字が同じ大きさのとき
			if (isTrigger(KEY_H) && SetNum[0] == SetNum[1] ||
				isTrigger(KEY_L) && SetNum[0] == SetNum[1]){
				drawFlag = true;
				State = SHOW;
			}

			//所持コインが0で負けたとき
			if (playerCoins == 0 && (isTrigger(KEY_H) && SetNum[0] > SetNum[1] ||
				isTrigger(KEY_L) && SetNum[0] < SetNum[1])) {
				jobFlag = true;
				State = SHOW;
			}

			//9連勝していてかつ相手の数字より自分の数字が大きいとき
			if (WinCnt == 9 && (isTrigger(KEY_H) && SetNum[0] < SetNum[1] ||
				isTrigger(KEY_L) && SetNum[0] > SetNum[1])) {
				straightWinFlag = true;
				State = SHOW;
			}
		}
		draw();
	}

	void GAME::Show()
	{
		if (winFlag == true) {
			winFlag = false;
			Sleep(800);
			if (WinCnt < 9) {
				playSound(WinSnd);
			}
			State = WIN;
		}
		if (loseFlag == true) {
			loseFlag = false;
			Sleep(800);
			stopSound(BackSnd);
			if (playerCoins > 0) {
				playSound(LoseSnd);
			}
			State = LOSE;
		}
		if (drawFlag == true) {
			drawFlag = false;
			Sleep(800);
			State = DRAW;
		}
		if (jobFlag == true) {
			jobFlag = false;
			Sleep(400);
			stopSound(BackSnd);
			stopSound(LoseSnd);
			State = JOB;
		}
		if (straightWinFlag == true) {
			straightWinFlag = false;
			Sleep(500);
			playSound(straightWinSnd);
			stopSound(BackSnd);
			State = STRAIGHTWIN;
		}
	}

	void GAME::Win()
	{
		clear(15, 140, 34);
		fill(255);
		textSize(100);
		text("勝ちました！", 700, 200);
		text("ゲームを続けますか?", 500, 400);
		text("Y:ゲームを続ける", 600, 600);
		text("N:タイトル画面に戻る", 500, 800);

		if (isTrigger(KEY_Y)) {
			WinCnt++;
			GetCoins *= 2;
			SetImg[0] = SetImg[1];
			SetNum[0] = SetNum[1];
			shuffleCards(deck);
			SetImg[1] = HaimenImg;
			playSound(DrawSnd);
			stopSound(WinSnd);
			State = PLAY;
		}
		
		if (isTrigger(KEY_N)) {
			playerCoins += GetCoins;
			WinCnt = 0;
			PlayCnt++;
			BetCoins = 100;
			GetCoins = BetCoins;
			State = TITLE;
		}
	}

	void GAME::StraightWin()
	{
		clear(255);
		fill(213, 202, 112);
		rectMode(CORNER);
		image(WinImg, 200, 0);
		textSize(50);
		text("10+1連ガチャが1回無料!", 0, 980);
		fill(0);
		textSize(50);
		text("ENTERキーでタイトルに戻る", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			GetCoins *= 2;
			playerCoins += GetCoins;
			WinCnt = 0;
			straightCnt++; 
			PlayCnt++;
			playLoopSound(BackSnd);
			stopSound(straightWinSnd);
			BetCoins = 100;
			GetCoins = BetCoins;
			State = TITLE;
		}
	}

	void GAME::Lose()
	{
		clear(15, 140, 34);
		fill(255);
		textSize(100);
		text("負けました…", 600, 540);
		textSize(50);
		text("ENTERでタイトルへ", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			WinCnt = 0;
			PlayCnt++;
			stopSound(LoseSnd);
			playLoopSound(BackSnd);
			BetCoins = 100;
			GetCoins = BetCoins;
			State = TITLE;
		}
	}

	void GAME::Draw()
	{
		clear(15, 140, 34);
		fill(255);
		textSize(100);
		text("DRAW", 820, 540);
		text("ENTERでもう一回", 500, 640);
		if (isTrigger(KEY_ENTER)) {
			SetImg[0] = SetImg[1];
			SetNum[0] = SetNum[1];
			shuffleCards(deck);
			SetImg[1] = HaimenImg;
			State = PLAY;
		}
	}

	void GAME::Init2()
	{
		TotalProb5 = 58.8f;
		TotalProb6 = 87.5f;
		TotalProb7 = 97.1f;
		confirm = random() % 50;
		sFrameCnt = 100.0f;
		rFrameCnt = 300.0f;

		s0 = random() % 100 + 1;
		r1 = random() % 100 + 1, r2 = random() % 100 + 1, r3 = random() % 100 + 1, r4 = random() % 100 + 1, r5 = random() % 100 + 1,
		r6 = random() % 100 + 1, r7 = random() % 100 + 1, r8 = random() % 100 + 1, r9 = random() % 100 + 1, r10 = random() % 100 + 1;
		r11 = random() % 100 + 1;

		rare4Total = 10; rare5Total = 9; rare6Total = 8; rare7Total = 7;

		randrare4 = random() % rare4Total; randrare5 = random() % rare5Total;
		randrare6 = random() % rare6Total; randrare7 = random() % rare7Total;

		randrare4_1 = random() % rare4Total; randrare5_1 = random() % rare5Total;
		randrare6_1 = random() % rare6Total; randrare7_1 = random() % rare7Total;

		randrare4_2 = random() % rare4Total; randrare5_2 = random() % rare5Total;
		randrare6_2 = random() % rare6Total; randrare7_2 = random() % rare7Total;

		randrare4_3 = random() % rare4Total; randrare5_3 = random() % rare5Total;
		randrare6_3 = random() % rare6Total; randrare7_3 = random() % rare7Total;

		randrare4_4 = random() % rare4Total; randrare5_4 = random() % rare5Total;
		randrare6_4 = random() % rare6Total; randrare7_4 = random() % rare7Total;

		randrare4_5 = random() % rare4Total; randrare5_5 = random() % rare5Total;
		randrare6_5 = random() % rare6Total; randrare7_5 = random() % rare7Total;

		randrare4_6 = random() % rare4Total; randrare5_6 = random() % rare5Total;
		randrare6_6 = random() % rare6Total; randrare7_6 = random() % rare7Total;

		randrare4_7 = random() % rare4Total; randrare5_7 = random() % rare5Total;
		randrare6_7 = random() % rare6Total; randrare7_7 = random() % rare7Total;

		randrare4_8 = random() % rare4Total; randrare5_8 = random() % rare5Total;
		randrare6_8 = random() % rare6Total; randrare7_8 = random() % rare7Total;

		randrare4_9 = random() % rare4Total; randrare5_9 = random() % rare5Total;
		randrare6_9 = random() % rare6Total; randrare7_9 = random() % rare7Total;

		randrare4_10 = random() % rare4Total; randrare5_10 = random() % rare5Total;
		randrare6_10 = random() % rare6Total; randrare7_10 = random() % rare7Total;

		randrare4_11 = random() % rare4Total; randrare5_11 = random() % rare5Total;
		randrare6_11 = random() % rare6Total; randrare7_11 = random() % rare7Total;

		sPx = 165.0f, sPy = 560.0f;
		r1Px = 10.0f; r1Py = 260.0f;
		r2Px = 650.0f; r3Px = 1300.0f;
		r4Py = 460.0f; r7Py = 660.0f;
		r10Px = 300.0f; r10Py = 860.0f;
		r11Px = 1050.0f;
	}

	void GAME::Gacha()
	{
		clear(255);
		rectMode(CORNER);
		image(GachaImg, 0, 0);
		image(GachaImg, 0, 400);
		image(GachaImg, 0, 800);
		image(GachaImg, 960, 0);
		image(GachaImg, 960, 400);
		image(GachaImg, 960, 800); 
		rectMode(CENTER);
		image(ChipImg, 50, 70);
		fill(0);
		textSize(50);
		if (playerCoins >= 999999) {
			text("999999+", 80, 90);
		}
		else {
			text((let)playerCoins, 80, 95);
		}
		text("ゲームプレイ数:" + (let)PlayCnt, 0, 200);
		text("B:獲得キャラ一覧", 600, 1080);
		text("P:排出確率", 1200, 1080);
		text("ENTERでタイトルへ", 0, 1080);
		if (PlayCnt < 3 && straightCnt <= 0) {
			textSize(100);
			text("ゲームを3回以上プレイしていないので", 50, 540);
			text("ガチャを引くことができません。", 200, 680);
		}
		else if(PlayCnt >= 3 && straightCnt <= 0) {
			textSize(120);
			text("S:シングルガチャ 5000コイン", 100, 500);
			text("R:10+1連ガチャ 50000コイン", 100, 800);
		}
		else if (PlayCnt >= 3 && straightCnt >= 1) {
			textSize(120);
			text("S:シングルガチャ 5000コイン", 50, 500);
			textSize(110);
			text("R:10+1連ガチャ あと" + (let)straightCnt + "回無料", 50, 800);
		}
		else if(PlayCnt < 3 && straightCnt >= 1){
			textSize(120);
			if (straightCnt > 0) {
				textSize(110);
				text("R:10+1連ガチャ あと" + (let)straightCnt + "回無料", 80, 630);
			}
		}
		if (isTrigger(KEY_S) && playerCoins >= 5000 && PlayCnt >= 3) {
			Init2();
			playerCoins -= 5000;
			clear(255);
			image(TamagoImg, width / 2, height / 2);
			playSound(PakaSnd);
			if (confirm == 1) {
				playSound(KakuteiSnd);
			}
			State = RESULT;
		}

		if (isTrigger(KEY_R) && playerCoins >= 50000 && straightCnt <= 0 && PlayCnt >= 3) {
			Init2();
			playerCoins -= 50000;
			clear(255);
			image(Egg1Img, 300, 220);
			image(Egg2Img, 950, 220);
			image(Egg3Img, 1600, 220);
			image(Egg4Img, 300, 420);
			image(Egg5Img, 950, 420);
			image(Egg6Img, 1600, 420);
			image(Egg7Img, 300, 620);
			image(Egg8Img, 950, 620);
			image(Egg9Img, 1600, 620);
			image(Egg10Img, 540, 820);
			image(Egg11Img, 1260, 820);
			playSound(PakaSnd);
			if (confirm == 1) {
				playSound(KakuteiSnd);
			}
			State = RESULT2;
		}

		if (isTrigger(KEY_R) && straightCnt > 0) {
			Init2();
			clear(255);
			image(Egg1Img, 300, 220);
			image(Egg2Img, 950, 220);
			image(Egg3Img, 1600, 220);
			image(Egg4Img, 300, 420);
			image(Egg5Img, 950, 420);
			image(Egg6Img, 1600, 420);
			image(Egg7Img, 300, 620);
			image(Egg8Img, 950, 620);
			image(Egg9Img, 1600, 620);
			image(Egg10Img, 540, 820);
			image(Egg11Img, 1260, 820);
			playSound(PakaSnd);
			if (confirm == 1) {
				playSound(KakuteiSnd);
			}
			State = RESULT2;
		}

		if (isTrigger(KEY_B)) {
			State = BOX;
		}

		if (isTrigger(KEY_P)) {
			Init2();
			State = PROB;
		}

		if (isTrigger(KEY_ENTER)) {
			WinCnt = 0;
			State = TITLE;
		}
	}

	void GAME::Result()
	{
		if (confirm == 1) {
			fill(0);
			textSize(50);
			text("☆7確定!", 0, 100);
		}
		if (sFrameCnt < 80) {
			TamagoImg = WhiteImg;
			image(TamagoImg, width / 2, height / 2);
			if (confirm == 1) {
				fill(213, 202, 112);
				textSize(210);
				text("☆7:" + (let)rare7[randrare7].name, sPx, sPy);
			}
			else {
				if (s0 > TotalProb7) {
					fill(213, 202, 112);
					textSize(210);
					text("☆7:", sPx, sPy);
					fill(0);
					text((let)rare7[randrare7].name, 600, sPy);
				}
				else if (s0 > TotalProb6) {
					textSize(210);
					text("☆6:" + (let)rare6[randrare6].name, sPx, sPy);
				}
				else if (s0 > TotalProb5) {
					textSize(210);
					text("☆5:" + (let)rare5[randrare5].name, sPx, sPy);
				}
				else {
					textSize(210);
					text("☆4:" + (let)rare4[randrare4].name, sPx, sPy);
				}
			}
		}
		if (sFrameCnt <= 0.5f) {
			if (confirm == 1) {
				chara = randrare7;
				rare7[chara].getCnt += 1;
			}
			else {
				if (s0 > TotalProb7) {
					chara = randrare7;
					rare7[chara].getCnt += 1;
				}
				else if (s0 > TotalProb6) {
					chara = randrare6;
					rare6[chara].getCnt += 1;
				}
				else if (s0 > TotalProb5) {
					chara = randrare5;
					rare5[chara].getCnt += 1;
				}
				else {
					chara = randrare4;
					rare4[chara].getCnt += 1;
				}
			}
		}
		if (sFrameCnt > 0) {
			sFrameCnt--;
		}
		else{
			TamagoImg = loadImage("..\\main\\assets\\game05\\tamago.png");
			State = GACHA;
		}
	}

	void GAME::Result2()
	{
		if (confirm == 1) {
			fill(0);
			textSize(50);
			text("☆7確定!", 0, 100);
		}
		textSize(80);
		if (rFrameCnt < 280.0f) {
			Egg1Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg1Img, 300, 220);
			//1
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_1].name, r1Px, r1Py);
			}
			else {
				if (r1 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", r1Px, r1Py);
					fill(0);
					text((let)rare7[randrare7_1].name, 160, r1Py);
				}
				else if (r1 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_1].name, r1Px, r1Py);
				}
				else if (r1 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_1].name, r1Px, r1Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_1].name, r1Px, r1Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_1;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r1 > TotalProb7) {
						chara = randrare7_1;
						rare7[chara].getCnt += 1;
					}
					else if (r1 > TotalProb6) {
						chara = randrare6_1;
						rare6[chara].getCnt += 1;
					}
					else if (r1 > TotalProb5) {
						chara = randrare5_1;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_1;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 260.0f) {
			//2
			Egg2Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg2Img, 950, 220);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_2].name, r2Px, r1Py);
			}
			else {
				if (r2 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", 650.0f, r1Py);
					fill(0);
					text((let)rare7[randrare7_2].name, 820.0f, r1Py);
				}
				else if (r2 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_2].name, r2Px, r1Py);
				}
				else if (r2 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_2].name, r2Px, r1Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_2].name, r2Px, r1Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_2;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r2 > TotalProb7) {
						chara = randrare7_2;
						rare7[chara].getCnt += 1;
					}
					else if (r2 > TotalProb6) {
						chara = randrare6_2;
						rare6[chara].getCnt += 1;
					}
					else if (r2 > TotalProb5) {
						chara = randrare5_2;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_2;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 240.0f) {
			//3
			Egg3Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg3Img, 1600, 220);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_3].name, r3Px, r1Py);
			}
			else {
				if (r3 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", r3Px, r1Py);
					fill(0);
					text((let)rare7[randrare7_3].name, 1470, r1Py);
				}
				else if (r3 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_3].name, r3Px, r1Py);
				}
				else if (r3 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_3].name, r3Px, r1Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_3].name, r3Px, r1Py);
				}
			}if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_3;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r3 > TotalProb7) {
						chara = randrare7_3;
						rare7[chara].getCnt += 1;
					}
					else if (r3 > TotalProb6) {
						chara = randrare6_3;
						rare6[chara].getCnt += 1;
					}
					else if (r3 > TotalProb5) {
						chara = randrare5_3;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_3;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 220.0f) {
			//4
			Egg4Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg4Img, 300, 420);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_4].name, r1Px, r4Py);
			}
			else {
				if (r4 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", r1Px, r4Py);
					fill(0);
					text((let)rare7[randrare7_4].name, 160, r4Py);
				}
				else if (r4 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_4].name, r1Px, r4Py);
				}
				else if (r4 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_4].name, r1Px, r4Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_4].name, r1Px, r4Py);
				}
			}if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r4 > TotalProb7) {
						chara = randrare7_4;
						rare7[chara].getCnt += 1;
					}
					else if (r4 > TotalProb6) {
						chara = randrare6_4;
						rare6[chara].getCnt += 1;
					}
					else if (r4 > TotalProb5) {
						chara = randrare5_4;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_4;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 200.0f) {
			//5
			Egg5Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg5Img, 950, 420);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_5].name, r2Px, r4Py);
			}
			else {
				if (r5 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", 650, r4Py);
					fill(0);
					text((let)rare7[randrare7_5].name, 820, r4Py);
				}
				else if (r5 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_5].name, r2Px, r4Py);
				}
				else if (r5 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_5].name, r2Px, r4Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_5].name, r2Px, r4Py);
				}
			}if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r5 > TotalProb7) {
						chara = randrare7_5;
						rare7[chara].getCnt += 1;
					}
					else if (r5 > TotalProb6) {
						chara = randrare6_5;
						rare6[chara].getCnt += 1;
					}
					else if (r5 > TotalProb5) {
						chara = randrare5_5;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_5;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 180.0f) {
			//6
			Egg6Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg6Img, 1600, 420);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_6].name, r3Px, r4Py);
			}
			else {
				if (r6 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", r3Px, r4Py);
					fill(0);
					text((let)rare7[randrare7_6].name, 1470, r4Py);
				}
				else if (r6 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_6].name, r3Px, r4Py);
				}
				else if (r6 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_6].name, r3Px, r4Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_6].name, r3Px, r4Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_6;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r6 > TotalProb7) {
						chara = randrare7_6;
						rare7[chara].getCnt += 1;
					}
					else if (r6 > TotalProb6) {
						chara = randrare6_6;
						rare6[chara].getCnt += 1;
					}
					else if (r6 > TotalProb5) {
						chara = randrare5_6;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_6;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 160.0f) {
			//7
			Egg7Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg7Img, 300, 620);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_7].name, r1Px, r7Py);
			}
			else {
				if (r7 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", r1Px, r7Py);
					fill(0);
					text((let)rare7[randrare7_7].name, 160, r7Py);
				}
				else if (r7 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_7].name, r1Px, r7Py);
				}
				else if (r7 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_7].name, r1Px, r7Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_7].name, r1Px, r7Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_7;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r7 > TotalProb7) {
						chara = randrare7_7;
						rare7[chara].getCnt += 1;
					}
					else if (r7 > TotalProb6) {
						chara = randrare6_7;
						rare6[chara].getCnt += 1;
					}
					else if (r7 > TotalProb5) {
						chara = randrare5_7;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_7;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 140.0f) {
			//8
			Egg8Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg8Img, 950, 620);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_8].name, r2Px, r7Py);
			}
			else {
				if (r8 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", 650, r7Py);
					fill(0);
					text((let)rare7[randrare7_8].name, 820, r7Py);
				}
				else if (r8 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_8].name, r2Px, r7Py);
				}
				else if (r8 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_8].name, r2Px, r7Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_8].name, r2Px, r7Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_8;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r8 > TotalProb7) {
						chara = randrare7_8;
						rare7[chara].getCnt += 1;
					}
					else if (r8 > TotalProb6) {
						chara = randrare6_8;
						rare6[chara].getCnt += 1;
					}
					else if (r8 > TotalProb5) {
						chara = randrare5_8;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_8;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 120.0f) {
			//9
			Egg9Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg9Img, 1600, 620);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_9].name, r3Px, r7Py);
			}
			else {
				if (r9 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", r3Px, r7Py);
					fill(0);
					text((let)rare7[randrare7_9].name, 1470, r7Py);
				}
				else if (r9 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_9].name, r3Px, r7Py);
				}
				else if (r9 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_9].name, r3Px, r7Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_9].name, r3Px, r7Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_9;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r9 > TotalProb7) {
						chara = randrare7_9;
						rare7[chara].getCnt += 1;
					}
					else if (r9 > TotalProb6) {
						chara = randrare6_9;
						rare6[chara].getCnt += 1;
					}
					else if (r9 > TotalProb5) {
						chara = randrare5_9;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_9;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 100.0f) {
			//10
			Egg10Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg10Img, 540, 820);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_10].name, r10Px, r10Py);
			}
			else {
				if (r10 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", r10Px, r10Py);
					fill(0);
					text((let)rare7[randrare7_10].name, 450, r10Py);
				}
				else if (r10 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_10].name, r10Px, r10Py);
				}
				else if (r10 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_10].name, r10Px, r10Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_10].name, r10Px, r10Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_10;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r10 > TotalProb7) {
						chara = randrare7_10;
						rare7[chara].getCnt += 1;
					}
					else if (r10 > TotalProb6) {
						chara = randrare6_10;
						rare6[chara].getCnt += 1;
					}
					else if (r10 > TotalProb5) {
						chara = randrare5_10;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_10;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt < 80.0f) {
			//11
			Egg11Img = loadImage("..\\main\\assets\\game05\\white2.png");
			image(Egg11Img, 1150, 820);
			if (confirm == 1) {
				fill(213, 202, 112);
				text("☆7:" + (let)rare7[randrare7_11].name, r11Px, r10Py);
			}
			else {
				if (r11 > TotalProb7) {
					fill(213, 202, 112);
					text("☆7:", 1050, r10Py);
					fill(0);
					text((let)rare7[randrare7_11].name, 1200, r10Py);
				}
				else if (r11 > TotalProb6) {
					fill(0);
					text("☆6:" + (let)rare6[randrare6_11].name, r11Px, r10Py);
				}
				else if (r11 > TotalProb5) {
					fill(0);
					text("☆5:" + (let)rare5[randrare5_11].name, r11Px, r10Py);
				}
				else {
					fill(0);
					text("☆4:" + (let)rare4[randrare4_11].name, r11Px, r10Py);
				}
			}
			if (rFrameCnt <= 0.5f) {
				if (confirm == 1) {
					chara = randrare7_11;
					rare7[chara].getCnt += 1;
				}
				else {
					if (r11 > TotalProb7) {
						chara = randrare7_11;
						rare7[chara].getCnt += 1;
					}
					else if (r11 > TotalProb6) {
						chara = randrare6_11;
						rare6[chara].getCnt += 1;
					}
					else if (r11 > TotalProb5) {
						chara = randrare5_11;
						rare5[chara].getCnt += 1;
					}
					else {
						chara = randrare4_11;
						rare4[chara].getCnt += 1;
					}
				}
			}
		}
		if (rFrameCnt > 0) {
			rFrameCnt--;
		}
		else{
			Egg1Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg2Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg3Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg4Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg5Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg6Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg7Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg8Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg9Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg10Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			Egg11Img = loadImage("..\\main\\assets\\game05\\tamago2.png");
			straightCnt--;
			State = GACHA;
		}
	}

	void GAME::Box()
	{
		clear(255);
		textSize(60);
		for (int i = 0; i < rare4Total; i++) {
			text("☆4", 160.0f, 100.0f);
			if (rare4[i].getCnt >= 99.0f) {
				text(rare4[i].name, 50.0f, 200.0f + 90.0f * i);
				text("×99+", 350.0f, 200.0f + 90.0f * i);
			}
			else {
				text(rare4[i].name, 50.0f, 200.0f + 90.0f * i);
				text("×" + (let)rare4[i].getCnt, 350.0f, 200.0f + 90.0f * i);
			}
		}
		for (int i = 0; i < rare5Total; i++) {
			text("☆5", 640.0f, 100.0f);
			if (rare5[i].getCnt >= 99.0f) {
				text(rare5[i].name, 530.0f, 200.0f + 90.0f * i);
				text("×99+", 830.0f, 200.0f + 90.0f * i);
			}
			else {
				text(rare5[i].name, 530.0f, 200.0f + 90.0f * i);
				text("×" + (let)rare5[i].getCnt, 830.0f, 200.0f + 90.0f * i);
			}
		}
		for (int i = 0; i < rare6Total; i++) {
			text("☆6", 1120.0f, 100.0f);
			if (rare6[i].getCnt >= 99.0f) {
				text(rare6[i].name, 1010.0f, 200.0f + 90.0f * i);
				text("×99+", 1310.0f, 200.0f + 90.0f * i);
			}
			else {
				text(rare6[i].name, 1010.0f, 200.0f + 90.0f * i);
				text("×" + (let)rare6[i].getCnt, 1310.0f, 200.0f + 90.0f * i);
			}
		}
		for (int i = 0; i < rare7Total; i++) {
			fill(213, 202, 112);
			text("☆7", 1600, 100);
			fill(0);
			if (rare7[i].getCnt >= 99) {
				text(rare7[i].name, 1490.0f, 200.0f + 90.0f * i);
				text("×99+", 1740.0f, 200.0f + 90.0f * i);
			}
			else {
				text(rare7[i].name, 1490.0f, 200.0f + 90.0f * i);
				text("×" + (let)rare7[i].getCnt, 1740.0f, 200.0f + 90.0f * i);
			}
		}

		textSize(50);
		text("ENTER:ガチャ選択画面にもどる", 600.0f, 1080.0f);
		if (isTrigger(KEY_ENTER)) {
			State = GACHA;
		}
	}

	void GAME::Prob()
	{
		clear(37, 44, 107);
		fill(255);
		textSize(50);
		for (int i = 0; i < 10; i++) {
			text("☆4:10体:58.8%", 60, 100);
			text(rare4[i].name, 50.0f, 200.0f + 90.0f * i);
			text(":5.88%", 300.0f, 200.0f + 90.0f * i);

		}
		for (int i = 0; i < 9; i++) {
			text("☆5:9体:28.8%", 540, 100);
			text(rare5[i].name, 530.0f, 200.0f + 90.0f * i);
			text(":3.2%", 780.0f, 200.0f + 90.0f * i);
		}
		for (int i = 0; i < 8; i++) {
			text("☆6:8体:9.6%", 1020, 100);
			text(rare6[i].name, 1010.0f, 200.0f + 90.0f * i);
			text(":1.2%", 1260.0f, 200.0f + 90.0f * i);
		}
		for (int i = 0; i < 7; i++) {
			fill(213, 202, 112);
			text("☆7:7体:2.8%", 1500, 100);
			fill(255);
			text(rare7[i].name, 1440.0f, 200.0f + 90.0f * i);
			text(":0.4%", 1690.0f, 200.0f + 90.0f * i);
		}
		fill(255);
		textSize(50);
		text("ENTER:ガチャ選択画面にもどる", 600, 1080);
		if (isTrigger(KEY_ENTER)) {
			State = GACHA;
		}
	}

	void GAME::draw()
	{
		textSize(50);
		fill(255);
		text((let)WinCnt + "/" + (let)straightWinCnt + "連勝", 50, 100);
		text("勝てばもらえる枚数:" + (let)GetCoins + "コイン", 50, 200);
		image(HaimenImg, HaimenPx, HaimenPy);
		image(HaimenImg, HaimenPx, 197);
		image(HaimenImg, HaimenPx, 194);
		image(HaimenImg, HaimenPx, 191);
		image(HaimenImg, HaimenPx, 188);
		image(HaimenImg, HaimenPx, 185);
		image(HaimenImg, HaimenPx, 182);
		image(HaimenImg, HaimenPx, 179);
		image(SetImg[0], CardSetPx[0], CardSetPy[0]);
		image(SetImg[1], CardSetPx[1], CardSetPy[1]);
		text("ディーラー", 840, 50);
		strokeWeight(5);
		stroke(255);
		line(830, 70, 1080, 70);
		line(830, 70, 830, 380);
		line(830, 380, 1080, 380);
		line(1080, 70, 1080, 380);
	}
}