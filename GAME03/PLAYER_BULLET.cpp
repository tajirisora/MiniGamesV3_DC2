#include "../../libOne/inc/graphic.h"
#include"../../libOne/inc/window.h"
#include"../../libOne/inc/input.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME03.h"
#include"MAP.h"
#include"PLAYER_BULLET.h"
namespace GAME03 {
    void PLAYER_BULLET::create() {
        Chara = game()->container()->data().playerBulletChara;
        Player_Bullet = game()->container()->data().playerBullet;
    }
    void PLAYER_BULLET::appear(float wx, float wy, float vx, float vy) {
        Chara.hp = game()->container()->data().playerBulletChara.hp;
        Chara.wx = wx;
        Chara.wy = wy;
        Chara.vx = vx;
        Chara.vy = vy;
    }
    void PLAYER_BULLET::update() {
        if (!op_option) {
            Chara.wx += Chara.vx * (Chara.speed * delta);
            if ((Chara.wx <= 0.001 && Chara.wy <= 0.001 && Chara.wx >= -0.001 && Chara.wy >= -0.001) ||
                Chara.wx < game()->characterManager()->player()->playerWx() - 830.0f ||
                Chara.wx > game()->characterManager()->player()->playerWx() + 830.0f ||
                Chara.wy > game()->characterManager()->player()->playerWy() + 550.0f ||
                Chara.wy < game()->characterManager()->player()->playerWy() - 550.0f) {
                Chara.hp = 0;
            }
            if (isTrigger(KEY_ESCAPE) ||
                ((mouseX > 12 && mouseX < 100 && mouseY>12 && mouseY < 83) && isTrigger(MOUSE_LBUTTON))) {
                op_option = true;
            }
        }
        if (op_option) {
            if (isTrigger(KEY_N) || (mouseX > 1005 && mouseX < 1234 && mouseY>707 && mouseY < 772) && isTrigger(MOUSE_LBUTTON)) {
                op_option = false;
            }
            if (isTrigger(KEY_O) || (mouseX > 687 && mouseX < 918 && mouseY>707 && mouseY < 772) && isTrigger(MOUSE_LBUTTON)) {
                op_option = false;
                Chara.hp = 0;
            }
        }
    }
    void PLAYER_BULLET::damage() {
        if (Chara.hp > 0) {
            Chara.hp--;
        }
    }
}