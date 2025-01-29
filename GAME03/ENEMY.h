#pragma once
#include"CHARACTER.h"
#include<time.h>
namespace GAME03 {
    class ENEMY :public CHARACTER {
    public:
        struct DATA {
            int rightAnimId = 0;
            int leftAnimId = 1;
            int jumpFlag = 0;
            int score = 0;
            int newscore = 0;
            int upDate = false;
            float damageTime = 0;
            float damageInterval = 0;
            float curWx = 0;
            float curWy = 0;
            float initVecUp = 0;
            float initVecDown = 0;
            time_t s_time = 0, e_time = 0, n_time = 0;
            COLOR damageColor;
            COLOR normalColor;
        };
    private:
        DATA Enemy;
        enum class STATE { STRUGGLING,  DIED };
        STATE State = STATE::STRUGGLING;
        FILE* fp{};
    public:
        ENEMY(class GAME* game) :CHARACTER(game) {}
        void create();
        void appear(float wx, float wy, float vx, float vy);
        void update();
    private:
        void Move();
        void CollisionWithMap();
        void CheckState(); 
        void ChangeColor();
        void damage();
        void reflection(float x, float y);
    public:
        float enemyWx();
        float enemyWy();
        int timeCnt = 0;
        int op_option = false;
    };
}
