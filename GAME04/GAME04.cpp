#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME04.h"
namespace GAME04
{
	int GAME::create()
	{
		d = new DATA;
		c = new CHARA;
		b = new BULLET;

		State = TITLE;
		d->Player.normalImg = loadImage("..\\main\\assets\\game04\\player1.png");
		d->Player.damageImg = loadImage("..\\main\\assets\\game04\\player2.png");

		d->Enemy.normalImg = loadImage("..\\main\\assets\\game04\\Enemy1.png");
		d->Enemy.damageImg = loadImage("..\\main\\assets\\game04\\Enemy2.png");

	//	d->BOSS.normalImg = loadImage("..\\main\\assets\\game04\\Boss1.png");

		d->PBullet.img = loadImage("..\\main\\assets\\game04\\PBullet.png");
		d->PBOM.img = loadImage("..\\main\\assets\\game04\\PBom.png");

		d->EBullet.img = loadImage("..\\main\\assets\\game04\\EBullet.png");
		//FireSoundN = loadImage("..\\main\\assets\\game04\\EBulletSnd.wav");

		d->titleImg = loadImage("..\\main\\assets\\game04\\title.png");
		d->backImg = loadImage("..\\main\\assets\\game04\\back1.png");
		return 0;
	}

	void GAME::destroy()
	{
		delete d;
		delete c;
		delete b;
	}



	void GAME::proc()
	{
		if (State == TITLE)Title(d);
		else if (State == PLAY)Play(d);
		else if (State == RESULT)Result(d);
	}

	void GAME::Title(DATA* d)
	{
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
		if (isTrigger(KEY_ESCAPE)) {
			main()->backToMenu();
		}
	}
	void GAME::Init(DATA* d)
	{
		d->Player.img = d->Player.normalImg;
		d->Player.px = 100.0f;
		d->Player.py = 540.0f;
		d->Player.vy = 15.0f;
		d->Player.hp = 15;
		d->Player.bulletOfsX = -70;

		d->Enemy.img = d->Enemy.normalImg;
		d->Enemy.px = 1540.0f;
		d->Enemy.py = 150.0f;
		d->Enemy.vy = 15.0f;
		d->Enemy.bulletOfsX = 55;
		d->Enemy.hp = 15;
		
		d->EBullet.px = 0.0f;
		d->EBullet.py = 0.0f;
		d->EBullet.vx = 300.0f;
		d->EBullet.hp = 0;

		d->PBullet.px = 0.0f;
		d->PBullet.py = 0.0f;
		d->PBullet.vx = 30.0f;
		d->PBullet.hp = 0;

		d->PBOM.px = 0.0f;
		d->PBOM.py = 0.0f;
		d->PBOM.vx = 15.0f;
		d->PBOM.hp = 0;
		d->PBOM.cnt = 7;
		//当たり判定用データ
		d->Player.halfW = 60;
		d->Player.halfH = 80;

		d->Enemy.halfW = 60;
		d->Enemy.halfH = 80;

		d->PBullet.halfW = 25;
		d->PBullet.halfH = 26;

		d->EBullet.halfW = 25;
		d->EBullet.halfH = 26;

		d->PBOM.halfW = 45;
		d->PBOM.halfH = 50;

		d->frameRestrictInput = 90;

	}
	void GAME::Play(DATA* d)
	{
		//プレイヤーを動かす
		if (isPress(KEY_W)) { d->Player.py += -d->Player.vy; }
		if (isPress(KEY_S)) { d->Player.py += d->Player.vy; }
		//プレイヤーの移動範囲制限
		if (d->Player.py < d->Player.halfH) {
			d->Player.py = d->Player.halfH;
		}
		if (d->Player.py > height - d->Player.halfH) {
			d->Player.py = height - d->Player.halfH;
		}
		//Bullet発射
		if (d->PBullet.hp == 0 && isTrigger(KEY_SPACE)) {

			//発射位置
			d->PBullet.px = d->Player.px - d->Player.bulletOfsX;
			d->PBullet.py = d->Player.py;
			d->PBullet.hp = 1;
		}
		//Bulletを動かす
		if (d->PBullet.hp > 0) {
			d->PBullet.px += d->PBullet.vx;
			//ウィンドウの外に出た
			if (d->PBullet.px > width) {
				d->PBullet.hp = 0;
			}
		}
		//PlayerBOM発射
		if (d->PBOM.hp == 0 && d->PBOM.cnt>0&& isTrigger(KEY_B)) {

			//発射位置
			d->PBOM.px = d->Player.px - d->Player.bulletOfsX;
			d->PBOM.py = d->Player.py;
			d->PBOM.hp = 1;
			d->PBOM.cnt--;
		}
		//PlayerBOMを動かす
		if (d->PBOM.hp > 0) {
			d->PBOM.px += d->PBOM.vx;
			//ウィンドウの外に出た
			if (d->PBOM.px > width) {
				d->PBOM.hp = 0;
			}
		}

		//Enemyを動かす
		d->Enemy.py +=d->Enemy.vy;
		if (d->Enemy.py<d->Enemy.halfH ||
			d->Enemy.py>height - d->Enemy.halfH) {
			//移動方向反転	
			d->Enemy.vy = -d->Enemy.vy;
		}
		//EnemyBullet発射
		if (d->EBullet.hp == 0) {
			playSound(FireSoundN);
			//発射位置
			d->EBullet.px = d->Enemy.px+d->Enemy.bulletOfsX;
			d->EBullet.py = d->Enemy.py;
			d->EBullet.hp = 1;
			d->EBullet.vx = -30;
		}
		//EnemyBulletMove
		if (d->EBullet.hp > 0) {
			d->EBullet.px += d->EBullet.vx;
			//ウィンドウの外に出た
			if (d->EBullet.px < 0) {
				d->EBullet.hp = 0;
			}
		}

		//当たり判定・Player&EnemyBullet
		if (Collision(&d->Player, &d->EBullet)) {
			
			d->Player.img = d->Player.damageImg;
			d->Player.hp--;
		}
		else {
			d->Player.img = d->Player.normalImg;
		}
		//あたり判定・Enemy&PlayerBullet
		if (Collision(&d->Enemy, &d->PBullet)) {

			d->Enemy.img = d->Enemy.damageImg;
			d->Enemy.hp--;
		}
		else {
			d->Enemy.img = d->Enemy.normalImg;
		}
		if (d->Enemy.hp == 0) {
			d->Enemy.vy = 0;
			for (int i = 120; i > 0; i--) {
				image(d->Enemy.damageImg, d->Enemy.px, d->Enemy.py);
			}
			if (d->Enemy.totalCnt <= 3) {
				d->Enemy.px = 1540.0f;
				d->Enemy.py = random() % 1080 + 100;
				d->Enemy.vy = 15.0f;
				d->Enemy.hp = 10;
				d->Enemy.Imghp = 1;
				d->Enemy.totalCnt++;
			}
		}
		//あたり判定・Enemy&PlayerBOM
		if (Collision(&d->Enemy, &d->PBOM)) {
			d->Enemy.img = d->Enemy.damageImg;
			d->Enemy.hp--;
		}
		else {
			d->Enemy.img = d->Enemy.normalImg;
		}
		if (d->Enemy.hp == 0) {
			d->Enemy.vy = 0;
			for (int i = 120; i > 0; i--) {
				image(d->Enemy.damageImg, d->Enemy.px, d->Enemy.py);
			}
			if (d->Enemy.totalCnt <= 3) {
				d->Enemy.px = 1540.0f;
				d->Enemy.py = random() % 1080 + 100;
				d->Enemy.vy = 15.0f;
				d->Enemy.hp = 10;
				d->Enemy.Imghp = 1;
				d->Enemy.totalCnt++;
			}
		}
		//勝負がついた
		if (d->Player.hp <= 0 || d->Enemy.hp <= 0) {
			//勝ち負け画像の切り替え
			if (d->Enemy.hp > 0) {//Enemy Win
				d->Enemy.img = d->Enemy.normalImg;
				d->Player.img = d->Player.damageImg;
				//playSound(GAMEOSound);
			}
			else {//Player Win
				d->Player.img = d->Player.normalImg;
				d->Enemy.img = d->Enemy.damageImg;
				//playSound(GAMECSound);
			}
			//Steate change
			//stopSound(BgmSound);
			d->frameCnt = d->frameRestrictInput;
			State = RESULT;
		}
		d->frameCnt = d->frameRestrictInput;
		Draw(d);
		textSize(100);
		text((let)d->Player.hp, 0, 200);
		if (d->Enemy.Imghp == 1) {
			text((let)d->Enemy.hp, 0, 300);
		}
		text((let)d->Enemy.totalCnt, 0, 500);
	}

