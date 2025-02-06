#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME07
{
    class FRUITS :
        public GAME_OBJECT
    {
    public:
        enum FRUITS_KINDS {
            CHERRY,
            STRAWBERRY,
            GRAPE,
            DEKOPON,
            PERSIMMON,
            APPLE,
            PEAR,
            PEACH,
            PINEAPPLE,
            MELON,
            WATERMELON,
            NUM_FRUITS_KINDS
        };
        struct DATA {
            float sw;
            float attenuationRate; //�^���ʂ̌�����(�n�ʂœ����^��������̂�����邽��)
            float initTheta;

            int imgs[NUM_FRUITS_KINDS];
            float cherryImgSize;
            float cherryRadius;
            float nextFruitsSizeRate;

            float inflateMaxTime;
            float initValue;
            float vibeMaxDist;
            float vibeSpeed;
        };
    private:
        DATA Fruits;
        FRUITS_KINDS Kinds;

        VECTOR2 Pos_current;
        VECTOR2 Pos_old;
        VECTOR2 Acc;
        bool Touch; //���̃I�u�W�F�N�g�ƐG��Ă��邩�ǂ���
        float Omega; //�p���x
        float Theta; //�p�x(���W�A��)

        float Radius;
        float ImgSize;
        float InflateTime;
        float MaxRadius;
        bool Inflate;
        bool TouchedAny = false;
        bool Last = false;
        bool Vibe = false;
        float VibeAnimeTime = 0;
    public:
        FRUITS(class GAME* game, VECTOR2 pos, FRUITS_KINDS kinds, bool inflate = false);
        ~FRUITS();
        void create();
        void init();
        void update(float dt);
        void accelerate(VECTOR2 acc);
        void draw();
        bool gameOverJudge();

        const VECTOR2& getPosC() { return Pos_current; }
        const VECTOR2& getPosO() { return Pos_old; }
        float getRadius() { return Radius; }
        FRUITS_KINDS getKinds() { return Kinds; }

        void setPosC(const VECTOR2& newPos) { Pos_current = newPos; }
        void setPosO(const VECTOR2& newPos) { Pos_old = newPos; }
        void setTouch(bool touch);
        void setLast(bool last) { Last = last; }
        void setVibe(bool vibe);
        void setTheta() { Theta = Fruits.initTheta; }
        
        bool getTouchedAny() { return TouchedAny; }
        bool getLast() { return Last; }
    };
}
