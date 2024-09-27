#include "CONTAINER.h"
#include"STAGE.h"
#include"PLAYER.h"
#include "../../libOne/inc/libOne.h"
CONTAINER::CONTAINER() {
	//stageのlaneの動的確保
	Data.stage.LaneNum = 4;
	Data.stage.Lanes = new STAGE::DATA::LANE[Data.stage.LaneNum];
	Data.player.weaponNum = 3;
	Data.player.weaponKind = new int[Data.player.weaponNum];
}
CONTAINER::~CONTAINER() {
	delete[] Data.stage.Lanes;
	delete[] Data.player.weaponKind;
}
void CONTAINER::load(){
	setData();
	setImage();
}
void CONTAINER::setImage() {
	Data.title.titleImg = loadImage("..\\main\\assets\\game10\\title.png");

	Data.stage.stageImg = loadImage("..\\main\\assets\\game10\\stageImg.png");
	Data.stage.backImg = loadImage("..\\main\\assets\\game10\\backImg.png");
	Data.stage.frontImg = loadImage("..\\main\\assets\\game10\\frontImg.png");

	Data.result.resultImg = loadImage("..\\main\\assets\\game10\\title.png");
	for (int i = 0; i < 4; i++) {
		Data.stage.Lanes[i].LaneImg = loadImage("..\\main\\assets\\game10\\stageLane.png");
	}
	Data.stage.GoalImg = loadImage("..\\main\\assets\\game10\\goalTape.png");
	Data.player.playerImg = loadImage("..\\main\\assets\\game10\\playerImg.png");
	Data.player.timeImage = loadImage("..\\main\\assets\\game10\\timeImg.png");

	Data.hp_gause.gaugeImg = loadImage("..\\main\\assets\\game10\\heartImg.png");

	Data.handgun.GunsImg = loadImage("..\\main\\assets\\game10\\HandgunImg.png");
}
void CONTAINER::setData(){
	Data.title.imgPos.x = 0;
	Data.title.imgPos.y = 0;

//ステージ
	Data.stage.imgPos.x = 0;
	Data.stage.imgPos.y = 0;
	Data.stage.frontPos.x = 0;
	Data.stage.frontPos.y = 100;
	Data.stage.frontMx = 5.0f;
	Data.stage.fImgNum = 6;

	Data.stage.backPos.x = 0;
	Data.stage.backPos.y = 100;
	Data.stage.backMx = 2.2f;
	Data.stage.bImgNum = 5;
	Data.stage.ImgLen = 3000.0f;

	Data.stage.LaneLenNum = 8;
	Data.stage.opx = 0;
	Data.stage.opy = 640;
	Data.stage.My = 60;
	Data.stage.bworldX = 0;
	Data.stage.fworldX = 0;
	Data.stage.stopFlag = false;
	for (int i = 0; i < Data.stage.LaneNum; i++) {
		Data.stage.Lanes[i].Pos.y = Data.stage.opy + Data.stage.My * i;
		Data.stage.Lanes[i].Pos.x = Data.stage.opx;
		Data.stage.Lanes[i].LaneNumber = i;
	}
	//ゴールテープ
	Data.stage.gPos.x = Width * (Data.stage.LaneLenNum - 1);
	Data.stage.gPos.y = Data.stage.opy;
	//result
	Data.result.imgPos.x = 0;
	Data.result.imgPos.y = 0;
	//プレイヤー
	Data.player.Opos.x = 400;
	Data.player.Opos.y = 500;
	Data.player.maxSpeed = 10.0f;
	Data.player.minSpeed = 5.0f;
	Data.player.gearSpeed = 0.05f;
	Data.player.speed = 0;
	Data.player.nowLane = 1;
	Data.player.Pmy = 60;
	Data.player.hp = 16;
	Data.player.Pos.x = Data.player.Opos.x;
	Data.player.Pos.y = Data.stage.opy - Data.player.Pmy * Data.player.nowLane;
	Data.player.LaneMax = Data.stage.LaneNum;
	Data.player.Tpos.x = 900;
	Data.player.Tpos.y = 0;
	Data.player.timeLimit = 40;
	//初期武器としてハンドガン所持
	for (int i = 0; i < Data.player.weaponNum; i++) {
		if (i == 0) {
			Data.player.weaponKind[i] = 0;
			Data.player.weaponHaveNum = 1;
		}
		else {
			Data.player.weaponKind[i] = -1;
		}
	}

	//HPゲージ
	Data.hp_gause.imgPos.x = 70;
	Data.hp_gause.imgPos.y = 920;
	Data.hp_gause.gaugePos.x = 200;
	Data.hp_gause.gaugePos.y = 930;
	Data.hp_gause.CurHp = 0;
	Data.hp_gause.gaugeMx = 40;
	Data.hp_gause.hpWidth = 20;
	Data.hp_gause.hpHeight = 90;

	//武器
	Data.handgun.Pos.x = 1000;
	Data.handgun.Pos.y = 920;
	Data.handgun.bulletNum = 1;
	Data.handgun.damage = 100;
	Data.handgun.ctIntervalTime = 250;
	Data.handgun.intervalTime = Data.handgun.ctIntervalTime;
	Data.handgun.Level = 1;
}