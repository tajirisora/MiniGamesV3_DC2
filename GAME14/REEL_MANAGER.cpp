#include"GAME14.h"
#include"LEVER.h"
#include"REEL.h"
#include"LEFT_REEL.h"
#include"MIDDLE_REEL.h"
#include"REEL_MANAGER.h"
#include"RIGHT_REEL.h"
namespace GAME14 {
	REEL_MANAGER::~REEL_MANAGER(){
		for (int i = 0; i < NUM_REEL; i++) {
			delete Reels[i];
		}
		delete[] Reels;
	}
	void REEL_MANAGER::create(){
		Reels = new REEL * [NUM_REEL];
		Reels[LEFT_REEL_ID] = new LEFT_REEL(game());
		Reels[MIDDLE_REEL_ID] = new MIDDLE_REEL(game());
		Reels[RIGHT_REEL_ID] = new RIGHT_REEL(game());

		for (int i = 0; i < NUM_REEL; i++) {
			Reels[i]->create();
		}
	}
	void REEL_MANAGER::init(){
		for (int i = 0; i < NUM_REEL; i++) {
			Reels[i]->init(i);
		}
	}
	void REEL_MANAGER::update() {
		for (int i = 0; i < NUM_REEL; i++) {
			Reels[i]->update();
		}
		game()->lever()->setSistemFlag(false);
	}
	void REEL_MANAGER::draw(){
		for (int i = 0; i < NUM_REEL; i++) {
			Reels[i]->draw();
		}
		
	}
	void REEL_MANAGER::reelMove() {
		for (int i = 0; i < NUM_REEL; i++) {
			Reels[i]->move();
		}
	}
}