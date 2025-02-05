#pragma once
#include "GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14 {
    class BONUS_ANNOUNCE :
        public GAME_OBJECT
    {
    public:
        enum BONUSTYPE {
            RED_BB,
            BLUE_BB,
            REG,
            NUM_BONUS
        };
        struct DATA{
            int bonusTypeImg[NUM_BONUS];
            VECTOR2 imgPos[NUM_BONUS];
            float imgSize;
            COLOR imgDefaltColor;
            COLOR imgAnnounceColor;
           const char* announceText = nullptr;
            VECTOR2 drawPos;
            float textSize;
            COLOR defaltColor;
            COLOR announceColor;

            int announceMaxPlayTime;//当たった後の告知までのゲーム数
            int announceBonusTypeTime;//ボーナス告知後のボーナスの種類を告知するまでのゲーム数
        };
    private:
        DATA Announce;
        int CurPlayTimeforBonus;
    public:
        BONUS_ANNOUNCE(GAME* game);
        ~BONUS_ANNOUNCE();
        void create();
        void init();
        void draw();
        void addPlayTimeforBonus() { CurPlayTimeforBonus++; }
        void resetCurPlayTimeforBonus() { CurPlayTimeforBonus = 0; }
    };
}

