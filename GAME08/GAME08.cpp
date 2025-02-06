#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME08.h"
namespace GAME08
{
	int GAME::create()
	{
		Bgm = loadSound("..\\main\\assets\\game08\\bgm.wav");

		TitleImg = loadImage("..\\main\\assets\\game08\\title.png");

		FrameImg = loadImage("..\\main\\assets\\game08\\Frame.png");

		BackImg = loadImage("..\\main\\assets\\game08\\Back.png");

		BasicImg[0] = loadImage("..\\main\\assets\\game08\\1-1.png");
		BasicImg[1] = loadImage("..\\main\\assets\\game08\\2-1.png");
		BasicImg[2] = loadImage("..\\main\\assets\\game08\\2-2.png");
		BasicImg[3] = loadImage("..\\main\\assets\\game08\\2-3.png");
		BasicImg[4] = loadImage("..\\main\\assets\\game08\\3-1.png");
		BasicImg[5] = loadImage("..\\main\\assets\\game08\\4-1.png");
		BasicImg[6] = loadImage("..\\main\\assets\\game08\\4-2.png");

		AnomalyImg[0] = loadImage("..\\main\\assets\\game08\\2-2ihen.png");
		AnomalyImg[1] = loadImage("..\\main\\assets\\game08\\2-3ihen.png");
		AnomalyImg[2] = loadImage("..\\main\\assets\\game08\\2-4ihen.png");
		AnomalyImg[3] = loadImage("..\\main\\assets\\game08\\backihen1.png");
		AnomalyImg[4] = loadImage("..\\main\\assets\\game08\\backihen2.png");
		AnomalyImg[5] = loadImage("..\\main\\assets\\game08\\4-1ihen.png");
		AnomalyImg[6] = loadImage("..\\main\\assets\\game08\\2-3ihen2.png");
		AnomalyImg[7] = loadImage("..\\main\\assets\\game08\\2-3ihen3.png");
		AnomalyImg[8] = loadImage("..\\main\\assets\\game08\\4-1ihen2.png");
		AnomalyImg[9] = loadImage("..\\main\\assets\\game08\\4-1ihen3.png");
		AnomalyImg[10] = loadImage("..\\main\\assets\\game08\\3-1ihen.png");
		AnomalyImg[11] = loadImage("..\\main\\assets\\game08\\3-1ihen2.png");
		AnomalyImg[12] = loadImage("..\\main\\assets\\game08\\3-1ihen3.png");




		PlayerImg = loadImage("..\\main\\assets\\game08\\player.png");

		NumberImg[0] = loadImage("..\\main\\assets\\game08\\0.png");
		NumberImg[1] = loadImage("..\\main\\assets\\game08\\1.png");
		NumberImg[2] = loadImage("..\\main\\assets\\game08\\2.png");
		NumberImg[3] = loadImage("..\\main\\assets\\game08\\3.png");
		NumberImg[4] = loadImage("..\\main\\assets\\game08\\4.png");
		NumberImg[5] = loadImage("..\\main\\assets\\game08\\5.png");
		NumberImg[6] = loadImage("..\\main\\assets\\game08\\6.png");
		NumberImg[7] = loadImage("..\\main\\assets\\game08\\7.png");
		NumberImg[8] = loadImage("..\\main\\assets\\game08\\8.png");
		NumberImg[9] = loadImage("..\\main\\assets\\game08\\9.png");

		GameClearImg = loadImage("..\\main\\assets\\game08\\gameclear.png");

		SpaceImg = loadImage("..\\main\\assets\\game08\\space.png");

		RightImg = loadImage("..\\main\\assets\\game08\\right.png");

		BgmFlag = true;

		return 0;
	}

	void GAME::init() {

		ClearNum = 0;
		AnomalyFlag = false;
		AnomalyTypeFlag = 0;

		BeforeAnomaly = 0;

		player.px = width / 2;
		player.py = height / 2;
		player.vx = 1300.0f;

		firstFlag = true;
		onceAnomalyFlag = false;
		AnomalyClearFlag = false;

		

	}


