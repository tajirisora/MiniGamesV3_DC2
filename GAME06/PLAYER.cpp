#include"PLAYER.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
namespace GAME06 
{
	void PLAYER::create() {
		Player = game()->container()->data().player;
	}

	void PLAYER::init() {
		const DATA& player = game()->container()->data().player;
		Player.img = Player.type1;
		Player.pos = player.pos;
		Player.triggerFlag = false;
	}

	void PLAYER::update() {
		//ã‰º‚ÌˆÚ“®
		if (isPress(KEY_W) && Player.pos.y > Player.limmitH)Player.pos.y += -Player.speed * delta;
		else if (isPress(KEY_S) && Player.pos.y < height - Player.limmitH)Player.pos.y += Player.speed * delta;
		//’e‚Ì”­ŽË€”õ
		if (isTrigger(KEY_K) && Player.triggerFlag == false) {
			game()->bullet()->init();
			Player.triggerFlag = true;
		}
	}

	void PLAYER::draw() {
		rectMode(CENTER);
		image(Player.img, Player.pos.x, Player.pos.y, Player.angle, Player.scale);
	}
}