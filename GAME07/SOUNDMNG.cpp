#include "SOUNDMNG.h"
#include "GAME07.h"
#include "CONTAINER.h"
#include "../../libOne/inc/sound.h"

namespace GAME07
{
	SOUNDMNG::SOUNDMNG(GAME* game) :
		GAME_OBJECT(game) {

	}
	SOUNDMNG::~SOUNDMNG() {

	}

	void SOUNDMNG::create() {
		SoundMNG = game()->container()->data().soundMNG;
	}

	void SOUNDMNG::playSE(SOUND_EFFECT id) {
		playSound(SoundMNG.soundEffects[id]);
	}
	void SOUNDMNG::loopBGM(){
		playLoopSound(SoundMNG.bgm);
	}
}