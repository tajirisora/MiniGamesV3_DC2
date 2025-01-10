#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME01
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    private:
    enum STATE { TITLE, INIT, PLAY, OVER };
    STATE State = TITLE;
    void title();
    void init();
    void hsbToRgb(float h, float s, float v, int& r, int& g, int& b);
    void drawStage();
    void setPtnPosition();
    void setPtnNoToStage();
    void delPtnNoFromStage();
    int collision();
    void complete();
    void play();
    void over();
    void gmain();
    void drawNextBlock();

    //色
    struct COLOR2 {
        float hue;
        float satu;
        float value;
        float alpha;
        COLOR2(float h, float s, float v, float a) {
            hue = h;
            satu = s;
            value = v;
            alpha = a;
        }
    };
    float Satu = 200;
    float Value = 255;
    float Alpha = 255;
    struct COLOR2 Color[9] = {
    COLOR2(0,Satu,Value,Alpha),
    COLOR2(30,Satu,Value,Alpha),
    COLOR2(60,Satu,Value,Alpha),
    COLOR2(120,Satu,Value,Alpha),
    COLOR2(180,Satu,Value,Alpha),
    COLOR2(220,Satu,Value,Alpha),
    COLOR2(300,Satu,Value,Alpha),
    COLOR2(200,44,88,Alpha),
    COLOR2(0,0,20,Alpha),
    };
    //壁と背景の色番号
    const int WALL = 7;
    const int BACK = 8;
    //ステージ（色番号を記憶する）
    static const int ROWS = 20;
    static const int COLS = 12;
    int Stage[ROWS][COLS];
    float Size = 50;
    //基準ブロック位置と回転数
    int X, Y, R;
    //ブロックパターンの位置
    int Px[4], Py[4];
    //ブロック移動制御
    int FallFlag = 0;
    int LoopCnt = 0;
    //ブロックパターン番号  ※ 兼色番号 ※
    int PtnNo;

    int offsetX = 650; // 横方向のオフセット
    int offsetY = 90; // 縦方向のオフセット

    int NextPtnNo = 0;

    int previewX = -4; // ステージ左側に配置
    int previewY = 4;  // 少し下に配置
    int size = Size;   // 表示サイズを通常のブロックと同じに

};




}
