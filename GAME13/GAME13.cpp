#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME13.h"
#include <cstdlib> 
#include <ctime>   
#include <string>  

namespace GAME13 {

    int GAME::create() {
        return 0;
    }
    
    void GAME::proc() {
        if (State == TITLE)Title();
        else if (State == KAKURITU)Kakuritu();
        else if (State == PLAY)Play();
        else if (State == PUSH)Push();
        else if (State == SUCCESS)Success();
        else if (State == TENSUCCESS)TenSuccess();
        else if (State == OVER)Over();
    }

    void GAME::destroy() {
    
    }

    void GAME::Init() {
        srand(time(0));
        half = random() % 2;
    }

    void GAME::Title() {
        clear(255);
        fill(0);
        textSize(200);
        text("1/1024", 650, 500);
        textSize(100);
        text("Sキー:GAME START", 500, 900);

        if (isTrigger(KEY_S)) {
            Init();
            State = PLAY;
        }

        if (isTrigger(KEY_K)) {
            State = KAKURITU;
        }

        textSize(50);
        text("ENTERキーでメニューに戻る", 50, 1080);
        text("Kキー:確率", 50, 980);
        // ENTERキーでメニューに戻る
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }  
    
    void GAME::Kakuritu()
    {
        clear(0);
        fill(255);
        textSize(60);
        for (int i = 1; i < 11; i++) {
            text("試行回数", 600, 100);
            text(i,600.0f, 150.0f + 90.0f * i);
        }
        text("確率", 1100, 100);
        text("1/2", 1100, 240);
        text("1/4", 1100, 330);
        text("1/8", 1100, 420);
        text("1/16", 1100, 510);
        text("1/32", 1100, 600);
        text("1/64", 1100, 690);
        text("1/128", 1100, 780);
        text("1/256", 1100, 870);
        text("1/512", 1100, 960);
        text("1/1024", 1100, 1050);

        textSize(50);
        text("Enterでタイトルに戻る", 0, 1080);
        if (isTrigger(KEY_ENTER)) {
            State = TITLE;
        }
    }

    void GAME::Play() {
        clear(100);
        fill(255);
        textSize(300);
        text("L", 50, 700);
        text("R", 1600, 700);
        textSize(150);
        text("RかLを", 500, 450);
        text("選んでください", 450, 650);
        textSize(50);
        text("成功回数:" + (let)SuccessCnt + "/" + "10", 0, 100);

        int playerChoice = -1;
        bool playerChose = false;

        if (isTrigger(KEY_L)) {
            fill(255, 0, 0);
            textSize(300);
            text("L", 50, 700);
            playerChoice = 0;
            playerChose = true;
        }

        if (isTrigger(KEY_R)) {
            fill(255, 0, 0);
            textSize(300);
            text("R", 1600, 700);
            playerChoice = 1;
            playerChose = true;
        }

        if (playerChose) {
            Sleep(500);

            int computerChoice = rand() % 2;


            if (playerChoice == computerChoice) {
                SuccFlag = true;
                State = PUSH;
            }
            else {
                OverFlag = true;
                State = PUSH;
            }

            if (SuccessCnt == 9 && ((isTrigger(KEY_L) && half == 1) || (isTrigger(KEY_R) && half == 1))) {
                TenSuccFlag = true;
                State = PUSH;
            }
        }
    }
    void GAME::Push()
    {
        if (SuccFlag == true) {
            SuccFlag = false;
            Sleep(800);
            State = SUCCESS;
        }

        if (OverFlag == true) {
            OverFlag = false;
            Sleep(800);
            State = OVER;
        }

        if (TenSuccFlag == true) {
            TenSuccFlag = false;
            Sleep(800);
            State = TENSUCCESS;
        }
    }
    void GAME::Success()
    {
        clear(255, 255, 0);
        fill(0);
        textSize(300);
        text("成功", 600, 600);
        textSize(100);
        text("スペースでもう一度", 500, 700);
        if(isTrigger(KEY_SPACE)) {
            Init();
            SuccessCnt++;
            State = PLAY;
        }
    }
    void GAME::TenSuccess()
    {
        clear(255);
        fill(255, 0, 0);
        textSize(300);
        text("10連続達成",250,540);
        textSize(100);
        text("ENTERキーでタイトルに戻る", 50, 1080);
        if (isTrigger(KEY_ENTER)) {
            SuccessCnt = 0;
            State = TITLE;
        }

    }
    void GAME::Over()
    {
        clear(255);
        fill(0);
        textSize(300);
        text("失敗", 600, 600);
        textSize(100);
        text("ENTERキーでタイトルに戻る", 50, 1080);
        if (isTrigger(KEY_ENTER)) {
            SuccessCnt = 0;
            State = TITLE;
        }
    }
}
