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
	enum WEAPON_ID {
		HANDGUN_ID,
		NUM_WEAPON
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;

	class PLAYER* Player;
	class HP_GAUGE* PlayerHpGauge;
	class TIME* Time;

	class WEAPONS* Weapons[NUM_WEAPON];
	WEAPON_ID CurWeaponId;
public:
	GAME10_GAME();
	~GAME10_GAME();
	void run();
	void changeScene(SCENE_ID SceneId);
	class SCENE* scenes(int i) { return Scenes[i]; }
	class HP_GAUGE* PlayerHp_gauge() { return PlayerHpGauge; }
	class PLAYER* player() { return Player; }
	class WEAPONS* weapons(int Weaponkind) { return Weapons[Weaponkind]; }
	class TIME* time() { return Time; }
};

