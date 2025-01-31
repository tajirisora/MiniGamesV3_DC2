#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
namespace GAME06
{
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}

	void CONTAINER::setData() {
		//タイトルデータ
		Data.title.backScreenColor = { 0,135,180 };
		Data.title.textColor1 = { 0,0,0 };
		Data.title.textSize1 = 150;
		Data.title.textPos1 = { 500,550 };
		Data.title.str1 = "スナイパー";
		Data.title.textColor2 = { 0,0,0 };
		Data.title.textSize2 = 50;
		Data.title.textPos2 = { 650,750 };
		Data.title.str2 = "SPACEキーでスタート";
		//ステージデータ
		Data.stage.backScreenColor = { 75,45,22 };
		Data.stage.timer = 30.0f;
		Data.stage.curState = STAGE::WAITING_FOR_DECIDING_TYPE_ID;
		//リザルトデータ
		//CRank
		Data.rankC.backScreenColor = { 128,128,128 };
		Data.rankC.textColor1 = { 0,225,225 };
		Data.rankC.textSize1 = 150;
		Data.rankC.textPos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankC.str1 = "C";
		Data.rankC.textColor2 = { 0,0,0 };
		Data.rankC.textSize2 = 50;
		Data.rankC.textPos2 = { 550,750 };
		Data.rankC.str2 = "SPACEキーでタイトルに戻る";
		Data.rankC.textColor3 = { 0,0,0 };
		Data.rankC.textSize3 = 70;
		Data.rankC.textPos3 = { width / 2 + 140,height / 2 + 35 };
		//BRank
		Data.rankB.backScreenColor = { 128,128,128 };
		Data.rankB.textColor1 = { 0,60,240 };
		Data.rankB.textSize1 = 150;
		Data.rankB.textPos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankB.str1 = "B";
		Data.rankB.textColor2 = { 0,0,0 };
		Data.rankB.textSize2 = 50;
		Data.rankB.textPos2 = { 550,750 };
		Data.rankB.str2 = "SPACEキーでタイトルに戻る";
		Data.rankB.textColor3 = { 0,0,0 };
		Data.rankB.textSize3 = 70;
		Data.rankB.textPos3 = { width / 2 + 140,height / 2 + 35 };
		//ARank
		Data.rankA.backScreenColor = { 128,128,128 };
		Data.rankA.textColor1 = { 235,0,0 };
		Data.rankA.textSize1 = 150;
		Data.rankA.textPos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankA.str1 = "A";
		Data.rankA.textColor2 = { 0,0,0 };
		Data.rankA.textSize2 = 50;
		Data.rankA.textPos2 = { 550,750 };
		Data.rankA.str2 = "SPACEキーでタイトルに戻る";
		Data.rankA.textColor3 = { 0,0,0 };
		Data.rankA.textSize3 = 70;
		Data.rankA.textPos3 = { width / 2 + 140,height / 2 + 35 };
		//SRank
		Data.rankS.backScreenColor = { 128,128,128 };
		Data.rankS.textColor1 = { 220,0,110 };
		Data.rankS.textSize1 = 150;
		Data.rankS.textPos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankS.str1 = "S";
		Data.rankS.textColor2 = { 0,0,0 };
		Data.rankS.textSize2 = 50;
		Data.rankS.textPos2 = { 550,750 };
		Data.rankS.str2 = "SPACEキーでタイトルに戻る";
		Data.rankS.textColor3 = { 0,0,0 };
		Data.rankS.textSize3 = 70;
		Data.rankS.textPos3 = { width / 2 + 140,height / 2 + 35 };
		//判定表データ
		Data.judgeList.textColor = { 0,0,0 };
		Data.judgeList.textSize = 40;
		Data.judgeList.textPos1 = { 0,40 };
		Data.judgeList.str1 = "S:6発以上";
		Data.judgeList.textPos2 = { 0,80 };
		Data.judgeList.str2 = "A:4～5発";
		Data.judgeList.textPos3 = { 0,120 };
		Data.judgeList.str3 = "B:1～3発";
		Data.judgeList.textPos4 = { 0,160 };
		Data.judgeList.str4 = "C:0発";
		//プレイヤーデータ
		Data.player.pos = { 330,height / 2 };
		Data.player.angle = 0.0f;
		Data.player.scale = 0.175f;//280*210
		Data.player.speed = height / 3;
		Data.player.limmitH = 100.0f;
		//ターゲットデータ
		Data.target.pos = { width - 330,height / 2 };
		Data.target.angle = 0.0f;
		Data.target.scale = 0.1f;//120*120
		Data.target.speed = height / 3;
		Data.target.vec = 1;
		Data.target.limmitH = 80.0f;
		Data.target.collisionFlag = false;
		Data.target.collisionDirectionTimer = 0.2f;
		//バレットデータ
		Data.bullet.pos = { Data.player.pos.x,Data.player.pos.y };
		Data.bullet.angle = 90.0f;
		Data.bullet.scale = 0.05f;//60*60
		Data.bullet.speed = width / 2;
	}

	void CONTAINER::loadGraphic() {
		Data.player.type1 = loadImage("../MAIN/assets/game06/player1.png");
		Data.player.type2 = loadImage("../MAIN/assets/game06/player2.png");
		Data.player.img = Data.player.type1;
		Data.target.type1 = loadImage("../MAIN/assets/game06/target1.png");
		Data.target.type2 = loadImage("../MAIN/assets/game06/target2.png");
		Data.target.img = Data.target.type1;
		Data.bullet.img = loadImage("../MAIN/assets/game06/bullet.png");
	}
}