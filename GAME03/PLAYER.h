#pragma once
#include"CHARACTER.h"
namespace GAME03 {
    class PLAYER :public CHARACTER {
    public:
        struct DATA {
            int rightAnimId = 0;
            int leftAnimId = 1;
            float curWx = 0;
            float initVecUp = 0;
            float initVecDown = 0;
            float damageTime = 0;
            float damageInterval = 0;
            char bulletCharaId = 0;
            float bulletOffsetX = 0;
            float bulletOffsetY = 0;
            COLOR damageColor;
            COLOR normalColor;
            time_t s_time = 0, time = 0,
                   n_time = 0, stp_time = 0,
                   cnt_time = 0;
        };
    private:
        DATA Player;
        DATA Stage;
        enum class STATE { STRUGGLING, SURVIVED, DIED };
        STATE State = STATE::STRUGGLING;
        FILE* fp{};
    public:
        PLAYER(class GAME* game) :CHARACTER(game) {}
        void create();
        void appear(float wx, float wy, float vx, float vy);
        void update();
    private:
        void Launch();
        void Move();
        void CollisionWithMap();
        void CheckState();
    public:
        void damage();
        void ChangeColor();
        bool died();
        bool survived() const;
        float overCenterVx();
        float overCenterVy();
        float playerWx();
        float playerWy();
        int playerHp();
        int DeterPlayer = 0;
        int op_option = false;
        int onceSe = true;
    };
}

