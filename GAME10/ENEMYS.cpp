#include "ENEMYS.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include"ENEMY_HPGAUGE.h"
#include"HANDGUN_BULLETS.h"
#include"SCENE.h"
#include"STAGE.h"
ENEMYS::ENEMYS(class GAME10_GAME* game) :GAME_OBJECT10(game) {
}
ENEMYS::~ENEMYS() {
	if (Enemies != nullptr) {
		delete[] Enemies;
	}
}
void ENEMYS::init() {
	Enemy = game()->container()->enemy();
	if (Enemies != nullptr) {
		delete[] Enemies;
		Enemies = new ENEMY[Enemy.totalNum];
	}
	game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->init();
}
void ENEMYS::create() {
	Enemy = game()->container()->enemy();
	Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMYS::update() {
	move();
	collision();
}
void ENEMYS::appear() {
	if (Enemy.callIntervalDist <= NULL) {
		Enemies[Enemy.nowNum].lane = random() % 4;
		Enemies[Enemy.nowNum].pos.x = Enemy.opos.x;
		Enemies[Enemy.nowNum].pos.y = Enemy.opos.y + Enemy.my * Enemies[Enemy.nowNum].lane;
		Enemies[Enemy.nowNum].level = Enemy.level;
		Enemies[Enemy.nowNum].hp = Enemy.ohp + Enemy.upHp * Enemy.level;
		Enemies[Enemy.nowNum].Img = Enemy.Img[random() % 3];
		game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->appear(Enemies[Enemy.nowNum].hp, Enemies[Enemy.nowNum].level);
		Enemy.nowNum++;
		Enemy.callIntervalDist = Enemy.initIntervalDist + Enemy.sumTime * (random() % 4);
	}
	else {
		Enemy.callIntervalDist -= game()->scenes(GAME10_GAME::STAGE_ID)->speed();
	}
}
void ENEMYS::move() {
	for (int i = Enemy.nowNum - 1; i >= 0; i--) {
		Enemies[i].pos.x -= Enemy.speed;
		if (Enemies[i].pos.x <= 0) {
			kill(i);
		}
	}
}
void ENEMYS::collision() {
	for (int i = 0; Enemy.nowNum > i; i++) {//“G‚Ì‘”•ª‰ñ‚é
		for (int bulletKind = 0; bulletKind < game()->player()->PlayerWeaHaveNum(); bulletKind++) {
			for (int j = 0; j < game()->bullets(game()->player()->PlayerWeaponKind(bulletKind))->BulletNum(); j++) {//’e‚»‚ê‚¼‚ê‚É”»’è‚ğŒŸõ‚·‚é
				if (Enemies[i].pos.x + Enemy.rightMx >= game()->bullets(game()->player()->PlayerWeaponKind(bulletKind))->bulletLeft(j)
					&& Enemies[i].pos.x <= game()->bullets(game()->player()->PlayerWeaponKind(bulletKind))->BulletRight(j)
					&& Enemies[i].lane == game()->bullets(game()->player()->PlayerWeaponKind(bulletKind))->bulletLane(j)) {
					game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->getDamage(game()->weapons(game()->player()->PlayerWeaponKind(bulletKind))->damage(), i,bulletKind);
					game()->bullets(game()->player()->PlayerWeaponKind(bulletKind))->kill(j);
				}
			}
		}

		if (game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->GetHp(i) <= 0) {
			Enemy.sumDestroy++;
			kill(i);
			game()->time()->rewind();
		}
	}
}
void ENEMYS::levelUp() {
	Enemy.level++;
}
void ENEMYS::kill(int i) {
	Enemy.nowNum--;
	Enemies[i] = Enemies[Enemy.nowNum];
	game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->death(i);
}
void ENEMYS::AllKill() {
	for (int i = 0; i < Enemy.nowNum; i++) {
		Enemies[i] = Enemies[Enemy.nowNum];
	}
	Enemy.nowNum = NULL;
	Enemy.callIntervalDist = Enemy.initIntervalDist;
}
void ENEMYS::draw(int EnemyKind) {
	image(Enemies[EnemyKind].Img, Enemies[EnemyKind].pos.x, Enemies[EnemyKind].pos.y);
	game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->draw(Enemies[EnemyKind].pos, EnemyKind);
}