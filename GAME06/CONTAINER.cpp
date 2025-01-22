#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
namespace GAME06{
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}

	void CONTAINER::setData() {
		//タイトルデータ
		Data.title.backgroundColor = { 128,128,128 };
		Data.title.nameSize = 150;
		Data.title.nameColor = { 0,0,0 };
		Data.title.namePos = { 650,550 };
		Data.title.name = "スナイパー";
		Data.title.guidanceSize = 50;
		Data.title.guidanceColor = { 0,0,0 };
		Data.title.guidancePos = { 550,750 };
		Data.title.guidance = "SPACEキーでスタート";
		//ステージデータ
		Data.stage.backgroundColor = { 128,128,128 };
		Data.stage.curTimer = 0.0f;
		Data.stage.initTimer = 30.0f;
		Data.stage.hitCounter = 0;
		//リザルトデータ
		//CRank
		Data.rankC.backgroundColor = { 128,128,128 };
		Data.rankC.nameSize = 150;
		Data.rankC.nameColor = { 0,225,225 };
		Data.rankC.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rankC.name = "C";
		Data.rankC.guidanceSize = 50;
		Data.rankC.guidanceColor = { 0,0,0 };
		Data.rankC.guidancePos = { 550,750 };
		Data.rankC.guidance = "SPACEキーでタイトルに戻る";
		Data.rankC.recodeSize = 70;
		Data.rankC.recodeColor = { 0,0,0 };
		Data.rankC.recodePos = { width / 2 + 140,height / 2 + 35 };
		//BRank
		Data.rankB.backgroundColor = { 128,128,128 };
		Data.rankB.nameSize = 150;
		Data.rankB.nameColor = { 0,60,240 };
		Data.rankB.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rankB.name = "B";
		Data.rankB.guidanceSize = 50;
		Data.rankB.guidanceColor = { 0,0,0 };
		Data.rankB.guidancePos = { 550,750 };
		Data.rankB.guidance = "SPACEキーでタイトルに戻る";
		Data.rankB.recodeSize = 70;
		Data.rankB.recodeColor = { 0,0,0 };
		Data.rankB.recodePos = { width / 2 + 140,height / 2 + 35 };
		//ARank
		Data.rankA.backgroundColor = { 128,128,128 };
		Data.rankA.nameSize = 150;
		Data.rankA.nameColor = { 235,0,0 };
		Data.rankA.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rankA.name = "A";
		Data.rankA.guidanceSize = 50;
		Data.rankA.guidanceColor = { 0,0,0 };
		Data.rankA.guidancePos = { 550,750 };
		Data.rankA.guidance = "SPACEキーでタイトルに戻る";
		Data.rankA.recodeSize = 70;
		Data.rankA.recodeColor = { 0,0,0 };
		Data.rankA.recodePos = { width / 2 + 140,height / 2 + 35 };
		//SRank
		Data.rankS.backgroundColor = { 128,128,128 };
		Data.rankS.nameSize = 150;
		Data.rankS.nameColor = { 220,0,110 };
		Data.rankS.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rankS.name = "S";
		Data.rankS.guidanceSize = 50;
		Data.rankS.guidanceColor = { 0,0,0 };
		Data.rankS.guidancePos = { 550,750 };
		Data.rankS.guidance = "SPACEキーでタイトルに戻る";
		Data.rankS.recodeSize = 70;
		Data.rankS.recodeColor = { 0,0,0 };
		Data.rankS.recodePos = { width / 2 + 140,height / 2 + 35 };
		//判定表データ
		Data.judgeList.textColor = { 0,0,0 };
		Data.judgeList.textSize = 40;
		Data.judgeList.pos1 = { 0,40 };
		Data.judgeList.str1 = "S:15発以上";
		Data.judgeList.pos2 = { 0,80 };
		Data.judgeList.str2 = "A:10～14発";
		Data.judgeList.pos3 = { 0,120 };
		Data.judgeList.str3 = "B:5～9発";
		Data.judgeList.pos4 = { 0,160 };
		Data.judgeList.str4 = "C:0～4発";
		//プレイヤーデータ
		Data.player.pos = { 100,height / 2 };
		Data.player.radius = 50;
		Data.player.advSpeed = 120;
		Data.player.fillColor = { 0,225,0 };
		Data.player.hp = 100;
		//エネミーデータ
		Data.enemy.pos = { width - 150,height / 2 };
		Data.enemy.radius = 100;
		Data.enemy.fillColor = { 235,0,185 };
		Data.enemy.hp = 150;
	}

	void CONTAINER::loadGraphic() {

	}
}