#include"../../libOne/inc/window.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include "CREDIT.h"
#include"LOTTERY.h"
#include"BET.h"
#include"PLAYER.h"
#include"BONUS_ANNOUNCE.h"
#include<fstream>
namespace GAME14 {
    CREDIT::CREDIT(class GAME* game):
        GAME_OBJECT(game){}
    CREDIT::~CREDIT(){}
    void CREDIT::create(){
        Credit = game()->container()->data().credit;

    }
    void CREDIT::init() {
        Credit = game()->container()->data().credit;
        for (int i = 0; i < LOTTERY::NUM_RESULT - 1; i++) {
            Result[i].resultId = 0;
            Result[i].numPayout = 0;
            Result[i].numMissPayout = 0;
        }
        Payout = 0;
        CurPayout = 0;
        CurTime = 0;
        BBPayoutNum = 0;
        REGPlayTime = 0;
        BBAdjustFlag = false;
        SistemFlag = false;
        initResult();
    }
    void CREDIT::initResult() {
        std::ifstream file;
        std::string str;
        std::string cutStr;
        std::string::size_type startPos = 0;
        int i = 0;
        file.open(Credit.payoutFileName, std::ios::binary);
        if (!file) {
            file.close();
            WARNING(1, "ファイルが開けませんでした", Credit.payoutFileName);
        }
        
        while (1) {
            std::getline(file, str);
            if (file.eof()) {
                break;
            }

            while (1) {

                std::string::size_type cutPos = str.find(Credit.separator, startPos);

                if (cutPos == std::string::npos) {
                    cutPos = str.length() - 1;
                }

                cutStr = str.substr(startPos, cutPos - startPos);
                startPos = cutPos + Credit.separator.length();

                if (Result[i].resultId > 0) {

                    if (startPos < str.length()) {
                        Result[i].numPayout = std::stoi(cutStr);
                        continue;
                    }
                    else {
                        Result[i].numMissPayout = std::stoi(cutStr);
                        startPos = 0;
                        i++;

                        break;
                    }
                }
                //ニューメリック・チェック
                if (strspn(cutStr.c_str(), "1234567890 ") < cutStr.length()) {

                    std::string::size_type resizePos = cutStr.find(" ");
                    if (resizePos != std::string::npos) {
                        //スペースを削除
                        cutStr = cutStr.substr(0, resizePos);
                    }

                    Result[i].resultId = game()->lottery()->resultId(cutStr);

                }
            }

        }

        file.close();
    }

    void CREDIT::update(){
        CurTime += delta;
        if (Payout&&CurTime>Credit.onePayoutTime) {
            CurPayout++;
            game()->player()->addMedal();
            Payout--;
            CurTime -= CurTime;
            if (game()->lottery()->state()==LOTTERY::BB) {
                BBPayoutNum--;
                if (BBPayoutNum < 0) {
                    BBPayoutNum = 0;
                }
                if (!BBPayoutNum) {
                    game()->lottery()->changeStateNORMAL();
                    game()->lottery()->clearBonusResult();
                }
            }
            if (game()->lottery()->state() == LOTTERY::RG) {
                if (!REGPlayTime && !Payout) {
                    game()->lottery()->changeStateNORMAL();
                    game()->lottery()->clearBonusResult();
                }
            }
        }

        if (Payout <= 0) {
            SistemFlag = false;
        }
    }
    void CREDIT::resultPayout(bool flag) {
        int result = game()->lottery()->result();
        if (result == LOTTERY::Hazure) {
            return;
        }
        if (REGPlayTime) {
            REGPlayTime--;
        }
        for (int i = 0; i < LOTTERY::NUM_RESULT - 1; i++) {
            if (Result[i].resultId == result) {
                if ((result == LOTTERY::Replay) ){
                    if (flag) {
                        game()->bet()->replay();
                    }
                }
                else {
                    SistemFlag = true;
                    if (flag) {
                        Payout = Result[i].numPayout;
                        
                        if (BBAdjustFlag) {
                            //BB_BellA||BB_BellBはMissに調整用枚数を記入している
                            Payout = Result[i].numMissPayout;
                            BBAdjustFlag = false;
                        }
                        
                    }
                    else {
                        Payout = Result[i].numMissPayout;
                    }
                }
            }
        }
    }
    void CREDIT::resultBonus(bool flag) {
        int bonusId = game()->lottery()->bonusResult();
        if (flag) {
            game()->bonus_Announce()->resetCurPlayTimeforBonus();
            if (bonusId < LOTTERY::REGULAR) {
                game()->lottery()->changeStateBB();
                game()->player()->addBBTime();
                BBPayoutNum = Credit.BBPayoutMaxNum;
            }
            else {
                game()->lottery()->changeStateREG();
                game()->player()->addREGTime();
                REGPlayTime = Credit.REGPayoutMaxTime;
            }
        }
    }

    void CREDIT::draw() {
        textSize(Credit.drawPayoutSize);
        fill(Credit.drawPayoutColor);
        float adjust = (Credit.drawPayoutSize * (std::to_string(CurPayout).length()-1)) / 2;
        text(CurPayout, Credit.drawPayoutPos.x-adjust, Credit.drawPayoutPos.y);
        if (game()->lottery()->state() == LOTTERY::BB) {
            adjust = (Credit.drawPayoutSize * (std::to_string(BBPayoutNum).length() - 1)) / 2;
            text(BBPayoutNum, Credit.drawBBPayoutPos.x - adjust, Credit.drawBBPayoutPos.y);
        }
    }
    void CREDIT::debagdraw() {
        /*
        textSize(40);
        int j = 0;
        print(Result[16].resultId);
        for (int i = 0; i < LOTTERY::NUM_RESULT-1; i++) {
            if (i == 22) {
                text("1989", 1500, 100 + j * 40);
                j++;
            }
            text(Result[i].resultId, 1500, 100 + j * 40);
            text(Result[i].numPayout, 1600, 100 + j * 40);
            text(Result[i].numMissPayout, 1700, 100 + j * 40);
            j++;
        }

        */
        fill(255);
        print(CurTime);
        print("払い出し数");
        print(Payout);

    }
}