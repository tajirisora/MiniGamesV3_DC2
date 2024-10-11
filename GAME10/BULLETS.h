#pragma once
#include "GAME10_GAME.h"
class BULLETS :public GAME_OBJECT10
{
public:
	struct DATA {
		int totalNum;
		int curNum;
		int img;
		float speed;
		float cRadius;
		int ImgHalf;
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
	void launch(const VECTOR2& pos,int speed,int lane);
	void update();
	void kill(int i);
	void AllKill();
	void draw();
};

