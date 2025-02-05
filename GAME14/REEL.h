#pragma once
#include"../../libOne//inc//VECTOR2.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class REEL :
        public GAME_OBJECT{//リールの動き、表示,役の成立判定
    public:
        enum IMG_ID {
            BONUS_A,
            BONUS_B,
            BAR_A,
            BAR_B,
            REPLAY,
            WATERMELON_A,
            WATERMELON_B,
            CHERRY,
            BELL_A,
            BELL_B,
            NUM_IMG
        };
        enum STOP_NUMBER {
            FIRST=1,
            SECOND,
            THIRD
        };
        enum REEL_ID {
            LEFT,
            MIDDLE,
            RIGHT,
            NUM_REEL
        };
        struct DATA {//全体共通データ
            const char* combinationFileName;
            const char* bonusCombinationFileName;
            std::string separator;
            int reelNum = 0;
            int img[NUM_IMG] = { 0 };
            int BBAdjustImgId = 0;;//BB中の枚数調整用の先頭画像ID
            int cellNum = 0;
            int checkLineNum = 0;
            VECTOR2 bacePos = 0.0f;//リールの基準位置
            VECTOR2 reelSize = 0.0f;
            VECTOR2 imgPos = 0.0f;//画像基準位置
            float imgSize = 0.0f;//画像倍率
            VECTOR2 offsetPos = 0.0f;//画像修正位置
            VECTOR2 cellSize = 0.0f;//一コマのサイズ
            float offset = 0.0f;//一つのリールの間隔
            int drawNum = 0;//表示コマ数
            float RPM = 0.0f;//RotateParMinits
            float NeedTime = 0.0f;//一コマ動くのに必要な時間
            bool animeFlag = false;
            int maxMoveRange = 0;
        };
        struct COMBI_DATA {
            int resultId = -1;
            int combiImg[NUM_REEL];
            int& operator[](int id) {
                return combiImg[id];
            }
        };
        struct BONUS_COMBI_DATA {
            int bonusId = 0;
            int combiImg[NUM_REEL];
            int& operator[](int id) {
                return combiImg[id];
            }
        };
    private:
        struct REELS {//リールごとのデータ
            int reelId = -1;
            int beforeNum = 0;//動く前のコマ番号
            int afterNum = 0;//止まるコマ番号
            float curNum = 0.0f;//現在下段に表示しているコマ番号
            bool animeFlag = false;//全リールが動いているか
            bool stopFlag = false;//リールが止まるときのフラグ
            bool setAfter = false;//afterNumを一度だけ設定するフラグ
        };
        DATA Reels;
        REELS* Reel = 0;
        std::vector<COMBI_DATA> Combi;
        std::vector<BONUS_COMBI_DATA> BonusCombi;
        bool MoveFlag = false;//リール全体を動かすスイッチ
        float AnimeTime = 0.0f;//動き始めてからの時間
        int StopCunt = 0;//止めたリールのカウント
        int StopCell;//止めたリールのコマ番号
        //int AfterNum;
        //int DrawCellId;
        //float CurCell;
        //int Result;
        //int Bonus;
        //int moveCell;
        std::vector<COMBI_DATA> Buffer;
        void initresultcombination();
        void initbonuscombination();
        int I = 0;
        int J = 0;
    public:
        REEL(class GAME* game);
        ~REEL();
        void create();
        void init();
        void update();
        void initcombination();
        bool checkresultexist();//役が成立しているか
        bool checkbonusexist();//ボーナスが成立しているか
        bool checkresultexist(int moveCell,int reelId);//出目に役が成立する並びがあるか
        bool checkbonusexist(int moveCell, int reelId);//出目にボーナスが成立する並びがあるか
        int tellresultexistcell(int resultId,int reelId);//出目に指定した役が成立する並びまで何コマあるか
        int tellbonusexistcell(int bonusId, int reelId);//出目に指定したボーナスが成立する並びまで何コマあるか
        void draw();
        void debagDraw();
        void stop(int i) { Reel[i].stopFlag = true; }
        void move() { MoveFlag = true; }
        bool tellmovereel() { return Reels.animeFlag; }
        bool tellmovereel(int i){return Reel[i].animeFlag;}
        int maxMoveRange() { return Reels.maxMoveRange; }
    };
}

