#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"GAME_OBJECT.h"
namespace GAME14 {
	class REEL_MANAGER:
		public GAME_OBJECT{
	public:
		enum REEL_ID {
			LEFT_REEL_ID,
			MIDDLE_REEL_ID,
			RIGHT_REEL_ID,
			NUM_REEL
		};
	private:
		class REEL** Reels = nullptr;
	public:
		REEL_MANAGER(class GAME* game):
			GAME_OBJECT(game){}
		~REEL_MANAGER();
		void create();
		void init();
		void update();
		void draw();
		class REEL* reel(int Id) { return Reels[Id]; }
		void reelMove();
	};
}