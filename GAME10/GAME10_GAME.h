#pragma once
#include"SCENE.h"
#include"WEAPONS.h"
#include"PLAYER.h"
#include"HP_GAUGE.h"
class GAME10_GAME
{
//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
public:
	//シーンの数
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		RESULT_ID,
		NUM_SCENES
	};
	//武器のID
	enum WEAPON_ID {
		HANDGUN_ID,
		SHOTGUN_ID,
		NUM_WEAPON
	};
	//HPのID
	enum HP_ID {
		PLAYERHP_ID,
		ENEMYHP_ID,
		OBJECTHP_ID,
		NUM_HP
	};
	enum BULLET_ID {
		HANDGUNBULLET_ID,
		SHOTGUNBULLET_ID,
		MISSILEBULLET_ID,
		BULLET_NUM
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
	//キャラ関連
	class PLAYER* Player;
	class HP_GAUGE* HpGauge[NUM_HP];
	class BULLETS* Bullets[BULLET_NUM];
	class HANDGUN_BULLETS* HandgunBullets;
	class SHOTGUN_BULLETS* ShotgunBullets;
	BULLET_ID CurBulletId;

	class ENEMYS* Enemies;
	
	class OBJECT* Objects;

	class TIME* Time;
	class DISTANCE* Distance;
	class WEAPONS* Weapons[NUM_WEAPON];
	WEAPON_ID CurWeaponId;
public:
	GAME10_GAME();
	~GAME10_GAME();
	void run();
	void changeScene(SCENE_ID SceneId);
	class SCENE* scenes(int i) { return Scenes[i]; }
	class HP_GAUGE* Hp_gauge(int i) { return HpGauge[i]; }
	class PLAYER* player() { return Player; }
	class WEAPONS* weapons(int Weaponkind) { return Weapons[Weaponkind]; }
	class TIME* time() { return Time; }
	class DISTANCE* distance(){ return Distance; }
	class BULLETS* bullets(int i) { return Bullets[i]; }
	class ENEMYS* enemies() { return Enemies; }
	class OBJECT* objects() { return Objects; }
};

