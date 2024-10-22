#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"HP_GAUGE.h"
#include"PLAYER_HP.h"
#include"ENEMY_HPGAUGE.h"
#include"HANDGUN.h"
#include"BULLETS.h"
#include"TIME.h"
#include"ENEMYS.h"
class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		STAGE::DATA stage;
		RESULT::DATA result;
		PLAYER::DATA player;
		PLAYER_HP::DATA playerGauge;
		ENEMY_HPGAUGE::DATA enemyGauge;
		HANDGUN::DATA handgun;
		TIME::DATA time;
		BULLETS::DATA handgunBullet;
		ENEMYS::DATA enemy;
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
	const PLAYER_HP::DATA& PlayerHpGauge() { return Data.playerGauge; }
	const ENEMY_HPGAUGE::DATA& EnemyHpGauge() { return Data.enemyGauge; }
	const HANDGUN::DATA& handgun() { return Data.handgun; }
	const TIME::DATA& time() { return Data.time; }
	const BULLETS::DATA& handgunBullet() { return Data.handgunBullet; }
	const ENEMYS::DATA& enemy() { return Data.enemy; }
};

