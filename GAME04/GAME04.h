#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME04
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
        void Init(struct DATA* d);
    private:
        enum STATE { TITLE, PLAY, RESULT };
        STATE State = TITLE;
        void Title(struct DATA* d);
        void Play(struct DATA* d);
        void Result(struct DATA* d);
        int Collision(struct CHARA* c, struct BULLET* b);
        void Draw(struct DATA* d);
        // void Hpgauge(struct CHARA* c);
        int FireSoundP;
        int FireSoundN;
        int FireSoundBOM;
        int FireSoundB;
        int DamageSoundP;
        int DamageSoundN;
        int DamageSoundB;
        int BgmSound;
        int GAMECSound;
        int GAMEOSound;

        struct DATA* d = 0;
        struct CHARA* c = 0;
        struct BULLET* b = 0;
        int PBulletsnd = 0;
        int NBulletsnd = 0;
    };
    struct CHARA {
        //各画像番号
        int normalImg;
        int damageImg;
        int Imghp;
        //現在の画像番号
        int img;
        //位置
        float px;
        float py;
        //移動方向ベクトル
        float vx;
        float vy;
        //弾発射オフセット位置
        float bulletOfsY;
        //体力
        int hp;
        //HPゲージ表示オフセット位置
        float hpGaugeOfsY;
        //当たり判定、半分の幅と高さ
        float halfW;
        float halfH;
        //エネミーの倒された数
        int totalCnt = 0;

    };
    //プレイヤーとNPCの弾用構造体型
    struct BULLET {
        //画像番号
        int img;
        //位置
        float px;
        float py;
        //方向ベクトル
        float vx;
        float vy;
        //体力？(ウィンドウ内を飛んでいるかを意識する)
        int hp;
        //当たり判定用、半分の幅と高さ
        float halfW;
        float halfH;
        //カウント
        int cnt = 0;
    };
    //全データを管理する構造体系
    struct DATA {
        //RESURTの時、キー入力をも硬化するフレーム数
        int frameRestrictInput;
        int frameCnt;
        //キャラクタデータ
        struct CHARA Player;
        struct CHARA NPC;

        struct CHARA BOSS;
        struct BULLET PBullet;
        struct BULLET PBOM;
        struct BULLET NBullet;
        struct BULLET BBullet;
        int titleImg;
        int backImg;

    };


}
