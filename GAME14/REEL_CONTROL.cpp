#include"CONTAINER.h"
#include"GAME14.h"
#include "REEL_CONTROL.h"
namespace GAME14 {
	REEL_CONTROL::~REEL_CONTROL(){}
	void REEL_CONTROL::create(){
		Information = game()->container()->data().control;
	}
	void REEL_CONTROL::proc(){
		
	}

}