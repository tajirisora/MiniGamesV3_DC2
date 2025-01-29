#include "../../libOne/inc/libOne.h"
#include "ANIMS.h"
#include "CONTAINER.h"
#include "GAME03.h"
#include "MAP.h"
#include "PLAYER.h"
#include "VOLUME.h"
#include <time.h>
namespace GAME03 {
	void PLAYER::create() {
		DeterPlayer = game()->container()->data().select.deterPlayer;
		Chara = game()->container()->data().playerChara1;
		Player = game()->container()->data().player;
	}
	void PLAYER::appear(float wx, float wy, float vx, float vy) {
		Chara.hp = game()->container()->data().playerChara1.hp;
		Chara.wx = wx;
		Chara.wy = wy;
		Chara.animId = Player.rightAnimId;
		time(&Player.s_time);
		time(&Player.n_time);
		time(&Player.cnt_time);
		op_option = false;
		flg_clear = false;
		onceSe = true;
		State = STATE::STRUGGLING;
	}
	void PLAYER::update() {
		Launch();
		Move();
		CollisionWithMap();
		ChangeColor();
		CheckState();
	}
	void PLAYER::Launch() {
		float vx = 1.0f;
		float wx = 0.0f;
		float wy = 0.0f;
		if (Chara.animId == Player.leftAnimId) {
			vx = -1.0f; 
		}
		wx = Chara.wx + Player.bulletOffsetX * vx;
		wy = Chara.wy;
		game()->characterManager()->appear(Player.bulletCharaId, wx, wy, vx);
	}
	void PLAYER::Move() {
		if (State == STATE::STRUGGLING && !op_option) {
			Chara.vx = 0.0f;
			Chara.vy = 0.0f;
			if (isPress(KEY_A) || isPress(KEY_LEFT) ||
				(isPress(MOUSE_LBUTTON) && width / 2 >= mouseX)) {
				Chara.vx = -Chara.speed * delta;
				Chara.animId = Player.leftAnimId;
			}
			if (isPress(KEY_D) || isPress(KEY_RIGHT) ||
				(isPress(MOUSE_LBUTTON) && width / 2 <= mouseX)) {
				Chara.vx = Chara.speed * delta;
				Chara.animId = Player.rightAnimId;
			}
			if (isPress(KEY_W) || isPress(KEY_UP) ||
				(isPress(MOUSE_LBUTTON) && height / 2 >= mouseY)) {
				Chara.vy = -Chara.speed * delta;
			}
			if (isPress(KEY_S) || isPress(KEY_DOWN) ||
				(isPress(MOUSE_LBUTTON) && height / 2 <= mouseY)) {
				Chara.vy = Chara.speed * delta;
			}
		}
		else {
			Chara.vx = 0.0f;
			Chara.vy = 0.0f;
		}
		Player.curWx = Chara.wx;
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
	void PLAYER::CollisionWithMap() {
		MAP* map = game()->map();
		if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
			Chara.wx = Player.curWx;
		}
		if (map->collisionCharaLeft(Chara.wx, Chara.wy) || Chara.wx < map->wx()) {
			Chara.wx = Player.curWx;
		}
		if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
			Chara.vy = Player.initVecDown;
		}
		if (map->collisionCharaBottom(Player.curWx, Chara.wy)) {
			Chara.vy = 0.0f;
			Chara.wy = (int)(Chara.wy / map->chipSize()) * (float)map->chipSize();
		}
	}
	void PLAYER::CheckState() {
		if (!op_option) {
			if (isTrigger(KEY_ESCAPE) ||
				((mouseX > 12 && mouseX < 100 && mouseY>12 && mouseY < 83) && isTrigger(MOUSE_LBUTTON))) {
				Player.time = Player.stp_time;
				op_option = true;
			}
		}
		if (op_option) {
			time(&Player.cnt_time);
			if (isTrigger(KEY_N) || isTrigger(KEY_O) ||
				((mouseX > 1005 && mouseX < 1234 && mouseY>707 && mouseY < 772) && isTrigger(MOUSE_LBUTTON)) ||
				((mouseX > 687 && mouseX < 918 && mouseY>707 && mouseY < 772) && isTrigger(MOUSE_LBUTTON))) {
				Player.s_time += (Player.cnt_time - Player.n_time);
				op_option = false;
			}
		}
		else {
			time(&Player.n_time);
			Player.time = Player.n_time - Player.s_time;
			Player.stp_time = Player.time;
		}
		if (Player.time >= 30 + game()->select()->timepls()) {
			flg_clear = true;
		}
		if (flg_clear && State != STATE::DIED) {
			if (onceSe) {
				playSound(game()->container()->data().volume.Se_F);
				onceSe = false;
			}
			State = STATE::SURVIVED;
			Chara.hp = 1;
		}
		if (isPress(KEY_SHIFT) && isPress(KEY_ENTER)) {
			State = STATE::SURVIVED;
			Chara.hp = 1;
		}//debug
		if (isPress(KEY_SHIFT) && isPress(KEY_M)) {
			State = STATE::DIED;
			Chara.hp = 1;
		}//debug
	}
	void PLAYER::ChangeColor() {
		if (Player.damageTime > 0) {
			Player.damageTime -= delta;
			Chara.color = Player.damageColor;
		}
		else {
			Chara.color = Player.normalColor;
		}
	}
	void PLAYER::damage() {
		if (Chara.hp > 1 && Player.damageTime <= 0) {
			Player.damageTime = Player.damageInterval;
			playSound(game()->container()->data().volume.Se_A);
			Chara.hp--;
			if (Chara.hp == 1) {
				playSound(game()->container()->data().volume.Se_B);
				State = STATE::DIED;
			}
		}
	}
	bool PLAYER::died() {
		if (State == STATE::DIED) {
			Chara.vx = 0.0f;
			Chara.vy = 0.0f;
			draw();
			return true;
		}
		return false;
	}
	bool PLAYER::survived() const{
		return State == STATE::SURVIVED;
	}
	float PLAYER::overCenterVx() {
		float overCenterVx = Chara.wx - (game()->map()->wx() + width / 2.0f);
		if (Chara.hp == 0)overCenterVx = 0;
		return overCenterVx;
	}
	float PLAYER::overCenterVy() {
		float overCenterVy = Chara.wy - (game()->map()->wy() + height / 2.0f);
		if (Chara.hp == 0)overCenterVy = 0;
		return overCenterVy;
	}
	float PLAYER::playerWx() {
		return Chara.wx;
	}
	float PLAYER::playerWy() {
		return Chara.wy;
	}
	int PLAYER::playerHp() {
		return Chara.hp - 1;
	}
}