	void GAME::Result(DATA* d)
	{
		//PlayerBullet & EnemyBulletを画面外まで移動
		if (d->PBullet.hp > 0) {
			d->PBullet.px += d->PBullet.vx;
			if (d->PBullet.px < -d->PBullet.halfW) {
				d->PBullet.hp = 0;
			}
		}
		if (d->PBOM.hp > 0) {
			d->PBOM.px += d->PBOM.vx;
			if (d->PBOM.px < -d->PBOM.halfW) {
				d->PBOM.hp = 0;
			}
		}
		if (d->EBullet.hp > 0) {
			d->EBullet.px += d->EBullet.vx;
			if (d->EBullet.px < -d->EBullet.halfW) {
				d->EBullet.hp = 0;
			}
		}
		Draw(d);
		//リスタート(数フレームループしないとスペースキーを押せない)
		if (d->frameCnt > 0) {
			d->frameCnt--;
		}
		else if (d->Player.hp > 0) {
			fill(255, 255, 0);
			printSize(150);
			print("GameClear!!");
			fill(0);
			text("SPACEでタイトルに戻る", 25, height);
			if (isTrigger(KEY_SPACE)) {
				State = TITLE;
			}
		}
		else {
			fill(255, 0, 0);
			printSize(150);
			print("GAME OVER");
			fill(0);
			text("EPACEでタイトルに戻る", 25, height);
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
		rectMode(CORNER);
		image(d->backImg, 0, 0);
		rectMode(CENTER);
		image(d->Player.img, d->Player.px, d->Player.py);
		image(d->Enemy.img, d->Enemy.px, d->Enemy.py);
		//Bullet
		if (d->PBullet.hp > 0) {
			image(d->PBullet.img, d->PBullet.px, d->PBullet.py);
		}
		if (d->PBOM.hp > 0) {
			image(d->PBOM.img, d->PBOM.px, d->PBOM.py);
		}
		if (d->EBullet.hp > 0) {
			image(d->EBullet.img, d->EBullet.px, d->EBullet.py);
		}
	}
	void GAME::HpGauge(CHARA* c)
	{
		strokeWeight(0);
		if (d->Player.hp > 10) {
			fill(0, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(c->px, c->py + c->hpGaugeOfsY, c->hpGaugeOfsY, 10);
	}
	
}
