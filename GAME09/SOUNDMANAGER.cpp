#include "SOUNDMANAGER.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/sound.h"

namespace GAME09 {
	SOUNDMANAGER::SOUNDMANAGER(GAME* game) :
		GAME_OBJECT(game) {

	}
	SOUNDMANAGER::~SOUNDMANAGER() {

	}

	void SOUNDMANAGER::create() {
		Sound = game()->container()->data().sound;
		SoundEffect = &game()->loadOption()->optionData().soundEffect;
	}

	void SOUNDMANAGER::init() {
		//setVolume(Sound.tapSound, -1000);
		playSound(Sound.tapSound);
		stopSound(Sound.tapSound);
	}

	int SOUNDMANAGER::loadMusic(const char* fileName, float volume) {
		int m = loadSound(fileName);
		setVolume(m, (long)volume);
		return m;
	}
	void SOUNDMANAGER::playMusic(int idx) {
		stopMusic();
		Music = idx;
		playSound(Music);
	}
	void SOUNDMANAGER::stopMusic() {
		stopSound(Music);
	}
	void SOUNDMANAGER::tapSound() {
		if (*SoundEffect) {
			stopSound(Sound.tapSound);
			playSound(Sound.tapSound);
		}
	}
}