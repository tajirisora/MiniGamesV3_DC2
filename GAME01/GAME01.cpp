#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME01.h"
namespace GAME01
{
	int GAME::create()
	{
		return 0;
	}

	void GAME::destroy()
	{

	}

    void GAME::proc()
    {
        if (State == TITLE)title();
        else if (State == INIT)init();
        else if (State == PLAY)play();
        else if (State == OVER)over();
    }
    int bonus = 0;
    int Score = 0;
    int Offsets[7][3][2] = {
        //■□■■...0
        -1,0,   1,0,  2,0,
        //■
        //■□■....1
        -1,-1, -1,0,  1,0,
        //  　■
        //■□■....2
        -1,0,   1,-1, 1,0,
        //■□
        //　■■....3
        -1,0,   0,1,  1,1,
        //　□■
        //■■  ....4
         1,0,   0,1, -1,1,
         //　■
         //■□■....5
         -1,0,   0,-1, 1,0,
         //□■
         //■■......6
          1,0,   0,1,  1,1,
    };

    // HSBからRGBへの変換関数
    void GAME::hsbToRgb(float h, float s, float v, int& r, int& g, int& b) {
        if (s == 0) {
            r = g = b = static_cast<int>(v * 255);
        }
        else {
            float f = (h - static_cast<int>(h)) * 6.0f;
            float p = v * (1.0f - s);
            float q = v * (1.0f - s * f);
            float t = v * (1.0f - (s * (1.0f - f)));
            switch (static_cast<int>(h)) {
            case 0:
                r = static_cast<int>(v * 255);
                g = static_cast<int>(t * 255);
                b = static_cast<int>(p * 255);
                break;
            case 1:
                r = static_cast<int>(q * 255);
                g = static_cast<int>(v * 255);
                b = static_cast<int>(p * 255);
                break;
            case 2:
                r = static_cast<int>(p * 255);
                g = static_cast<int>(v * 255);
                b = static_cast<int>(t * 255);
                break;
            case 3:
                r = static_cast<int>(p * 255);
                g = static_cast<int>(q * 255);
                b = static_cast<int>(v * 255);
                break;
            case 4:
                r = static_cast<int>(t * 255);
                g = static_cast<int>(p * 255);
                b = static_cast<int>(v * 255);
                break;
            default:
                r = static_cast<int>(v * 255);
                g = static_cast<int>(p * 255);
                b = static_cast<int>(q * 255);
                break;
            }
        }
    }

    void GAME::title()
    {
        clear(255, 255, 255);
        //テキスト情報
        fill(0, 255, 0);
        textSize(200);
       // text("Tetris", 600, 450);
        fill(0, 0, 0);
        textSize(40);
        text("クリックで操作説明画面へ", 750, 500);
        text("Enterでメニューに戻る", 0, 1080);
        //シーン切り替え
        setPtnPosition();
        if (isTrigger(MOUSE_LBUTTON)) {
            State = INIT;
            return;
        }
       
        
        //メニューに戻る
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::init() {
        //壁と背景の色番号をStage2次元配列にセット
        
        clear(255, 60, 60);
        fill(0, 0, 0);
        textSize(60);
        text("右へ１マス:D", 750, 500);
        text("左へ１マス:A", 750, 550);
        text("回転:W", 750, 600);
        text("落下:S", 750, 650);
        text("クリックでゲームスタート", 750, 700);

        for (int y = 0; y < ROWS; y++) {
            Stage[y][0] = Stage[y][COLS - 1] = WALL;
            for (int x = 1; x < COLS - 1; x++) {
                Stage[y][x] = BACK;
                if (y == ROWS - 1) {
                    Stage[y][x] = WALL;
                }
            }
        }
        
        //ブロック初期値
        X = 5;
        Y = 1;
        R = 0;
        PtnNo = random() % 7;
        NextPtnNo = random() % 7;
        setPtnPosition();
        if (isTrigger(MOUSE_LBUTTON)) {
            State = PLAY;
            return;
        }
        
    }

    void GAME::drawStage() {
        void complete();
        angleMode(DEGREES);
        colorMode(HSV);
        strokeWeight(20);
        rectMode(CENTER);
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                int no = Stage[y][x];
              
               stroke(Color[no].hue, Color[no].satu, Color[no].value);
     

                fill(0, 0, 100);
               
               
                rect(offsetX + Size / 2 + Size * x, 
                    offsetY + Size / 2 + Size * y,
                    Size / 2, Size / 2);
               
            }

       
        }
        drawNextBlock();

