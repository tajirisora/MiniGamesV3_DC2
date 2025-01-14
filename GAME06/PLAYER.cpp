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
		
	}

	void PLAYER::update() {
		if (isPress(KEY_W))Player.pos.y += -Player.advSpeed * delta;
		else if (isPress(KEY_S))Player.pos.y += Player.advSpeed * delta;
	}

	void PLAYER::draw() {
		fill(Player.fillColor);
		circle(Player.pos.x, Player.pos.y, Player.radius * 2);
	}
}