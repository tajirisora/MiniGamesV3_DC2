#include"string.h"
#include "CONTAINER.h"
namespace GAME14 {
	void CONTAINER::load() {
		setData();
		setImage();
	}
	void CONTAINER::setData(){
		
		Data.title.backColor = COLOR(125.0f, 125.0f, 125.0f);
		Data.title.str = "スロットシミュレター";
		Data.title.strSize = 150.0f;
		Data.title.strColor = COLOR(0.0f, 0.0f, 0.0f);
		Data.title.strPos = VECTOR2((width - Data.title.strSize * strlen(Data.title.str)/2) / 2.0f,
											height / 2.0f);
		Data.title.msg = "click to START...";
		Data.title.msgSize = 50.0f;
		Data.title.msgColor = COLOR(0.0f, 0.0f, 0.0f);
		Data.title.msgPos = VECTOR2((width - Data.title.msgSize * strlen(Data.title.msg) / 2) / 2.0f,
			                        height -200);
		Data.title.msg2 = "push Enter to END";
		Data.title.msg2Pos = VECTOR2(width / 2, height - 100);
		
		Data.stage.textSize = 30.0f;
		Data.stage.startPos = VECTOR2(Data.stage.textSize / 2, Data.stage.textSize * 1.5);
		Data.stage.textColor = COLOR(255, 255, 255);
		Data.stage.offsetPosY = Data.stage.textSize + 5;
		Data.stage.kyoutaiSize1 = VECTOR2(1200, 338);
		Data.stage.kyoutaiSize2 = VECTOR2(222, height);
		float kyoutaiW = Data.stage.kyoutaiSize1.x;
		float kyoutaiH = Data.stage.kyoutaiSize1.y;
		Data.stage.kyoutaiPos1 = VECTOR2((width - kyoutaiW) / 2, 0);
		float kyoutaiX = Data.stage.kyoutaiPos1.x;
		Data.stage.kyoutaiPos2 = Data.stage.kyoutaiPos1;
		Data.stage.kyoutaiPos3 = VECTOR2((width - kyoutaiW) / 2, height-kyoutaiH+20);
		Data.stage.kyoutaiPos4 = VECTOR2(kyoutaiX + kyoutaiW - 220, 0);
		Data.stage.frameSize = VECTOR2(40, height);
		float fremuW = Data.stage.frameSize.x;
		Data.stage.leftFramePos = VECTOR2(kyoutaiX, 0);
		Data.stage.rightFramePos = VECTOR2(kyoutaiX + kyoutaiW - fremuW, 0);
		float rightframeX = Data.stage.rightFramePos.x;
		Data.stage.reelSize = VECTOR2(250, 430);
		float reelW = Data.stage.reelSize.x;
		float reelH = Data.stage.reelSize.y;
		Data.stage.reelStartPos = VECTOR2((width - reelW * 3) / 2, (height-reelH)/2+10);
		float reelX = Data.stage.reelStartPos.x;
		float reelY = Data.stage.reelStartPos.y;
		
		Data.stage.buttonAreaPos = VECTOR2(kyoutaiX, 910);
		Data.stage.buttonAreaSize = VECTOR2(kyoutaiW, 100);
		Data.stage.buttonAreaTopPos = VECTOR2(kyoutaiX, 885);
		Data.stage.buttonAreaTopSize = VECTOR2(kyoutaiW, 25);
		Data.stage.reelBangoSize = VECTOR2(150, 70);
		float reelbangoW = Data.stage.reelBangoSize.x;
		float reelbangoH = Data.stage.reelBangoSize.y;
		Data.stage.reelBangoPos = VECTOR2(reelX - reelbangoW-20 ,reelY+reelbangoH/2+15);
		float reelbangoX = Data.stage.reelBangoPos.x;
		float reelbangoY = Data.stage.reelBangoPos.y;
		Data.stage.reelBangoOffset = reelbangoH + 60;
		float reelBangoOffset = Data.stage.reelBangoOffset;
		Data.stage.kokutiranpuR = 130;
		float r = Data.stage.kokutiranpuR;
		Data.stage.kokutiranpuPos = VECTOR2(rightframeX - 105, 255);
		Data.stage.kokutiBonusranpuPos1 = VECTOR2(kyoutaiX + 60, 52);
		Data.stage.kokutiBonusranpuPos2 = VECTOR2(kyoutaiX + 60, 220);
		Data.stage.kokutiBonusranpuPos3 = VECTOR2(kyoutaiX + kyoutaiW - 230, 52);
		Data.stage.kokutiBonusranpuSize = VECTOR2(170, 100);
		Data.stage.creditPos = VECTOR2(reelX + 40, reelY + reelH + 20);
		Data.stage.creditSize = VECTOR2(120, 70);
		Data.stage.payoutPos = VECTOR2(1170, reelY + reelH + 20);
		Data.stage.payoutSize = VECTOR2(120, 70);
		Data.stage.textColor = COLOR(255, 255, 255);
		Data.stage.kyoutaiColor = COLOR(100, 0, 0);
		Data.stage.frameColor = COLOR(150, 150, 150);
		Data.stage.reelColor = COLOR(230, 230, 230);
		Data.stage.buttonAreaColor = COLOR(150, 150, 150);
		Data.stage.buttonAreaTopColor = COLOR(30, 30, 30);
		Data.stage.reelBangoColor = COLOR(0, 0, 0);
		Data.stage.kokutiranpuColor = COLOR(40, 0, 0);
		Data.stage.creditColor = COLOR(0, 0, 0);
		Data.stage.payoutColor = COLOR(0, 0, 0);

		Data.stage.text[0]  = "遊び方";
		Data.stage.text[1]  = "1.赤い四角いボタンを左";
		Data.stage.text[2]  = "クリックする";
		Data.stage.text[3]  = "2.黒い丸を左クリックす";
		Data.stage.text[4]  = "る";
		Data.stage.text[5]  = "3.青いボタンを左クリッ";
		Data.stage.text[6]  = "クしてリールを止める";
		Data.stage.text[7]  = "押す順番は左・右・中";
		Data.stage.text[8]  = " ";
		Data.stage.text[9]  = "ボーナスが入っていたら";
		Data.stage.text[10] = "祝の文字が黄色く光る";
		Data.stage.text[11] = "その他はどのボーナスが";
		Data.stage.text[12] = "入っているかを告知する";
		Data.stage.text[13] = " ";
		Data.stage.text[14] = "ビッグボーナス中";
		Data.stage.text[15] = "三連BARを1回ビタ止めす";
		Data.stage.text[16] = "ると枚数調整できる";
		Data.stage.text[17] = " ";
		Data.stage.text[18] = "レギュラーボーナス中";
		Data.stage.text[19] = "左リールに三連BARを";
		Data.stage.text[20] = "ビタ止めして";
		Data.stage.text[21] = "右リールの上中段に赤か";
		Data.stage.text[22] = "青のBB図柄を止める";
		Data.stage.text[23] = "中リールにBARを止める";
		Data.stage.text[24] = "ことで最高払い出しにな";
		Data.stage.text[25] = "る";
		Data.stage.text[26] = " ";
		Data.stage.text[27] = "終わり方";
		Data.stage.text[28] = "終わるときは赤い丸を長";
		Data.stage.text[29] = "押しする";
		Data.stage.numText = 30;
		Data.stage.numReel = 3;

		Data.stage.text2Pos = VECTOR2(width / 2, 250);
		Data.stage.text2Size = 170;
		Data.stage.text2 = "傷 物 語";
		Data.stage.text2Color = COLOR(0, 0, 0);


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
		Data.stop.waiteTime = 0.6f;

		Data.leverButton.basePos = VECTOR2(width / 2.0f- Data.stop.offset*2.50f, 960.0f);
		Data.leverButton.areaColor = COLOR(0.0f, 0.0f, 0.0f);
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

		Data.reel.BBAdjustImgId = 3;
		Data.reel.reelNum = 3;
		Data.reel.cellNum = 21;
		Data.reel.checkLineNum = 5;
		Data.reel.combinationFileName = "../MAIN\\assets\\game14\\combi.txt";
		Data.reel.bonusCombinationFileName = "../MAIN\\assets\\game14\\bonus_combi.txt";
		Data.reel.separator = "/";
		VECTOR2 riruSize = Data.reel.reelSize = VECTOR2(250, 400);
		VECTOR2 cellSize = Data.reel.cellSize = VECTOR2(250, 400 / 3.15);
		float reelOffset = Data.reel.offset = 350.0f;
		Data.reel.bacePos = VECTOR2((width - riruSize.x * 3) / 2, reelOffset);
		Data.reel.offsetPos = VECTOR2(30, 10);
		Data.reel.imgPos = VECTOR2(Data.reel.bacePos.x + 15, Data.reel.bacePos.y + cellSize.y * 2 -40);// -riruSize.y);
		Data.reel.imgSize = 0.22f;
		Data.reel.drawNum = 5;
		Data.reel.RPM = 78.0f;
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
		Data.credit.drawPayoutPos = VECTOR2((kyoutaiX+kyoutaiW)/1.25,height / 1.253-5);
		Data.credit.drawPayoutColor = COLOR(255, 255, 0);
		Data.credit.drawPayoutSize = 70.0f;
		Data.credit.drawBBPayoutPos = VECTOR2(kyoutaiX + kyoutaiW / 3.5, height / 1.253-5);
		Data.credit.onePayoutTime = 0.18f;
		Data.credit.BBPayoutMaxNum = 280;
		Data.credit.REGPayoutMaxTime = 8;

		Data.bet.maxBetNum = 3;
		Data.bet.turnBetNum = 3;
		Data.bet.oneBetTime = 0.08f;
		Data.bet.drawStr = "回胴";
		Data.bet.strSize = 70.0f;
		Data.bet.noBetColor = COLOR(125, 125, 125);
		Data.bet.betColor = COLOR(255, 255, 0);
		Data.bet.bacePos = VECTOR2(reelbangoX+4, reelbangoY+reelBangoOffset*2+Data.bet.strSize);
		Data.bet.offsetPos = 130.0f;
		
		Data.max_bet_Button.basePos = VECTOR2(kyoutaiX+kyoutaiW/4.35, height / 1.23);
		Data.max_bet_Button.areaSize = VECTOR2(100, 25);
		Data.max_bet_Button.areaColor = COLOR(255, 125, 125,210);
		Data.max_bet_Button.filter = COLOR(255, 255, 255, 120);
		Data.max_bet_Button.filterFlag = false;
		Data.max_bet_Button.sistemFlag = false;
		Data.max_bet_Button.drawFlag = false;
		Data.max_betButton.moveDis = Data.max_bet_Button.areaSize.y / 2;

		Data.player.statusDrawAreaPos = VECTOR2(kyoutaiX+kyoutaiW, 0);
		Data.player.statusDrawAreaSize = VECTOR2(Width-Data.player.statusDrawAreaPos.x, Height);
		Data.player.statusDrawAreaColor = COLOR(0, 0, 0);

		Data.player.nameSize = 50.0f;
		Data.player.nameDrawStartPos = VECTOR2(Data.player.statusDrawAreaPos.x + Data.player.nameSize/2, Data.player.nameSize*2);
		Data.player.offsetForName = 60.0f;
		Data.player.drawNumSize = 50;
		Data.player.drawNumPosX = Data.player.nameDrawStartPos.x + 200;
		Data.player.drawNumColor = COLOR(255, 255, 255);
		Data.player.numStatus = 8;
		Data.player.oneStatusSize = Data.player.nameSize+
			                        Data.player.drawNumSize+
			                        20.0f;

		Data.player.curPlayTimeNameColor = COLOR(0, 255, 0);
		Data.player.textCurPlayTimeName = "総回転数";
		Data.player.playTimeForBonusNameColor = COLOR(150, 255, 0);
		Data.player.textplayTimeForBonusName = "回転数";
		Data.player.curMedalNameColor = COLOR(225, 125, 0);
		Data.player.textCurMedalName = "差枚数";
		Data.player.curBBTimeNameColor = COLOR(255, 0, 0);
		Data.player.textCurBBTimeName = "BB回数";
		Data.player.BBRatioNameColor = COLOR(255, 0, 0);
		Data.player.textBBRatioName = "BB確率";
		Data.player.curREGTimeNameColor = COLOR(255, 255, 0);
		Data.player.textCurREGTimeName = "REG回数";
		Data.player.REGRatioNameColor = COLOR(255, 255, 0);
		Data.player.textREGRatioName = "REG確率";
		Data.player.BonusRatioNameColor = COLOR(0, 150, 255);
		Data.player.textBonusRatioName = "ボーナス確率";

		Data.bonus_announce.imgPos[BONUS_ANNOUNCE::RED_BB] = VECTOR2(kyoutaiX +70, Height/40);
		Data.bonus_announce.imgPos[BONUS_ANNOUNCE::BLUE_BB] = VECTOR2(kyoutaiX + 70, Height / 5.5);
		Data.bonus_announce.imgPos[BONUS_ANNOUNCE::REG] = VECTOR2((kyoutaiX + kyoutaiW) - (kyoutaiW / 5.5), Height / 40);
		Data.bonus_announce.imgSize = 0.15f;
		Data.bonus_announce.imgDefaltColor = COLOR(125, 125, 125);
		Data.bonus_announce.imgAnnounceColor = COLOR(255, 255, 255);
		Data.bonus_announce.announceText = "祝";
		Data.bonus_announce.textSize = 110.0f;
		Data.bonus_announce.drawPos = VECTOR2(kyoutaiX + kyoutaiW-203, Height/3.5);
		Data.bonus_announce.defaltColor = COLOR(80, 80, 80);
		Data.bonus_announce.announceColor = COLOR(255, 255, 0);
		Data.bonus_announce.announceMaxPlayTime = 5;
		Data.bonus_announce.announceBonusTypeTime = 5;

		Data.endButton.basePos = VECTOR2(kyoutaiX + kyoutaiW / 3.8, Height / 1.1);
		Data.endButton.r = 18.0f;
		Data.endButton.areaColor = COLOR(180, 40, 40);
		Data.endButton.filter = COLOR(255, 255, 255, 80);
		Data.endButton.filterFlag = false;
		Data.endButton.sistemFlag = false;
		Data.endButton.drawFlag = false;
		Data.end.stateMoveTime = 1.5f;

		Data.result.backColor = COLOR(150, 150, 150);
		Data.result.text = "リザルトーショップ";
		Data.result.textPos = VECTOR2(Width / 2, Height / 3);
		Data.result.textColor = COLOR(115, 255, 0);
		Data.result.textSize = 150.0f;
		Data.result.messageColor = COLOR(255, 255, 255);
		Data.result.message = "push Z to title...";
		Data.result.messagePos = VECTOR2(Width / 2, height - 200);
		Data.result.messageSize = 50.0f;
		Data.result.message2 = "push Enter to END";
		Data.result.message2Pos = VECTOR2(Width / 2, height - 100);

		Data.result.resultNumText = "差枚数";
		Data.result.resultNumPos = VECTOR2(Width / 2, Height / 2);
		Data.result.resultNumColor = COLOR(0, 0, 0);
		Data.result.resultNumSize = 100.0f;
		Data.result.resultText = "収支";
		Data.result.resultPos = VECTOR2(Width / 2, Height / 1.5);
		Data.result.resultWinColor = COLOR(0, 0, 255);
		Data.result.resultLossColor = COLOR(255, 0, 0);
		Data.result.resultSize = 100.0f;
		Data.result.rato = 20;

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

		Data.bonus_announce.bonusTypeImg[BONUS_ANNOUNCE::RED_BB] = Data.reel.img[REEL::BONUS_A];
		Data.bonus_announce.bonusTypeImg[BONUS_ANNOUNCE::BLUE_BB] = Data.reel.img[REEL::BONUS_B];
		Data.bonus_announce.bonusTypeImg[BONUS_ANNOUNCE::REG] = Data.reel.img[REEL::BAR_A];
	}
}