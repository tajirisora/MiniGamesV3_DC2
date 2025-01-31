#pragma once
class GAME_OBJECT10
{
private:
	class GAME10_GAME* Game = 0;
public:
	GAME_OBJECT10(class GAME10_GAME* game);
	~GAME_OBJECT10();
	class GAME10_GAME* game() {
		return Game;
	}
};

