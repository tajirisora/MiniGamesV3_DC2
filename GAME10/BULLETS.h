#pragma once
#include "GAME10_GAME.h"
class BULLETS :public GAME_OBJECT10
{
public:
	struct DATA {
		int totalNum;
		int curNum;
		int img;
		int imgShadow;
		int Bmy;//弾丸の位置
		int RightX;//画像の右側
		int LaneMax;
		float speed;
		float cRadius;
		int ImgHalf;
		int BulletNum;
	};
protected:
	void SetBullets(const BULLETS::DATA& data);
private:
	//共通データ
	DATA Bullet;
	//単体データ配列
	struct BULLET {
		VECTOR2 pos;
		VECTOR2 vec;
		int Lane;
	};
	BULLET* Bullets;
public:
	BULLETS(class GAME10_GAME* game);
	~BULLETS();
	void init();
	virtual void create() {};
	virtual void launch(const VECTOR2& pos,int speed,int lane);
	void update();
	void kill(int i);
	void AllKill();
	virtual void draw(int bulletKind);
	int BulletNum() { return Bullet.curNum; }
	float bulletLeft(int i) { return Bullets[i].pos.x; }
	float BulletRight(int i) { return Bullets[i].pos.x + Bullet.RightX; }
	int bulletLane(int i) { return Bullets[i].Lane; }
};

