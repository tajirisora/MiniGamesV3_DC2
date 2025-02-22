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
        //シーン分け
        enum STATE { TITLE, PLAY,CLEAR,OVER };
        STATE State = TITLE;
        void Title(struct DATA* d);
        void Play(struct DATA* d);
        void Clear(struct DATA* d);
        void Over(struct DATA* d);
        int Collision(struct CHARA* c, struct BULLET* b);
        void Draw(struct DATA* d);
        void HpGauge(struct CHARA* c);
        int FireSoundP;
        int FireSoundPBOM;
        int FireSoundE;
        int FireSoundB;

        int DamageSndP;
        int DamageSndE;
        int DamageSndB;

        int BgmSound;
        
        int GAMECSound;
        int GAMEOSound;

        int PBulletsnd = 0;
        //int PBOMsnd = 0;
        int EBulletsnd = 0;
        //int BBulletsnd = 0;

        float hpWarning = 0.0f;
        float hpDanger = 0.0f;

        bool PBHitFlag = false;
        bool PBOMHitFlag = false;
        bool EBHitFlag = false;
        bool BBHitFlag = false;
        bool EHpGaugeFlag = true;

        struct DATA* d = 0;
        struct CHARA* c = 0;
        struct BULLET* b = 0;  
    };
    struct CHARA {
        //各画像番号
        int normalImg;
        int damageImg;
        int damage2Img;
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
        float bulletOfsX;

        //体力
        int hp;
        //MaxHp
        int MaxHp;
        //ＨＰゲージ表示オフセット位置
        float hpGaugeOfsY;
        float hpGaugeOfsX;
        //当たり判定用、半分の幅と高さ
        float halfW;
        float halfH;
        bool ColFlag;

        //エネミーの倒された数
        int totalCnt = 0;
        //リポップタイム
        int repoptime;
        bool repoptimeFlag;
    };
    //プレイヤーの弾とNPCの弾用構造体型
    struct BULLET {
        //画像番号
        int img;
        //位置
        float px;
        float py;
        //方向ベクトル
        float vx;
        float vy;
        //体力？（ウィンドウ内を飛んでいるかを意味する）
        int hp;
        //当たり判定用、半分の幅と高さ
        float halfW;
        float halfH;
        int cnt = 0;
    };
    //全データを管理する構造体型
    struct DATA {
        //----------------------------------------
        //RESULTの時、キー入力を無効化するフレーム数
        int frameRestrictInput;
        int frameCnt;
        //----------------------------------------
        //キャラクタデータ
        struct CHARA Player;
        struct CHARA Enemy;
        struct CHARA BOSS;
        struct BULLET PBullet;
        struct BULLET PBOM;
        struct BULLET EBullet;
        struct BULLET BBullet;
        int titleImg;
        int backImg;
    };
}
