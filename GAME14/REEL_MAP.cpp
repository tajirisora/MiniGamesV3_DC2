#include"GAME14.h"
#include"CONTAINER.h"
#include "REEL_MAP.h"
#include<fstream>
#include<sstream>
#include<vector>
namespace GAME14 {
    REEL_MAP::REEL_MAP(class GAME* game):
        GAME_OBJECT(game){}
    REEL_MAP::~REEL_MAP(){
        destroy();
    }
    void REEL_MAP::create(){
        Map = game()->container()->data().map;

    }
    void REEL_MAP::destroy() {
        if (Map.reelData) {
            delete[] Map.reelData;
        }
        for (int i = 0; i < LOTTERY::NUM_RESULT; i++) {
            if (Control_Data[i].normalBuffer) {
                delete[] Control_Data[i].normalBuffer;
            }
            if (Control_Data[i].R_BB_Buffer) {
                delete[] Control_Data[i].R_BB_Buffer;
            }
            if (Control_Data[i].B_BB_Buffer) {
                delete[] Control_Data[i].B_BB_Buffer;
            }
            if (Control_Data[i].REG_Buffer) {
                delete[] Control_Data[i].REG_Buffer;
            }
        }

        for (int i = 0; i < LOTTERY::NUM_RESULT * NUM_POS; i++) {
            if (Second_Control_Data[i].normalBuffer) {
                delete[] Second_Control_Data[i].normalBuffer;
            }
            if (Second_Control_Data[i].R_BB_Buffer) {
                delete[] Second_Control_Data[i].R_BB_Buffer;
            }
            if (Second_Control_Data[i].B_BB_Buffer) {
                delete[] Second_Control_Data[i].B_BB_Buffer;
            }
            if (Second_Control_Data[i].REG_Buffer) {
                delete[] Second_Control_Data[i].REG_Buffer;
            }
        }

    }

    void REEL_MAP::ControlDatacreate() {
        for (int i = 0; i < LOTTERY::NUM_RESULT; i++) {
            Control_Data[i].normalBuffer = new int[Map.rows];
            Control_Data[i].R_BB_Buffer = new int[Map.rows];
            Control_Data[i].B_BB_Buffer = new int[Map.rows];
            Control_Data[i].REG_Buffer = new int[Map.rows];
        }
        for (int i = 0; i < LOTTERY::NUM_RESULT*NUM_POS; i++) {
            Second_Control_Data[i].normalBuffer = new int[Map.rows];
            Second_Control_Data[i].R_BB_Buffer = new int[Map.rows];
            Second_Control_Data[i].B_BB_Buffer = new int[Map.rows];
            Second_Control_Data[i].REG_Buffer = new int[Map.rows];

        }
    }

