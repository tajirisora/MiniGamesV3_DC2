#pragma once
#include "../MAIN/GAME_BASE.h"
#include "SONGINFO.h"
#include <vector>

namespace GAME09
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
		//ƒRƒ“ƒeƒi
	private:
		class CONTAINER* Container;
	public:
		class CONTAINER* container() {
			return Container;
		}
	public:
		enum SCENE_ID {
			TITLE_ID,
			SELECT_ID,
			STAGE_ID,
			GAME_CLEAR_ID,
			NUM_SCENES
		};
	private:
		class SCENE* Scenes[NUM_SCENES];
		SCENE_ID CurSceneId;
		class RHYTHM_GAME_CONTROLLER* RGCont;
		class BACKGROUND* Back;
		class BANNER* Banner;
		class JACKET* Jacket;
		class FADE* Fade;
		class DETAIL_VIEW* Detail;
		class COMBO* Combo;
		class SCORE* Score;
		class AUTOBUTTON* AutoButton;
		class OPTIONBUTTON* OptionButton;
		class OPTION* Option;
		class SONGTITLE* SongTitle;
		class ACHIEVEMENT* Achievement;

		std::vector<SONGINFO> SongInfos;
	public:
		void changeScene(SCENE_ID sceneId);
		class SCENE* scene(SCENE_ID sceneId) { return Scenes[sceneId]; }
		class RHYTHM_GAME_CONTROLLER* rgCont() { return RGCont; }
		class BACKGROUND* back() { return Back; }
		class JACKET* jacket() { return Jacket; }
		class FADE* fade() { return Fade; }
		class BANNER* banner() { return Banner; }
		class DETAIL_VIEW* detail() { return Detail; }
		class COMBO* combo() { return Combo; }
		class SCORE* score() { return Score; }
		class AUTOBUTTON* autoButton() { return AutoButton; }
		class OPTIONBUTTON* optionButton() { return OptionButton; }
		class OPTION* option() { return Option; }
		class SONGTITLE* songTitle() { return SongTitle; }
		class ACHIEVEMENT* achievement() { return Achievement; }

		std::vector<SONGINFO>& songInfos() { return SongInfos; }
    };
}
