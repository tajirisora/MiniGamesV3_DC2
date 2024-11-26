#pragma once
#include "../MAIN/GAME_BASE.h"
#include "SONGINFO.h"
#include "CHANGEDATA.h"
#include "NOTE.h"
#include <vector>
extern bool EscapeKeyValid;
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
			OPTION_ID,
			STAGE_ID,
			GAME_CLEAR_ID,
			LOADSONGS_ID,
			LOADCHART_ID,
			NUM_SCENES
		};
	private:
		class SCENE* Scenes[NUM_SCENES];
		SCENE_ID CurSceneId;
		class FADE* Fade;
		class CHARTMANAGER* ChartMNG;
		class BANNER* Banner;
		class JACKET* Jacket;
		class BACKGROUND* BackGround;
		class RHYTHM_GAME_CONTROLLER* RGCont;
		class LANE* Lane;
		class SOUNDMANAGER* SoundMNG;
		class KEYCONFIG* KeyConfig;
		class JUDGEMANAGER* JudgeMNG;
		class OPTIONBUTTON* OptionButton;
		class BACKBUTTON* BackButton;
		class LOADOPTION* LoadOption;

		std::vector<SONGINFO> Songs;
		std::vector<NOTE*> Notes;
		std::vector<CHANGEDATA> ChangeDatas;
	public:
		void changeScene(SCENE_ID sceneId);
		void exit();
		class SCENE* scene(SCENE_ID sceneId) { return Scenes[sceneId]; }
		class FADE* fade() { return Fade; }
		class CHARTMANAGER* chartMNG() { return ChartMNG; }
		class BANNER* banner() { return Banner; }
		class JACKET* jacket() { return Jacket; }
		class BACKGROUND* backGround() { return BackGround; }
		class RHYTHM_GAME_CONTROLLER* rgCont() { return RGCont; }
		class LANE* lane() { return Lane; }
		class SOUNDMANAGER* soundMNG() { return SoundMNG; }
		class KEYCONFIG* keyConfig() { return KeyConfig; }
		class JUDGEMANAGER* judgeMNG() { return JudgeMNG; }
		class OPTIONBUTTON* optionButton() { return OptionButton; }
		class BACKBUTTON* backButton() { return BackButton; }
		class LOADOPTION* loadOption() { return LoadOption; }

		std::vector<SONGINFO>& songs() { return Songs; }
		std::vector<NOTE*>& notes() { return Notes; }
		std::vector<CHANGEDATA>& changeDatas() { return ChangeDatas; }
    };
}
