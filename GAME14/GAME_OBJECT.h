#pragma once
namespace GAME14 {
	class GAME_OBJECT{
	private:
		class GAME* Game = nullptr;
	public:
		GAME_OBJECT(class GAME* game);
		class GAME* game() { return Game; }
	};
}

