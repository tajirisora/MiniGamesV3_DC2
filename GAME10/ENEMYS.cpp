#include "ENEMYS.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
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
		Enemy.nowNum++;
		Enemy.callIntervalDist = Enemy.initIntervalDist;
	}
	else {
		Enemy.callIntervalDist -= game()->scenes(GAME10_GAME::STAGE_ID)->speed();
	}
}
void ENEMYS::move() {
	Enemy.speed = -game()->scenes(GAME10_GAME::STAGE_ID)->speed();
	for (int i = Enemy.nowNum - 1; i >= 0; i--) {
		Enemies[i].pos.x += Enemy.speed;
		if (Enemies[i].pos.x <= 0) {
			kill(i);
		}
	}
}
void ENEMYS::collision(){
}
void ENEMYS::kill(int i) {
	Enemy.nowNum--;
	Enemies[i] = Enemies[Enemy.nowNum];
}
void ENEMYS::AllKill() {
	for (int i = 0; i < Enemy.nowNum; i++) {
		Enemies[i] = Enemies[Enemy.nowNum];
	}
	Enemy.nowNum = NULL;
	Enemy.callIntervalDist = Enemy.initIntervalDist;
}
void ENEMYS::draw(){
	for (int i = 0; Enemy.nowNum > i; i++) {
		image(Enemies[i].Img, Enemies[i].pos.x, Enemies[i].pos.y);
	}
}