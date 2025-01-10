#pragma once
#include"../../libOne//inc//VECTOR2.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class REEL :
        public GAME_OBJECT{//リールの動き、表示,役の成立判定
    public:
        enum PATTERN_ID {
            BONUS_A,
            BONUS_B,
            BAR,
            REPLAY,
            WATERMELON_A,
            WATERMELON_B,
            CHERRY,
            BELL_A,
            BELL_B,
            NUM_PATTERN
        };
        struct DATA {//全体共通データ
            int reelNum = 0;
            int img[NUM_PATTERN] = { 0 };
            int cellNum = 0;
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
        };
    private:
        struct REELS {//リールごとのデータ
            int reelId = -1;
            int beforeNum = 0;//動く前のコマ番号
            int afterNum = 0;//止まるコマ番号
            float curNum = 0.0f;//現在下段に表示しているコマ番号
            bool animeFlag = false;//リールが動いているか
            bool stopFlag = false;//リールが止まるときのフラグ
            bool setAfter = false;//afterNumを一度だけ設定するフラグ
        };
        DATA Reels;
        REELS* Reel = 0;
        bool MoveFlag = false;//リール全体を動かすスイッチ
        float AnimeTime = 0.0f;//動き始めてからの時間
        int StopCunt = 0;//止めたリールのカウント
        int StopCell;
    public:
        REEL(class GAME* game);
        ~REEL();
        void create();
        void init();
        void update();
        void draw();
        void debagDraw();
        void stop(int i) { Reel[i].stopFlag = true; }
        void move() { MoveFlag = true; }
    };
}

