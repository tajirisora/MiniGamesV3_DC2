#pragma once

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			//TITLE::DATA title;
			//MUSICSELECT::DATA select;
			//STAGE::DATA stage;
			//GAME_CLEAR::DATA gameClear;
			//NOTE::DATA note;
			//LONGBELT::DATA longBelt;
			//RHYTHM_GAME_CONTROLLER::DATA rgCont;
			//SOUNDMANAGER::DATA sound;
			//CHARTMANAGER::DATA chart;
			//JUDGEMANAGER::DATA judge;
			//BEAM::DATA beam;
			//BANNER::DATA banner;
			//BACKGROUND::DATA back;
			//JACKET::DATA jacket;
			//FADE::DATA fade;
			//DETAIL_VIEW::DATA detail;
			//COMBO::DATA combo;
			//SCORE::DATA score;
			//AUTOBUTTON::DATA autoButton;
			//OPTIONBUTTON::DATA optionButton;
			//OPTION::DATA option;
			//SONGTITLE::DATA songTitle;
			//ACHIEVEMENT::DATA achievement;
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