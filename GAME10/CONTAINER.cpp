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
	Data.stage.GoalBoardImg = loadImage("..\\main\\assets\\game10\\kanban1.png");

	Data.result.resultImg = loadImage("..\\main\\assets\\game10\\title.png");
	for (int i = 0; i < 4; i++) {
		Data.stage.Lanes[i].LaneImg = loadImage("..\\main\\assets\\game10\\stageLane.png");
	}
	Data.stage.GoalImg = loadImage("..\\main\\assets\\game10\\goalTape.png");
	Data.player.playerImg = loadImage("..\\main\\assets\\game10\\playerImg.png");
	Data.player.timeImage = loadImage("..\\main\\assets\\game10\\timeImg.png");

	Data.enemy.Img[0] = loadImage("..\\main\\assets\\game10\\enemyImg00.png");
	Data.enemy.Img[1] = loadImage("..\\main\\assets\\game10\\enemyImg10.png");
	Data.enemy.Img[2] = loadImage("..\\main\\assets\\game10\\enemyImg20.png");

	Data.object.Img[0] = loadImage("..\\main\\assets\\game10\\objectImg00.png");
	Data.object.Img[1] = loadImage("..\\main\\assets\\game10\\objectImg10.png");
	Data.object.Img[2] = loadImage("..\\main\\assets\\game10\\objectImg20.png");

	Data.playerGauge.gaugeImg = loadImage("..\\main\\assets\\game10\\heartImg.png");

	Data.handgun.GunsImg = loadImage("..\\main\\assets\\game10\\HandgunImg.png");
	Data.shotgun.GunsImg = loadImage("..\\main\\assets\\game10\\shotgunImg.png");
	Data.handgunBullet.img = loadImage("..\\main\\assets\\game10\\Bullet.png");
	Data.shotGunBullet.img = loadImage("..\\main\\assets\\game10\\Bullet.png");
	Data.handgunBullet.imgShadow = loadImage("..\\main\\assets\\game10\\BulletShadow.png");
	Data.shotGunBullet.imgShadow = loadImage("..\\main\\assets\\game10\\BulletShadow.png");
}
void CONTAINER::setData(){
	Data.title.imgPos.x = 0;
	Data.title.imgPos.y = 0;
	Data.title.selectMy = 120;
	Data.title.textSize = 80;
	Data.title.selectX = 900;
	Data.title.selectY = 600;
	Data.title.crPos.x = 850;
	Data.title.crPos.y = 560;
	Data.title.rad = 50;
//ステージ
	Data.stage.imgPos.x = 0;
	Data.stage.imgPos.y = 0;
	Data.stage.frontPos.x = 0;
	Data.stage.frontPos.y = 100;
	Data.stage.frontMx = 4.5f;
	Data.stage.fImgNum = 6;
	Data.stage.frontImgNumber = -1;
	Data.stage.NofrontImg = -1;

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
	Data.stage.gPos.x = Width * (Data.stage.LaneLenNum - 1);//ゴールテープの位置
	Data.stage.gPos.y = Data.stage.opy;
	//看板
	Data.stage.bPos.x = Width * (Data.stage.LaneLenNum - 1) - 100;
	Data.stage.bPos.y = 400;

	//result
	Data.result.imgPos.x = 0;
	Data.result.imgPos.y = 0;

	//プレイヤー
	Data.player.Opos.x = 400;
	Data.player.Opos.y = 500;
	Data.player.ImgRight = 100;
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
	Data.player.initInvisibleTime = 150;
	Data.player.invisibleTime = 0;
	Data.player.Tpos.x = 900;
	Data.player.Tpos.y = 0;
	Data.player.timeLimit = 40;
	Data.player.weaponHaveNum = 0;
	//初期武器としてハンドガン所持
	for (int i = 0; i < Data.player.weaponNum; i++) {
		if (i == 0) {
			Data.player.weaponKind[i] = 0;
			Data.player.weaponHaveNum++;
		}
		else {
			Data.player.weaponKind[i] = -1;
		}
	}

	//敵データ
	Data.enemy.opos.x = width;
	Data.enemy.opos.y = 520;
	Data.enemy.my = Data.player.Pmy;
	Data.enemy.ohp = 200;
	Data.enemy.rightMx = 100;
	Data.enemy.totalNum = 50;
	Data.enemy.nowNum = 0;
	Data.enemy.speed = 6;
	Data.enemy.level = 1;
	Data.enemy.initIntervalDist = 1000;
	Data.enemy.callIntervalDist = Data.enemy.initIntervalDist;
	Data.enemy.sumTime = 500;
	Data.enemy.hitDamage = 2;
	Data.enemy.shortTime = 20;

	//障害物データ
	Data.object.opos.x = width;
	Data.object.opos.y = 520;
	Data.object.my = Data.player.Pmy;
	Data.object.ohp = 200;
	Data.object.rightMx = 100;
	Data.object.totalNum = 50;
	Data.object.nowNum = 0;
	Data.object.speed = 6;
	Data.object.level = 1;
	Data.object.initIntervalDist = 600;
	Data.object.callIntervalDist = Data.object.initIntervalDist;
	Data.object.sumTime = 300;
	Data.object.shortTime = 20;

	//HPゲージ
	Data.playerGauge.imgPos.x = 70;
	Data.playerGauge.imgPos.y = 920;
	Data.playerGauge.gaugePos.x = 200;
	Data.playerGauge.gaugePos.y = 930;
	Data.playerGauge.CurHp = 0;
	Data.playerGauge.gaugeMx = 40;
	Data.playerGauge.hpWidth = 20;
	Data.playerGauge.hpHeight = 90;

	Data.enemyGauge.curHp = 0;
	Data.enemyGauge.hpHeight = 15;
	Data.enemyGauge.MaxNumHp = Data.enemy.totalNum;
	Data.enemyGauge.hpWidth = 100;
	Data.enemyGauge.My = 155;

	Data.objectGauge.curHp = 0;
	Data.objectGauge.hpHeight = 15;
	Data.objectGauge.MaxNumHp = Data.object.totalNum;
	Data.objectGauge.hpWidth = 100;
	Data.objectGauge.My = 155;

	//武器
	Data.handgun.Pos.x = 1000;
	Data.handgun.Pos.y = 920;
	Data.handgun.speed = 15;
	Data.handgun.bulletNum = 1;
	Data.handgun.damage = 50;
	Data.handgun.ctIntervalTime = 60;
	Data.handgun.intervalTime = Data.handgun.ctIntervalTime;
	Data.handgun.Level = 1;

	Data.shotgun.Pos.x = 1200;
	Data.shotgun.Pos.y = 920;
	Data.shotgun.speed = 20;
	Data.shotgun.bulletNum = 3;
	Data.shotgun.damage = 150;
	Data.shotgun.ctIntervalTime = 90;
	Data.shotgun.intervalTime = Data.shotgun.ctIntervalTime;
	Data.shotgun.Level = 1;

	//時間
	Data.time.time = 3600;
	Data.time.frame = 60;
	Data.time.rewindTime = 480;
	Data.time.Pos.x = 1000;
	Data.time.Pos.y = 90;

	//距離
	Data.distance.loopNum = 0;
	Data.distance.standardDist = 1000.0;
	Data.distance.cntDist = Data.distance.standardDist /(Data.stage.gPos.x - Data.player.Opos.x);
	Data.distance.sumDist = 0;
	Data.distance.clearDist = 0;
	Data.distance.distPos.x = 400;
	Data.distance.distPos.y = 100;

	Data.handgunBullet.totalNum = 20;
	Data.handgunBullet.curNum = 0;
	Data.handgunBullet.speed = 4.0f;
	Data.handgunBullet.LaneMax = Data.stage.LaneNum;
	Data.handgunBullet.Bmy = Data.player.Pmy;
	Data.handgunBullet.RightX = 50;
	Data.handgunBullet.cRadius = 10;
	Data.handgunBullet.ImgHalf = 25;
	Data.handgunBullet.BulletNum = 1;

	Data.shotGunBullet.totalNum = 60;
	Data.shotGunBullet.curNum = 0;
	Data.shotGunBullet.speed = 0;
	Data.shotGunBullet.LaneMax = Data.stage.LaneNum;
	Data.shotGunBullet.Bmy = Data.player.Pmy;
	Data.shotGunBullet.RightX = 50;
	Data.shotGunBullet.img = 0;
	Data.shotGunBullet.cRadius = 10;
	Data.shotGunBullet.ImgHalf = 25;
	Data.shotGunBullet.BulletNum = 3;
}