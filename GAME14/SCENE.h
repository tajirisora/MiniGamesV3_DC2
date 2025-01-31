#pragma once
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include"GAME14.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class SCENE : 
        public GAME_OBJECT{
    public:
        SCENE(class GAME* game);
        virtual ~SCENE();
        virtual void create();
        virtual void init();
        virtual void proc();
        virtual void update();
        virtual void draw();
        virtual void nextScene();
    };
}

