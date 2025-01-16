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
		Data.title.namePos.x = 650;
		Data.title.namePos.y = 550;
		Data.title.name = "射撃の達人";
		Data.title.guidanceSize = 50;
		Data.title.guidanceColor = { 0,0,0 };
		Data.title.guidancePos.x = 550;
		Data.title.guidancePos.y = 720;
		Data.title.guidance = "SPACEキーでステージへ進む";
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
		Data.resultC.namePos.x = width / 2 - 75;
		Data.resultC.namePos.y = height / 2 + 75;
		Data.resultC.name = "C";
		Data.resultC.guidanceSize = 50;
		Data.resultC.guidanceColor = { 0,0,0 };
		Data.resultC.guidancePos.x = 550;
		Data.resultC.guidancePos.y = 750;
		Data.resultC.guidance = "SPACEキーでタイトルに戻る";
		//BRank
		Data.resultB.backgroundColor = { 128,128,128 };
		Data.resultB.nameSize = 150;
		Data.resultB.nameColor = { 0,60,240 };
		Data.resultB.namePos.x = width / 2 - 75;
		Data.resultB.namePos.y = height / 2 + 75;
		Data.resultB.name = "B";
		Data.resultB.guidanceSize = 50;
		Data.resultB.guidanceColor = { 0,0,0 };
		Data.resultB.guidancePos.x = 550;
		Data.resultB.guidancePos.y = 750;
		Data.resultB.guidance = "SPACEキーでタイトルに戻る";
		//ARank
		Data.resultA.backgroundColor = { 128,128,128 };
		Data.resultA.nameSize = 150;
		Data.resultA.nameColor = { 235,0,0 };
		Data.resultA.namePos.x = width / 2 - 75;
		Data.resultA.namePos.y = height / 2 + 75;
		Data.resultA.name = "A";
		Data.resultA.guidanceSize = 50;
		Data.resultA.guidanceColor = { 0,0,0 };
		Data.resultA.guidancePos.x = 550;
		Data.resultA.guidancePos.y = 750;
		Data.resultA.guidance = "SPACEキーでタイトルに戻る";
		//SRank
		Data.resultS.backgroundColor = { 128,128,128 };
		Data.resultS.nameSize = 150;
		Data.resultS.nameColor = { 220,0,110 };
		Data.resultS.namePos.x = width / 2 - 75;
		Data.resultS.namePos.y = height / 2 + 75;
		Data.resultS.name = "S";
		Data.resultS.guidanceSize = 50;
		Data.resultS.guidanceColor = { 0,0,0 };
		Data.resultS.guidancePos.x = 550;
		Data.resultS.guidancePos.y = 750;
		Data.resultS.guidance = "SPACEキーでタイトルに戻る";
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