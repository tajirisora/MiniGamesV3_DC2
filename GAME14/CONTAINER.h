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
#include"REEL.h"
#include"LOTTERY.h"
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
			GAME14::REEL::DATA left;
			GAME14::REEL::DATA middle;
			GAME14::REEL::DATA right;
			GAME14::LOTTERY::DATA lottery;
		};
		DATA Data;
		void setData();
		void setImage();
	public:
		void load();
		DATA& data() { return Data; }
	};
}

