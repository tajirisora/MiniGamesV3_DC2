#pragma once
#include "GAME09.h"
#include "GAME_OBJECT.h"
namespace GAME09 {
    class SCENE :
        public GAME_OBJECT
    {
    protected:
        GAME::SCENE_ID NextScene = GAME::TITLE_ID;
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