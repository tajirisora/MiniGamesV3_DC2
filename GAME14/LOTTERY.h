#pragma once
#include "GAME_OBJECT.h"
#include<vector>
#include<string>
#include<map>
#include<random>
namespace GAME14 {
    class LOTTERY ://フラグ抽選クラス
        public GAME_OBJECT{
    public:
        enum PROB_ID {//確率用ID
            REPLAY,
            F_RT_REPLAY,//前半RT中のREPLAY
            JAC_REPLAY,//前半RT中のJAC_REPLAY通常時はでない
            JAC_REPLAY_RB,//R_BB付きJAC_REPLAY
            JAC_REPLAY_BB,//B_BB付きJAC_REPLAY
            RT_REPLAY,//後半RT中の
            RT_REPLAY_RB,//R_BB付きRT_REPLAY
            RT_REPLAY_BB,//B_BB付きRT_REPLAY
            RT_REPLAY_REG,//REG付きRT_REPLAY
            BELL_A,
            BB_BELL_A,//BB中の中段揃いベル
            BELL_B,//単体
            BELL_B_BB,//B_BB付きBELL_B
            BB_BELL_B,//BB中の斜め揃いベル
            BB_EX_BELL,//BB中のバラケ目
            WATERMELON_A,
            WATERMELON_B,
            REG_WATERMELON,//REG中のスイカ
            CHERRY_A1,//単体
            CHERRY_A1_RB,//R_BB付きTHERRY_A1
            CHERRY_A2,
            CHERRY_B,//単体
            CHERRY_B_RB,//R_BB付きTHERRY_B
            CHERRY_B_BB,//B_BB付きTHERRY_B
            CHERRY_B_REG,//REG付きTHERRY_B
            EX_A_RB,//R_BB対応一枚役EX_A
            EX_A_BB,//B_BB対応一枚役EX_A
            EX_B_BB,//B_BB対応一枚役EX_B
            EX_B_REG,//REG対応一枚役EX_B
            EX_C_RB,//R_BB対応一枚役EX_C
            EX_D_BB,//B_BB対応一枚役EX_D
            EX_D_REG,//REG対応一枚役EX_D
            EX_E_RB,//R_BB対応一枚役EX_E
            EX_E_BB,//B_BB対応一枚役EX_E
            EX_E_REG,//REG対応一枚役EX_E
            R_BB,//単体
            B_BB,//単体
            REG,//単体
            CHALLENGE_A,//REG中技術介入役 1st失敗: 4枚 2st以降失敗:6枚 成功:15枚
            CHALLENGE_B,//REG中技術介入役 1st失敗: 4枚 2st以降失敗:6枚 成功:15枚
            LUCKY,      //REG中技術介入役 1st失敗:15枚 2st以降失敗:6枚 成功:15枚
            REG_EX,//REG中一枚役
            NUM_PROB
        };
        
        enum RESULT_ID {//小役の種類またはリール制御の種類
            //REG_WATERMELONはWatermelon_Bと同じリール制御
            Hazure,
            Replay,
            Jac_Replay,
            Rt_Replay,
            Bell_A,
            Bell_B,
            Watermelon_A,
            Watermelon_B,
            Cherry_A1,
            Cherry_A2,
            Cherry_B,
            Ex_A,
            Ex_B,
            Ex_C,
            Ex_D,
            Ex_E,
            NUM_NORMAL_RESULT,
            Ex_Bell,
            Challenge_A,
            Challenge_B,
            Lucky,
            Reg_Ex,
            NUM_RESULT

        };
        enum BONUS_ID {//ボーナスの種類
            NO_BONUS,
            RED_BB,
            BLUE_BB,
            REGULAR,
            NUM_BONUS,

        };
        enum STATE_ID {//ゲームフローのどこにいるか
            ALL,//ボーナス中以外
            NORMAL,
            F_RT,
            S_RT,
            BONUS,
            BB,
            RG
        };

        enum LEVEL {
            LEVEL_1 = 1,
            LEVEL_2,
            LEVEL_3,
            LEVEL_4,
            LEVEL_5,
            LEVEL_6,
            NUM_LEVEL
        };
        struct DATA {

            const char* fileName = nullptr;

            int  probFlagMax = 0;

            int levelFlagMax = 0;//レベルを決める乱数の最大値
            int levelWaite[NUM_LEVEL];//各レベルの重さ(出やすさ)

            std::string separator;


        };
        struct PROB_DATA {
            int stateId = 0;

            int level1 = 0;
            int level2 = 0;
            int level5 = 0;
            int level6 = 0;
            int& operator [](int level) {
                switch (level) {
                    case 1:
                        return level1;
                    case 2:
                        return level2;
                    case 5:
                        return level5;
                    case 6:
                        return level6;
                }
            }

        };
    private:
        PROB_DATA Prob[NUM_PROB];
        DATA Lottery;
        std::map<std::string,PROB_ID> ProbId;
        std::map<std::string, STATE_ID> StateId;
        std::map<std::string, RESULT_ID> ResultId;
        bool SeedCreate = true;
        std::mt19937 Mt;
        std::uniform_int_distribution<int>Dist;
        int Level;
        int Result;//成立した小役
        int BonusResult;//成立中のボーナス
        int RundNumber;
        int State;
    public:
        LOTTERY(class GAME* game) :
            GAME_OBJECT(game) {}
        ~LOTTERY();
        void create();
        void init();
        void createLevel();
        void proc();
        void debugdraw();
        void playlottery();
        void initProbId();
        void initStateId();
        void initResultId();
        void deletResult() { Result = -1; }
        int result() { return Result ; }
        int bonusResult(){ return BonusResult ; }
        void setResult(int id);
        int resultId(std::string str) { return ResultId[str]; }
    };
}

