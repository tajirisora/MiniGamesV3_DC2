#pragma once
#include"TITLE.h"
#include"TUTORIAL.h"
#include"STAGE.h"
#include"SELECT.h"
#include"RESULT.h"
#include"PLAYER.h"
#include"HP_GAUGE.h"
#include"PLAYER_HP.h"
#include"ENEMY_HPGAUGE.h"
#include"OBJECT_HP.h"
#include"HANDGUN.h"
#include"SHOTGUN.h"
#include"MISSILE.h"
#include"MISSILE_BULLETS.h"
#include"BULLETS.h"
#include"TIME.h"
#include"DISTANCE.h"
#include"ENEMYS.h"
#include"OBJECT.h"
class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		TUTORIAL::DATA tutorial;
		STAGE::DATA stage;
		SELECT::DATA select;
		RESULT::DATA result;
		PLAYER::DATA player;
		PLAYER_HP::DATA playerGauge;
		ENEMY_HPGAUGE::DATA enemyGauge;
		OBJECT_HP::DATA objectGauge;
		HANDGUN::DATA handgun;
		SHOTGUN::DATA shotgun;
		MISSILE::DATA missile;
		TIME::DATA time;
		DISTANCE::DATA distance;
		BULLETS::DATA handgunBullet;
		BULLETS::DATA shotGunBullet;
		BULLETS::DATA missileBullet;
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
	const TUTORIAL::DATA& tutorial(){ return Data.tutorial; }
	const STAGE::DATA& stage() { return Data.stage; }
	const SELECT::DATA& select() { return Data.select; }
	const RESULT::DATA& result() { return Data.result; }
	const PLAYER::DATA& player() { return Data.player; }
	const PLAYER_HP::DATA& PlayerHpGauge() { return Data.playerGauge; }
	const ENEMY_HPGAUGE::DATA& EnemyHpGauge() { return Data.enemyGauge; }
	const OBJECT_HP::DATA& objectHpGauge() { return Data.objectGauge; }
	const HANDGUN::DATA& handgun() { return Data.handgun; }
	const SHOTGUN::DATA& shotgun() { return Data.shotgun; }
	const MISSILE::DATA& missile() { return Data.missile; }
	const TIME::DATA& time() { return Data.time; }
	const DISTANCE::DATA& distance(){ return Data.distance; }
	const BULLETS::DATA& handgunBullet() { return Data.handgunBullet; }
	const BULLETS::DATA& shotgunBullet() { return Data.shotGunBullet; }
	const MISSILE_BULLETS::DATA& missileBullet() { return Data.missileBullet; }
	const ENEMYS::DATA& enemy() { return Data.enemy; }
	const OBJECT::DATA& object() { return Data.object; }
};

