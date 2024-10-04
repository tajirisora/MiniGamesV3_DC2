#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"HP_GAUGE.h"
#include"HANDGUN.h"
#include"BULLETS.h"
#include"TIME.h"
class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		STAGE::DATA stage;
		RESULT::DATA result;
		PLAYER::DATA player;
		HP_GAUGE::DATA hp_gause;
		HANDGUN::DATA handgun;
		TIME::DATA time;
		BULLETS::DATA handgunBullet;
	};
	DATA Data;
public:
	CONTAINER();
	~CONTAINER();
	void load();
	void setImage();
	void setData();
	const TITLE::DATA& title() { return Data.title; }
	const STAGE::DATA& stage() { return Data.stage; }
	const RESULT::DATA& result() { return Data.result; }
	const PLAYER::DATA& player() { return Data.player; }
	const HP_GAUGE::DATA& gauge() { return Data.hp_gause; }
	const HANDGUN::DATA& handgun() { return Data.handgun; }
	const TIME::DATA& time() { return Data.time; }
	const BULLETS::DATA& handgunBullet() { return Data.handgunBullet; }
};

