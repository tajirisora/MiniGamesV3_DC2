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
        delete[] Map.reelData;
        for (int j = 0; j < LOTTERY::NUM_NORMAL_RESULT; j++) {
            delete[] Control_Data[j].normalBuffer ;
            delete[] Control_Data[j].R_BB_Buffer ;
            delete[] Control_Data[j].B_BB_Buffer ;
            delete[] Control_Data[j].REG_Buffer ;
        }

    }
    void REEL_MAP::create(){
        Map = game()->container()->data().map;
    }
    void REEL_MAP::init(){
        std::stringstream buffer;//stringに変換するためのバッファ
        std::string str;
        std::string resultStr;
        std::ifstream file;
        Map.reelData = new int[Map.rows * Map.cols+2];
        for (int j = 0; j < LOTTERY::NUM_NORMAL_RESULT; j++) {
            Control_Data[j].normalBuffer = new int[Map.rows];
            Control_Data[j].R_BB_Buffer = new int[Map.rows];
            Control_Data[j].B_BB_Buffer = new int[Map.rows];
            Control_Data[j].REG_Buffer = new int[Map.rows];
        }
        file.open(Map.reelMapFile, std::ios::binary);
        if (!file) {
            WARNING(1, "リールマップが開けませんでした", Map.reelMapFile);
        }
        buffer<<file.rdbuf();
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


        std::vector<int> resultId;
        std::string cutStr;
        std::string::size_type cutPos;
        std::string::size_type startPos ;
        int cellNumber = 0;

        file.open(Map.leftControlFile, std::ios::binary);
        if (!file) {
            WARNING(1, "controlファイルが開けませんでした", Map.leftControlFile);
        }

        while (1) {

            std::getline(file, str);
            if (file.eof()) { 
                break; 
            }

            startPos = 0;
            cutPos = 0;

            if (strcspn(str.c_str(), "1234567890 ")) {
                while (startPos <= str.length()-1) {
                    cutPos = str.find(Map.separator,startPos);
                    if (cutPos == std::string::npos) {
                        cutPos = str.length() - 1;
                    }
                    cutStr = str.substr(startPos, cutPos - startPos);
                    startPos = cutPos + Map.separator.length();
                    resultId.emplace_back(game()->lottery()->resultId(cutStr));
                }

            }
            else {
                if (resultId.size()) {
                    for (int i = 0; i < resultId.size(); i++) {
                        if (startPos >= str.length()) {
                            WARNING(1, "役の数とテーブル数が合いません", Map.leftControlFile);
                        }
                        cutPos = str.find(Map.separator,startPos);
                        if (cutPos == std::string::npos) {
                            
                            cutPos = str.length() - 1;
                        }
                        cutStr = str.substr(startPos, cutPos - startPos);
                        startPos = cutPos + Map.separator.length();
                        Control_Data[resultId[i]][LOTTERY::NO_BONUS][cellNumber] = std::stoi(cutStr);
                    }
                    cellNumber++;
                    //
                }
                else {
                    WARNING(1, "役の記述が最初にありません", Map.leftControlFile);

                }
            }
        }
        file.close();
   }
   int REEL_MAP::tellStopCell(int cellId,int reelId) {
       int resultId = game()->lottery()->result();
       int bonusId = game()->lottery()->bonusResult();
       return StopCell = Control_Data[resultId][bonusId][cellId];
   }

    void REEL_MAP::debagDraw() {
        /*
        print(rowLength);
        print(Str.length());
        textSize(40);
        */
       /*
        for (int j = 0; j < LOTTERY::NUM_NORMAL_RESULT; j++) {

            for (int i = 0; i < Map.rows; i++) {
                text(Control_Data[j][LOTTERY::NO_BONUS][i], 50 * j + 100, 40 * i + 60);
            }
        }
        */
        print("滑りコマ数");
        print(StopCell);

    }
    int REEL_MAP::textureNum(int reelId, int cellNum) {
        //return Map.data[Map.cols * cellNum + reelId]-'0';
        return Map.reelData[((Map.rows-1)-cellNum)*Map.cols+reelId] ;

    }

}