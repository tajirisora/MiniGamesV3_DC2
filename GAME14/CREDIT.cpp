#include"../../libOne/inc/window.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include "CREDIT.h"
#include"LOTTERY.h"
#include"BET.h"
#include<fstream>
namespace GAME14 {
    CREDIT::CREDIT(class GAME* game):
        GAME_OBJECT(game){}
    CREDIT::~CREDIT(){}
    void CREDIT::create(){
        Credit = game()->container()->data().credit;
    }
    void CREDIT::init() {
        Payout = 0;
        CurPayout = 0;
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
            Payout--;
            CurTime -= CurTime;
        }
    }
    void CREDIT::resultPayout(bool flag) {
        int result = game()->lottery()->result();
        if (result == LOTTERY::Hazure) {
            return;
        }
        for (int i = 0; i < LOTTERY::NUM_RESULT - 1; i++) {
            if (Result[i].resultId == result) {
                if ((result == LOTTERY::Replay) ){
                    if (flag) {
                        game()->bet()->replay();
                    }
                }
                else {
                    if (flag) {
                        Payout = Result[i].numPayout;
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
            if (bonusId < LOTTERY::REGULAR) {
                game()->lottery()->changeStateBB();

            }
            else {
                game()->lottery()->changeStateREG();

            }
        }
    }

    void CREDIT::draw() {
        print(CurTime);
        print("払い出し数");
        print(Payout);
        textSize(Credit.drawPayoutSize);
        fill(Credit.drawPayoutColor);
        float adjust = (Credit.drawPayoutSize * (std::to_string(CurPayout).length()-1)) / 2;
        text(CurPayout, Credit.drawPayoutPos.x-adjust, Credit.drawPayoutPos.y);
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
    }
}