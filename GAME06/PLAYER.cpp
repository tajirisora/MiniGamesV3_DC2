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
		Player.img = Player.type1;
	}

	void PLAYER::init() {
		const DATA player = game()->container()->data().player;
		Player.img = Player.type1;
		Player.pos = player.pos;
	}

	void PLAYER::update() {
		if (isPress(KEY_W) && Player.pos.y > Player.limmitH)Player.pos.y += -Player.advSpeed * delta;
		else if (isPress(KEY_S) && Player.pos.y < height - Player.limmitH)Player.pos.y += Player.advSpeed * delta;
	}

	void PLAYER::draw() {
		rectMode(CENTER);
		image(Player.img, Player.pos.x, Player.pos.y, Player.angle, Player.scale);
	}
}