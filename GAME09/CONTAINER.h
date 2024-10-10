#pragma once
#include "TITLE.h"
#include "MUSICSELECT.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "NOTE.h"
#include "LONGBELT.h"
#include "RHYTHM_GAME_CONTROLLER.h"
#include "SOUNDMANAGER.h"
#include "CHARTMANAGER.h"
#include "JUDGEMANAGER.h"
//#include "BEAM.h"
#include "BANNER.h"
#include "BACKGROUND.h"
#include "JACKET.h"
#include "FADE.h"
//#include "DETAIL_VIEW.h"
//#include "COMBO.h"
//#include "SCORE.h"
//#include "AUTOBUTTON.h"
//#include "OPTIONBUTTON.h"
#include "OPTION.h"
//#include "SONGTITLE.h"
//#include "ACHIEVEMENT.h"
#include "LANE.h"
#include "LOADSONGS.h"
#include "LOADCHART.h"
#include "KEYCONFIG.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			MUSICSELECT::DATA select;
			STAGE::DATA stage;
			GAME_CLEAR::DATA gameClear;
			LOADSONGS::DATA loadSongs;
			LOADCHART::DATA loadChart;
			NOTE::DATA note;
			LONGBELT::DATA longBelt;
			RHYTHM_GAME_CONTROLLER::DATA rgCont;
			SOUNDMANAGER::DATA sound;
			CHARTMANAGER::DATA chartMNG;
			JUDGEMANAGER::DATA judge;
			//BEAM::DATA beam;
			BANNER::DATA banner;
			BACKGROUND::DATA back;
			JACKET::DATA jacket;
			FADE::DATA fade;
			//DETAIL_VIEW::DATA detail;
			//COMBO::DATA combo;
			//SCORE::DATA score;
			//AUTOBUTTON::DATA autoButton;
			//OPTIONBUTTON::DATA optionButton;
			OPTION::DATA option;
			//SONGTITLE::DATA songTitle;
			//ACHIEVEMENT::DATA achievement;
			LANE::DATA lane;
			KEYCONFIG::DATA keyConfig;
		};
		DATA Data;
	public:
		void load();
		void setData();
		void loadGraphic();
		void loadSounds();
		const DATA& data() {
			return Data;
		}
	};
}