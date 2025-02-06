#include "PHYSICS_ENGINE.h"
#include "GAME07.h"
#include "CONTAINER.h"
#include "BOX.h"
#include "SOUNDMNG.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/rand.h"
#include "myFunc.h"

namespace GAME07
{
	PHYSICS_ENGINE::PHYSICS_ENGINE(GAME* game) :
		GAME_OBJECT(game) {

	}
	PHYSICS_ENGINE::~PHYSICS_ENGINE() {
		safe_clear(Fruits);
	}

	void PHYSICS_ENGINE::create() {
		Physics = game()->container()->data().physics;
	}

	void PHYSICS_ENGINE::init() {
		safe_clear(Fruits);
		isSetMove = true;
	}

	void PHYSICS_ENGINE::update() {

		//�t���[�c�𑝂₷����
		//if (isTrigger(MOUSE_LBUTTON)) {
		//	Fruits.emplace_back(new FRUITS(game(), VECTOR2(mouseX, mouseY), (FRUITS::FRUITS_KINDS)random(0, 4)));
		//	Fruits.back()->create();
		//	Fruits.back()->init();
		//}

		//�������Z
		const int subSteps = 8;
		const float subDt = delta / (float)subSteps;
		for (int i = 0; i < subSteps; i++) {
			applyGravity();
			updatePos(subDt);
			solveCollisions();
			applyConstraint();
		}
	}

	void PHYSICS_ENGINE::draw() {
		rectMode(CENTER);
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->draw();
			//fill(0);
			//print((*it)->getPosC().x);
			//print((*it)->getPosC().y);
		}
	}

	void PHYSICS_ENGINE::updatePos(float dt) {
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->update(dt);
		}
	}

	void PHYSICS_ENGINE::applyGravity() {
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->accelerate(Physics.gravity);
		}
	}

	void PHYSICS_ENGINE::applyConstraint() {
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			applyConstraintIndividual(*it);
		}
	}

	void PHYSICS_ENGINE::addFruits(FRUITS* fruits){
		Fruits.emplace_back(fruits);
		Fruits.back()->setLast(true);
		isSetMove = false;
	}

	void PHYSICS_ENGINE::setVibe(bool vibe) {
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			(*it)->setVibe(vibe);
		}
	}

	void PHYSICS_ENGINE::applyConstraintIndividual(class FRUITS* fruits){
		if (fruits->getPosC().y + fruits->getRadius() > game()->box()->under()) {
			fruits->setPosC(VECTOR2(fruits->getPosC().x, game()->box()->under() - fruits->getRadius()));
			fruits->setPosO(VECTOR2(fruits->getPosO().x, game()->box()->under() - fruits->getRadius()));
			fruits->setTouch(true);
			if (!isSetMove && fruits->getLast()) {
				isSetMove = true;
				game()->cloud()->setMove();
				fruits->setLast(false);
			}
		}
		if (fruits->getPosC().x + fruits->getRadius() > game()->box()->right()) {
			fruits->setPosC(VECTOR2(game()->box()->right() - fruits->getRadius() - 0.01f, fruits->getPosC().y));
			fruits->setPosO(VECTOR2(game()->box()->right() - fruits->getRadius() - 0.01f, fruits->getPosO().y));
			//fruits->setTouch(true);
		}
		if (fruits->getPosC().x - fruits->getRadius() < game()->box()->left()) {
			fruits->setPosC(VECTOR2(game()->box()->left() + fruits->getRadius() + 0.01f, fruits->getPosC().y));
			fruits->setPosO(VECTOR2(game()->box()->left() + fruits->getRadius() + 0.01f, fruits->getPosO().y));
			//fruits->setTouch(true);
		}
	}

	bool PHYSICS_ENGINE::gameOverJudge() {
		for (auto it = Fruits.begin(); it != Fruits.end(); it++) {
			if ((*it)->gameOverJudge()) {
				return true;
			}
		}
		return false;
	}

	void PHYSICS_ENGINE::solveCollisions() {
		std::vector<FRUITS*> TempEvolution;
		for (auto it = Fruits.begin(); it != Fruits.end();) {
			FRUITS*& fruits1 = *it;
			bool erase = false;
			for (auto it2 = it + 1; it2 != Fruits.end(); it2++) {
				FRUITS*& fruits2 = *it2;
				const VECTOR2 colliAxis = fruits1->getPosC() - fruits2->getPosC();
				const float dist = colliAxis.mag();
				const float distR = fruits1->getRadius() + fruits2->getRadius();
				//�Փ˂��Ă�Ȃ�
				if (dist < distR) {
					if (!isSetMove) {
						if (fruits1->getLast() || fruits2->getLast()) {
   							isSetMove = true;
							game()->cloud()->setMove();
							fruits1->setLast(false);
							fruits2->setLast(false);
						}
					}
					//�����t���[�c�Ȃ����
					if (fruits1->getKinds() == fruits2->getKinds()) {
						//�X�R�A
						game()->score()->addScore(fruits1->getKinds());
						//�X�C�J����Ȃ���ΐi�������z�𐶐�
						if (fruits1->getKinds() != FRUITS::WATERMELON) {
							VECTOR2 pos = (fruits1->getPosC() + fruits2->getPosC()) / 2;
							TempEvolution.emplace_back(new FRUITS(game(), pos, (FRUITS::FRUITS_KINDS)(fruits1->getKinds() + 1)));
						}
						//���ʉ�
						game()->soundMNG()->playSE(SOUNDMNG::STICK);
						delete (*it2);
						Fruits.erase(it2);
						delete (*it);
						it = Fruits.erase(it);
						erase = true;
						break;
					}
					else {
						//�d�Ȃ����
						const VECTOR2 n = colliAxis / dist;
						const float solveV = (distR - dist) * 0.9f;
						const float ratio = pow(fruits1->getRadius(), 1) / (pow(fruits1->getRadius(), 1) + pow(fruits2->getRadius(), 1));
						fruits1->setPosC(fruits1->getPosC() + (solveV * n * (1 - ratio)));
						fruits2->setPosC(fruits2->getPosC() - (solveV * n * ratio));
						fruits1->setTouch(true);
						fruits2->setTouch(true);
						//�Ԃ���іh�~
						const float maxSpeed = 1.0f;
						VECTOR2 curVel1 = fruits1->getPosC() - fruits1->getPosO();
						VECTOR2 curVel2 = fruits2->getPosC() - fruits2->getPosO();
						float velLen1 = curVel1.mag();
						float velLen2 = curVel2.mag();
						if (velLen1 > maxSpeed) {
							VECTOR2 n1 = curVel1 / velLen1;
							fruits1->setPosO(fruits1->getPosC() - (maxSpeed * n1));
						}
						if (velLen2 > maxSpeed) {
							VECTOR2 n2 = curVel2 / velLen2;
							fruits2->setPosO(fruits2->getPosC() - (maxSpeed * n2));
						}
					}
				}
			}
			if (!erase) {
				it++;
			}
		}
		if (TempEvolution.size() != 0) {
			for (auto it = TempEvolution.begin(); it != TempEvolution.end();) {
				Fruits.emplace_back(*it);
				Fruits.back()->create();
				Fruits.back()->init();
				Fruits.back()->setTheta();
				it = TempEvolution.erase(it);
			}
		}
	}
}