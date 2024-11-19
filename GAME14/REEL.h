#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class REEL :
        public GAME_OBJECT{
    public:
        struct DATA {
            VECTOR2 pos = 0.0f;
            VECTOR2 cellSize = 0.0f;
            COLOR color = COLOR(0, 0, 0);
            int cellId[21] = { 0 };

        };
    protected:
        int ReelId = -1;//停止ボタンとの参照
        int brank = -1;
        int MaxNum = 21;//コマ数
        int DrawNum = 5;//表示コマ数
        float RPM = 78.0f;//RotateParMinits
        int BeforeNum = 0;//動く前のコマ番号
        int AfterNum = 0;//止まるコマ番号
        float CurNum = 0;//現在中段に表示しているコマ番号
        float AnimeTime = 0;//動き出してからの時間
        float NeedTime = 0;//１コマ動くのに必要な時間
        bool AnimeFlag = false;//リールが動いているか
        bool Stop = false;//リールが止まるときのフラグ
        bool SetAfter = false;//AfterNumを一度だけ設定するフラグ
        bool Move = false;//リールを動かすスイッチ
        DATA Reel;
    public:
        REEL(class GAME* game):
            GAME_OBJECT(game){}
        ~REEL();
        virtual void create();
        void init(int reelId);
        virtual void update();
        void draw();
        void stop() { Stop = true; }
        void move() { Move = true; }
    };
}

