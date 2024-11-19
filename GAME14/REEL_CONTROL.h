#pragma once
#include"GAME_OBJECT.h"
#include<vector>
namespace GAME14{
	class REEL_CONTROL ://図柄配置読み込み、リール制御
		public GAME_OBJECT{
	public:
		struct DATA {
			int img[10]{ 0 };
			const char* ControlFILEName;

		};
	private:
		DATA Information;
	public:
		REEL_CONTROL(class GAME* game):
			GAME_OBJECT(game){}
		~REEL_CONTROL();
		void create();
		void proc();//図柄の配置、リール制御の情報、読み込み
		
	};
}

