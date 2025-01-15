#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class OBJECT :public GAME_OBJECT10
{
public:
	//共通データ
	struct DATA
	{
		int Img[3];
		int totalNum;//敵の最大数
		int nowNum;
		int speed;//ステージ速度に依存
		int ohp;//Hp
		int rightMx;//画像の右側
		int my;//出現位置を決めるためのY軸移動量
		int callIntervalDist;
		int initIntervalDist;//初期値
		int sumTime;
		int shortTime;//短くする時間
		int level;
		int sumDestroy;//倒した数
		VECTOR2 opos;
	};
private:
	DATA Object;
public:
	//単体データ
	struct OBJECTS {
		VECTOR2 pos;
		int Img;
		int hp;
		int level;
		int lane;
	};
private:
	OBJECTS* Objects;
public:
	OBJECT(class GAME10_GAME* game);
	~OBJECT();
	void init();
	void create();
	void update();
	void appear();//出現させるためのやつ
	void move();
	void collision();
	void kill(int i);
	void AllKill();
	void draw(int ObjectKind);
	DATA& uniObject() { return Object; }//共通データ
	float& ObjectsLeft(int i) { return Objects[i].pos.x; }//敵ひとりひとりの位置データ(左)
	float ObjectsRight(int i) { return Objects[i].pos.x + (float)Object.rightMx; }//敵ひとりひとりの位置データ(左)
	int& ObjectsLane(int i) { return Objects[i].lane; }//敵ひとりひとりのlaneデータ
};

