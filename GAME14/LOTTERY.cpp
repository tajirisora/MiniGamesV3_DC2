#include"GAME14.h"
#include"../../libOne/inc/window.h"
#include"CONTAINER.h"
#include"REEL.h"
#include "LOTTERY.h"
#include<fstream>
namespace GAME14 {
    void LOTTERY::create() {
        Lottery = game()->container()->data().lottery;
        initProbId();
        initStateId();
        initResultId();
        createLevel();//3,4は除外
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, Lottery.probFlagMax);
        Mt = mt;
        Dist = dist;
        Result = -1;
        BonusResult = 0;
        State = NORMAL;

    }
    void LOTTERY::createLevel() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, Lottery.levelFlagMax);
        int randnum = dist(mt);

        for (int i = LEVEL_1; i < NUM_LEVEL; i++) {
            randnum -= Lottery.levelWaite[i];
            if (randnum <= 0) {
                Level = i;
                break;
            }
        }
    }
    LOTTERY::~LOTTERY() {
    }

    void LOTTERY::init() {
        std::string str;
        std::string cutStr;
        std::string::size_type startPos = 0;
        std::string probName = "\0";
        std::string state = "\0";
        int level = 0;

        std::ifstream file(Lottery.fileName , std::ios::binary);
        if (!file) { 
            file.close();
            WARNING(1, "flag_prob.txtが開けませんでした","");
        }
        while (1) {

            std::getline(file, str);
            if (file.eof()) { break; }

            while (1) {
                
                std::string::size_type pos = str.find(Lottery.separator, startPos);
                //　'/'が見つからなかったら 最後だったら
                if (pos == std::string::npos) {
                    pos = str.length()-1;
                }

                cutStr = str.substr(startPos, pos - startPos);
                startPos = pos + Lottery.separator.length();

                if (probName.length() != 0 && level != 0) {
                    Prob[ProbId[probName]].stateId = StateId[state];
                    Prob[ProbId[probName]][level] = std::stoi(cutStr);
                    level = 0;
                    //最後だったら
                    if (startPos >= str.length()) {
                        probName = "\0";
                        state = "\0";
                        startPos = 0;
                        break;
                    }
                    continue;
                }

                //長さが１のときレベルとする
                if (cutStr.length() == 1) {
                        level = std::stoi(cutStr);
                }
                else {
                    //ニューメリック・チェック
                    if (strspn(cutStr.c_str(), "1234567890 ") < cutStr.length()) {
                        
                        std::string::size_type cutPos = cutStr.find(" ");
                        if (cutPos != std::string::npos) {
                            //スペースを削除
                            cutStr = cutStr.substr(0, cutPos);
                        }
                        //出現ステート取得 4文字以下
                        if (cutStr.length() <= 4) {
                            state = cutStr;
                        }
                        else {

                            probName = cutStr;
                        }
                    }
                }
            }
        }
        file.close();
    }
    void LOTTERY::proc(){
        playlottery();
        game()->reel()->move();
    }
    void LOTTERY::playlottery() {

        int randNumber = Dist(Mt);

        for (int i = 0; i < NUM_PROB; i++) {

            if (State>BONUS) {
                if (Prob[i].stateId == State) {
                    randNumber -= (int)Prob[i][Level];
                }
            }
            else {
                        
                if (Prob[i].stateId == State|| Prob[i].stateId == ALL) {
                    randNumber -= (int)Prob[i][Level];
                }
            }

            if (randNumber <= 0) {
                setResult(i);
                return;
            }
        }
            
        Result = Hazure;
        
    }
    void LOTTERY::setResult(int id) {
        switch (id) {
            case REPLAY:
            case F_RT_REPLAY:

                Result = Replay;

                break;

            case JAC_REPLAY:

                Result = Jac_Replay;

                break;

            case JAC_REPLAY_RB:

                Result = Jac_Replay;

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case JAC_REPLAY_BB:

                Result = Jac_Replay;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case RT_REPLAY:

                Result = Rt_Replay;

                break;

            case RT_REPLAY_RB:

                Result = Rt_Replay;

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case RT_REPLAY_BB:

                Result = Rt_Replay;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case RT_REPLAY_REG:

                Result = Rt_Replay;

                if (BonusResult <= 0)
                BonusResult = REGULAR;

                break;

            case BELL_A:

                Result = Bell_A;

                break;

            case BB_BELL_A:

                Result = Bell_A;

                break;

            case BELL_B:

                Result = Bell_B;

                break;

            case BELL_B_BB:

                Result = Bell_B;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case BB_BELL_B:

                Result = Bell_B;

                break;

            case BB_EX_BELL:

                Result = Ex_Bell;

                break;

            case WATERMELON_A:

                Result = Watermelon_A;

                break;

            case WATERMELON_B:

                Result = Watermelon_B;

                break;

            case REG_WATERMELON:

                Result = Watermelon_B;

                break;

            case CHERRY_A1:

                Result = Cherry_A1;

                break;

            case CHERRY_A1_RB:

                Result = Cherry_A1;

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case CHERRY_A2:

                Result = Cherry_A2;

                break;

            case CHERRY_B:

                Result = Cherry_B;

                break;

            case CHERRY_B_RB:

                Result = Cherry_B;

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case CHERRY_B_BB:

                Result = Cherry_B;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case CHERRY_B_REG:

                Result = Cherry_B;

                if (BonusResult <= 0)
                BonusResult = REGULAR;

                break;

            case EX_A_RB:

                Result = Ex_A;

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case EX_A_BB:

                Result = Ex_A;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case EX_B_BB:

                Result = Ex_B;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case EX_B_REG:

                Result = Ex_B;

                if (BonusResult <= 0)
                BonusResult = REGULAR;

                break;

            case EX_C_RB:

                Result = Ex_C;

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case EX_D_BB:

                Result = Ex_D;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case EX_D_REG:

                Result = Ex_D;

                if (BonusResult <= 0)
                BonusResult = REGULAR;

                break;

            case EX_E_RB:

                Result = Ex_E;

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case EX_E_BB:

                Result = Ex_E;

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case EX_E_REG:

                Result = Ex_E;

                if (BonusResult <= 0)
                BonusResult = REGULAR;

                break;

            case R_BB:

                if (BonusResult <= 0)
                BonusResult = RED_BB;

                break;

            case B_BB:

                if (BonusResult <= 0)
                BonusResult = BLUE_BB;

                break;

            case REG:

                if (BonusResult <= 0)
                BonusResult = REGULAR;

                break;

            case CHALLENGE_A:

                Result = Challenge_A;

                break;

            case CHALLENGE_B:

                Result = Challenge_B;

                break;

            case LUCKY:

                Result = Lucky;

                break;

            case REG_EX:

                Result = Reg_Ex;

                break;

        }
    }
    void LOTTERY::debugdraw(){
        /*
        textSize(30);
        fill(255);
        for (int i = 0; i < NUM_RESULT; i++) {
            text(Prob[i].stateId,0,25*(i+1));
            for (int j = 0; j < 7; j++) {
                if (j == 1 || j == 2 || j == 5 || j == 6) {
                    text(Prob[i][j], 200*(j), 25*(i+1));
                }

            }
        }
        
        print(Level);
        print(ProbId);
        print(BonusResult);
        print(RundNumber);
        */
        print("成立した役");
        print(Result);
        print("成立したボーナス");
        print(BonusResult);
    }

    void LOTTERY::initProbId() {
        //確率用のID
        ProbId["Replay"] = REPLAY;
        ProbId["F_RT_REPLAY"] = F_RT_REPLAY;
        ProbId["JACReplay"] = JAC_REPLAY;
        ProbId["JACReplay_RB"] = JAC_REPLAY_RB;
        ProbId["JACReplay_BB"] = JAC_REPLAY_BB;
        ProbId["RTReplay"] = RT_REPLAY;
        ProbId["RTReplay_RB"] = RT_REPLAY_RB;
        ProbId["RTReplay_BB"] = RT_REPLAY_BB;
        ProbId["RTReplay_REG"] = RT_REPLAY_REG;
        ProbId["Bell_A"] = BELL_A;
        ProbId["BB_Bell_A"] = BB_BELL_A;
        ProbId["Bell_B"] = BELL_B;
        ProbId["Bell_B_BB"] = BELL_B_BB;
        ProbId["BB_Bell_B"] = BB_BELL_B;
        ProbId["BB_Ex_Bell"] = BB_EX_BELL;
        ProbId["Watermelon_A"] = WATERMELON_A;
        ProbId["Watermelon_B"] = WATERMELON_B;
        ProbId["REG_Watermelon"] = REG_WATERMELON;
        ProbId["Cherry_A1"] = CHERRY_A1;
        ProbId["Cherry_A1_RB"] = CHERRY_A1_RB;
        ProbId["Cherry_A2"] = CHERRY_A2;
        ProbId["Cherry_B"] = CHERRY_B;
        ProbId["Cherry_B_RB"] = CHERRY_B_RB;
        ProbId["Cherry_B_BB"] = CHERRY_B_BB;
        ProbId["Cherry_B_REG"] = CHERRY_B_REG;
        ProbId["EX_A_RB"] = EX_A_RB;
        ProbId["EX_A_BB"] = EX_A_BB;
        ProbId["EX_B_BB"] = EX_B_BB;
        ProbId["EX_B_REG"] = EX_B_REG;
        ProbId["EX_C_RB"] = EX_C_RB;
        ProbId["EX_D_BB"] = EX_D_BB;
        ProbId["EX_D_REG"] = EX_D_REG;
        ProbId["EX_E_RB"] = EX_E_RB;
        ProbId["EX_E_BB"] = EX_E_BB;
        ProbId["EX_E_REG"] = EX_E_REG;
        ProbId["R_BigBonus"] = R_BB;
        ProbId["B_BigBonus"] = B_BB;
        ProbId["Regular"] = REG;
        ProbId["Challenge_A"] = CHALLENGE_A;
        ProbId["Challenge_B"] = CHALLENGE_B;
        ProbId["Lucky"] = LUCKY;
        ProbId["REG_Ex"] = REG_EX;
    }
    void LOTTERY::initStateId() {
        StateId["NR"] = NORMAL;
        StateId["F_RT"] = F_RT;
        StateId["S_RT"] = S_RT;
        StateId["BB"] = BB;
        StateId["REG"] = RG;
        StateId["ALL"] = ALL;
    }
    void LOTTERY::initResultId() {
        
        ResultId["Hazure"] = Hazure ;
        ResultId["Replay"] = Replay ;
        ResultId["JACReplay"] = Jac_Replay ;
        ResultId["RTReplay"] = Rt_Replay ;
        ResultId["Bell_A"] = Bell_A ;
        ResultId["Bell_B"] = Bell_B ;
        ResultId["Watermelon_A"] = Watermelon_A ;
        ResultId["Watermelon_B"] = Watermelon_B ;
        ResultId["Cherry_A1"] = Cherry_A1 ;
        ResultId["Cherry_A2"] = Cherry_A2 ;
        ResultId["Cherry_B"] = Cherry_B ;
        ResultId["EX_A"] = Ex_A ;
        ResultId["EX_B"] = Ex_B ;
        ResultId["EX_C"] = Ex_C ;
        ResultId["EX_D"] = Ex_D ;
        ResultId["EX_E"] = Ex_E ;
        ResultId["EX_Bell"] = Ex_Bell ;
        ResultId["Challenge_A"] = Challenge_A ;
        ResultId["Challenge_B"] = Challenge_B ;
        ResultId["Lucky"] = Lucky ;
        ResultId["Reg_EX"] = Reg_Ex ;
    }

}