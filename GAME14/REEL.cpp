#include"../../libOne/inc/window.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"REEL_MAP.h"
#include"LOTTERY.h"
#include "REEL.h"
#include"CREDIT.h"
#include"PLAYER.h"
#include"BONUS_ANNOUNCE.h"
#include<fstream>
namespace GAME14 {
    REEL::REEL(class GAME* game) :
        GAME_OBJECT(game) {}
    REEL::~REEL() {
        delete[] Reel;
    }
    void REEL::create() {
        Reels = game()->container()->data().reel;
        if (Reel) { delete[] Reel; }
        Reel = new REELS[Reels.cellNum];
    }
    void REEL::init() {
        MoveFlag = false;
        AnimeTime = 0.0f;
        StopCunt = 0;
        StopCell;

        for (int i = 0; i < Reels.reelNum; i++) {
            Reel[i].reelId = i;
            Reel[i].beforeNum = 0;
            Reel[i].afterNum = 0;
            Reel[i].curNum = 0.0f;
            Reel[i].animeFlag = false;
            Reel[i].stopFlag = false;
            Reel[i].setAfter = false;
        }
        initcombination();
        if (Buffer.size()) { Buffer.resize(0); }
        for (int i = 0; i < Reels.checkLineNum; i++) {
            Buffer.emplace_back();
        }
    }
    void REEL::initcombination() {
        initresultcombination();
        initbonuscombination();
    }
    void REEL::initresultcombination() {
        std::string str;
        std::string cutStr;
        std::string::size_type startPos = 0;
        std::ifstream file;
        file.open(Reels.combinationFileName);
        int i = 0;
        int j = 0;
        if (!file) {
            file.close();
            WARNING(1, "ファイルが開けませんでした", Reels.combinationFileName);
        }
        if (Combi.size()) {
            Combi.resize(0);
        }
        while (1) {
            std::getline(file, str);

            if (file.eof()) {
                break;
            }
            Combi.emplace_back();
            while (1) {

                std::string::size_type cutPos = str.find(Reels.separator, startPos);

                if (cutPos == std::string::npos) {
                    cutPos = startPos + 1;
                }
                cutStr = str.substr(startPos, cutPos - startPos);
                startPos = cutPos + Reels.separator.length();

                if (Combi[i].resultId > -1) {
                    Combi[i][j] = std::stoi(cutStr);
                    j++;
                    if (j >= NUM_REEL) {
                        startPos = 0;
                        j = 0;
                        i++;
                        break;
                    }
                }

                //ニューメリック・チェック
                if (strspn(cutStr.c_str(), "1234567890 -") < cutStr.length()) {
                    std::string::size_type resizePos = cutStr.find(" ");
                    if (resizePos != std::string::npos) {
                        cutStr = str.substr(0, resizePos);
                    }
                    Combi[i].resultId = game()->lottery()->resultId(cutStr);
                }
            }
        }
        file.close();


    }
    void REEL::initbonuscombination() {
        std::string str;
        std::string cutStr;
        std::string::size_type startPos = 0;
        std::ifstream file;
        file.open(Reels.bonusCombinationFileName,std::ios::binary);
        int i = 0;
        int j = 0;
        if (!file) {
            file.close();
            WARNING(1, "ファイルが開けませんでした", Reels.bonusCombinationFileName);
        }

        if (BonusCombi.size()) {
            BonusCombi.resize(0);
        }
        while (1) {
            std::getline(file, str);

            if (file.eof()) {
                break;
            }
            BonusCombi.emplace_back();
            while (1) {

                std::string::size_type cutPos = str.find(Reels.separator, startPos);

                if (cutPos == std::string::npos) {
                    cutPos = startPos + 1;
                }
                cutStr = str.substr(startPos, cutPos - startPos);
                startPos = cutPos + Reels.separator.length();

                if (BonusCombi[i].bonusId > 0) {
                    BonusCombi[i][j] = std::stoi(cutStr);
                    j++;
                    if (j >= NUM_REEL) {
                        startPos = 0;
                        j = 0;
                        i++;
                        break;
                    }
                    continue;
                }

                //ニューメリック・チェック
                if (strspn(cutStr.c_str(), "1234567890 -") < cutStr.length()) {
                    std::string::size_type resizePos = cutStr.find(" ");
                    if (resizePos != std::string::npos) {
                        cutStr = str.substr(0, resizePos);
                    }
                    BonusCombi[i].bonusId = game()->lottery()->bonusId(cutStr);
                }
            }
        }
        file.close();



    }
    void REEL::update() {

        //抽選が終わったらかつウェイト時間を満たしていたら回転させる
        if (MoveFlag) {
            for (int i = 0; i < Reels.reelNum; i++) {
                Reel[i].animeFlag = true;
            }
            AnimeTime = 0.0f;
            MoveFlag = false;
            Reels.animeFlag = true;
        }
        if (Reels.animeFlag) {
            AnimeTime += delta;
            for (int i = 0; i < Reels.reelNum; i++) {
                if (Reel[i].animeFlag) {//そのリールが動いているか
                    //進んだコマ数//
                    Reel[i].curNum = Reel[i].beforeNum + AnimeTime / Reels.NeedTime;
                    //if(i == 0)
                    //CurCell = Reel[i].curNum;
                    if (Reel[i].stopFlag) {//止まるときの処理
                        if (!Reel[i].setAfter) {//止まる場所の指定
                            StopCunt++;
                            //StopCell 
                            //Reel[i].afterNum = ceil(Reel[i].curNum);

                            StopCell = (int)ceil(Reel[i].curNum) % Reels.cellNum;
                            Reel[i].afterNum = ceil(Reel[i].curNum);

                            switch (Reel[i].reelId) {
                            case LEFT:
                                Reel[i].afterNum = Reel[i].afterNum + game()->reelMap()->tellTableStopCell(StopCell, Reel[i].reelId);
                                //AfterNum = Reel[i].afterNum;
                                break;
                            case MIDDLE:
                                Reel[i].afterNum = Reel[i].afterNum + game()->reelMap()->tellStopCell(StopCell, Reel[i].reelId);

                                break;

                            case RIGHT:
                                int LeftStop = Reel[LEFT].afterNum % Reels.cellNum;
                                Reel[i].afterNum = Reel[i].afterNum + game()->reelMap()->tellSecondTableStopCell(StopCell, Reel[i].reelId, LeftStop);
                                break;

                            }

                            Reel[i].setAfter = true;
                        }
                        else {
                            if (Reel[i].curNum > Reel[i].afterNum) {//止まる場所まで来た時の処理
                                Reel[i].beforeNum = Reel[i].afterNum % Reels.cellNum;
                                Reel[i].curNum = Reel[i].beforeNum;
                                Reel[i].setAfter = false;
                                Reel[i].animeFlag = false;
                                Reel[i].stopFlag = false;

                            }
                        }
                    }
                }
            }
            int stopreel = 0;
            for (int j = 0; j < Reels.reelNum; j++) {
                if (!Reel[j].animeFlag) {
                    stopreel++;
                }
            }
            if (stopreel >= Reels.reelNum) {
                Reels.animeFlag = false;
                if (game()->lottery()->state() == LOTTERY::NORMAL) {
                    game()->player()->addPlayTime();
                    game()->player()->addPlayTimeForBonus();
                    if (game()->lottery()->bonusResult()) {
                        game()->bonus_Announce()->addPlayTimeforBonus();
                    }
                }
                game()->credit()->resultPayout(checkresultexist());
                game()->credit()->resultBonus(checkbonusexist());
                StopCunt = 0;
            }

        }

    }
    void REEL::draw() {
        fill(0);
        textSize(50);
        for (int i = 0; i < Reels.reelNum; i++) {
            int startIdx = round(Reel[i].curNum) - 1;//表示し始めるコマcurNumは下段
            for (int j = 0; j < Reels.drawNum; j++) {
                float dist = Reel[i].curNum - startIdx - j;//表示し始めるコマからどれくらい離れているか
                int cellNum = (startIdx + j + Reels.cellNum) % Reels.cellNum;//0から20に収まるように
                VECTOR2 pos = VECTOR2(Reels.imgPos.x + (Reels.reelSize.x * i), Reels.imgPos.y);//表示位置の決定
                pos.y += Reels.cellSize.y * dist;//y軸の調整
                int imgIdx = game()->reelMap()->textureNum(Reel[i].reelId, cellNum);//(reelId)行(cellNum)列目の画像インデックスを取得
                image(Reels.img[imgIdx], pos.x, pos.y, 0, Reels.imgSize);
            }
        }
    }
    void REEL::debagDraw() {
        //  if (isTrigger(KEY_SHIFT)) {
        //      StopCell++;
        //  }
          /*
          print("止めたコマ数");
          print(StopCell);
          print("現在のコマ数");
          print(StopCell);
          print("表示し始めるコマ番号");
          print(DrawCellId);
          print("止まるコマ番号");
          print(StopCell+game()->reelMap()->tellStopCell(StopCell, Reel[0].reelId));
          print("現在のコマ番号");
          print(CurCell);
          */
        /*
        print("止まるコマ番号");
          print(AfterNum);
          
        
        print("成立した役");
        print(Result);
        */
        /*
        print("成立したボーナス");
        print(Bonus);
        */
        /*
        print(StopCunt);
        print(Reels.reelNum);
        print("全リールがうごいているか");
        print(Reels.animeFlag);
        print("リールが動いているか");
        for (int i = 0; i < Reels.reelNum; i++) {
            print(Reel[i].animeFlag);
        }
        */
        /*
        textSize(20);
        for (int i = 0; i < Combi.size(); i++) {
            for (int j = 0; j < NUM_REEL; j++) {
                text(Combi[i][j], 50 * j + 1500, 20 * i + 60);
            }
        }
        print(Combi.size());
        */
        /*
        print("何コマ動くか");
        print(moveCell);
        textSize(40);
        for (int i = 0; i < Reels.checkLineNum; i++) {
            for (int j = 0; j < 3; j++) {
                text(Buffer[i][j], 1500 + j * 50, 300 + i * 40);
            }
        }
        */
          /*
        textSize(40);
        for (int i = 0; i < BonusCombi.size(); i++) {
            for (int j = 0; j < 3; j++) {
                text(BonusCombi[i][j], 1500 + j * 50, 300 + i * 40);
            }
        }*/
        /*
        print("I");
        print(I);
        print("J");
        print(J);
        */
    }
    bool REEL::checkresultexist() {
        int resultId = game()->lottery()->result();
        int bonusId = game()->lottery()->bonusResult();
        REEL_MAP* map = game()->reelMap();
        std::vector<COMBI_DATA> buffer;
        for (int i = 0; i < Reels.checkLineNum; i++) {
            buffer.emplace_back();
        }
        //わからんのでベタ打ち
        buffer[0][0] = map->textureNum(LEFT, Reel[0].afterNum % Reels.cellNum);
        buffer[0][1] = map->textureNum(MIDDLE, Reel[1].afterNum % Reels.cellNum);
        buffer[0][2] = map->textureNum(RIGHT, Reel[2].afterNum % Reels.cellNum);

        buffer[1][0] = map->textureNum(LEFT, Reel[0].afterNum % Reels.cellNum);
        buffer[1][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 1) % Reels.cellNum);
        buffer[1][2] = map->textureNum(RIGHT, (Reel[2].afterNum + 2) % Reels.cellNum);

