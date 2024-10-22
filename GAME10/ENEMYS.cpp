#include "ENEMYS.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include"ENEMY_HPGAUGE.h"
#include"SCENE.h"
#include"STAGE.h"
ENEMYS::ENEMYS(class GAME10_GAME* game):GAME_OBJECT10(game){
}
ENEMYS::~ENEMYS(){
	delete[] Enemies;
}
void ENEMYS::init(){
}
void ENEMYS::create(){
	Enemy = game()->container()->enemy();
	Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMYS::update(){
	appear();
	move();
	collision();
}
void ENEMYS::appear() {
	if (Enemy.callIntervalDist <= NULL) {
		Enemies[Enemy.nowNum].lane = random() % 4;
		Enemies[Enemy.nowNum].pos.x = Enemy.opos.x;
		Enemies[Enemy.nowNum].pos.y = Enemy.opos.y + Enemy.my * Enemies[Enemy.nowNum].lane;
		Enemies[Enemy.nowNum].hp = Enemy.ohp;
		Enemies[Enemy.nowNum].level = Enemy.level;
		Enemies[Enemy.nowNum].Img = Enemy.Img[random() % 3];
		game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->appear(Enemies[Enemy.nowNum].hp,Enemies[Enemy.nowNum].level);
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
	if (isTrigger(KEY_SPACE)) {
		for (int i = Enemy.nowNum - 1; i >= 0; i--) {
			game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->getDamage(10.0f, i);
		}
	}
}
void ENEMYS::collision(){
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
void ENEMYS::draw(){
	textSize(30);
	//text(Enemy.callIntervalDist, 0, 50);
	for (int i = 0; Enemy.nowNum > i; i++) {
		image(Enemies[i].Img, Enemies[i].pos.x, Enemies[i].pos.y);
		game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->draw(Enemies[i].pos,i);
	}
}