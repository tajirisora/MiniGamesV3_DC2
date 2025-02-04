#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME01.h"
#include <cstdio>


namespace GAME01
{

	int GAME::create()
	{
        bgmSnd = loadSound("..\\main\\assets\\game01\\BGM.wav");
        aaaSnd = loadSound("..\\main\\assets\\game01\\aaa.wav");
        haikeiImg = loadImage("..\\main\\assets\\game01\\haikei1.jpg");
        haikei2Img = loadImage("..\\main\\assets\\game01\\haikei2.jpg");
        overImg = loadImage("..\\main\\assets\\game01\\over.png");


        loadHighScore();

        for (int i = 0; i < RANKING_SIZE; i++) {
            rankings[i] = 0;
        }
		return 0;
	}

	void GAME::destroy()
	{
        saveHighScore();
        //freeSound();
        
        
        
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

        angleMode(DEGREES);
        colorMode(RGB); // タイトル画面用にRGBモードに設定
        clear(240, 240, 255); // 薄い青

        clear(0, 0, 0);
        rectMode(CENTER);
        image(haikeiImg, width / 2, height / 2);

       

        // タイトル文字
        fill(0, 102, 204); // 濃い青
        textSize(200);
        text("Tetris ", 600, 450);

        // ハイスコア表示
        fill(255, 255, 255); 
        textSize(50);
        char highScoreStr[20];
        intToStr(highScore, highScoreStr);
        text("High Score: ", 300, 600);
        text(highScoreStr, 750, 600);

        // 操作説明文字
        fill(255, 255, 255); 
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
        
        clear(0, 0, 0); 
        rectMode(CENTER);
        image(haikei2Img, width / 2, height / 2);

        // 説明文字
        fill(255, 255, 255);
        textSize(60);
        text("右へ１マス:D", 750, 500);
        text("左へ１マス:A", 750, 550);
        text("回転:W", 750, 600);
        text("落下:S", 750, 650);
        text("levelは8まであり、一定スコア到達でlevelと速度アップ", 250, 760);
        text("クリックでゲームスタート", 750, 900);


        for (int y = 0; y < ROWS; y++) {
            Stage[y][0] = Stage[y][COLS - 1] = WALL;
            for (int x = 1; x < COLS - 1; x++) {
                Stage[y][x] = BACK;
                if (y == ROWS - 1) {
                    Stage[y][x] = WALL;
                }
            }
        }
        Score = 0;
        Level = 1;
        dropSpeed = INITIAL_DROP_SPEED;
       

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



    void GAME::intToStr(int num, char* buffer) {
        char temp[12]; // 一時バッファ（最大11桁の整数 + 終端文字）
        int index = 0;

        if (num == 0) {
            buffer[index++] = '0';
            buffer[index] = '\0';
            return;
        }

        // 負の数の場合
        if (num < 0) {
            buffer[index++] = '-';
            num = -num;
        }

        // 数字を逆順で格納
        while (num > 0) {
            temp[index++] = '0' + (num % 10);
            num /= 10;
        }

        // バッファに逆順でコピー
        int start = (buffer[0] == '-') ? 1 : 0; // 負の数の場合を考慮
        for (int i = 0; i < index; i++) {
            buffer[start + i] = temp[index - i - 1];
        }
        buffer[start + index] = '\0'; // 終端文字
    }


    // ハイスコアを読み込む関数
    void GAME::loadHighScore() {
        
        FILE* file = nullptr;
        // 保存先のパスを変更
        errno_t err = fopen_s(&file, "..\\main\\assets\\game01\\highscore.txt", "r");

        if (err == 0 && file) {
            // fscanf_s を使用
            fscanf_s(file, "%d", &highScore);
            fclose(file);
        }
        else {
            // ファイルが開けなかった場合の処理
            highScore = 0; // デフォルト値
        }
    }

    // ハイスコアを保存する関数
    void GAME::saveHighScore() {
        FILE* file = nullptr;
        // 保存先のパスを変更
        // fopen_s(&file, "C:\\path\\to\\your\\highscore.txt", "w");

        fopen_s(&file, "..\\main\\assets\\game01\\highscore.txt", "w");
        if (file) {
            fprintf(file, "%d", highScore); // ハイスコアを保存する
            fclose(file);
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
       text((let)"Level:" + Level, 800, 150);
       fill(255);
       textSize(40);
        text("Score:",0,0);
        text((let)Score,100,0);
    }

    void GAME::setPtnPosition() {
        //基準ブロック位置
        Px[0] = X;
        Py[0] = Y;
        
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
                        playSound(aaaSnd);

                    }
                }
            }
        }
    }
    
    
    void GAME::drawNextBlock() {
        // 次のブロックを表示する基準位置

        rectMode(CENTER);
        for (int i = 0; i < 4; i++){
    
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
        if (!isBgmPlaying) {
            playSound(bgmSnd);  
            isBgmPlaying = true; // BGMが再生中であることを記録
        }

        delPtnNoFromStage();
        adjustFallSpeed();
       
        //移動、回転
        int dy = 0, dx = 0, dr = 0;;
        if ((++LoopCnt % FallSpeed) == 0)dy = 1;
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
                    stopSound(bgmSnd);  // ゲームオーバー時にBGMを止める
                    isBgmPlaying = false; // フラグをリセット
                    

                }
            }
        }
        //パターン番号（色番号）をステージにセット
        setPtnNoToStage();

        //描画
        clear(0);
        drawStage();
       

        if (showLevelUpMessage) {
            fill(255, 0, 0);
            textSize(50);
            text("Speed Up!", 650, 400);
            if (++messageTimer > 60) { // 1秒間表示
                showLevelUpMessage = false;
                messageTimer = 0;
            }
        }
       
    }

    void GAME::adjustFallSpeed() {
        // スコアに応じて落下速度とレベルを調整
        int newLevel = Level;

        if (Score >= 3000) newLevel = 2, FallSpeed = 25;
        if (Score >= 5000) newLevel = 3, FallSpeed = 20;
        if (Score >= 10000) newLevel = 4, FallSpeed = 15;
        if (Score >= 20000) newLevel = 5, FallSpeed = 10;
        if (Score >= 30000)newLevel = 6, FallSpeed = 8;
        if (Score >= 40000)newLevel = 7, FallSpeed = 5;
        if (Score >= 50000)newLevel = 8, FallSpeed = 2;

        if (newLevel > Level) {
            Level = newLevel;
            showLevelUpMessage = true; // レベルアップ通知フラグをオン
        }
    }

    void intToStr(int num, char* buffer) {
        char temp[12]; // 一時バッファ（最大11桁の整数 + 終端文字）
        int index = 0;

        if (num == 0) {
            buffer[index++] = '0';
            buffer[index] = '\0';
            return;
        }

        // 負の数の場合
        if (num < 0) {
            buffer[index++] = '-';
            num = -num;
        }

        // 数字を逆順で格納
        while (num > 0) {
            temp[index++] = '0' + (num % 10);
            num /= 10;
        }

        // バッファに逆順でコピー
        int start = (buffer[0] == '-') ? 1 : 0; // 負の数の場合を考慮
        for (int i = 0; i < index; i++) {
            buffer[start + i] = temp[index - i - 1];
        }
        buffer[start + index] = '\0'; // 終端文字
    }



        //ゲームオーバー           
    void GAME::over() {
        
        stopSound(bgmSnd);
        isBgmPlaying = false;
        
        // 現在のスコアがハイスコアを超えた場合、ハイスコアを更新
        if (Score > highScore) {
            highScore = Score;
            saveHighScore(); // 新しいハイスコアを保存
        }
        
     


        // 背景色
       
        clear(0, 0, 0);
        rectMode(CENTER);
        image(overImg, width / 2, height / 2);
        // ゲームオーバー文字
        fill(255, 255, 255);
        textSize(150);
        text("Game Over", 570, 200);

        // 最終スコア表示
        fill(255, 255, 255);
        textSize(70);
        char scoreStr[20];
        intToStr(Score, scoreStr); // スコアを文字列に変換
        text("Score: ", 600, 400);
        text(scoreStr, 800, 400);

        char highScoreStr[20];
        intToStr(highScore, highScoreStr);
        text("High Score: ", 600, 500);
        text(highScoreStr, 1000, 500);


       //fill(0, 0, 0); // 黒
        //textSize(50);
        //text((let)"Score:" + Score, 650, 650); 
        //text((let)"Level:" + Level, 800, 150);

        
        // 再開案内
        fill(255, 255, 255); 
        textSize(80);
        text("SPACEキーでタイトルに戻る", 480, 700);

        if (isTrigger(KEY_SPACE)) {
            State = TITLE;
            FallSpeed = 30;
        }
    }

    void GAME::gmain() {
        window(Size * COLS * 2, Size * ROWS, full);
    }

   
}


