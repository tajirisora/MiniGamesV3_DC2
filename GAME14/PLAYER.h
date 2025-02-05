#pragma once
#include "GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14
{
    class PLAYER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 statusDrawAreaPos;
            VECTOR2 statusDrawAreaSize;
            COLOR statusDrawAreaColor;

            VECTOR2 nameDrawStartPos;
            float nameSize;
            float offsetForName;
            float drawNumPosX;
            float drawNumSize;
            COLOR drawNumColor;
            int numStatus;
            int oneStatusSize;

            COLOR curMedalNameColor;
            const char* textCurMedalName;

            COLOR curPlayTimeNameColor;
            const char* textCurPlayTimeName;

            COLOR playTimeForBonusNameColor;
            const char* textplayTimeForBonusName;

            COLOR curBBTimeNameColor;
            const char* textCurBBTimeName;

            COLOR BBRatioNameColor;
            const char* textBBRatioName;

            COLOR curREGTimeNameColor;
            const char* textCurREGTimeName;

            COLOR REGRatioNameColor;
            const char* textREGRatioName;

            COLOR BonusRatioNameColor;
            const char* textBonusRatioName;
        };

    private:
        DATA Player;
        int CurMedal;
        int CurPlayTime;
        int PlayTimeForBonus;
        int CurBBTime;
        int CurREGTime;
        int CurNumStatus;
    public:
        PLAYER(GAME* game);
        ~PLAYER();
        void create();
        void init();
        void update();
        void draw();
        void drawStatus(int curNum,const char* name, COLOR nameColor);
        void drawRatio(int curNum, const char* name, COLOR nameColor);
        void addMedal() { CurMedal++; }
        void addMedal(int num) { CurMedal += num; }
        void subMedal() { CurMedal--; }
        void addPlayTime() { CurPlayTime++; }
        void addPlayTimeForBonus() { PlayTimeForBonus++; }
        void addBBTime() {
            PlayTimeForBonus -= PlayTimeForBonus;
            CurBBTime++;
        }
        void addREGTime() {
            PlayTimeForBonus -= PlayTimeForBonus;
            CurREGTime++;
        }
        int result() { return CurMedal; }
    };
}
