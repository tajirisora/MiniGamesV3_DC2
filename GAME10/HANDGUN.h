#pragma once
#include "WEAPONS.h"
#include "../../libOne/inc/libOne.h"
class HANDGUN :public WEAPONS
{
public:
	struct DATA{
		int GunsImg = 0;
		VECTOR2 Pos = 0;
		int speed = 0;
		int bulletNum = 0;
		int damage = 0;
		int ctIntervalTime = 0;//É^ÉCÉÄÇÃê›íË
		int intervalTime = 0;
		int Level = 0;
	};
private:
	DATA Handgun;
public:
	HANDGUN(class GAME10_GAME* game);
	~HANDGUN();
	void create();
	void init();
	void proc();
	void launch(VECTOR2 pos,int lane);
	void draw();
};

