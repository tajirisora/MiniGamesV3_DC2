#pragma once
#include "NOTE.h"
#include "LONGBELT.h"
#include <vector>

namespace GAME09 {
    class LONGNOTE :
        public NOTE
    {
    private:
        std::vector<NOTE*> Belts;
        bool IsPress = false;
    public:
        LONGNOTE(class GAME* game);
        ~LONGNOTE();
        void init();
        void update();
        void draw();

        void setBelts(std::vector<NOTE::NOTE_DATA*> belts);
        void setPress(bool press) { IsPress = press; }
        bool getPress() { return IsPress; }
    };
}