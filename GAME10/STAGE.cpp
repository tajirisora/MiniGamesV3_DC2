#include "STAGE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
#include"GAME10_GAME.h"
#include"HANDGUN_BULLETS.h"
#include"ENEMYS.h"
#include"WEAPONS.h"
STAGE::STAGE(GAME10_GAME* game) :SCENE(game) {}
STAGE::~STAGE() {
}
void STAGE::init() {
	playSound(Stage.sound);
	Stage = game()->container()->stage();
	game()->player()->init();
	game()->time()->init();
	game()->distance()->init();
	game()->enemies()->init();
	game()->objects()->init();
	game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->init();
	game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->init();
	game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->init();
}
void STAGE::goalStage() {
	Stage.bworldX = NULL;
	Stage.fworldX = NULL;
	game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->AllKill();//弾丸を全部消す
	game()->bullets(GAME10_GAME::SHOTGUN_ID)->AllKill();//弾丸を全部消す
	game()->enemies()->AllKill();//敵を全部消す
	game()->objects()->AllKill();//オブジェクトを全部消す
	game()->player()->stageGoal();
}
void STAGE::appear() {
	game()->enemies()->appear();
	game()->objects()->appear();
}
void STAGE::update() {
	//ステージの強制スクロール（スピードはプレイヤーのスピードの依存する）
	if (Stage.gPos.x - Stage.fworldX > width / 2 
		&& (int)game()->player()->playerOpos().x == (int)game()->player()->playerPos().x) {
		Stage.frontMx = game()->player()->playerSpeed();
		Stage.fworldX += Stage.frontMx;
		if (game()->player()->playerSpeed() >= Stage.backMx) {
			Stage.bworldX += game()->player()->playerSpeed() - Stage.backMx;
		}
		game()->time()->timeCount();//強制スクロール中のみ時間が進む
		if(Stage.gPos.x - Stage.fworldX > width ){
			appear();//敵の出現だけ制限する
		}
	}
	//ゴールテープが画面の中央に来た時、プレイヤーだけ動くようにするために少しだけプレイヤーを動かす。
	else if(game()->player()->playerOpos().x == game()->player()->playerPos().x){
		game()->player()->playerMove();
	}
	
	//プレイヤーがgoalしたときの処理
	if (game()->player()->playerPos().x > width) {
		goalStage();
	}
	//エネミーのスピードを変える（プレイヤーの速度依存のため）
	game()->enemies()->update();
	game()->player()->update();
	game()->objects()->update();
}
void STAGE::create() {
	Stage = game()->container()->stage();
	game()->player()->create();
	game()->enemies()->create();
	game()->objects()->create();
	game()->distance()->create();
	game()->Hp_gauge(GAME10_GAME::PLAYERHP_ID)->create();
	game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->create();
	game()->Hp_gauge(GAME10_GAME::OBJECTHP_ID)->create();
}
void STAGE::draw() {
	clear(255);
	printSize(200);
	image(Stage.stageImg, Stage.imgPos.x, Stage.imgPos.y);
	for (int i = 0; i < Stage.bImgNum; i++) {
		image(Stage.backImg, (Stage.backPos.x + Stage.ImgLen * i) - Stage.bworldX, Stage.backPos.y);
	}
	for (int i = 0; i < Stage.fImgNum; i++) {
		image(Stage.frontImg, (Stage.frontPos.x + Stage.ImgLen * i) - Stage.fworldX, Stage.frontPos.y);
	}
	for (int j = 0; j < Stage.LaneLenNum; j++) {
		for (int i = 0; i < Stage.LaneNum; i++) {
			image(Stage.Lanes[i].LaneImg, (Stage.Lanes[i].Pos.x + width * j) - Stage.fworldX, Stage.Lanes[i].Pos.y);
		}
	}
	if (Stage.gPos.x - Stage.fworldX < width) {
		image(Stage.GoalImg, Stage.gPos.x - Stage.fworldX, Stage.gPos.y);
	}

	for (int LNum = 0; Stage.LaneNum > LNum; LNum++) {//描画の前後
		layer(LNum);
	}

	game()->time()->draw();
	Stage.DestNum = game()->player()->levelUpBorder() - (game()->enemies()->sumDestroy() + game()->objects()->sumDestroy());
	game()->distance()->draw();
	fill(255);
	textSize(Stage.DestTextSize);
	text("LEVEL UPまであと" +(let)Stage.DestNum +(let)"体", Stage.DestPos.x, Stage.DestPos.y);
}
void STAGE::sound() {
	playSound(Stage.sound);
}
void STAGE::layer(int drawLane) {
	for (int ENum = 0; ENum < game()->enemies()->EnemiesNum(); ENum++) {
		if (drawLane == game()->enemies()->EnemiesLane(ENum)) {
			game()->enemies()->draw(ENum);
		}
	}	

	for (int Onum = 0; Onum < game()->objects()->objectNum(); Onum++) {
		if (drawLane == game()->objects()->ObjectsLane(Onum)) {
			game()->objects()->draw(Onum);
		}
	}

	for (int HBNum = 0; game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->BulletNum() > HBNum;HBNum++) {
		if (drawLane == game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->bulletLane(HBNum)) {
			game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->draw(HBNum);
		}
	}

	for (int SBNum = 0; game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->BulletNum() > SBNum; SBNum++) {
		if (drawLane == game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->bulletLane(SBNum)) {
			game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->draw(SBNum);
		}
	}

	for(int MBNum = 0;game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->BulletNum()> MBNum;MBNum++){
		if (drawLane == game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->bulletLane(MBNum)) {
			game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->draw(MBNum);
		}
	}

	if (game()->player()->playerNowLane() == drawLane) {
		game()->player()->draw();
	}
}
void STAGE::nextScene() {
	//レベルアップした場合、selectへ
	if (game()->enemies()->sumDestroy() + game()->objects()->sumDestroy() >= game()->player()->levelUpBorder()) {
		game()->scenes(GAME10_GAME::SELECT_ID)->sound();
		game()->changeScene(GAME10_GAME::SELECT_ID);
	}
	//リザルトへ
	if (game()->time()->nowTime() - game()->time()->timeFlame() <= NULL - 1
		|| game()->player()->playerHp()<= NULL
		|| (game()->distance()->clearDist() <= game()->distance()->sumDist()
		&& game()->player()->playerPos().x>=width)) {
		stopSound(Stage.sound);
		game()->changeScene(GAME10_GAME::RESULT_ID);
		game()->scenes(GAME10_GAME::RESULT_ID)->sound();
	}
}