    void REEL_MAP::init(){
        Map = game()->container()->data().map;

        ControlDatacreate();
        initmap();
        initreelMap();
        initfirstreelControl();
        initsecondreelControl();
        initStopPos_NO_Bonus();
        initStopPos_Bonus();
   }
   void REEL_MAP::initmap() {
        if (StopId.size()) {
            StopId.clear();
        }
        StopId["top"] = TOP;
        StopId["middle"] = MID;
        StopId["bottom"] = BOT;
        StopId["NO"] = NO_POS;
    }
   void REEL_MAP::initreelMap() {
       std::stringstream buffer;//stringに変換するためのバッファ
       std::string str;
       std::string resultStr;
       std::ifstream file;
       Map.reelData = new int[Map.rows * Map.cols + 2];
       file.open(Map.reelMapFile, std::ios::binary);
       if (!file) {
           file.close();
           WARNING(1, "リールマップが開けませんでした", Map.reelMapFile);
       }
       buffer << file.rdbuf();
       file.close();
       str = buffer.str();
       buffer.str("");
       int cntCol = 0;
       for (int i = 0; i < str.size(); i++) {
           cntCol++;
           if (str[i] == '\n') {
               if (cntCol != Map.cols) {
                   WARNING(1, "列数が３じゃない", "");
               }
               cntCol = 0;
           }
       }
       if (str.size() % Map.cols != 0) {
           WARNING(1, "最後が改行されていない", "");
       }
       int i = 0;
       while (1) {
           if (i >= str.size()) {
               break;
           }
           if (str[i] != '\n') {
               Map.reelData[i] = str[i] - '0';
           }
           i++;

       }



   }
   void REEL_MAP::initfirstreelControl() {
       std::ifstream file;
       std::vector<int> resultId;
       std::string str;
       std::string cutStr;
       std::string::size_type cutPos;
       std::string::size_type startPos;
       int cellNumber = 0;
       int stateId = 0;
       int reelId = 0;
       for (int n = 0; n < NUM_FILE; n++) {
           //どの状態のリール制御かを決める
           stateId = n % NUM_FILE;
           //要素数の初期化
           resultId.resize(0);
           file.open(Map.controlFile[n], std::ios::binary);
           if (!file) {
               WARNING(1, "controlファイルが開けませんでした", Map.controlFile[n]);
           }
           //入れ始めるコマ番号の初期化
           cellNumber = Map.cellnum - 1;
           while (1) {
               //一行取得
               std::getline(file, str);
               //それがファイルの最後か？
               if (file.eof()) {
                   break;
               }
               //文字の切り取り字数の初期化
               startPos = 0;
               cutPos = 0;
               //数字以外から文字列が始まっているか？
               if (strcspn(str.c_str(), "1234567890 ")) {
                   while (startPos <= str.length() - 1) {
                       //切り取り場所取得
                       cutPos = str.find(Map.separator, startPos);
                       //セパレータが見つからなかったらその後の全文字読み込む
                       if (cutPos == std::string::npos) {
                           cutPos = str.length() - 1;
                       }
                       //文字切り取り
                       cutStr = str.substr(startPos, cutPos - startPos);
                       //切り取り初めの位置をセパレータの次の文字へ
                       startPos = cutPos + Map.separator.length();
                       //切り取った文字のリザルトIDを取得
                       resultId.emplace_back(game()->lottery()->resultId(cutStr));
                   }

               }
               else {
                   //一番最初にリザルトIDを取得しているか？
                   if (resultId.size()) {
                       //取得したリザルトの数分のリール制御テーブルを読み込む
                       for (int j = 0; j < resultId.size(); j++) {
                           //取得したリザルトよりテーブル数が多いか？
                           if (startPos >= str.length()) {
                               WARNING(1, "役の数とテーブル数が合いません", Map.controlFile[n]);
                           }
                           //切り取り場所の取得
                           cutPos = str.find(Map.separator, startPos);
                           //セパレータが見つからなかったらその後の全文字読み込む
                           if (cutPos == std::string::npos) {

                               cutPos = str.length() - 1;
                           }
                           //文字切り取り
                           cutStr = str.substr(startPos, cutPos - startPos);
                           //切り取り初めの位置をセパレータの次の文字へ
                           startPos = cutPos + Map.separator.length();
                           //滑りコマ数の取得
                           Control_Data[resultId[j]][stateId][cellNumber] = std::stoi(cutStr);
                       }
                       cellNumber--;

                   }
                   else {
                       WARNING(1, "役の記述が最初にありません", Map.controlFile[n]);

                   }
               }
           }
           file.close();
       }

   }
   void REEL_MAP::initsecondreelControl() {
       std::ifstream file;
       std::vector<int> resultId;
       std::string str;
       std::string cutStr;
       std::string::size_type cutPos;
       std::string::size_type startPos;
       int cellNumber = 0;
       int curPosId = 0;
       int stateId = 0;
       int reelId = 0;
       int numResult = LOTTERY::NUM_RESULT;

       for (int n = 0; n < NUM_SECOND_FILE; n++) {
           //どの状態のリール制御かを決める
           stateId = n % ONE_FILES;
           //左リールがどの位置のリール制御か
           curPosId = n / ONE_FILES;
           //入れ始めるコマ番号の初期化
           cellNumber = Map.cellnum - 1;
           //要素数の初期化
           resultId.resize(0);
           file.open(Map.secondControlFile[n], std::ios::binary);
           if (!file) {
               WARNING(1, "controlファイルが開けませんでした", Map.secondControlFile[n]);
           }
           while (1) {
               //一行取得
               std::getline(file, str);
               //それがファイルの最後か？
               if (file.eof()) {
                   break;
               }
               //文字の切り取り字数の初期化
               startPos = 0;
               cutPos = 0;
               //数字以外から文字列が始まっているか？
               if (strcspn(str.c_str(), "1234567890 ")) {
                   while (startPos <= str.length() - 1) {
                       //切り取り場所取得
                       cutPos = str.find(Map.separator, startPos);
                       //セパレータが見つからなかったらその後の全文字読み込む
                       if (cutPos == std::string::npos) {
                           cutPos = str.length() - 1;
                       }
                       //文字切り取り
                       cutStr = str.substr(startPos, cutPos - startPos);
                       //切り取り初めの位置をセパレータの次の文字へ
                       startPos = cutPos + Map.separator.length();
                       //切り取った文字のリザルトIDを取得
                       resultId.emplace_back(game()->lottery()->resultId(cutStr));
                   }

               }
               else {
                   //一番最初にリザルトIDを取得しているか？
                   if (resultId.size()) {
                       //取得したリザルトの数分のリール制御テーブルを読み込む
                       for (int j = 0; j < resultId.size(); j++) {
                           //取得したリザルトよりテーブル数が多いか？
                           if (startPos >= str.length()) {
                               WARNING(1, "役の数とテーブル数が合いません", Map.secondControlFile[n]);
                           }
                           //切り取り場所の取得
                           cutPos = str.find(Map.separator, startPos);
                           //セパレータが見つからなかったらその後の全文字読み込む
                           if (cutPos == std::string::npos) {

                               cutPos = str.length() - 1;
                           }
                           //文字切り取り
                           cutStr = str.substr(startPos, cutPos - startPos);
                           //切り取り初めの位置をセパレータの次の文字へ
                           startPos = cutPos + Map.separator.length();
                           //滑りコマ数の取得
                           Second_Control_Data[resultId[j] + (numResult * curPosId)][stateId][cellNumber] = std::stoi(cutStr);
                       }
                       cellNumber--;

                   }
                   else {
                       WARNING(1, "役の記述が最初にありません", Map.secondControlFile[n]);

                   }
               }
           }
           file.close();
       }

   }
   void REEL_MAP::initStopPos_NO_Bonus() {
       std::ifstream file;
       std::string str;
       std::string cutStr;
       std::string::size_type startPos = 0;
       std::string::size_type cutPos = 0;
       int resultId = -1;
       STOP_ID stopId = NUM_POS;
       int cellNum = 0;
       int i = 0;
       bool resultFlag = false;

       file.open(Map.distinction_NO_BonusFile, std::ios::binary);
       if (!file) {
           file.close();
           WARNING(1, "リールマップが開けませんでした", Map.distinction_NO_BonusFile);

       }
       while (1) {
           
           std::getline(file, str);
           //それがファイルの最後か？
           if (file.eof()) {
               break;
           }
           resultFlag = false;
           startPos = 0;
           cutPos = 0;
           while (1) {
               cutPos = str.find(Map.separator, startPos);

               if (cutPos == std::string::npos) {
                   cutPos = str.length() - 1;
                   resultFlag = true;
               }

               cutStr = str.substr(startPos, cutPos - startPos);
               startPos = cutPos + Map.separator.length();
               //数字から始まってるか
               if (strspn(cutStr.c_str(), "0123456789 ")) {
                   resultFlag = false;
                   if (resultId < 0) {
                       file.close();
                       WARNING(1, "役が指定されてません", Map.distinction_NO_BonusFile);
                   }
                   if (stopId<TOP) {
                       file.close();
                       WARNING(1, "コマ番号の横に位置がありません", Map.distinction_NO_BonusFile);
                   }

                   cellNum = std::stoi(cutStr) - 1;
                   if (cellNum > -1&&cellNum<Map.rows+1) {
                       StopPos_NO_Bonus[resultId].stop[cellNum] = stopId;
                   }

               }
               else {
                   if (resultFlag) {
                       std::string::size_type resizePos = cutStr.find(" ");
                       if (resizePos != std::string::npos) {
                           cutStr = cutStr.substr(0, resizePos);
                       }

                       resultId = game()->lottery()->resultId(cutStr);
                       if (resultId == LOTTERY::BB_Bell_A) {
                           int kaak =0;
                       }
                       break;
                   }
                   else {
                       std::string::size_type resizePos = cutStr.find(" ");
                       if (resizePos != std::string::npos) {
                           cutStr = cutStr.substr(0, resizePos);
                       }
                       stopId = StopId[cutStr];

                   }
               }
               
               if (startPos >= str.length()) {
                   break;
               }
           }
       }
       file.close();
   }
   void REEL_MAP::initStopPos_Bonus(){
       std::ifstream file;
       std::string str;
       std::string cutStr;
       std::string::size_type startPos = 0;
       std::string::size_type cutPos = 0;
       int bonusId = -1;
       STOP_ID stopId = NUM_POS;
       int cellNum = 0;
       int i = 0;

       file.open(Map.distinction_BonusFile, std::ios::binary);
       if (!file) {
           file.close();
           WARNING(1, "リールマップが開けませんでした", Map.distinction_BonusFile);

       }

       while (1) {

           std::getline(file, str);
           //それがファイルの最後か？
           if (file.eof()) {
               break;
           }

           //数値が入っていたら
           if (strcspn(str.c_str(), "0123456789") < str.length() - 1) {
               if (bonusId < 0) {
                   file.close();
                   WARNING(1, "役が指定されてません", Map.distinction_BonusFile);
               }
               while (1) {
                   cutPos = str.find(Map.separator, startPos);

                   if (cutPos == std::string::npos) {
                       cutPos = str.length() - 1;
                   }

                   cutStr = str.substr(startPos, cutPos - startPos);
                   startPos = cutPos + Map.separator.length();

                   if (strspn(cutStr.c_str(), "0123456789 ") < cutStr.length()) {
                       std::string::size_type resizePos = cutStr.find(" ");
                       if (resizePos != std::string::npos) {
                           cutStr = cutStr.substr(0, resizePos);
                       }
                       stopId = StopId[cutStr];
                   }
                   else {
                       cellNum = std::stoi(cutStr) - 1;
                       if (cellNum > -1) {
                           StopPos_Bonus[bonusId].stop[cellNum] = stopId;
                       }

                   }

                   if (startPos >= str.length()) {
                       stopId = NUM_POS;
                       cellNum = 0;
                       startPos = 0;
                       cutPos = 0;
                       break;
                   }
               }

           }
           else {
               str = str.substr(0, str.length() - 1);
               bonusId = game()->lottery()->bonusId(str);
           }
       }
       file.close();

   }


