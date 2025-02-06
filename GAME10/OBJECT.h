#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class OBJECT :public GAME_OBJECT10
{
public:
	//共通データ
	struct DATA
	{
		int hitSound;
		int Img[3];
		int totalNum;//敵の最大数
		int nowNum;
		int speed;//ステージ速度に依存
		int ohp;//Hp
		int upHp;//レベルごとにアップするHp
		int rightMx;//画像の右側
		int my;//出現位置を決めるためのY軸移動量
		int callIntervalDist;
		int initIntervalDist;//初期値
		int sumTime;
		int hitDamage;
		int shortTime;//短くする時間
		int level;
		int sumDestroy;//倒した数
		int downSound;
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
	void levelUp();
	void kill(int i);
	void AllKill();
	void draw(int ObjectKind);
	int objectNum() { return Object.nowNum; }
	const int objectsHitDamage() { return Object.hitDamage; }
	VECTOR2 objectPos(int i) { return Objects[i].pos; }
	float& ObjectsLeft(int i) { return Objects[i].pos.x; }//障害物ひとつずつの位置データ(左)
	float ObjectsRight(int i) { return Objects[i].pos.x + (float)Object.rightMx; }//障害物ひとつずつの位置データ(左)
	int& ObjectsLane(int i) { return Objects[i].lane; }//障害物ひとつずつのlaneデータ
	const int& sumDestroy() { return Object.sumDestroy; }
	void DestroyReset() { Object.sumDestroy = 0; }
};

