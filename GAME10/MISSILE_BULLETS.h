#pragma once
#include "BULLETS.h"
class MISSILE_BULLETS :public BULLETS
{
public:
    MISSILE_BULLETS(class GAME10_GAME* game);
    void create();
    void launch(const VECTOR2& pos, int speed, int lane);
    void update();
};