    int REEL_MAP::tellTableStopCell(int cellId, int reelId) {
        int resultId = game()->lottery()->result();
        if (resultId < 0) {
            return 0;
        }
        int bonusId = game()->lottery()->bonusResult();
        int state = game()->lottery()->state();
        return Control_Data[resultId][bonusId][cellId];
   }
    int REEL_MAP::tellSecondTableStopCell(int cellId, int reelId, int leftCellId) {
        int resultId = game()->lottery()->result();
        if (resultId < 0) {
            return 0;
        }
        int bonusId = game()->lottery()->bonusResult();
        
        int leftCellPos = StopPos_NO_Bonus[resultId][leftCellId];
        if (resultId == LOTTERY::Hazure && bonusId > LOTTERY::NO_BONUS) {
            leftCellPos = StopPos_Bonus[bonusId][leftCellId];
        }
        if (leftCellPos) {
            leftCellPos -= 1;
            return Second_Control_Data[resultId + (LOTTERY::NUM_RESULT * leftCellPos)][bonusId][cellId];

        }
        return 0;
    }

   int REEL_MAP::tellStopCell(int cellId,int reelId) {
       int maxMoveRange = game()->reel()->maxMoveRange();
       int resultId = game()->lottery()->result();
       if (resultId < 0) {
           return 0;
       }
       int bonusId = game()->lottery()->bonusResult();
       if (resultId == LOTTERY::Hazure) {
           if (bonusId > 0) {
               int range = game()->reel()->tellbonusexistcell(bonusId, reelId);
               if (range>-1) {
                   return range;
               }
               else {
                   for (int i = 0; i <= maxMoveRange; i++) {
                       if (game()->reel()->checkbonusexist(i, reelId)) {

                           if (!game()->reel()->checkresultexist(i, reelId)) {
                               return i;
                           }
                       }
                   }

               }
           }
           else {
               for (int i = 0; i <= maxMoveRange; i++) {
                   if (!game()->reel()->checkbonusexist(i, reelId)) {
                       if (!game()->reel()->checkresultexist(i, reelId)) {
                           return i;
                       }
                   }
               }
           }
       }
       else {
           int range = game()->reel()->tellresultexistcell(resultId, reelId);
           if (resultId == LOTTERY::Cherry_A1 ||
               resultId == LOTTERY::Cherry_A2 ||
               resultId == LOTTERY::Cherry_B) {
               for (range = 0; range <= maxMoveRange; range++) {
                   if (!game()->reel()->checkbonusexist(range, reelId)) {
                       if (!game()->reel()->checkresultexist(range, reelId)) {
                           return range;
                       }
                   }

               }
           }
       }
   }

