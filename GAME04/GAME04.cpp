#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME04.h"
namespace GAME04
{
	int GAME::create() {
		d = new DATA;
		c = new CHARA;
		b = new BULLET;

		State = TITLE;
		d->Player.normalImg = loadImage("..\\main\\assets\\game04\\player1.png");
		d->Player.damageImg = loadImage("..\\main\\assets\\game04\\player2.png");

		d->NPC.normalImg = loadImage("..\\main\\assets\\game04\\ENEMY1.png");
		d->NPC.damageImg = loadImage("..\\main\\assets\\game04\\ENEMY2.png");

		d->BOSS.normalImg = loadImage("..\\main\\assets\\game04\\BOSS1.png");
		d->BOSS.damageImg = loadImage("..\\main\\assets\\game04\\BOSS2.png");

		d->PBOM.img = loadImage("..\\main\\assets\\game04\\PLAYERBOM.png");
		d->PBullet.img = loadImage("..\\main\\assets\\game04\\PBullet.png");

		d->NBullet.img = loadImage("..\\main\\assets\\game04\\NBullet.png");

		d->BBullet.img = loadImage("..\\main\\assets\\game04\\BBullet.png");

		d->titleImg = loadImage("..\\main\\assets\\game04\\title.png");

		d->backImg = loadImage("..\\main\\assets\\game04\\back.png");

		FireSoundP = loadSound("..\\main\\assets\\game04\\PBsnd.wav");
		FireSoundN = loadSound("..\\main\\assets\\game04\\NBsnd.wav");
		FireSoundB = loadSound("..\\main\\assets\\game04\\BBsnd.wav");
		FireSoundBOM = loadSound("..\\main\\assets\\game04\\BOMsnd.wav");

		DamageSoundP = loadSound("..\\main\\assets\\game04\\DamageP.wav");
		DamageSoundN = loadSound("..\\main\\assets\\game04\\DamageN.wav");
		DamageSoundB = loadSound("..\\main\\assets\\game04\\DamageBOSS.wav");

		GAMECSound = loadSound("..\\main\\assets\\game04\\GAMEC.wav");
		GAMEOSound = loadSound("..\\main\\assets\\game04\\GAMEO.wav");
		
		BgmSound = loadSound("..\\main\\assets\\game04\\BGM.wav");

		return 0;
	}
	void GAME::destroy() {
		delete new DATA;
		delete new CHARA;
		delete new BULLET;
	}
	
