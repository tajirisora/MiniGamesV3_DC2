#include "OBJECT.h"
#include"SCENE.h"
#include"STAGE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
OBJECT::OBJECT(class GAME10_GAME* game) :GAME_OBJECT10(game) {
}
OBJECT::~OBJECT() {
	delete[] Objects;
}
void OBJECT::init() {
}
void OBJECT::create() {
	Object = game()->container()->object();
	Objects = new OBJECTS[Object.totalNum];
}
void OBJECT::update() {
	move();
	collision();
}
void OBJECT::appear() {
	if (Object.callIntervalDist <= NULL) {
		Objects[Object.nowNum].lane = random() % 4;
		Objects[Object.nowNum].pos.x = Object.opos.x;
		Objects[Object.nowNum].pos.y = Object.opos.y + Object.my * Objects[Object.nowNum].lane;
		Objects[Object.nowNum].hp = Object.ohp;
		Objects[Object.nowNum].level = Object.level;
		Objects[Object.nowNum].Img = Object.Img[random() % 3];
		game()->Hp_gauge(GAME10_GAME::OBJECTHP_ID)->appear(Objects[Object.nowNum].hp, Objects[Object.nowNum].level);
		Object.nowNum++;
		Object.callIntervalDist = Object.initIntervalDist + Object.sumTime * (random() % 4);
	}
	else {
		Object.callIntervalDist -= game()->scenes(GAME10_GAME::STAGE_ID)->speed();
	}
}
void OBJECT::move() {
	for (int i = Object.nowNum - 1; i >= 0; i--) {
		Objects[i].pos.x -= Object.speed;
		if (Objects[i].pos.x <= 0) {
			kill(i);
		}
	}
}
void OBJECT::collision() {
	for (int i = 0; Object.nowNum > i; i++) {//“G‚Ì‘”•ª‰ñ‚é
		for (int bulletKind = 0; bulletKind < game()->player()->playerData().weaponHaveNum; bulletKind++) {
			for (int j = 0; j < game()->bullets(game()->player()->playerData().weaponKind[bulletKind])->BulletNum(); j++) {//’e‚»‚ê‚¼‚ê‚É”»’è‚ğŒŸõ‚·‚é
				if (Objects[i].pos.x <= game()->bullets(game()->player()->playerData().weaponKind[bulletKind])->BulletRight(j)
					&& Objects[i].lane == game()->bullets(game()->player()->playerData().weaponKind[bulletKind])->bulletLane(j)) {
					game()->Hp_gauge(GAME10_GAME::OBJECTHP_ID)->getDamage(game()->weapons(game()->player()->playerData().weaponKind[bulletKind])->damage(), i,bulletKind);
					game()->bullets(game()->player()->playerData().weaponKind[bulletKind])->kill(j);
				}
			}
		}

		if (game()->Hp_gauge(GAME10_GAME::OBJECTHP_ID)->GetHp(i) <= 0) {
			kill(i);
		}
	}
}
void OBJECT::kill(int i) {
	Object.nowNum--;
	Objects[i] = Objects[Object.nowNum];
	game()->Hp_gauge(GAME10_GAME::OBJECTHP_ID)->death(i);
}
void OBJECT::AllKill() {
	for (int i = 0; i < Object.nowNum; i++) {
		Objects[i] = Objects[Object.nowNum];
	}
	Object.nowNum = NULL;
	Object.callIntervalDist = Object.initIntervalDist;
}
void OBJECT::draw() {
	textSize(30);
	for (int i = 0; Object.nowNum > i; i++) {
		image(Objects[i].Img, Objects[i].pos.x, Objects[i].pos.y);
		game()->Hp_gauge(GAME10_GAME::OBJECTHP_ID)->draw(Objects[i].pos, i);
	}
}