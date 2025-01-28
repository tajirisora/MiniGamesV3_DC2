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
		Data.title.backScreenColor = { 128,128,128 };
		Data.title.size1 = 150;
		Data.title.color1 = { 0,0,0 };
		Data.title.pos1 = { 500,550 };
		Data.title.str1 = "スナイパー";
		Data.title.size2 = 50;
		Data.title.color2 = { 0,0,0 };
		Data.title.pos2 = { 650,750 };
		Data.title.str2 = "SPACEキーでスタート";
		//ステージデータ
		Data.stage.backScreenColor = { 128,128,128 };
		Data.stage.timer = 30.0f;
		Data.stage.curState = STAGE::CHOOSING_TYPE_ID;
		//リザルトデータ
		//CRank
		Data.rankC.backScreenColor = { 128,128,128 };
		Data.rankC.size1 = 150;
		Data.rankC.color1 = { 0,225,225 };
		Data.rankC.pos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankC.str1 = "C";
		Data.rankC.size2 = 50;
		Data.rankC.color2 = { 0,0,0 };
		Data.rankC.pos2 = { 550,750 };
		Data.rankC.str2 = "SPACEキーでタイトルに戻る";
		Data.rankC.size3 = 70;
		Data.rankC.color3 = { 0,0,0 };
		Data.rankC.pos3 = { width / 2 + 140,height / 2 + 35 };
		//BRank
		Data.rankB.backScreenColor = { 128,128,128 };
		Data.rankB.size1 = 150;
		Data.rankB.color1 = { 0,60,240 };
		Data.rankB.pos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankB.str1 = "B";
		Data.rankB.size2 = 50;
		Data.rankB.color2 = { 0,0,0 };
		Data.rankB.pos2 = { 550,750 };
		Data.rankB.str2 = "SPACEキーでタイトルに戻る";
		Data.rankB.size3 = 70;
		Data.rankB.color3 = { 0,0,0 };
		Data.rankB.pos3 = { width / 2 + 140,height / 2 + 35 };
		//ARank
		Data.rankA.backScreenColor = { 128,128,128 };
		Data.rankA.size1 = 150;
		Data.rankA.color1 = { 235,0,0 };
		Data.rankA.pos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankA.str1 = "A";
		Data.rankA.size2 = 50;
		Data.rankA.color2 = { 0,0,0 };
		Data.rankA.pos2 = { 550,750 };
		Data.rankA.str2 = "SPACEキーでタイトルに戻る";
		Data.rankA.size3 = 70;
		Data.rankA.color3 = { 0,0,0 };
		Data.rankA.pos3 = { width / 2 + 140,height / 2 + 35 };
		//SRank
		Data.rankS.backScreenColor = { 128,128,128 };
		Data.rankS.size1 = 150;
		Data.rankS.color1 = { 220,0,110 };
		Data.rankS.pos1 = { width / 2 - 75,height / 2 + 75 };
		Data.rankS.str1 = "S";
		Data.rankS.size2 = 50;
		Data.rankS.color2 = { 0,0,0 };
		Data.rankS.pos2 = { 550,750 };
		Data.rankS.str2 = "SPACEキーでタイトルに戻る";
		Data.rankS.size3 = 70;
		Data.rankS.color3 = { 0,0,0 };
		Data.rankS.pos3 = { width / 2 + 140,height / 2 + 35 };
		//判定表データ
		Data.judgeList.color = { 0,0,0 };
		Data.judgeList.size = 40;
		Data.judgeList.pos1 = { 0,40 };
		Data.judgeList.str1 = "S:15発以上";
		Data.judgeList.pos2 = { 0,80 };
		Data.judgeList.str2 = "A:10～14発";
		Data.judgeList.pos3 = { 0,120 };
		Data.judgeList.str3 = "B:5～9発";
		Data.judgeList.pos4 = { 0,160 };
		Data.judgeList.str4 = "C:0～4発";
		//プレイヤーデータ
		Data.player.img = 0;
		Data.player.pos = { 300,height / 2 };
		Data.player.angle = 0.0f;
		Data.player.scale = 0.2f;//288*216
		Data.player.speed = height / 3;
		Data.player.limmitH = 100.0f;
		//ターゲットデータ
		Data.target.img = 0;
		Data.target.pos = { width - 300,height / 2 };
		Data.target.angle = 0.0f;
		Data.target.scale = 0.1f;
		Data.target.speed = height / 3;
		Data.target.vec = 1;
		Data.target.limmitH = 80.0f;
		Data.target.collisionFlag = false;
		Data.target.collisionTimer = 0.2f;
		//バレットデータ
		Data.bullet.pos = { Data.player.pos.x,Data.player.pos.y };
		Data.bullet.angle = 90.0f;
		Data.bullet.scale = 0.05f;
		Data.bullet.speed = width / 10 * 4;
	}

	void CONTAINER::loadGraphic() {
		Data.player.type1 = loadImage("../MAIN/assets/game06/player1.png");
		Data.player.type2 = loadImage("../MAIN/assets/game06/player2.png");
		Data.target.type1 = loadImage("../MAIN/assets/game06/target1.png");
		Data.target.type2 = loadImage("../MAIN/assets/game06/target2.png");
		Data.bullet.img = loadImage("../MAIN/assets/game06/bullet.png");
	}
}