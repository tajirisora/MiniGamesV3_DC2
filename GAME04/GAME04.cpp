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
		d->Enemy.damage2Img = loadImage("..\\main\\assets\\game04\\Enemy3.png");

		d->BOSS.normalImg = loadImage("..\\main\\assets\\game04\\BOSS1.png");
		d->BOSS.damageImg = loadImage("..\\main\\assets\\game04\\BOSS2.png");

		d->PBullet.img = loadImage("..\\main\\assets\\game04\\PBullet.png");
		d->PBOM.img = loadImage("..\\main\\assets\\game04\\PBom.png");

		d->EBullet.img = loadImage("..\\main\\assets\\game04\\EBullet.png");

		d->BBullet.img = loadImage("..\\main\\assets\\game04\\BBullet.png");
		
		FireSoundP = loadSound("..\\main\\assets\\game04\\PBSound.wav");
		FireSoundE = loadSound("..\\main\\assets\\game04\\EBsound.wav");
		FireSoundPBOM = loadSound("..\\main\\assets\\game04\\PBOMSnd.wav");
		FireSoundB = loadSound("..\\main\\assets\\game04\\BBsound.wav");

		DamageSndP = loadSound("..\\main\\assets\\game04\\PdamageSnd.wav");
		DamageSndE = loadSound("..\\main\\assets\\game04\\EdamageSnd.wav");
		DamageSndB = loadSound("..\\main\\assets\\game04\\BdamageSnd.wav");

		BgmSound = loadSound("..\\main\\assets\\game04\\BGM.wav");

		GAMECSound = loadSound("..\\main\\assets\\game04\\GameClearSnd.wav");
		GAMEOSound = loadSound("..\\main\\assets\\game04\\GameOverSnd.wav");

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
		else if (State == CLEAR)Clear(d);
		else if (State == OVER)Over(d);
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
		textSize(80);
		text("Enterでメニューに戻る", 0, height);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}

	void GAME::Init(DATA* d)
	{
		d->Player.img = d->Player.normalImg;
		d->Player.px = 100.0f;
		d->Player.py = 540.0f;
		d->Player.vy = 15.0f;
		d->Player.hp = 30;
		d->Player.bulletOfsX = 500;
		d->Player.hpGaugeOfsY = -90;
		d->Player.MaxHp = d->Player.hp;

		d->Enemy.img = d->Enemy.normalImg;
		d->Enemy.px = 1540.0f;
		d->Enemy.py = 150.0f;
		d->Enemy.vy = 15.0f;
		d->Enemy.bulletOfsX = 55;
		d->Enemy.hpGaugeOfsY = -90;
		d->Enemy.hp = 10;
		d->Enemy.totalCnt = 3;
		d->Enemy.Imghp = 1;
		d->Enemy.MaxHp = d->Enemy.hp;
		d->Enemy.repoptimeFlag = true;
		d->Enemy.ColFlag = true;

		d->BOSS.img = d->BOSS.normalImg;
		d->BOSS.px = 1540.0f;
		d->BOSS.py = 150.0f;
		d->BOSS.vy = 10.0f;
		d->BOSS.bulletOfsX = 55;
		d->BOSS.hpGaugeOfsY = -90;
		d->BOSS.hp = 15;
		d->BOSS.Imghp = 1;
		d->BOSS.MaxHp = d->BOSS.hp;

		d->BBullet.px = 0;
		d->BBullet.py = 0;
		d->BBullet.vx = 30.0f;
		d->BBullet.hp = 0;

		d->EBullet.px = 0.0f;
		d->EBullet.py = 0.0f;
		d->EBullet.vx = 300.0f;
		d->EBullet.hp = 0;

		d->PBullet.px = 0.0f;
		d->PBullet.py = 0.0f;
		d->PBullet.vx = 25.0f;
		d->PBullet.hp = 0;

		d->PBOM.px = 0.0f;
		d->PBOM.py = 0.0f;
		d->PBOM.vx = 20.0f;
		d->PBOM.hp = 0;
		d->PBOM.cnt = 7;
		//当たり判定用データ
		d->Player.halfW = 60;
		d->Player.halfH = 80;

		d->Enemy.halfW = 75;
		d->Enemy.halfH = 65;

		d->BOSS.halfW = 80;
		d->BOSS.halfH = 100;

		d->PBullet.halfW = 50;
		d->PBullet.halfH = 24;

		d->EBullet.halfW = 50;
		d->EBullet.halfH = 26;

		d->PBOM.halfW = 45;
		d->PBOM.halfH = 50;

		d->BBullet.halfW = 35;
		d->BBullet.halfH = 40;

		d->frameRestrictInput = 90;

		hpWarning = d->Player.hp * 0.3f;
		hpDanger = d->Player.hp * 0.1f;

		hpWarning = d->Enemy.hp * 0.4f;
		hpDanger = d->Enemy.hp * 0.2f;
		
		hpWarning = d->BOSS.hp * 0.4f;
		hpDanger = d->BOSS.hp * 0.2f;

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
		if (d->PBullet.hp == 0 && isPress(KEY_SPACE)) {
			playSound(FireSoundP);
			//発射位置
			d->PBullet.px = d->Player.px + d->Player.bulletOfsX - 420;
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
		if (d->PBOM.hp == 0 && d->PBOM.cnt > 0 && isTrigger(KEY_B)) {
			playSound(FireSoundPBOM);
			//発射位置
			d->PBOM.px = d->Player.px + d->Player.bulletOfsX - 420;
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
		d->Enemy.py += d->Enemy.vy;
		if (d->Enemy.py<d->Enemy.halfH ||
			d->Enemy.py>height - d->Enemy.halfH) {
			//移動方向反転	
			d->Enemy.vy = -d->Enemy.vy;
		}
		//EnemyBullet発射
			
		if (d->EBullet.hp == 0&&d->Enemy.hp>0) {
			
				playSound(FireSoundE);
				//発射位置
				d->EBullet.px = d->Enemy.px + d->Enemy.bulletOfsX - 150;
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
		if (d->Enemy.totalCnt == 0) {
			d->Enemy.Imghp = 0;
			d->EBullet.hp = 0;
			stopSound(FireSoundE);
		}

		//BOSSを動かす
		d->BOSS.py += d->BOSS.vy;
		if (d->BOSS.py<d->BOSS.halfH ||
			d->BOSS.py>height - d->BOSS.halfH) {
			//移動方向反転
			d->BOSS.vy = -d->BOSS.vy;
		}

		//BOSSBullet発射
		if (d->BOSS.Imghp == 1 && d->Enemy.totalCnt == 0) {
			if (d->BBullet.hp == 0) {
				playSound(FireSoundB);
				//発射位置
				d->BBullet.px = d->BOSS.px + d->BOSS.bulletOfsX;
				d->BBullet.py = d->BOSS.py;
				d->BBullet.hp = 1;
			}
		}
		//BOSSBulletMove
		if (d->BBullet.hp >= 1) {
			d->BBullet.px -= d->BBullet.vx;
			//ウィンドウの外に出た
			if (d->BBullet.px < width - 1900) {
				d->BBullet.hp = 0;
			}
		}

		if (d->EBullet.hp <= 0) {
			EBHitFlag = false;
		}

		//当たり判定・Player&EnemyBullet
		if (Collision(&d->Player, &d->EBullet) && EBHitFlag == false) {
			playSound(DamageSndP);
			d->EBullet.hp = 0;
			d->Player.img = d->Player.damageImg;
			d->Player.hp -= 2;
			EBHitFlag = true;
		}
		else {
			d->Player.img = d->Player.normalImg;
		}
		//あたり判定・Enemy&PlayerBullet
		if (d->PBullet.hp <= 0) {
			PBHitFlag = false;
		}
		if (d->Enemy.ColFlag) {
			if (Collision(&d->Enemy, &d->PBullet) && PBHitFlag == false) {
				playSound(DamageSndE);
				d->Enemy.img = d->Enemy.damage2Img;
				d->PBullet.hp = 0;
				d->Enemy.hp--;
				PBHitFlag = true;
			}
			else {
				d->Enemy.img = d->Enemy.normalImg;
			}

			if (d->Enemy.hp <= 0) {
				if (d->Enemy.totalCnt > 0) {

					if (d->Enemy.repoptimeFlag) {
						d->Enemy.repoptime = 0;
						d->Enemy.repoptimeFlag = false;
					}
					if (d->Enemy.repoptime > 180) {
						d->Enemy.py = 0;
						if (d->Enemy.totalCnt > 0) {
							d->Enemy.px = 1540.0f;
							d->Enemy.py = 860.0f;
							d->Enemy.vy = 15.0f;
							d->Enemy.hp = 10;
							d->Enemy.totalCnt--;
							d->Enemy.Imghp = 1;
							d->Enemy.repoptimeFlag = true;
						}
					}
					else {
						d->Enemy.repoptime++;
					}
				}
			}
		}
		//あたり判定・Enemy&PlayerBOM
		if (d->PBOM.hp <= 0) {
			PBOMHitFlag = false;
		}
		if (d->Enemy.ColFlag) {
			if (Collision(&d->Enemy, &d->PBOM) && PBOMHitFlag == false) {
				playSound(DamageSndE);
				d->Enemy.img = d->Enemy.damage2Img;
				d->PBOM.hp = 0;
				d->Enemy.hp -= 5;
				PBOMHitFlag = true;
			}
			else {
				d->Enemy.img = d->Enemy.normalImg;
			}
			if (d->Enemy.hp <= 0) {
				if (d->Enemy.totalCnt > 0) {
					if (d->Enemy.repoptimeFlag) {
						d->Enemy.repoptime = 0;
						d->Enemy.repoptimeFlag = false;
					}
					if (d->Enemy.repoptime > 180) {
						d->Enemy.py = 0;

						if (d->Enemy.totalCnt > 0) {
							d->Enemy.px = 1540.0f;
							d->Enemy.py = 860.0f;
							d->Enemy.vy = 15.0f;
							d->Enemy.hp = 10;
							d->Enemy.Imghp = 1;
							d->Enemy.totalCnt--;
							d->Enemy.repoptimeFlag = true;
						}
					}
					else {
						d->Enemy.repoptime++;
					}
				}
			}
		}
		//当たり判定・Player&BBullet
		if (Collision(&d->Player, &d->BBullet)) {
			playSound(DamageSndP);
			d->BBullet.hp = 0;

			d->Player.img = d->Player.damageImg;
			d->Player.hp-=3;
		}
		else {
			d->Player.img = d->Player.normalImg;
		}
		//当たり判定・BOSS & PBullet
		if (d->BOSS.Imghp == 1 && d->Enemy.totalCnt == 0) {
			if (Collision(&d->BOSS, &d->PBullet)) {
				playSound(DamageSndB);
				d->PBullet.hp = 0;
				d->BOSS.img = d->BOSS.damageImg;
				d->BOSS.hp--;
			}
			else {
				d->BOSS.img = d->BOSS.normalImg;
			}
		}
		//当たり判定・BOSS & PBOM
		if (d->BOSS.Imghp == 1 && d->Enemy.totalCnt == 0) {
			d->Enemy.ColFlag = false;
			if (Collision(&d->BOSS, &d->PBOM)) {
				playSound(DamageSndB);
			d->PBOM.hp = 0;
				d->BOSS.img = d->BOSS.damageImg;
				d->BOSS.hp--;
			}
			else {
				d->BOSS.img = d->BOSS.normalImg;
			}
		}

		//描画
		Draw(d);

		//勝負がついた
		if (d->Player.hp <= 0 || d->BOSS.hp <= 0) {
			//勝ち負け画像の切り替え
			if (d->BOSS.hp > 0) {//BOSS Win
				d->BOSS.img = d->BOSS.normalImg;
				d->Player.img = d->Player.damageImg;
				//playSound(GAMEOSound);
				State = OVER;
		         playSound(GAMEOSound);
			}			
			else {//Player Win
				d->Player.img = d->Player.normalImg;
				d->BOSS.img = d->BOSS.damageImg;
				//playSound(GAMECSound);
				State = CLEAR;
		        playSound(GAMECSound);
			}			
		}
	
		//ステート切り替え
		d->frameCnt = d->frameRestrictInput;
	}

	void GAME::Clear(DATA* d)
	{
		stopSound(BgmSound);
		clear(0);
		fill(255);
		printSize(150);
		text("Game Clear!!", 100,100);
		fill(0);
		text("SPACEでタイトルに戻る", 25, height);
		if (d->BOSS.hp<=0) {
			if (isTrigger(KEY_SPACE)) {
			State = TITLE;				
		   stopSound(GAMECSound);
			}

		}
	}

	void GAME::Over(DATA* d)
	{
		stopSound(BgmSound);
		clear(0);
		fill(255);
		printSize(150);
		print("GAME OVER");
		fill(0);
		text("SPACEでタイトルに戻る", 25, height);
		if (isTrigger(KEY_SPACE)) {
			State = TITLE;		
		    stopSound(GAMEOSound);
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
		if (d->Enemy.hp <= 0) {
			d->Enemy.Imghp = 0;
		}
		if (d->Enemy.Imghp == 1) {
			HpGauge(&d->Enemy);
			image(d->Enemy.img, d->Enemy.px, d->Enemy.py);
		}
		if (d->BOSS.hp <= 0) {
			d->BOSS.Imghp = 0;
		}
		if (d->Enemy.totalCnt == 0 && d->BOSS.Imghp == 1) {
			HpGauge(&d->BOSS);
			image(d->BOSS.img, d->BOSS.px, d->BOSS.py);
		}
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

		if (d->BBullet.hp > 0) {
			image(d->BBullet.img, d->BBullet.px, d->BBullet.py);
		}
		
		HpGauge(&d->Player);

		//当たり判定表示エリア
		//fill(255, 255, 255, 128);
		//rect(d->Player.px, d->Player.py, d->Player.halfW * 2, d->Player.halfH * 2);
		//rect(d->Enemy.px, d->Enemy.py, d->Enemy.halfW * 2, d->Enemy.halfH * 2);
		//rect(d->BOSS.px, d->BOSS.py, d->BOSS.halfW * 2, d->BOSS.halfH * 2);

		//rect(d->PBullet.px, d->PBullet.py, d->PBullet.halfW * 2, d->PBullet.halfH * 2);
		//rect(d->PBOM.px, d->PBOM.py, d->PBOM.halfW * 2, d->PBOM.halfH * 2);
		//rect(d->EBullet.px, d->EBullet.py, d->EBullet.halfW * 2, d->EBullet.halfH * 2);
		//rect(d->BBullet.px, d->BBullet.py, d->BBullet.halfW * 2, d->BBullet.halfH * 2);

	}

	void GAME::HpGauge(CHARA*c)
	{
		strokeWeight(0);
		fill(128);
		rect(c->px, c->py + c->hpGaugeOfsY, c->MaxHp*6, 10);
		if (c->hp > hpWarning) {
			fill(0, 255, 0);
		}
		else if(c->hp > hpDanger){
			fill(255, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(c->px, c->py + c->hpGaugeOfsY, c->hp*6, 10);			
	}
	
}
