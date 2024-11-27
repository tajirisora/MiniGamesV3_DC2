#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"HP_GAUGE.h"
#include"PLAYER_HP.h"
#include"ENEMY_HPGAUGE.h"
#include"OBJECT_HP.h"
#include"HANDGUN.h"
#include"SHOTGUN.h"
#include"BULLETS.h"
#include"TIME.h"
#include"ENEMYS.h"
#include"OBJECT.h"
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
		OBJECT_HP::DATA objectGauge;
		HANDGUN::DATA handgun;
		SHOTGUN::DATA shotgun;
		TIME::DATA time;
		BULLETS::DATA handgunBullet;
		BULLETS::DATA shotGunBullet;
		ENEMYS::DATA enemy;
		OBJECT::DATA object;
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
	const OBJECT_HP::DATA& objectHpGauge() { return Data.objectGauge; }
	const HANDGUN::DATA& handgun() { return Data.handgun; }
	const SHOTGUN::DATA& shotgun() { return Data.shotgun; }
	const TIME::DATA& time() { return Data.time; }
	const BULLETS::DATA& handgunBullet() { return Data.handgunBullet; }
	const BULLETS::DATA& shotgunBullet() { return Data.shotGunBullet; }
	const ENEMYS::DATA& enemy() { return Data.enemy; }
	const OBJECT::DATA& object() { return Data.object; }
};

