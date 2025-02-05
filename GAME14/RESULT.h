#pragma once
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include<string>
#include "SCENE.h"
namespace GAME14 {
    class RESULT :
        public SCENE
    {
    public:
        struct DATA {
            COLOR backColor;

            std::string text;
            VECTOR2 textPos;
            COLOR textColor;
            float textSize;
            
            std::string message;
            VECTOR2 messagePos;
            COLOR messageColor;
            float messageSize;
            std::string message2;
            VECTOR2 message2Pos;

            std::string resultNumText;
            VECTOR2 resultNumPos;
            COLOR resultNumColor;
            float resultNumSize;

            std::string resultText;
            VECTOR2 resultPos;
            COLOR resultWinColor;
            COLOR resultLossColor;
            float resultSize;

            int rato;
        };
    private:
        DATA Result;
        int ResultNum;
    public:
        RESULT(GAME* game) :SCENE(game) {}
        ~RESULT();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();

    };
}

