#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09 {
    class LANE :
        public GAME_OBJECT
    {
    public:
        enum LANESTATE {
            START,
            STAY,
            END
        };
        struct LANEDATA {
            int laneNo;
            LANESTATE state;
            float laneWidth;

            void setWidth(float ratio);
        };
        struct CHANGEDATA {
            std::vector<int> lane;
            double beatS;
            double beatE;
        };
        struct DATA {
            VECTOR2 pos; //xÇÕíÜâõÇÃà íuÅAyÇÕîªíËê¸ÇÃà íu
            float laneWidth;
            int maxLaneNum;
        };
    private:
        DATA Lane;
        std::vector<LANEDATA> Lanes;
        std::vector<CHANGEDATA> ChangeLaneData;

        float LaneWidthSum();
        int SearchLaneNum(int num);
        void SortLane();
    public:
        LANE(class GAME* game);
        ~LANE();
        void create();
        void init();
        void update();
        void draw();

        float laneWidth() { return Lane.laneWidth; }
        int maxLaneNum() { return Lane.maxLaneNum; }
        VECTOR2 lanePos() { return Lane.pos; }
        std::vector<CHANGEDATA>& changeLaneData() { return ChangeLaneData; }
    };
}