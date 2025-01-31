#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class HP_GAUGE :public GAME_OBJECT10
{
public:
	HP_GAUGE(class GAME10_GAME* game);
	virtual ~HP_GAUGE();
	virtual void init();
	virtual void setHp(int Hp);//セッター
	virtual void create();
	virtual void appear(int hp, int Level);//
	virtual void getDamage(int damage);
	virtual void getDamage(float damage, int EnemyKind,int weaponKind);
	virtual void death(int i);//敵・プレイヤーがやられたとき
	virtual void draw();
	virtual void draw(VECTOR2 pos, int EnemyKind);
	virtual int GetHp(int i) { return 0; };
};

