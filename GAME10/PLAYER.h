#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class PLAYER :public GAME_OBJECT10
{
public:
	struct DATA {
		VECTOR2 Opos =0;
		VECTOR2 Pos = 0;
		int level;
		int levelUpBorder;//この数だけ倒すと、レベルが上がる
		int borderSum;

		float Pmy = 0;
		int pImg[2];
		int nowImage;
		int nowFlame;
		int nextFlame;
		int imgNum;
		int playerImg = 0;
		float ImgRight = 0;
		float maxSpeed = 0;
		float minSpeed = 0;
		float gearSpeed = 0;//変速スピード
		float speed = 0;
		float hp = 0;
		int nowLane = 0;
		int LaneMax = 0;
		VECTOR2 Tpos = 0;
		int timeImage = 0;
		int timeLimit = 0;
		int initInvisibleTime = 0;
		int invisibleTime = 0;
		//武器
		int weaponHaveNum = 0;
		int weaponNum = 0;
		int* weaponKind = nullptr;
	};
private:
	DATA Player;
public:
	PLAYER(class GAME10_GAME* game);
	~PLAYER();
	void init();
	void stageGoal();
	void create();
	void update();
	void levelUp();
	void launch();
	void getWeapons(int weaponKind);
	void collision();
	void draw();
	void playerMove();
	void doubleUp() { Player.levelUpBorder += Player.borderSum; }//レベルが上がったらborderがあがる

	VECTOR2 playerOpos() { return Player.Opos; }
	VECTOR2 playerPos() { return Player.Pos; }
	float playerHp() { return Player.hp; }
	int playerNowLane() { return Player.nowLane; }
	int PlayerWeaHaveNum() { return Player.weaponHaveNum; }
	int PlayerWeaponKind(int weaponKind) { return Player.weaponKind[weaponKind]; }
	float playerSpeed() { return Player.speed; }
	float playerRight() { return Player.Pos.x + Player.ImgRight; }
	int levelUpBorder() { return Player.levelUpBorder; }
	int playerImagenow() { return Player.nowImage; }//デバッグ用
};

