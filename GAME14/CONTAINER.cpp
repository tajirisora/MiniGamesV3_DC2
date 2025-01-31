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
		Data.reel.checkLineNum = 5;
		Data.reel.combinationFileName = "../MAIN\\assets\\game14\\combi.txt";
		Data.reel.bonusCombinationFileName = "../MAIN\\assets\\game14\\bonus_combi.txt";
		Data.reel.separator = "/";
		VECTOR2 riruSize = Data.reel.reelSize = VECTOR2(250, 400);
		VECTOR2 cellSize = Data.reel.cellSize = VECTOR2(250, 400 / 3.15);
		float reelOffset = Data.reel.offset = 350.0f;
		Data.reel.bacePos = VECTOR2((width - riruSize.x * 3) / 2, kyoutaiY + reelOffset);
		Data.reel.offsetPos = VECTOR2(30, 10);
		Data.reel.imgPos = VECTOR2(Data.reel.bacePos.x + 15, Data.reel.bacePos.y + cellSize.y * 2 -40);// -riruSize.y);
		Data.reel.imgSize = 0.22f;
		Data.reel.drawNum = 5;
		Data.reel.RPM = 10;//78.0f;
		Data.reel.NeedTime = (60.0f / Data.reel.RPM) / Data.reel.cellNum;
		Data.reel.maxMoveRange = 4;

		Data.map.reelMapFile = "../MAIN\\assets\\game14\\reel_map.txt";
		Data.map.controlFile[REEL_MAP::LEFT_NO_BB]                = "../MAIN\\assets\\game14\\left_first_control\\left_first_NO_BB.txt";
		Data.map.controlFile[REEL_MAP::LEFT_RED_BB]               = "../MAIN\\assets\\game14\\left_first_control\\left_first_Red_BB.txt";
		Data.map.controlFile[REEL_MAP::LEFT_BLUE_BB]              = "../MAIN\\assets\\game14\\left_first_control\\left_first_Blue_BB.txt";
		Data.map.controlFile[REEL_MAP::LEFT_REG]                  = "../MAIN\\assets\\game14\\left_first_control\\left_first_REG.txt";
		Data.map.secondControlFile[REEL_MAP::TOP_TIME_NO_BB]      = "../MAIN\\assets\\game14\\right_second_control\\left_top_time_NO_BB.txt";
		Data.map.secondControlFile[REEL_MAP::TOP_TIME_RED_BB]     = "../MAIN\\assets\\game14\\right_second_control\\left_top_time_Red_BB.txt";
		Data.map.secondControlFile[REEL_MAP::TOP_TIME_BLUE_BB]    = "../MAIN\\assets\\game14\\right_second_control\\left_top_time_Blue_BB.txt";
		Data.map.secondControlFile[REEL_MAP::TOP_TIME_REG]        = "../MAIN\\assets\\game14\\right_second_control\\left_top_time_REG.txt";
		Data.map.secondControlFile[REEL_MAP::MIDDLE_TIME_NO_BB]   = "../MAIN\\assets\\game14\\right_second_control\\left_middle_time_NO_BB.txt";
		Data.map.secondControlFile[REEL_MAP::MIDDLE_TIME_RED_BB]  = "../MAIN\\assets\\game14\\right_second_control\\left_middle_time_Red_BB.txt";
		Data.map.secondControlFile[REEL_MAP::MIDDLE_TIME_BLUE_BB] = "../MAIN\\assets\\game14\\right_second_control\\left_middle_time_Blue_BB.txt";
		Data.map.secondControlFile[REEL_MAP::MIDDLE_TIME_REG]     = "../MAIN\\assets\\game14\\right_second_control\\left_middle_time_REG.txt";
		Data.map.secondControlFile[REEL_MAP::BOTTOM_TIME_NO_BB]   = "../MAIN\\assets\\game14\\right_second_control\\left_bottom_time_NO_BB.txt";
		Data.map.secondControlFile[REEL_MAP::BOTTOM_TIME_RED_BB]  = "../MAIN\\assets\\game14\\right_second_control\\left_bottom_time_Red_BB.txt";
		Data.map.secondControlFile[REEL_MAP::BOTTOM_TIME_BLUE_BB] = "../MAIN\\assets\\game14\\right_second_control\\left_bottom_time_Blue_BB.txt";
		Data.map.secondControlFile[REEL_MAP::BOTTOM_TIME_REG]     = "../MAIN\\assets\\game14\\right_second_control\\left_bottom_time_REG.txt";
		Data.map.secondControlFile[REEL_MAP::NO_TIME_NO_BB]       = "../MAIN\\assets\\game14\\right_second_control\\left_No_time_NO_BB.txt";
		Data.map.secondControlFile[REEL_MAP::NO_TIME_RED_BB]      = "../MAIN\\assets\\game14\\right_second_control\\left_No_time_Red_BB.txt";
		Data.map.secondControlFile[REEL_MAP::NO_TIME_BLUE_BB]     = "../MAIN\\assets\\game14\\right_second_control\\left_No_time_Blue_BB.txt";
		Data.map.secondControlFile[REEL_MAP::NO_TIME_REG]         = "../MAIN\\assets\\game14\\right_second_control\\left_No_time_REG.txt";
		Data.map.distinction_NO_BonusFile = "../MAIN\\assets\\game14\\distinction_NO_Bonus.txt";
		Data.map.distinction_BonusFile = "../MAIN\\assets\\game14\\distinction_Bonus.txt";
		Data.map.cols = Data.reel.reelNum + 2;
		Data.map.rows = Data.reel.cellNum;
		Data.map.separator = "/";
		Data.map.cellnum = Data.reel.cellNum;

		Data.credit.payoutFileName = "../MAIN\\assets\\game14\\payout.txt";
		Data.credit.separator = "/";
		Data.credit.drawPayoutPos = VECTOR2((kyoutaiX+kyoutaiW)/1.25, kyoutaiH / 1.253);
		Data.credit.drawPayoutColor = COLOR(255, 255, 0);
		Data.credit.drawPayoutSize = 70.0f;
		Data.credit.onePayoutTime = 0.18f;
		Data.credit.BBPayoutMaxNum = 280;
		Data.credit.REGPlayMaxTime = 12;

		Data.bet.maxBetNum = 3;
		Data.bet.turnBetNum = 3;
		Data.bet.oneBetTime = 0.08f;
		Data.bet.drawStr = "回胴";
		Data.bet.strSize = 70.0f;
		Data.bet.noBetColor = COLOR(125, 125, 125);
		Data.bet.betColor = COLOR(255, 255, 0);
		Data.bet.bacePos = VECTOR2((kyoutaiX+kyoutaiW)/3.55, kyoutaiH / 1.505);
		Data.bet.offsetPos = 133.0f;
		
		Data.max_bet_Button.basePos = VECTOR2(kyoutaiX+kyoutaiW/4.35, kyoutaiH / 1.23);
		Data.max_bet_Button.areaSize = VECTOR2(100, 25);
		Data.max_bet_Button.areaColor = COLOR(0, 255, 0);
		Data.max_bet_Button.filter = COLOR(255, 255, 255, 120);
		Data.max_bet_Button.filterFlag = false;
		Data.max_bet_Button.sistemFlag = false;
		Data.max_bet_Button.drawFlag = false;

		Data.max_betButton.moveDis = Data.max_bet_Button.areaSize.y / 2;
	}
	void CONTAINER::setImage(){
		Data.stopButton.img = 0;
		Data.reel.img[REEL::BONUS_A] = loadImage("../MAIN\\assets\\game14\\bonus.0.png");
		Data.reel.img[REEL::BONUS_B] = loadImage("../MAIN\\assets\\game14\\bonus.1.png");
		Data.reel.img[REEL::BAR_A]   = loadImage("../MAIN\\assets\\game14\\bar.2.png");
		Data.reel.img[REEL::BAR_B] = loadImage("../MAIN\\assets\\game14\\bar.3.png");
		Data.reel.img[REEL::REPLAY]  = loadImage("../MAIN\\assets\\game14\\replay.4.png");
		Data.reel.img[REEL::WATERMELON_A] = loadImage("../MAIN\\assets\\game14\\watermelonA.5.png");
		Data.reel.img[REEL::WATERMELON_B] = loadImage("../MAIN\\assets\\game14\\watermelonB.6.png");
		Data.reel.img[REEL::CHERRY] = loadImage("../MAIN\\assets\\game14\\cherry.7.png");
		Data.reel.img[REEL::BELL_A] = loadImage("../MAIN\\assets\\game14\\bellA.8.png");
		Data.reel.img[REEL::BELL_B] = loadImage("../MAIN\\assets\\game14\\bellB.9.png");


	}
}