	void GAME::proc()
	{
		if (BgmFlag) {
			playLoopSound(Bgm);
			BgmFlag = false;
		}
		clear(0, 0, 64);
		textSize(50);
		fill(255, 255, 0);
		text("GAME08", 0, 100);
		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);

		if (STATE == TITLE) { title(); }
		else if (STATE == PLAY) { play(); }
		else if (STATE == RESULT) { result(); }

		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}

	void GAME::destroy()
	{

	}

	void GAME::title()
	{
		draw();
		//image(BackImg[1], width / 2, height / 2);

		if (isTrigger(KEY_SPACE)) {
			init();
			STATE = PLAY;
		}

	}

	void GAME::play()
	{

		draw();
		if (isPress(KEY_A) || isPress(KEY_LEFT))player.px -= player.vx * delta;
		if (isPress(KEY_D) || isPress(KEY_RIGHT))player.px += player.vx * delta;
		int scene = 0;

		//右に進んだ場合
		if (player.px >= width - 120.0f) {
			player.px = 201.0f;
			if (SCENE == SCENE1) {
				if (onceAnomalyFlag) {
					if (random() % 5 != 0)AnomalyFlag = true;
					else {
						AnomalyFlag = false;
						AnomalyTypeFlag = 0;
					}
					if (AnomalyFlag) {
						int AnomalyType = 0;
						AnomalyType = (random() % 13) + 1;
						while (AnomalyType == BeforeAnomaly) {
							AnomalyType = (random() % 13) + 1;
						}
						AnomalyTypeFlag = AnomalyType;
						BeforeAnomaly = AnomalyType;
						onceAnomalyFlag = false;
					}
				}
				SCENE = SCENE2;
			}
			else if (SCENE == SCENE2) {
				SCENE = SCENE3;
			}
			else if (SCENE == SCENE3) {
				SCENE = SCENE4;
			}
			else if (SCENE == SCENE4) {
				if (AnomalyFlag == false)ClearNum++;
				else ClearNum = 0;
				AnomalyClearFlag = true;
				SCENE = SCENE5;
			}
			else if (SCENE == SCENE5) {
				if (firstFlag == true)firstFlag = false;
				onceAnomalyFlag = true;
				AnomalyClearFlag = true;
				AnomalyFlag = false;
				if (ClearNum == 9)STATE = RESULT;
				SCENE = SCENE1;
			}
		}

		//左に進んだ場合
		if (player.px <= 0 + 200.0f) {
			if (firstFlag && SCENE == SCENE1 || AnomalyClearFlag && SCENE == SCENE5 )player.px = 201.0f;
			else player.px = width - 121.0f;

			if (SCENE == SCENE1) {
				if (AnomalyFlag) { ClearNum++; AnomalyClearFlag = true; }
				else { ClearNum = 0; AnomalyClearFlag = true; }
				if (firstFlag == false)SCENE = SCENE5;
			}

			else if (SCENE == SCENE2) {
				SCENE = SCENE1;
			}

			else if (SCENE == SCENE3) {
				SCENE = SCENE2;
			}

			else if (SCENE == SCENE4) {
				SCENE = SCENE3;
			}

			else if (SCENE == SCENE5) {
				if (AnomalyClearFlag == false) SCENE = SCENE4;
			}

		}
		if (SCENE == SCENE1)scene = 1;
		else if (SCENE == SCENE2)scene = 2;
		else if (SCENE == SCENE3)scene = 3;
		else if (SCENE == SCENE4)scene = 4;
		else if (SCENE == SCENE5)scene = 5;
		//デバッグ用
		//text((let)+scene, 0, height);
		//text((let)+AnomalyFlag, 50, height);
		//text((let)+AnomalyTypeFlag, 100, height);
		//text((let)+firstFlag, 150, height);
		//text((let)+AnomalyClearFlag, 200, height);
		//if (isTrigger(KEY_SPACE)) {
			//STATE = RESULT;
		//}
	}

	void GAME::result()
	{
		draw();

		if (isTrigger(KEY_SPACE)) {
			STATE = TITLE;
		}

	}

	void GAME::draw()
	{
		if (STATE == TITLE) {
			//clear(0 , 0 , 0);
			rectMode(CENTER);
			image(TitleImg, width / 2, height / 2);
			image(FrameImg, width / 2, height / 2);
		}

		if (STATE == PLAY) {
			clear(0, 0, 0);
			rectMode(CENTER);
			if (SCENE == SCENE1) {
				image(BackImg, width / 2, height / 2);
				image(RightImg, width / 2, height / 2);
				image(PlayerImg, player.px, player.py);
				image(BasicImg[0], width / 2, height / 2);
				image(FrameImg, width / 2, height / 2);
			}

			if (SCENE == SCENE2) {
				image(BackImg, width / 2, height / 2);
				image(RightImg, width / 2, height / 2);
				image(PlayerImg, player.px, player.py);
				for (int i = 1; i < 4; i++) {
					image(BasicImg[i], width / 2, height / 2);
				}
				if (AnomalyFlag && AnomalyTypeFlag == 1) {
					image(AnomalyImg[0], width / 2, height / 2);
				}
				else if (AnomalyFlag && AnomalyTypeFlag == 2) {
					image(AnomalyImg[1], width / 2, height / 2);
				}
				else if (AnomalyFlag && AnomalyTypeFlag == 3) {
					image(AnomalyImg[2], width / 2, height / 2);
				}
				else if (AnomalyFlag && AnomalyTypeFlag == 4) {
					image(AnomalyImg[6], width / 2, height / 2);
				}
				else if (AnomalyFlag && AnomalyTypeFlag == 5) {
					image(AnomalyImg[7], width / 2, height / 2);
				}
				image(FrameImg, width / 2, height / 2);
			}

			if (SCENE == SCENE3) {
				image(BackImg, width / 2, height / 2);
				image(RightImg, width / 2, height / 2);
				if (AnomalyFlag && AnomalyTypeFlag == 6) {
					image(AnomalyImg[3], width / 2, height / 2);
				}
				else if (AnomalyFlag && AnomalyTypeFlag == 7) {
					image(AnomalyImg[4], width / 2, height / 2);
				}


				image(PlayerImg, player.px, player.py);
				image(BasicImg[4], width / 2, height / 2);
				if (AnomalyFlag && AnomalyTypeFlag == 8) {
					image(AnomalyImg[10], width / 2, height / 2);
				}
				else if (AnomalyFlag && AnomalyTypeFlag == 9) {
					image(AnomalyImg[11], width / 2, height / 2);
				}
				else if (AnomalyFlag && AnomalyTypeFlag == 10) {
					image(AnomalyImg[12], width / 2, height / 2);
				}
				image(FrameImg, width / 2, height / 2);
			}

			if (SCENE == SCENE4) {
				image(BackImg, width / 2, height / 2);
				image(RightImg, width / 2, height / 2);
				image(PlayerImg, player.px, player.py);
				image(BasicImg[5], width / 2, height / 2);

				if (AnomalyFlag && AnomalyTypeFlag == 11) {
					image(AnomalyImg[5], width / 2, height / 2);
				}
				if (AnomalyFlag && AnomalyTypeFlag == 12) {
					image(AnomalyImg[8], width / 2, height / 2);
				}
				if (AnomalyFlag && AnomalyTypeFlag == 13) {
					image(AnomalyImg[8], width / 2, height / 2);
				}
				image(FrameImg, width / 2, height / 2);
			}

			if (SCENE == SCENE5) {
				image(BackImg, width / 2, height / 2);
				image(RightImg, width / 2, height / 2);
				if (ClearNum == 9)image(BasicImg[6], width / 2, height / 2);
				image(PlayerImg, player.px, player.py);
				for (int i = 0; i < 10; i++) {
					if (ClearNum == i)image(NumberImg[i], width / 2, height / 2);
				}
				image(FrameImg, width / 2, height / 2);
			}
		}

		if (STATE == RESULT) {
			clear(0, 0, 0);
			rectMode(CENTER);
			image(BackImg, width / 2, height / 2);
			image(GameClearImg, width / 2, height / 2);	
			image(SpaceImg, width / 2, height / 2);
			image(FrameImg, width / 2, height / 2);

		}
	}
}