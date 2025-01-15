#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class ENEMYS :public GAME_OBJECT10
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
		int hitDamage;
		int shortTime;//短くする時間
		int destroy;//倒された数
		int level;
		VECTOR2 opos;
	};
private:
	DATA Enemy;
public:
	//単体データ
	struct ENEMY {
		VECTOR2 pos;
		int Img;
		int hp;
		int level;
		int lane;
	};
private:
	ENEMY* Enemies;
public:
	ENEMYS(class GAME10_GAME* game);
	~ENEMYS();
	void init();
	void create();
	void update();
		void appear();//出現させるためのやつ
		void move();
		void collision();
	void kill(int i);
	void AllKill();
	void draw(int EnemyKind);
	const DATA& uniEnemy() { return Enemy; }//共通データ
	const int EnemiesHitDamage() { return Enemy.hitDamage; }
	const int EnemiesLaneKind(int i) { return Enemies[i].lane; }
	const float& EnemiesLeft(int i) { return Enemies[i].pos.x; }//敵ひとりひとりの位置データ(左)
	const float EnemiesRight(int i) { return Enemies[i].pos.x + (float)Enemy.rightMx; }//敵ひとりひとりの位置データ(左)
	const int& EnemiesLane(int i) { return Enemies[i].lane; }//敵ひとりひとりのlaneデータ
};

