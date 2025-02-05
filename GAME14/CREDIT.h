#pragma once
#include "GAME_OBJECT.h"
#include"LOTTERY.h"
namespace GAME14{
class CREDIT :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* payoutFileName;
        std::string separator;

        VECTOR2 drawPayoutPos;
        COLOR drawPayoutColor;
        float drawPayoutSize;

        VECTOR2 drawBBPayoutPos;

        float onePayoutTime;//一枚払い出すのにかかる時間

        int BBPayoutMaxNum;//払い出し枚数がこの枚数を超えたらBIGボーナス終了
        int REGPayoutMaxTime;//REGの最大払い出し回数
    };
    struct RESULT_DATA {
        int resultId = 0;
        int numPayout;//成立時の払い出し
        int numMissPayout;//非成立時の払い出し
    };
private:
    DATA Credit;
    RESULT_DATA Result[LOTTERY::NUM_RESULT-1];
    int Payout;//払い出す枚数
    int CurPayout;//今いくら払いだされたか
    float CurTime;
    int BBPayoutNum;//BIGボーナスの残り払い出し枚数
    int REGPlayTime;//REG中の残りゲーム数
    bool BBAdjustFlag;//BB中の枚数調整出目が出たか
    bool SistemFlag;//処理中のフラグ
public:
    CREDIT(class GAME* game);
    ~CREDIT();
    void create();
    void init();
    void initResult();
    void update();
    void resultPayout(bool flag);
    void resultBonus(bool flag);
    void draw();
    void debagdraw();
    void clearCurPayout() { CurPayout = 0; }
    void onBBAdjustFlag() { BBAdjustFlag = true; }
    bool payoutSistemFlag() { return SistemFlag; }

};
}

