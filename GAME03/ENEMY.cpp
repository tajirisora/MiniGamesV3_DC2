#include "../../libOne/inc/libOne.h"
#include "ANIMS.h"
#include "CONTAINER.h"
#include "GAME03.h"
#include "MAP.h"
#include "ENEMY.h"
#include "VOLUME.h"
#include <time.h>
namespace GAME03 {
	void ENEMY::create() {
		Chara = game()->container()->data().enemyChara1;
		Enemy = game()->container()->data().enemy;
	}
	void ENEMY::appear(float wx, float wy, float vx, float vy) {
		Chara.hp = game()->container()->data().enemyChara1.hp;
		Chara.wx = wx;
		Chara.wy = wy;
		Chara.animId = Enemy.rightAnimId;
		flg_clear = false;
		op_option = false;
		State = STATE::STRUGGLING;
	}
	void ENEMY::update() {
		Move();
		ChangeColor();
		CollisionWithMap();
		CheckState();
	}
	void ENEMY::Move() {
		if (State == STATE::STRUGGLING && !op_option) {
			Chara.vx = 0.0f;
			Chara.vy = 0.0f;
			if (Chara.wx > game()->characterManager()->player()->playerWx()) {
				Chara.animId = Enemy.leftAnimId;
				Chara.vx = -Chara.speed * delta;
			}
			else if (Chara.wx < game()->characterManager()->player()->playerWx()) {
				Chara.animId = Enemy.rightAnimId;
				Chara.vx = Chara.speed * delta;
			}
			if (Chara.wy < game()->characterManager()->player()->playerWy()) {
				Chara.vy = Chara.speed * delta;
			}
			else if (Chara.wy > game()->characterManager()->player()->playerWy()) {
				Chara.vy = -Chara.speed * delta;
			}
		}
		else {
			Chara.vx = 0.0f;
			Chara.vy = 0.0f;
		}
		if (Chara.wx < (game()->map()->wx() + width / 2.0f) - 1000.0f) {
			Chara.wx += 2000.0f;
			Chara.wy += rand() % 100;
		}
		if (Chara.wx > (game()->map()->wx() + width / 2.0f) + 1000.0f) {
			Chara.wx -= 2000.0f;
			Chara.wy += rand() % 100;
		}
		if (Chara.wy < (game()->map()->wy() + height / 2.0f) - 1000.0f) {
			Chara.wx += rand() % 100;
			Chara.wy += 2000.0f;
		}
		if (Chara.wy > (game()->map()->wy() + height / 2.0f) + 1000.0f) {
			Chara.wx += rand() % 100;
			Chara.wy -= 2000.0f;
		}
		Enemy.curWx = Chara.wx;
		Enemy.curWy = Chara.wy;
		if (Chara.vx != 0.0f || Chara.vy != 0.0f) {
			Chara.wx += Chara.vx;
			Chara.wy += Chara.vy;
		}
		else {
			Chara.animData.imgIdx = 0;
			Chara.animData.elapsedTime = -delta;
		}
		if (Chara.hp == 0) {
			Chara.speed = 0.0f;
		}
	}
	void ENEMY::CollisionWithMap() {

		MAP* map = game()->map();

		if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.wx = Enemy.curWx;
		}
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) || Chara.wx < map->wx()) {
			Chara.wx = Enemy.curWx;
		}
		if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
			Chara.vy = Enemy.initVecDown;
		}
		if (map->collisionCharaBottom(Enemy.curWx, Chara.wy)) {
			Chara.vy = 0.0f;
			Chara.wy = (int)(Chara.wy / map->chipSize()) * (float)map->chipSize();
		}
	}
	void ENEMY::CheckState() {
		if (!op_option) {
			if (isTrigger(KEY_ESCAPE) ||
				((mouseX > 12 && mouseX < 100 && mouseY>12 && mouseY < 83) && isTrigger(MOUSE_LBUTTON))) {
				op_option = true;
			}
		}
		if (op_option) {
			if (isTrigger(KEY_N) || (mouseX > 1005 && mouseX < 1234 && mouseY>707 && mouseY < 772) && isTrigger(MOUSE_LBUTTON)) {
				op_option = false;
			}
			if (isTrigger(KEY_O) || (mouseX > 687 && mouseX < 918 && mouseY>707 && mouseY < 772) && isTrigger(MOUSE_LBUTTON)) {
				Chara.hp = 0;
			}
		}
		if (game()->characterManager()->player()->survived()) {
			op_option = true;
		}
		if (Chara.hp == 0) {
			State = STATE::DIED;
		}

	}
	void ENEMY::ChangeColor() {
		if (Enemy.damageTime > 0) {
			Enemy.damageTime -= delta;
			Chara.color = Enemy.damageColor;
		}
		else if (Chara.wx < (game()->map()->wx() + width / 2.0f) - 830.0f ||
			Chara.wx >(game()->map()->wx() + width / 2.0f) + 830.0f) {
			Chara.color = COLOR(0, 0, 0, 0);
		}
		else {
			Chara.color = Enemy.normalColor;
		}
	}
	void ENEMY::damage() {
		if (Chara.hp > 0) {
			Enemy.damageTime = Enemy.damageInterval;
			Chara.hp--;
			if (Chara.wx >= game()->characterManager()->player()->playerWx()) {
				Chara.wx = Enemy.curWx + (3.4f * 100) * delta;
			}
			if (Chara.wx <= game()->characterManager()->player()->playerWx()) {
				Chara.wx = Enemy.curWx - (3.4f * 100) * delta;
			}
			if (Chara.wy <= game()->characterManager()->player()->playerWy()) {
				Chara.wy = Enemy.curWy - (3.4f * 100) * delta;
			}
			if (Chara.wy >= game()->characterManager()->player()->playerWy()) {
				Chara.wy = Enemy.curWy + (3.4f * 100) * delta;
			}
		}
	}
	void ENEMY::reflection(float x, float y) {
		if (!op_option) {
			Chara.wx += x;
			Chara.wy += y;
		}
	}
	float ENEMY::enemyWx() {
		return Chara.wx;
	}
	float ENEMY::enemyWy() {
		return Chara.wy;
	}
}