	void GAME::proc() {
		if (State == TITLE)Title(d);
		else if (State == PLAY)Play(d);
		else if (State == RESULT)Result(d);
	}
	void GAME::Title(DATA* d)
	{
		playSound(BgmSound);

		rectMode(CORNER);
		clear();
		imageColor(255, 255, 255);
		image(d->titleImg, 0, 0);
		if (isTrigger(KEY_SPACE)) {
			Init(d);
			clear(0, 180, 0);
			State = PLAY;
			return;
		}
		fill(0);
		textSize(100);
		text("Enterでメニューに戻る", 0, height);
		print(4);
		//メニューに戻る-------------------------------------------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::Init(DATA* d)
	{
		d->Player.img = d->Player.normalImg;
		d->Player.px = 960.0f;
		d->Player.py = 970.0f;
		d->Player.vx = 15.0f;
		d->Player.vy = 15.0f;
		d->Player.hp = 10;
		d->Player.bulletOfsY = -70;		
	//	d->Player.hpGaugeOfsY = -60;

		
		d->NPC.img = d->NPC.normalImg;
		d->NPC.px = 960.0f;
		d->NPC.py = 150.0f;
		d->NPC.vx = 30.0f;
		d->NPC.vy = 30.0f;
		d->NPC.bulletOfsY = 55;
		d->NPC.hp = 10;	
	//	d->NPC.hpGaugeOfsY = -62;
		d->NPC.Imghp = 1;
		d->NPC.totalCnt = 0;

		d->BOSS.img = d->BOSS.normalImg;
		d->BOSS.px = 960.0f;
		d->BOSS.py = 150;
		d->BOSS.vx = 20.0f;
		d->BOSS.vy = 20.0f;
		d->BOSS.bulletOfsY = 55;
		d->BOSS.hp = 30;
		d->BOSS.Imghp = 1;
	//	d->BOSS.hpGaugeOfsY = -162;

		d->NBullet.px = 0.0f;
		d->NBullet.py = 0.0;
		d->NBullet.vy = 30.0f;
		d->NBullet.hp = 0;

		d->PBullet.px = -100.0f;
		d->PBullet.py = 0.0f;
		d->PBullet.vy = -100.0f;
		d->PBullet.hp = 0;

		d->BBullet.px = 0.0f;
		d->BBullet.py = 0.0f;
		d->BBullet.vy = 40.0f;
		d->BBullet.hp = 0;

		d->PBOM.px = 100.0f;
		d->PBOM.py = 0.0f;
		d->PBOM.vy = -50.0f;
		d->PBOM.hp = 0;
		d->PBOM.cnt = 7;

		//当たり判定用データ
		d->Player.halfW = 20;
		d->Player.halfH = 30;
		

		d->NPC.halfW = 20;
		d->NPC.halfH = 30;
		

		d->BOSS.halfW = 40;
		d->BOSS.halfH = 50;

		d->BBullet.halfW = 40;
		d->BBullet.halfH = 30;

		d->NBullet.halfW = 25;
		d->NBullet.halfH = 26;

		d->PBullet.halfW = 25;
		d->PBullet.halfH = 26;

		d->PBOM.halfW = 100;
		d->PBOM.halfH = 120;



		d->frameRestrictInput = 90;

	}
	void GAME::Play(DATA* d)
	{
		//プレイヤーを動かす
		if (isPress(KEY_A)) { d->Player.px += -d->Player.vx; }
		if (isPress(KEY_D)) { d->Player.px += d->Player.vx; }
		if (isPress(KEY_W)) { d->Player.py -= d->Player.vy; }
		if (isPress(KEY_S)) { d->Player.py -= -d->Player.vy; }
		//プレイヤーの移動範囲制限
		if (d->Player.px < d->Player.halfW) {
			d->Player.px = d->Player.halfW;
		}
		if (d->Player.py < d->Player.halfH) {
			d->Player.py = d->Player.halfH;
		}
		if (d->Player.px > width + d->Player.halfW) {
			d->Player.px = width + d->Player.halfW;
		}
		if (d->Player.py > height + d->Player.halfH) {
			d->Player.py = height - d->Player.halfH;
		}

		//	//弾発射
		if (d->PBullet.hp == 0 && isPress(KEY_SPACE)) {
			playSound(FireSoundP);
			//発射位置
			d->PBullet.px = d->Player.px;
			d->PBullet.py = d->Player.py + d->Player.bulletOfsY;
			d->PBullet.hp = 1;
		}
		//弾を動かす
		if (d->PBullet.hp > 0) {
			d->PBullet.py += d->PBullet.vy;
			//ウィンドウの外に出た
			if (d->PBullet.py < -d->PBullet.halfH) {
				d->PBullet.hp = 0;
			}
		}
		//BOM発射
		if (d->PBOM.hp == 0 && d->PBOM.cnt > 0 && isTrigger(KEY_B)) {
			playSound(FireSoundBOM);
			//発射位置
			d->PBOM.px = d->Player.px;
			d->PBOM.py = d->Player.py + d->Player.bulletOfsY;
			d->PBOM.hp = 1;
			d->PBOM.cnt--;
		}
		if (d->PBOM.cnt <= 0) {
			d->PBOM.hp = 0;
		}
		//弾を動かす
		if (d->PBOM.hp > 0) {
			d->PBOM.py += d->PBOM.vy;
			//ウィンドウの外に出た
			if (d->PBOM.py < -d->PBOM.halfH) {
				d->PBOM.hp = 0;
			}
		}
		//NPCを動かす
		d->NPC.px += d->NPC.vx;
		if (d->NPC.px < d->NPC.halfW ||
			d->NPC.px > width - d->NPC.halfW) {
			d->NPC.py += d->NPC.vy;
			if (d->NPC.py < d->NPC.halfH ||
				d->NPC.py > height - d->NPC.halfH);
			//移動方向反転
			d->NPC.vx = -d->NPC.vx;
			d->NPC.vy = +d->NPC.vy;
		}
		if (d->NPC.py > 1080) {
			d->NPC.py = -1;
		 }
		//弾発射
		if (d->NPC.Imghp == 1) {

			if (d->NBullet.hp == 0) {
				playSound(FireSoundN);
				//発射位置
				d->NBullet.px = d->NPC.px;
				d->NBullet.py = d->NPC.py + d->NPC.bulletOfsY;
				d->NBullet.hp = 1;
			}
		}
		//弾を動かす	
		if (d->NBullet.hp > 0) {
			d->NBullet.py += d->NBullet.vy;
			//ウィンドウの外に出た
			if (d->NBullet.py > height + d->NBullet.halfH) {
				d->NBullet.hp = 0;
			}
		}
		//ボスを動かす
		d->BOSS.px += d->BOSS.vx;
		if (d->BOSS.px < d->BOSS.halfW ||
			d->BOSS.px > width - d->BOSS.halfW) {
			d->BOSS.py += d->BOSS.vy;
			if (d->BOSS.py < d->BOSS.halfH ||
				d->BOSS.py > height - d->BOSS.halfH);
			//移動方向反転
			d->BOSS.vx = -d->BOSS.vx;
			d->BOSS.vy = +d->BOSS.vy;
		}
		if (d->BOSS.py > 1080) {
			d->BOSS.py = -1;
		}
		//ボス弾発射
		if (d->BOSS.Imghp == 1 && d->NPC.totalCnt == 4) {
			if (d->BBullet.hp == 0) {
				playSound(FireSoundB);
				//発射位置
				d->BBullet.px = d->BOSS.px;
				d->BBullet.py = d->BOSS.py + d->BOSS.bulletOfsY;
				d->BBullet.hp = 1;
			}
		}
		//弾を動かす	
		if (d->BBullet.hp > 0) {
			d->BBullet.py += d->BBullet.vy;
			//ウィンドウの外に出た
			if (d->BBullet.py > height + d->BBullet.halfH) {
				d->BBullet.hp = 0;
			}
		}
		//当たり判定・プレイヤーとN弾
		if (Collision(&d->Player, &d->NBullet)) {
			d->Player.img = d->Player.damageImg;
			d->Player.hp--;
		}
		else {
			d->Player.img = d->Player.normalImg;
		}
		//当たり判定・NPCとP弾
		if (Collision(&d->NPC, &d->PBullet))
		{
			playSound(DamageSoundN);
			d->NPC.img = d->NPC.damageImg;
			d->NPC.hp--;
		}
		else {
			d->NPC.img = d->NPC.normalImg;

		}
		if (d->NPC.hp == 0) {
			d->NPC.vx = 0;
			for (int i = 120; i > 0; i--) {
				image(d->NPC.damageImg, d->NPC.px, d->NPC.py);
			}
			if (d->NPC.totalCnt < 4) {
				d->NPC.px = random() % 1500+100;
				d->NPC.py= 150.0f;
				d->NPC.vx = 30.0f;
				d->NPC.hp = 10;
				d->NPC.Imghp = 1;
				d->NPC.totalCnt++;
			}
			
		}
		//当たり判定・プレイヤーとボス弾
		if (Collision(&d->Player, &d->BBullet)) {
			d->Player.img = d->Player.damageImg;
			d->Player.hp--;
		}
		else {
			d->Player.img = d->Player.normalImg;
		}
		//当たり判定・ボスとP弾
		if (d->BOSS.Imghp == 1 && d->NPC.totalCnt == 4) {
			if (Collision(&d->BOSS, &d->PBullet)) {
				d->BOSS.img = d->BOSS.damageImg;
				d->BOSS.hp--;
			}
			else {
				d->BOSS.img = d->BOSS.normalImg;
			}
		}
		//NPCとPBOM
		//当たり判定・NPCとP弾
		if (Collision(&d->NPC, &d->PBOM)) {
			d->NPC.img = d->NPC.damageImg;
			d->NPC.hp--;
		}
		else {
			d->NPC.img = d->NPC.normalImg;
		}
		//BOSSとPBOM
		if (d->BOSS.Imghp == 1 && d->NPC.totalCnt == 4) {
			if (Collision(&d->BOSS, &d->PBOM)) {
				d->BOSS.img = d->BOSS.damageImg;
				d->BOSS.hp--;
			}
			else {
				d->BOSS.img = d->BOSS.normalImg;
			}
		}
		//勝負がついた
	   
		if (d->Player.hp <= 0 || d->BOSS.hp <= 0) {
			//勝ち負け画像の切り替え	
			if (d->BOSS.hp > 0) {//BOSSが勝った
				d->BOSS.img = d->BOSS.normalImg;
				d->Player.img = d->Player.damageImg;
				playSound(GAMEOSound);
				stopSound(BgmSound);
				State = RESULT;
			}
			else {//プレイヤーが勝った
				d->Player.img = d->Player.normalImg;
				d->BOSS.img = d->BOSS.damageImg;
				playSound(GAMECSound);
				stopSound(BgmSound);
				State = RESULT;
			}
		}

		//ステート切り替え
		d->frameCnt = d->frameRestrictInput;
		Draw(d);
		textSize(100);
		text((let)d->Player.hp, 0, 200);
		if (d->NPC.Imghp == 1) {
			text((let)d->NPC.hp, 0, 300);
		}
		text((let)d->BOSS.hp, 0, 400);
		text(4-(let)d->NPC.totalCnt,0, 500);
	}
	void GAME::Result(DATA* d)
	{
		if (d->PBullet.hp > 0) {
			d->PBullet.py += d->PBullet.vy;
			if (d->PBullet.py < -d->PBullet.halfH) {
				d->PBullet.hp = 0;
			}
		}
		if (d->NBullet.hp > 0) {
			d->NBullet.py += d->NBullet.vy;
			if (d->NBullet.py > height + d->NBullet.halfH) {
				d->NBullet.hp = 0;
			}
		}
		if (d->BBullet.hp > 0) {
			d->BBullet.py += d->BBullet.vy;
			if (d->BBullet.py > height + d->BBullet.halfH) {
				d->BBullet.hp = 0;
			}
		}
		if (d->PBOM.hp > 0) {
			d->PBOM.py += d->PBOM.vy;
			if (d->PBOM.py < -d->PBOM.halfH) {
				d->PBOM.hp = 0;
			}
		}
		Draw(d);
		//リスタート（数フレームループしないとスペースキーを押せない)
		if (d->frameCnt > 0) {
			d->frameCnt--;
		}
		else if (d->Player.hp > 0) {
			fill(255, 255, 0);
			printSize(150);
			print("GameClear!");
			fill(0);
			text("SPACEでタイトルに戻る", 25, height);
			if (isTrigger(KEY_SPACE)) {
				State = TITLE;
			}
		}
		else {
			fill(250, 0, 0);
			printSize(150);
			print("GameOver...");
			fill(0);
			text("SPACEでタイトルに戻る", 25, height);
			if (isTrigger(KEY_SPACE)) {
				State = TITLE;
			}
		}
		
	}

	int GAME::Collision(CHARA* c, BULLET* b)
	{
		if (b->hp > 0) {
			float cRight = c->px + c->halfW;
			float cLeft = c->px - c->halfW;
			float cTop = c->py - c->halfH;
			float cBottom = c->py + c->halfH;

			float bRight = b->px + b->halfW;
			float bLeft = b->px - b->halfW;
			float bTop = b->py - b->halfH;
			float bBottom = b->py + b->halfH;
			if (cRight < bLeft || bRight < cLeft ||
				bBottom < cTop || cBottom < bTop) {
				//触れていない
				return 0;
			}
			else {
				//触れている
				return 1;
			}
		}

		return 0;
	}

	void GAME::Draw(DATA* d)
	{
		clear();
		//キャラ
		rectMode(CORNER);
		image(d->backImg, 0, 0);
		rectMode(CENTER);
		image(d->Player.img, d->Player.px, d->Player.py);
		if(d->NPC.hp<=0 ){
			d->NPC.Imghp = 0;
		}
		if (d->NPC.Imghp == 1) {
			image(d->NPC.img, d->NPC.px, d->NPC.py);
		}
		if (d->BOSS.hp <= 0) {
			d->BOSS.Imghp = 0;
		}
		if (d->NPC.totalCnt == 4 && d->BOSS.Imghp == 1) {
		image(d->BOSS.img, d->BOSS.px, d->BOSS.py);
		}
		//弾
		if (d->PBullet.hp > 0) {
			image(d->PBullet.img, d->PBullet.px, d->PBullet.py);
		}
		if (d->NBullet.hp > 0) {
			image(d->NBullet.img, d->NBullet.px, d->NBullet.py);
		}
		if (d->BBullet.hp > 0) {
			image(d->BBullet.img, d->BBullet.px, d->BBullet.py);
		}
		//BOM
		if (d->PBOM.hp > 0) {
			image(d->PBOM.img, d->PBOM.px, d->PBOM.py);
		}
		
	}

	
		
}
