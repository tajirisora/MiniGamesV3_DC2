#include "SCENE.h"
SCENE::SCENE(class GAME10_GAME* game): GAME_OBJECT10(game){}
SCENE::~SCENE(){}
void SCENE::create(){}
void SCENE::init(){}
void SCENE::proc(){
	update();
	draw();
	nextScene();
}
void SCENE::update(){}
void SCENE::draw(){}
void SCENE::nextScene(){}
void SCENE::sound() {}
int SCENE::speed() { return 0; }
