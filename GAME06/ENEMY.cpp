#include"ENEMY.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
namespace GAME06 
{
	void ENEMY::create() {
		Enemy = game()->container()->data().enemy;
	}

	void ENEMY::init() {

	}

	void ENEMY::update() {

	}

	void ENEMY::draw() {
		fill(Enemy.fillColor);
		circle(Enemy.pos.x, Enemy.pos.y, Enemy.radius * 2);
	}
}