#pragma once
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include"TITLE.h"
#include"HOME.h"
#include"STAGE.h"
#include"RESULT.h"
#include"BUTTON.h"
#include"LEVER.h"
#include"STOP_BUTTON.h"
#include"LOTTERY.h"
#include"REEL.h"
#include"REEL_MAP.h"
#include"CREDIT.h"
#include"BET.h"
#include"MAX_BET_BUTTON.h"
#include"GAME14.h"
namespace GAME14 {
	class CONTAINER{
	private:
		struct DATA {
			GAME14::TITLE::DATA title;
			GAME14::BUTTON::DATA leverButton;
			GAME14::LEVER::DATA lever;
			GAME14::BUTTON::DATA stopButton;
			GAME14::STOP_BUTTON::DATA stop;
			GAME14::LOTTERY::DATA lottery;
			GAME14::REEL::DATA reel;
			GAME14::REEL_MAP::DATA map;
			GAME14::CREDIT::DATA credit;
			GAME14::BET::DATA bet;
			GAME14::BUTTON::DATA max_bet_Button;
			GAME14::MAX_BET_BUTTON::DATA max_betButton;
		};
		DATA Data;
		void setData();
		void setImage();
	public:
		void load();
		DATA& data() { return Data; }
	};
}