        buffer[2][0] = map->textureNum(LEFT, (Reel[0].afterNum + 1) % Reels.cellNum);
        buffer[2][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 1) % Reels.cellNum);
        buffer[2][2] = map->textureNum(RIGHT, (Reel[2].afterNum + 1) % Reels.cellNum);

        buffer[3][0] = map->textureNum(LEFT, (Reel[0].afterNum + 2) % Reels.cellNum);
        buffer[3][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 1) % Reels.cellNum);
        buffer[3][2] = map->textureNum(RIGHT, Reel[2].afterNum % Reels.cellNum);

        buffer[4][0] = map->textureNum(LEFT, (Reel[0].afterNum + 2) % Reels.cellNum);
        buffer[4][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 2) % Reels.cellNum);
        buffer[4][2] = map->textureNum(RIGHT, (Reel[2].afterNum + 2) % Reels.cellNum);
        Buffer = buffer;


        for (int i = 0; i < Reels.checkLineNum; i++) {
            for (int j = 0; j < Combi.size(); j++) {
                if (resultId == Combi[j].resultId) {
                    if ((resultId == LOTTERY::Cherry_A1) ||
                        (resultId == LOTTERY::Cherry_A2) ||
                        (resultId == LOTTERY::Cherry_B)) {
                        if ((buffer[i][0] == Combi[j][0]) &&
                            (buffer[i][2] == Combi[j][2])) {
                            return true;
                        }
                    }
                    else {
                        if ((buffer[i][0] == Combi[j][0]) &&
                            (buffer[i][1] == Combi[j][1]) &&
                            (buffer[i][2] == Combi[j][2])) {
                            if ((bonusId == LOTTERY::RED_BB||
                                bonusId == LOTTERY::BLUE_BB)&&
                                buffer[i][0] == Reels.BBAdjustImgId) {
                                game()->credit()->onBBAdjustFlag();
                            }
                            
                            return true;
                        }
                    }
                }
            }
        }
        return false;

    }
    bool REEL::checkbonusexist() {
        int bonusId = game()->lottery()->bonusResult();
        REEL_MAP* map = game()->reelMap();
        std::vector<COMBI_DATA> buffer;
        for (int i = 0; i < Reels.checkLineNum; i++) {
            buffer.emplace_back();
        }
        //わからんのでベタ打ち
        buffer[0][0] = map->textureNum(LEFT, Reel[0].afterNum % Reels.cellNum);
        buffer[0][1] = map->textureNum(MIDDLE, Reel[1].afterNum % Reels.cellNum);
        buffer[0][2] = map->textureNum(RIGHT, Reel[2].afterNum % Reels.cellNum);

        buffer[1][0] = map->textureNum(LEFT, Reel[0].afterNum % Reels.cellNum);
        buffer[1][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 1) % Reels.cellNum);
        buffer[1][2] = map->textureNum(RIGHT, (Reel[2].afterNum + 2) % Reels.cellNum);

        buffer[2][0] = map->textureNum(LEFT, (Reel[0].afterNum + 1) % Reels.cellNum);
        buffer[2][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 1) % Reels.cellNum);
        buffer[2][2] = map->textureNum(RIGHT, (Reel[2].afterNum + 1) % Reels.cellNum);

        buffer[3][0] = map->textureNum(LEFT, (Reel[0].afterNum + 2) % Reels.cellNum);
        buffer[3][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 1) % Reels.cellNum);
        buffer[3][2] = map->textureNum(RIGHT, Reel[2].afterNum % Reels.cellNum);

        buffer[4][0] = map->textureNum(LEFT, (Reel[0].afterNum + 2) % Reels.cellNum);
        buffer[4][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + 2) % Reels.cellNum);
        buffer[4][2] = map->textureNum(RIGHT, (Reel[2].afterNum + 2) % Reels.cellNum);
        Buffer = buffer;


        for (int i = 0; i < Reels.checkLineNum; i++) {
            for (int j = 0; j < BonusCombi.size(); j++) {
                if (bonusId == BonusCombi[j].bonusId) {
                    if ((buffer[i][0] == BonusCombi[j][0]) &&
                        (buffer[i][1] == BonusCombi[j][1]) &&
                        (buffer[i][2] == BonusCombi[j][2])) {
                        return true;
                    }
                }
            }
        }
        return false;


    }
    bool REEL::checkresultexist(int moveCell, int reelId) {
        REEL_MAP* map = game()->reelMap();
        std::vector<COMBI_DATA> buffer;
        for (int i = 0; i < Reels.checkLineNum; i++) {
            buffer.emplace_back();
        }
        int leftrange = 0;
        int middlerange = 0;
        int rightrange = 0;

        switch (reelId) {
        case LEFT:
            leftrange = moveCell;
            break;
        case MIDDLE:
            middlerange = moveCell;
            break;
        case RIGHT:
            rightrange = moveCell;
            break;
        }

        //わからんのでベタ打ち
        buffer[0][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
        buffer[0][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange) % Reels.cellNum);
        buffer[0][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

        buffer[1][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
        buffer[1][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
        buffer[1][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);

        buffer[2][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 1) % Reels.cellNum);
        buffer[2][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
        buffer[2][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 1) % Reels.cellNum);

        buffer[3][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
        buffer[3][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
        buffer[3][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

        buffer[4][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
        buffer[4][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 2) % Reels.cellNum);
        buffer[4][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);


        for (int i = 0; i < Reels.checkLineNum; i++) {
            for (int j = 0; j < Combi.size(); j++) {
                if ((Combi[j].resultId != LOTTERY::Cherry_A1) ||
                    (Combi[j].resultId != LOTTERY::Cherry_A2) ||
                    (Combi[j].resultId != LOTTERY::Cherry_B)) {
                    if ((buffer[i][0] == Combi[j][0]) &&
                        (buffer[i][1] == Combi[j][1]) &&
                        (buffer[i][2] == Combi[j][2])) {
                        return true;
                    }
                }
                else {
                    if ((buffer[i][0] == Combi[j][0]) &&
                        (buffer[i][2] == Combi[j][2])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool REEL::checkbonusexist(int moveCell, int reelId) {
        REEL_MAP* map = game()->reelMap();
        std::vector<COMBI_DATA> buffer;
        for (int i = 0; i < Reels.checkLineNum; i++) {
            buffer.emplace_back();
        }
        int leftrange = 0;
        int middlerange = 0;
        int rightrange = 0;

        switch (reelId) {
        case LEFT:
            leftrange = moveCell;
            break;
        case MIDDLE:
            middlerange = moveCell;
            break;
        case RIGHT:
            rightrange = moveCell;
            break;
        }

        //わからんのでベタ打ち
        buffer[0][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
        buffer[0][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange) % Reels.cellNum);
        buffer[0][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

        buffer[1][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
        buffer[1][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
        buffer[1][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);

        buffer[2][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 1) % Reels.cellNum);
        buffer[2][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
        buffer[2][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 1) % Reels.cellNum);

        buffer[3][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
        buffer[3][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
        buffer[3][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

        buffer[4][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
        buffer[4][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 2) % Reels.cellNum);
        buffer[4][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);

        for (int i = 0; i < Reels.checkLineNum; i++) {
            for (int j = 0; j < BonusCombi.size(); j++) {
                if ((buffer[i][0] == BonusCombi[j][0]) &&
                    (buffer[i][1] == BonusCombi[j][1]) &&
                    (buffer[i][2] == BonusCombi[j][2])) {
                    return true;
                }
            }
        }
        return false;
    }
    int REEL::tellresultexistcell(int resultId, int reelId) {
        REEL_MAP* map = game()->reelMap();
        std::vector<COMBI_DATA> buffer;
        int checkStartLine = 0;
        int checkEndLine = Reels.checkLineNum;
        for (int i = 0; i < Reels.checkLineNum; i++) {
            buffer.emplace_back();
        }
        int leftrange = 0;
        int middlerange = 0;
        int rightrange = 0;
        int r = 0;
        int nullRange = 0;
        for (r = 0; r <= Reels.maxMoveRange; r++) {
            switch (reelId) {
            case LEFT:
                leftrange = r;
                break;
            case MIDDLE:
                middlerange = r;
                break;
            case RIGHT:
                rightrange = r;
                break;
            }
            //わからんのでベタ打ち
            buffer[0][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
            buffer[0][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange) % Reels.cellNum);
            buffer[0][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

            buffer[1][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
            buffer[1][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
            buffer[1][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);

            buffer[2][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 1) % Reels.cellNum);
            buffer[2][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
            buffer[2][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 1) % Reels.cellNum);

            buffer[3][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
            buffer[3][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
            buffer[3][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

            buffer[4][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
            buffer[4][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 2) % Reels.cellNum);
            buffer[4][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);
            //Buffer = buffer;
            if (resultId == LOTTERY::Replay) {
                //I = game()->reelMap()->tellStopPos(resultId, Reel[0].afterNum%Reels.cellNum);
                switch (game()->reelMap()->tellStopPos(resultId, Reel[0].afterNum%Reels.cellNum)) {
                case REEL_MAP::TOP:
                    checkStartLine = 3;
                    break;
                case REEL_MAP::BOT:
                    checkEndLine = 2;
                    break;
                }
            }
            for (int i = checkStartLine; i < checkEndLine; i++) {
                for (int j = 0; j < Combi.size(); j++) {
                    if ((resultId == LOTTERY::Cherry_A1) ||
                        (resultId == LOTTERY::Cherry_A2) ||
                        (resultId == LOTTERY::Cherry_B)) {

                        if (reelId != MIDDLE) {
                            if ((buffer[i][0] == Combi[j][0]) &&
                                (buffer[i][2] == Combi[j][2])) {
                                if (resultId == Combi[j].resultId) {

                                    return r;
                                }
                            }
                        }
                        else {
                            if (!((buffer[i][0] == Combi[j][0]) &&
                                (buffer[i][1] == Combi[j][1]) &&
                                (buffer[i][2] == Combi[j][2]))) {
                                return r;

                            }
                        }

                    }
                    else {
                        if ((buffer[i][0] == Combi[j][0]) &&
                            (buffer[i][1] == Combi[j][1]) &&
                            (buffer[i][2] == Combi[j][2])) {
                            if (resultId == Combi[j].resultId) {
                                return r;
                            }
                        }


                    }
                }
            }


        }
        for (int i = 0; i <= Reels.maxMoveRange; i++) {
            if (!game()->reel()->checkbonusexist(i, reelId)) {
                if (!game()->reel()->checkresultexist(i, reelId)) {
                    return i;
                }
            }
        }

    }
    int REEL::tellbonusexistcell(int bounasId, int reelId) {
        REEL_MAP* map = game()->reelMap();
        std::vector<COMBI_DATA> buffer;
        for (int i = 0; i < Reels.checkLineNum; i++) {
            buffer.emplace_back();
        }
        int leftrange = 0;
        int middlerange = 0;
        int rightrange = 0;
        int r = 0;
        for (r = 0; r <= Reels.maxMoveRange; r++) {
            switch (reelId) {
            case LEFT:
                leftrange = r;
                break;
            case MIDDLE:
                middlerange = r;
                break;
            case RIGHT:
                rightrange = r;
                break;
            }
            //わからんのでベタ打ち
            buffer[0][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
            buffer[0][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange) % Reels.cellNum);
            buffer[0][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

            buffer[1][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange) % Reels.cellNum);
            buffer[1][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
            buffer[1][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);

            buffer[2][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 1) % Reels.cellNum);
            buffer[2][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
            buffer[2][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 1) % Reels.cellNum);

            buffer[3][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
            buffer[3][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 1) % Reels.cellNum);
            buffer[3][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange) % Reels.cellNum);

            buffer[4][0] = map->textureNum(LEFT, (Reel[0].afterNum + leftrange + 2) % Reels.cellNum);
            buffer[4][1] = map->textureNum(MIDDLE, (Reel[1].afterNum + middlerange + 2) % Reels.cellNum);
            buffer[4][2] = map->textureNum(RIGHT, (Reel[2].afterNum + rightrange + 2) % Reels.cellNum);


            for (int i = 0; i < Reels.checkLineNum; i++) {
                for (int j = 0; j < BonusCombi.size(); j++) {
                    if ((buffer[i][0] == BonusCombi[j][0]) &&
                        (buffer[i][1] == BonusCombi[j][1]) &&
                        (buffer[i][2] == BonusCombi[j][2])) {
                        return r;
                    }

                }
            }
        }
            return -1;
    }

}