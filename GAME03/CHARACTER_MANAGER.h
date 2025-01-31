#pragma once
#include"GAME_OBJECT.h"
#include"../../libOne/inc/COLOR.h"
#include"ANIMS.h"
namespace GAME03 {
	class CHARACTER_MANAGER :public GAME_OBJECT {
	public:
		struct DATA {
			int numPlayers = 0;
			int numPlayerBullets = 0;
			int numBats = 0;
			time_t s_time = 0, e_time = 0, n_time = 0;
		};
	private:
		int Total = 0;
		DATA CharaMng;
		class CHARACTER** Characters = nullptr;
		class PLAYER* Player = nullptr;
		class ENEMY* Enemy = nullptr;
	public:
		CHARACTER_MANAGER(class GAME* game);
		~CHARACTER_MANAGER();
		void create();
		void init();
		void appear(char charaId, float wx, float wy, float vx = 0, float vy = 0);
		void update();
		void draw();
		class PLAYER* player() { return Player; }
		class ENEMY* enemy() { return Enemy; }
	};
};

