#include"string.h"
#include "CONTAINER.h"
namespace GAME14 {
	void CONTAINER::load() {
		setData();
		setImage();
	}
	void CONTAINER::setData(){
		
		Data.title.backColor = COLOR(125.0f, 125.0f, 125.0f);
		Data.title.str = "スロカスシミュレター";
		Data.title.strSize = 150.0f;
		Data.title.strColor = COLOR(0.0f, 0.0f, 0.0f);
		Data.title.strPos = VECTOR2((width - Data.title.strSize * strlen(Data.title.str)/2) / 2.0f,
											height / 2.0f);
		Data.title.msg = "click to START...";
		Data.title.msgSize = 50.0f;
		Data.title.msgColor = COLOR(0.0f, 0.0f, 0.0f);
		Data.title.msgPos = VECTOR2((width - Data.title.msgSize * strlen(Data.title.msg) / 2) / 2.0f,
			                        height *3.0f/4.0f);
		float kyoutaiW = 1200;
		float kyoutaiH = height;
		float kyoutaiX = (width - kyoutaiW) / 2;
		float kyoutaiY = 0;
		float reeloffset = 350;
		float reelW = 250;
		float reelH = 400;

		Data.stop.numButton = 3;
		Data.stop.offset = 150.0f;
		Data.stopButton.r = (100.0f * 3.0f / 5.0f)/2.0f;
		Data.stopButton.basePos = VECTOR2(width / 2.0f, 960.0f);
		Data.stopButton.areaColor = COLOR(0.0f, 0.0f, 255.0f);
		Data.stopButton.filter = COLOR(255.0f, 255.0f, 255.0f,80.0f);
		Data.stopButton.imgSize = 1.0f;
		Data.stopButton.sistemFlag = false;
		Data.stopButton.drawFlag = false;
		Data.stopButton.filterFlag = false;
		Data.stop.imgAlterSize = 0.9f;

		Data.leverButton.basePos = VECTOR2(width / 2.0f- Data.stop.offset*2.50f, 960.0f);
		Data.leverButton.areaColor = COLOR(255.0f, 0.0f, 0.0f);
		Data.leverButton.filter = COLOR(255.0f, 255.0f, 255.0f, 80.0f);
		Data.leverButton.sistemFlag = false;
		Data.leverButton.drawFlag = false;
		Data.leverButton.filterFlag = false;
		Data.leverButton.r = (100.0f*4.0f/6.0f)/2.0f;
		Data.lever.moveDis = Data.leverButton.r / 3.50f;
		Data.lever.waitTime = 4.1f;

		Data.lottery.fileName = "../MAIN\\assets\\game14\\flag_prob.txt";
		Data.lottery.probFlagMax = 256 * 256;
		Data.lottery.levelFlagMax = 100;
		Data.lottery.levelWaite[LOTTERY::LEVEL_1] = 75;
		Data.lottery.levelWaite[LOTTERY::LEVEL_2] = 15;
		Data.lottery.levelWaite[LOTTERY::LEVEL_3] = 0;
		Data.lottery.levelWaite[LOTTERY::LEVEL_4] = 0;
		Data.lottery.levelWaite[LOTTERY::LEVEL_5] = 8;
		Data.lottery.levelWaite[LOTTERY::LEVEL_6] = 2;
		Data.lottery.separator = "/";

		Data.reel.reelNum = 3;
		Data.reel.cellNum = 21;
		VECTOR2 riruSize = Data.reel.reelSize = VECTOR2(250, 400);
		VECTOR2 cellSize = Data.reel.cellSize = VECTOR2(250, 400 / 3);
		float reelOffset = Data.reel.offset = 350.0f;
		Data.reel.bacePos = VECTOR2((width - riruSize.x * 3) / 2, kyoutaiY + reelOffset);
		Data.reel.offsetPos = VECTOR2(30, 10);
		Data.reel.imgPos = VECTOR2(Data.reel.bacePos.x+15, Data.reel.bacePos.y+cellSize.y*2-48);// -riruSize.y);
		Data.reel.imgSize = 0.22f;
		Data.reel.drawNum = 5;
		Data.reel.RPM = 10;//78.0f;
		Data.reel.NeedTime = (60.0f / Data.reel.RPM) / Data.reel.cellNum;

		Data.map.reelMapFile = "../MAIN\\assets\\game14\\reel_map.txt";
		Data.map.leftControlFile = "../MAIN\\assets\\game14\\left_first_control\\left_first_NO_BB.txt";
		Data.map.cols = Data.reel.reelNum + 2;
		Data.map.rows = Data.reel.cellNum;
		Data.map.separator = "/";

	}
	void CONTAINER::setImage(){
		Data.stopButton.img = 0;
		Data.reel.img[REEL::BONUS_A] = loadImage("../MAIN\\assets\\game14\\bonus.0.png");
		Data.reel.img[REEL::BONUS_B] = loadImage("../MAIN\\assets\\game14\\bonus.1.png");
		Data.reel.img[REEL::BAR]     = loadImage("../MAIN\\assets\\game14\\bar.2.png");
		Data.reel.img[REEL::REPLAY]  = loadImage("../MAIN\\assets\\game14\\replay.3.png");
		Data.reel.img[REEL::WATERMELON_A] = loadImage("../MAIN\\assets\\game14\\watermelonA.4.png");
		Data.reel.img[REEL::WATERMELON_B] = loadImage("../MAIN\\assets\\game14\\watermelonB.5.png");
		Data.reel.img[REEL::CHERRY] = loadImage("../MAIN\\assets\\game14\\cherry.6.png");
		Data.reel.img[REEL::BELL_A] = loadImage("../MAIN\\assets\\game14\\bellA.7.png");
		Data.reel.img[REEL::BELL_B] = loadImage("../MAIN\\assets\\game14\\bellB.8.png");


	}
}