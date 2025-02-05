#pragma once
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include"TITLE.h"
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
#include"PLAYER.h"
#include"BONUS_ANNOUNCE.h"
#include"END_BUTTON.h"
#include"RESULT.h"
#include"GAME14.h"
namespace GAME14 {
	class CONTAINER{
	private:
		struct DATA {
			GAME14::TITLE::DATA title;
			GAME14::STAGE::DATA stage;
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
			GAME14::PLAYER::DATA player;
			GAME14::BONUS_ANNOUNCE::DATA bonus_announce;
			GAME14::BUTTON::DATA endButton;
			GAME14::END_BUTTON::DATA end;
			GAME14::RESULT::DATA result;
		};
		DATA Data;
		void setData();
		void setImage();
	public:
		void load();
		DATA& data() { return Data; }
	};
}

