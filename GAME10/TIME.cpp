#include "TIME.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
TIME::TIME(class GAME10_GAME* game):GAME_OBJECT10(game){
}
TIME::~TIME(){
}

void TIME::create() {
	Time = game()->container()->time();
}

void TIME::init(){
	Time = game()->container()->time();
}

void TIME::timeCount(){
	Time.time -= delta;
}

void TIME::rewind(){
	Time.time += Time.rewindTime;
}

void TIME::draw() {
	textSize(70);
	fill(255);
	text(Time.time/Time.frame,Time.Pos.x,Time.Pos.y);
}