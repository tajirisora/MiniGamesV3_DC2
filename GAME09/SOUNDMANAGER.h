#pragma once
#include "GAME_OBJECT.h"

namespace GAME09 {
    class SOUNDMANAGER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int tapSound;
        };
    private:
        DATA Sound;
        int Music = 0;
        bool SoundEffect = true;
    public:
        SOUNDMANAGER(class GAME* game);
        ~SOUNDMANAGER();
        void create();
        void init();

        int loadMusic(const char* fileName, float volume);
        void playMusic(int idx);
        void stopMusic();
        void tapSound();
        bool* soundEffect() { return &SoundEffect; }
    };
}