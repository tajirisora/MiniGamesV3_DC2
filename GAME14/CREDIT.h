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

        float onePayoutTime;//一枚払い出すのにかかる時間

        int BBPayoutMaxNum;//払い出し枚数がこの枚数を超えたらBIGボーナス終了
        int REGPlayMaxTime;//REGの最大ゲーム数
        int REGPayoutMaxTime;//REG中の最大払い出し回数 払い出しがあったら1ゲーム減らす
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
    int BBPayoutCurNum;//BIGボーナス中いくら払い出したか
    int REGPlayCurTime;//REG中の回したゲーム数
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
};
}

