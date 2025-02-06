#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME07
{
    class PHYSICS_ENGINE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 gravity;
        };
    private:
        DATA Physics;
        std::vector<class FRUITS*> Fruits;
        bool isSetMove;
    public:
        PHYSICS_ENGINE(class GAME* game);
        ~PHYSICS_ENGINE();
        void create();
        void init();
        void update();
        void draw();

		void updatePos(float dt);
		void applyGravity();
        void applyConstraint();
        void applyConstraintIndividual(class FRUITS* fruits);
        void solveCollisions();
        bool gameOverJudge();

        void addFruits(class FRUITS* fruits);
        void setVibe(bool vibe);
    };
}
