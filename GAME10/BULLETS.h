#pragma once
#include "GAME10_GAME.h"
class BULLETS :public GAME_OBJECT10
{
public:
	struct DATA {
		int BulletSmx;//弾をプレイヤーの前から出すために少し移動させる為の値
		int totalNum;
		int curNum;
		int img;
		int imgShadow;
		int Bmy;//弾丸の位置
		int RightX;//画像の右側
		int LaneMax;
		float speed;
		float upSpeed;//速度上昇
		float maxSpeed;//最大スピード
		int upFlame;
		int nowFlame;
		float cRadius;
		int ImgHalf;
		int bulletShadowMy;
		int BulletNum;
		int EPGap;//敵とプレイヤーの画像の大きさの差
		int shotSound;
	};
protected:
	void SetBullets(const BULLETS::DATA& data);
	//共通データ
	DATA Bullet;
private:
	//単体データ配列
	struct BULLET {
		VECTOR2 pos;
		VECTOR2 vec;
		int Lane;
		//MISSILEの移動用のやつ
		float my;
		int nearLane;
		float nearEy;//近い敵の高さ
	};
protected:
	BULLET* Bullets;
public:
	BULLETS(class GAME10_GAME* game);
	~BULLETS();
	void init();
	virtual void create() {};
	virtual void launch(const VECTOR2& pos,float speed,int lane);
	virtual void update();
	void kill(int i);
	void AllKill();
	virtual void draw(int bulletKind);
	void BulletPMove(float PlayerSpeed);
	int BulletNum() { return Bullet.curNum; }
	float bulletLeft(int i) { return Bullets[i].pos.x; }
	float BulletRight(int i) { return Bullets[i].pos.x + Bullet.RightX; }
	int bulletLane(int i) { return Bullets[i].Lane; }
};

