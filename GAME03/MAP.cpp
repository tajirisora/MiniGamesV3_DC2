#include"../../libOne/inc/window.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include "MAP.h"
namespace GAME03 {
    MAP::MAP(class GAME* game) : GAME_OBJECT(game) {
    }
    MAP::~MAP() {
        if (Map.data) { delete[] Map.data; Map.data = 0; }
    }
    void MAP::create() {
        Map = game()->container()->data().map;
    }
    void MAP::init() {
        Map.wx = 0.0f;
        Map.wy = 0.0f;
        srand((unsigned)time(NULL));
    }
    void MAP::update() {
        Map.wx += game()->characterManager()->player()->overCenterVx();
        Map.wy += game()->characterManager()->player()->overCenterVy();
        //if (Map.wy > Map.endWorldY) {
        //    Map.wy = Map.endWorldY;
        //}
        //if (Map.wx > Map.endWorldX) {
        //    Map.wx = Map.endWorldX;
        //}
    }
    void MAP::draw() {
        float wx = game()->characterManager()->player()->overCenterVx();
        float wy = game()->characterManager()->player()->overCenterVy();
        if (wx >= 0.001 && wy >= 0.001 && wx <= -0.001 && wy <= -0.001) {
            game()->characterManager()->appear('c', wx, wy);
        }
        game()->characterManager()->appear('a', wx, wy);

        for (int i = 0; i < 100; i++) {
            int x = rand();
            if (x % 4 == 0) {
                Map.random_x = rand();
                Map.random_y = rand();
            }
            else if(x % 4 == 1){
                Map.random_x = -rand();
                Map.random_y = -rand();
            }
            else if (x % 4 == 2) {
                Map.random_x = rand();
                Map.random_y = -rand();
            }
            else if (x % 4 == 3) {
                Map.random_x = -rand();
                Map.random_y = rand();
            }
            if (((Map.random_x >= wx - 1000 || Map.random_x <= wx + 1000) &&
                (Map.random_y <= wy - 1000 || Map.random_y >= wy + 1000)) ||
                ((Map.random_x >= wx + 5000 || Map.random_x <= wx - 5000) && 
                 (Map.random_y <= wy + 5000 || Map.random_y >= wy - 5000))) {
                i--;
                continue;
            }
            game()->characterManager()->appear('b', wx + Map.random_x, wy + Map.random_y);

        }
    }
    bool MAP::collisionCheck(float wx, float wy) const {
        int col = (int)wx / Map.chipSize;
        int row = (int)wy / Map.chipSize;
        if ((col < 0) || (col >= Map.cols) || (row < 0) || (row >= Map.rows)) {
            return false;
        }
        if (Map.data[col + row * Map.cols] == '1') {
            return true;
        }
        return false;
    }
    bool MAP::collisionCharaLeft(float wx, float wy) const {
        bool leftTop = collisionCheck(wx, wy);
        bool leftBottom = collisionCheck(wx, wy + Map.chipSize - 1);
        return leftTop || leftBottom;
    }
    bool MAP::collisionCharaRight(float wx, float wy) const {
        bool rightTop = collisionCheck(wx + Map.chipSize - 1, wy);
        bool rightBottom = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize - 1);
        return rightTop || rightBottom;
    }
    bool MAP::collisionCharaTop(float wx, float wy) const {
        bool topLeft = collisionCheck(wx, wy);
        bool topRight = collisionCheck(wx + Map.chipSize - 1, wy);
        return topLeft || topRight;
    }
    bool MAP::collisionCharaBottom(float wx, float wy) const {
        bool bottomLeft = collisionCheck(wx, wy + Map.chipSize);
        bool bottomRight = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize);
        return bottomLeft || bottomRight;
    }
    bool MAP::collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom) const {
        bool rightTop = collisionCheck(wRight, wTop);
        bool rightBottom = collisionCheck(wRight, wBottom);
        bool leftTop = collisionCheck(wLeft, wTop);
        bool leftBottom = collisionCheck(wLeft, wBottom);
        return rightTop || rightBottom || leftTop || leftBottom;
    }
    float MAP::wDispLeft() const {
        return Map.wx - Map.chipSize;
    }
    float MAP::wDispRight() const {
        return Map.wx + width;
    }
}
