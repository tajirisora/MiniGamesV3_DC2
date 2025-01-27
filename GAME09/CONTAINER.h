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
#include "DETAIL_VIEW.h"
#include "COMBO.h"
#include "SCORE.h"
#include "BUTTON.h"
#include "AUTOBUTTON.h"
#include "OPTIONBUTTON.h"
#include "BACKBUTTON.h"
#include "OPTION.h"
#include "SONGTITLE.h"
#include "ACHIEVEMENT.h"
#include "LANE.h"
#include "LOADSONGS.h"
#include "LOADCHART.h"
#include "LOADOPTION.h"
#include "KEYCONFIG.h"
#include "COLOR_PICKER.h"
#include "ADJUST.h"
#include "ADJUSTBUTTON.h"
#include "STARTBUTTON.h"
#include "DIFFICULTYSELECT.h"
#include "DIFFICULTYBUTTON.h"

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
			DETAIL_VIEW::DATA detail;
			COMBO::DATA combo;
			SCORE::DATA score;
			BUTTON::DATA autoButton;
			BUTTON::DATA optionButton;
			BUTTON::DATA backButton;
			BUTTON::DATA adjustButton;
			BUTTON::DATA startButton;
			BUTTON::DATA difficultyButton;
			OPTION::DATA option;
			SONGTITLE::DATA songTitle;
			ACHIEVEMENT::DATA achievement;
			LANE::DATA lane;
			KEYCONFIG::DATA keyConfig;
			LOADOPTION::DATA loadOption;
			COLOR_PICKER::DATA colorPicker;
			AUTOBUTTON::DATA autoButtonImg;
			ADJUST::DATA adjust;
			ADJUSTBUTTON::DATA adjustButtonImg;
			DIFFICULTYSELECT::DATA difficultySelect;
			DIFFICULTYBUTTON::DATA difficultyButtonData;
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