   void REEL_MAP::debagDraw() {
        /*
        print(rowLength);
        print(Str.length());
        textSize(10);
        
       
        */
       /*
       for (int j = 0; j < LOTTERY::NUM_RESULT; j++) {

           for (int i = 0; i < Map.rows; i++) {
               if (Control_Data[j][LOTTERY::REGULAR][i] >= 0) {
                   text(Control_Data[j][LOTTERY::REGULAR][i], 50 * j + 500, 40 * i + 60);
               }
           }
       }
       */
       /*
       int ID = LOTTERY::RED_BB;
        for (int j = 0; j < LOTTERY::NUM_RESULT; j++) {

            for (int i = 0; i < Map.rows; i++) {
       fill(0);
                if (Second_Control_Data[j][ID][i] >= 0) {
                    fill(80,80,80);
                }
                   text(Second_Control_Data[j+(LOTTERY::NUM_RESULT*(TOP-1))][ID][i], 50 * j + 500, 40 * i + 60);
            }
        }
        */
        //print("大きさ");
        //print(Control_Data[0].normalBuffer[0]);
       
       /*
        print("左の止まった場所");
        print(CellPos);
        
        print(Second_Control_Data[LOTTERY::BB_BELL_A + (LOTTERY::NUM_RESULT * StopPos_NO_Bonus[LOTTERY::BB_BELL_A][7])][LOTTERY::RED_BB][7]);
        */
        //print(StopPos_Bonus[LOTTERY::RED_BB][7]);
        //text(StopPos_Bonus[LOTTERY::RED_BB][0], 1500, 100);
        //text(StopPos_NO_Bonus[LOTTERY::Cherry_A1][13], 1500, 100);

        /*
        print("滑りコマ数");
        print(StopCell);
       */
       //textSize(50);
       
   }
   int REEL_MAP::textureNum(int reelId, int cellNum) {
        return Map.reelData[((Map.rows-1)-cellNum)*Map.cols+reelId] ;

   }

}