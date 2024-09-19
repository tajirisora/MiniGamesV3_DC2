#include "CONTAINER.h"
#include"STAGE.h"
#include "../../libOne/inc/libOne.h"
CONTAINER::CONTAINER() {
	//stageのlaneの動的確保
	Data.stage.LaneNum = 4;
	Data.stage.Lanes = new STAGE::DATA::LANE[Data.stage.LaneNum];
}
CONTAINER::~CONTAINER() {
	delete[] Data.stage.Lanes;
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

	Data.hp_gause.gaugeImg = loadImage("..\\main\\assets\\game10\\heartImg.png");
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

	//HPゲージ
	Data.hp_gause.imgPos.x = 70;
	Data.hp_gause.imgPos.y = 920;
	Data.hp_gause.gaugePos.x = 200;
	Data.hp_gause.gaugePos.y = 930;
	Data.hp_gause.gaugeMx = 40;
	Data.hp_gause.hpWidth = 20;
	Data.hp_gause.hpHeight = 90;
}