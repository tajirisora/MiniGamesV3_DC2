#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "BUTTON.h"

namespace GAME09 {
    BUTTON::BUTTON(class GAME* game) :
        GAME_OBJECT(game) {

    }
    BUTTON::~BUTTON() {

    }
    void BUTTON::create() {

    }
    void BUTTON::init() {
        
    }
    void BUTTON::update() {
        IsClick = false;
        if (collision() && isTrigger(MOUSE_LBUTTON) || Button.key != KEY_NONE && isTrigger(Button.key)) {
            IsClick = true;
        }
    }
    void BUTTON::draw() {
        rectMode(CENTER);
        angleMode(DEGREES);
        if (Button.img != -1) {
            image(Button.img, Button.pos.x, Button.pos.y, 0, Button.imgSize);
        }
        if (Button.debugFlag) {
            if (collision()) {
                fill(0, 255, 0, 100);
            }
            else {
                fill(255, 0, 0, 100);
            }
            noStroke();
            if (Button.colliType == CIRCLE) {
                circle(Button.pos.x + Button.ofst.x, Button.pos.y + Button.ofst.y, Button.radius * 2);
            }
            else if (Button.colliType == RECT) {
                rect(Button.pos.x + Button.ofst.x, Button.pos.y + Button.ofst.y,
                    Button.size.x, Button.size.y);
            }
            else {
                float len = Button.radius / Sqrt(2.0f) * 2;
                rect(Button.pos.x + Button.ofst.x, Button.pos.y + Button.ofst.y,
                    len, len, 45);
            }
        }
    }
    void BUTTON::setData(DATA& data) {
        Button = data;
    }
    bool BUTTON::collision() {
        VECTOR2 mousePos(mouseX, mouseY);
        VECTOR2 toMouse = mousePos - (Button.pos + Button.ofst);
        if (Button.colliType == CIRCLE) {
            if (toMouse.magSq() < Button.radius * Button.radius) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (Button.colliType == RECT) {
            if (Abs(toMouse.x) < Button.size.x / 2.0f && Abs(toMouse.y) < Button.size.y / 2.0f) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (Button.colliType == DIAMOND) {
            if (Abs(toMouse.x) + Abs(toMouse.y) < Button.radius) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
}