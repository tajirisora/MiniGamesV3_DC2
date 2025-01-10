#pragma once
#include "GAME_OBJECT.h"
#include"LOTTERY.h"

namespace GAME14 {
    class REEL_MAP :
        public GAME_OBJECT {//リールＭＡＰ取得、制御
    public:
        enum START_REEL_ID {
            LEFT,
            MIDDLE,
            RIGHT,
            NUM_REEL
        };
        
        struct DATA {
            const char* reelMapFile = nullptr;//リール配列のファイル名
            const char* leftControlFile = nullptr;//Bonusに入ってない時の左第一停止時のリール制御ファイル名
            int* reelData;//マップデータ
            char* leftControlData = nullptr;//左第一停止時のリール制御データ
            int rows = 0;//リール配列データの行数
            int cols = 0;//リール配列データの列数
            std::string separator;
        };

        struct CONTROL_DATA {
            int startId;//何打ちのリール制御か
            //int resultId;//なんの役のリール制御か
            //int bonusResultId;//なんのボーナス中のリール制御か
            int* normalBuffer;//ボーナスが成立していない時の滑りコマ数の配列
            int* R_BB_Buffer;//赤BBが成立している時の
            int* B_BB_Buffer;//青BBが成立している時の
            int* REG_Buffer;//REGが成立している時の
            
            int* operator[](int Id) {
                switch (Id) {
                   case LOTTERY::NO_BONUS:
                       return normalBuffer;
                   case LOTTERY::RED_BB:
                       return R_BB_Buffer;
                   case LOTTERY::BLUE_BB:
                       return B_BB_Buffer;
                   case LOTTERY::REGULAR:
                       return REG_Buffer;
                }
            }
        };
    private:
        DATA Map;
        int reelDataSize;
        std::string Str;
        int ID;
        int rowLength = 0;
        int StopCell = -1;
        CONTROL_DATA Control_Data [LOTTERY::NUM_NORMAL_RESULT] ;//とりあえず左リールのみ
    public:
        REEL_MAP(class GAME* game);
        ~REEL_MAP();
        void create();
        void init();
        int tellStopCell(int cellId,int reelId);
        void debagDraw();
        int textureNum(int reelId,int cellNum);
    };
}