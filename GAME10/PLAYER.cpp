#include "PLAYER.h"
#include"GAME10_GAME.h"
#include"STAGE.h"
#include"CONTAINER.h"
PLAYER::PLAYER(class GAME10_GAME* game):GAME_OBJECT10(game){
}
PLAYER::~PLAYER(){}
void PLAYER::init(){
	Player = game()->container()->player();
	game()->PlayerHp_gauge()->setHp(Player.hp);
}

void PLAYER::stageGoal() {
	Player.Pos.x = NULL;
}

void PLAYER::create(){
	Player = game()->container()->player();

}

void PLAYER::update() {
	if (isTrigger(KEY_D)) {
		game()->PlayerHp_gauge()->getDamage(2);
	}
	if ((int)Player.Pos.x != (int)Player.Opos.x) {
		playerMove();
	}
	else if(Player.Pos.x > Player.Opos.x){
		Player.Pos.x = Player.Opos.x;
	}
	//‘€ìŠÖ˜A
	if (isPress(KEY_A) && Player.speed >= Player.minSpeed && Player.Pos.x == Player.Opos.x) {
		Player.speed -= Player.gearSpeed;
	}
	else if (Player.speed <= Player.maxSpeed) {
		Player.speed += Player.gearSpeed;
	}
	if (isTrigger(KEY_W) && Player.nowLane > 0 && Player.Pos.x == Player.Opos.x) {
		Player.nowLane--;
		Player.Pos.y -= Player.Pmy;
	}
	if (isTrigger(KEY_S) && Player.nowLane < Player.LaneMax-1 && Player.Pos.x == Player.Opos.x) {
		Player.nowLane++;
		Player.Pos.y += Player.Pmy;
	}
}

void PLAYER::playerMove() {
	Player.Pos.x += Player.speed;
}

void PLAYER::draw(){
	image(Player.playerImg, Player.Pos.x, Player.Pos.y);
	image(Player.timeImage, Player.Tpos.x, Player.Tpos.y);
	fill(255);
	textSize(40);
	game()->PlayerHp_gauge()->draw();
	for (int i = 0; i < Player.weaponNum; i++) {
		if (Player.weaponKind[i] >= NULL) {
			game()->weapons(i)->draw();
		}
	}
}