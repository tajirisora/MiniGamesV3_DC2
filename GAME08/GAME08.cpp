#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME08.h"
namespace GAME08
{
	int GAME::create()
	{
		BackImg = loadImage("..\\main\\assets\\game08\\Back.png");
		PlayGameImg[0] = loadImage("..\\main\\assets\\game08\\1.png");
		PlayGameImg[1] = loadImage("..\\main\\assets\\game08\\2.png");
		PlayGameImg[2] = loadImage("..\\main\\assets\\game08\\3.png");
		PlayGameImg[3] = loadImage("..\\main\\assets\\game08\\4.png");
		PlayGameImg[4] = loadImage("..\\main\\assets\\game08\\5.png");
		PlayGameImg[5] = loadImage("..\\main\\assets\\game08\\6.png");
		PlayGameImg[6] = loadImage("..\\main\\assets\\game08\\7.png");
		//PlayGameImg[7] = loadImage("..\\main\\assets\\game08\\8.png");
		//PlayGameImg[8] = loadImage("..\\main\\assets\\game08\\9.png");
		PlayGameImg[9] = loadImage("..\\main\\assets\\game08\\10.png");
		PlayGameImg[10] = loadImage("..\\main\\assets\\game08\\11.png"); //異変1 人のみ
		//PlayGameImg[11] = loadImage("..\\main\\assets\\game08\\12.png");
		PlayGameImg[12] = loadImage("..\\main\\assets\\game08\\13.png");



		return 0;
	}

	void GAME::proc()
	{
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
		image(BackImg, width / 2, height / 2);
		if (isTrigger(KEY_SPACE)) {
			init();
			STATE = PLAY;
		}

	}

	void GAME::init()
	{

	}

	void GAME::play()
	{
		draw();
		image(BackImg, width / 2, height / 2);
		image(PlayGameImg[0], width / 2, height / 2);
		image(PlayGameImg[1], width / 2, height / 2);
		image(PlayGameImg[2], width / 2, height / 2);
		image(PlayGameImg[3], width / 2, height / 2);
		image(PlayGameImg[4], width / 2, height / 2);
		image(PlayGameImg[5], width / 2, height / 2);
		image(PlayGameImg[6], width / 2, height / 2);
		//image(PlayGameImg[7], width / 2, height / 2);
		//image(PlayGameImg[8], width / 2, height / 2);
		image(PlayGameImg[10], width / 2, height / 2); //異変1
		image(PlayGameImg[12], width / 2, height / 2);
		//image(PlayGameImg[11], width / 2, height / 2);
		image(PlayGameImg[9], width / 2, height / 2); //上




		if (isTrigger(KEY_SPACE)) {
			STATE = RESULT;
		}
	}

	void GAME::result()
	{
		draw();
		image(BackImg, width / 2, height / 2);

		if (isTrigger(KEY_SPACE)) {
			init();
			STATE = TITLE;
		}

	}

	void GAME::draw()
	{
		if (STATE == TITLE) {
			//clear(0 , 0 , 250);
			rectMode(CENTER);
			image(BackImg, width / 2, height / 2);
		}
		if (STATE == PLAY) {
			clear(0 , 250 , 0);
			rectMode(CENTER);
			image(BackImg, width / 2, height / 2);
			image(PlayGameImg[0], width / 2, height / 2);
			image(PlayGameImg[1], width / 2, height / 2);
			image(PlayGameImg[2], width / 2, height / 2);
			image(PlayGameImg[3], width / 2, height / 2);
			image(PlayGameImg[4], width / 2, height / 2);
			image(PlayGameImg[5], width / 2, height / 2);
			image(PlayGameImg[6], width / 2, height / 2);
			//image(PlayGameImg[7], width / 2, height / 2);
			//image(PlayGameImg[8], width / 2, height / 2);
			image(PlayGameImg[10], width / 2, height / 2); //異変1
			image(PlayGameImg[12], width / 2, height / 2);
			//image(PlayGameImg[11], width / 2, height / 2);
			image(PlayGameImg[9], width / 2, height / 2); //上



		}
		if (STATE == RESULT) {
			clear(250 , 0 , 0);
			rectMode(CENTER);
			image(BackImg, width / 2, height / 2);

		}

	}
}
