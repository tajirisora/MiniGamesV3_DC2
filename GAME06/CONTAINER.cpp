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
		Data.title.name = "射撃の達人";
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
		Data.resultC.backgroundColor = { 128,128,128 };
		Data.resultC.nameSize = 150;
		Data.resultC.nameColor = { 0,225,225 };
		Data.resultC.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.resultC.name = "C";
		Data.resultC.guidanceSize = 50;
		Data.resultC.guidanceColor = { 0,0,0 };
		Data.resultC.guidancePos = { 550,750 };
		Data.resultC.guidance = "SPACEキーでタイトルに戻る";
		//BRank
		Data.resultB.backgroundColor = { 128,128,128 };
		Data.resultB.nameSize = 150;
		Data.resultB.nameColor = { 0,60,240 };
		Data.resultB.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.resultB.name = "B";
		Data.resultB.guidanceSize = 50;
		Data.resultB.guidanceColor = { 0,0,0 };
		Data.resultB.guidancePos = { 550,750 };
		Data.resultB.guidance = "SPACEキーでタイトルに戻る";
		//ARank
		Data.resultA.backgroundColor = { 128,128,128 };
		Data.resultA.nameSize = 150;
		Data.resultA.nameColor = { 235,0,0 };
		Data.resultA.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.resultA.name = "A";
		Data.resultA.guidanceSize = 50;
		Data.resultA.guidanceColor = { 0,0,0 };
		Data.resultA.guidancePos = { 550,750 };
		Data.resultA.guidance = "SPACEキーでタイトルに戻る";
		//SRank
		Data.resultS.backgroundColor = { 128,128,128 };
		Data.resultS.nameSize = 150;
		Data.resultS.nameColor = { 220,0,110 };
		Data.resultS.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.resultS.name = "S";
		Data.resultS.guidanceSize = 50;
		Data.resultS.guidanceColor = { 0,0,0 };
		Data.resultS.guidancePos = { 550,750 };
		Data.resultS.guidance = "SPACEキーでタイトルに戻る";
		//判定基準データ
		Data.judgeList.textColor = { 0,0,0 };
		Data.judgeList.textSize = 40;
		Data.judgeList.pos_S = { 0,40 };
		Data.judgeList.str_S = "S:15発以上";
		Data.judgeList.pos_A = { 0,80 };
		Data.judgeList.str_A = "A:10～14発";
		Data.judgeList.pos_B = { 0,120 };
		Data.judgeList.str_B = "B:5～9発";
		Data.judgeList.pos_C = { 0,160 };
		Data.judgeList.str_C = "C:0～4発";
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