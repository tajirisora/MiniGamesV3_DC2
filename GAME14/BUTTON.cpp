#include"../../libOne/inc/input.h"
#include "BUTTON.h"
namespace GAME14 {
    void BUTTON::create(){}
    void BUTTON::init(){}
    void BUTTON::update(){}
    void BUTTON::draw(){}
    bool BUTTON::collisionCheck(VECTOR2 pos, float r) {
        float distanceX = pos.x - mouseX;
        float distanceY = pos.y - mouseY;
        float distance = distanceX * distanceX + distanceY * distanceY;
        if (distance < r * r) {
            return true;
        }

        return false;
    }
    bool BUTTON::collisionCheck(VECTOR2 pos, VECTOR2 size) {
        if (mouseX >= pos.x && mouseY >= pos.y &&
            mouseX <= pos.x + size.x && mouseY <= pos.y + size.y) {
            return true;
        }
        return false;
    }


}