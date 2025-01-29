#include"GAME03.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include"ENEMY.h"
#include "CHARACTER_MANAGER.h"
namespace GAME03 {
	CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game) : GAME_OBJECT(game) {
	}
	CHARACTER_MANAGER::~CHARACTER_MANAGER() {
		for (int i = 0; i < Total; i++) {
			delete Characters[i];
		}
		delete[] Characters;
		Player = nullptr;
	}
	void CHARACTER_MANAGER::init() {
		for (int i = 0; i < Total; i++) {
			Characters[i]->init();
		}
	}
	void CHARACTER_MANAGER::create() {
		CharaMng = game()->container()->data().charaMng;

		Total = 0;
		Total += CharaMng.numPlayers;
		Total += CharaMng.numBats;
		Total += CharaMng.numPlayerBullets;
		Characters = new CHARACTER * [Total + 9];

		Player = new PLAYER(game());
		int j = 0;
		for (int i = 0; i < CharaMng.numPlayers; i++) { Characters[j++] = Player; }
		for (int i = 0; i < CharaMng.numPlayerBullets; i++) Characters[j++] = new PLAYER_BULLET(game());
		for (int i = 0; i < CharaMng.numBats; i++) { Characters[j++] = new ENEMY(game()); }
		for (int k = 0; k < Total; k++) {
			Characters[k]->create();
		}

	}
	void CHARACTER_MANAGER::appear(char charaId, float wx, float wy, float vx, float vy) {
		for (int i = 0; i < Total; i++) {
			if (Characters[i]->charaId() == charaId) {
				if (Characters[i]->hp() <= 0) {
					Characters[i]->appear(wx, wy, vx, vy);
					break;
				}
			}
		}
	}
	void CHARACTER_MANAGER::update() {
		for (int i = 0; i < Total; i++) {
			if (Characters[i]->hp() > 0) {
				Characters[i]->update();
			}
		}
		for (int i = 0; i < Total - 1; i++) {
			if (Characters[i]->hp() == 0) {
				continue;
			}
			for (int j = i + 1; j < Total; j++) {
				if (Characters[j]->hp() == 0) {
					continue;
				}
				if (Characters[i]->groupId() == 1 && Characters[i]->groupId() == Characters[j]->groupId()) {
					if (Characters[i]->wLeft() < Characters[j]->wRight()) {
						Characters[i]->reflection(-0.01f, 0.00f);
						Characters[j]->reflection(0.01f, 0.00f);
					}
					if (Characters[j]->wLeft() < Characters[i]->wRight()) {
						Characters[i]->reflection(0.01f, 0.00f);
						Characters[j]->reflection(-0.01f, 0.00f);
					}
					if (Characters[i]->wTop() < Characters[j]->wBottom()) {
						Characters[i]->reflection(0.00f, -0.01f);
						Characters[j]->reflection(0.00f, 0.01f);
					}
					if (Characters[j]->wTop() < Characters[i]->wBottom()) {
						Characters[i]->reflection(0.00f, 0.01f);
						Characters[j]->reflection(0.00f, -0.01f);
					}
					continue;
				}
				else if (Characters[i]->groupId() == Characters[j]->groupId()) {
					continue;
				}
				if (Characters[i]->wLeft() < Characters[j]->wRight() &&
					Characters[j]->wLeft() < Characters[i]->wRight() &&
					Characters[i]->wTop() < Characters[j]->wBottom() &&
					Characters[j]->wTop() < Characters[i]->wBottom()) {
					//“–‚½‚Á‚½
					Characters[i]->damage();
					Characters[j]->damage();
				}
			}
		}
	}
	void CHARACTER_MANAGER::draw() {
		for (int i = 0; i < Total; i++) {
			if (Characters[i]->hp() > 0) {
				Characters[i]->draw();
			}
		}
	}
}