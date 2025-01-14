#pragma once
namespace GAME06 {
	class GAME_OBJECT {
	private:
		class GAME* Game = nullptr;
	public:
		GAME_OBJECT(class GAME* game) { Game = game; }
		virtual ~GAME_OBJECT(){}
		class GAME* game() { return Game; }
	};
}