        fill(255);
        textSize(40);
       text((let)"Score:" + Score, 800, 100);
        text("Score:",0,0);
        text((let)Score,100,0);
       
        
        
    }
    void GAME::setPtnPosition() {
        //基準ブロック位置
        Px[0] = X;
        Py[0] = Y;
        //回転数
        int r = R % 4;

        for (int i = 0; i < 3; i++) {
            //現在のブロックパターンのオフセット値を取得
            int ofsX = Offsets[PtnNo][i][0];
            int ofsY = Offsets[PtnNo][i][1];
            
            for (int j = 0; j < r; j++) {
                int w = ofsX;
                ofsX = -ofsY;
                ofsY = w;
            }
            
            Px[i + 1] = X + ofsX;
            Py[i + 1] = Y + ofsY;
        }
    }
    void GAME::setPtnNoToStage() {
        setPtnPosition();
        for (int i = 0; i < 4; i++) {
            int x = Px[i];
            int y = Py[i];
            Stage[y][x] = PtnNo;
        }
    }
    void GAME::delPtnNoFromStage() {
        for (int i = 0; i < 4; i++) {
            int x = Px[i];
            int y = Py[i];
            Stage[y][x] = BACK;
        }
    }
    int GAME::collision() {
        setPtnPosition();
        int flag = 0;
        for (int i = 0; i < 4; i++) {
            int x = Px[i];
            int y = Py[i];
            if (Stage[y][x] != BACK) {
                flag = 1;
            }
        }
        return flag;
    }

    void GAME::complete() {
        for (int y = 1; y < ROWS - 1; y++) {
            int flag = 1;
            for (int x = 1; x < COLS - 1; x++) {
                if (Stage[y][x] == BACK) {
                    flag = 0;
                }
            }
            if (flag) {
                if (bonus == 0) {
                    Score += 1000;
                }
                else if (bonus == 1) {
                    Score += 10000;
                    bonus = 0;
                }
                //そろったのでスライド
                for (int upy = y - 1; upy >= 0; upy--) {
                    for (int x = 1; x < COLS - 1; x++) {
                        Stage[upy + 1][x] = Stage[upy][x];
                    }
                }
            }
        }
    }
    
    void GAME::drawNextBlock() {
        // 次のブロックを表示する基準位置
        
        rectMode(CENTER);
        for (int i = 0; i < 4; i++) { // 基準ブロック + 3つのオフセット
            int ofsX = (i == 0) ? 0 : Offsets[NextPtnNo][i - 1][0];
            int ofsY = (i == 0) ? 0 : Offsets[NextPtnNo][i - 1][1];

            int px = previewX + ofsX;
            int py = previewY + ofsY;

            // 次のブロックの色を取得
            fill(Color[NextPtnNo].hue, Color[NextPtnNo].satu, Color[NextPtnNo].value);
            stroke(0, 0, 0); // 黒い枠線
            rect(offsetX + size * px, offsetY + size * py, size, size);
        }

        // "Next Block" のテキストを表示
        fill(255); // 白い文字
        textSize(40);
        text("Next Block", offsetX + size * (previewX - 1), offsetY + size * (previewY - 3));
    }


    void GAME::play() {
        //現在のパターン番号（色番号）をステージから消す
        delPtnNoFromStage();
        //移動、回転
        int dy = 0, dx = 0, dr = 0;;
        if ((++LoopCnt %= 30) == 0)dy = 1;
        if (isTrigger(KEY_D))dx = 1;
        if (isTrigger(KEY_A))dx = -1;
        if (isTrigger(KEY_W))dr = 1;
        if (isTrigger(KEY_S))FallFlag = 1;
        if (FallFlag)dy = 1;
        Y += dy;
        X += dx;
        R += dr;
        if (collision()) {
            //元の位置、回転に戻す
            Y -= dy;
            X -= dx;
            R -= dr;
            FallFlag = 0;
            if (dy == 1 && dx == 0 && dr == 0) {
                //積もらせる
                setPtnNoToStage();
                //行がそろっていたらスライドさせる
                complete();
                //新しいブロック誕生
                X = 5;
                Y = 1;
                R = 0;
                PtnNo = NextPtnNo;
                NextPtnNo = random() % 7;
                //PtnNo = random() % 7;
                if (collision()) {
                    State = OVER;
                }
            }
        }
        //パターン番号（色番号）をステージにセット
        setPtnNoToStage();

        //描画
        clear(0);
        drawStage();
       
    }

        //ゲームオーバー           
    void GAME::over() {
        clear(255, 0, 0);
        fill(0, 0, 255);
        textSize(80);
        text("   ", 650, 450);
        text("SPACEキーでタイトルに戻る", 500, 550);
        if (isTrigger(KEY_SPACE)) {
            State = TITLE;
        }
    }

    void GAME::gmain() {
        window(Size * COLS * 2, Size * ROWS, full);
    }

   
}
