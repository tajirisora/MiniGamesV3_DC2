#pragma once
#include "../MAIN/GAME_BASE.h"
#include "canvasResize.h"

namespace GAME07
{
	class GAME :
		public GAME_BASE
	{
		//�R���e�i
	private:
		class CONTAINER* Container;
	public:
		class CONTAINER* container() {
			return Container;
		}
	public:
		enum SCENE_ID {
			TITLE_ID,
			STAGE_ID,
			PAUSE_ID,
			RESULT_ID,
			HELP_ID,
			NUM_SCENES
		};
	private:
		class SCENE* Scenes[NUM_SCENES];
		SCENE_ID CurSceneId;
		class BACKGROUND* BackGround;
		class PHYSICS_ENGINE* Physics;
		class BOX* Box;
		class CLOUD* Cloud;
		class NEXT* Next;
		class SCORE* Score;
		class DRAW_NUM* DrawNum;
		class FRUITS_BUBBLES* FruitsBubbles;
		class CURTAIN* Curtain;
		class TRANSITION* Transition;
		class COMMAND* Command;
		class EVOLUTIONARY_CIRCLE* ECircle;
		class READYGO* ReadyGo;
		class CRACKER* Cracker;
		class SOUNDMNG* SoundMNG;
	public:
		class SCENE* getScene(SCENE_ID sceneId) { return Scenes[sceneId]; }
		class BACKGROUND* backGround() { return BackGround; }
		class PHYSICS_ENGINE* physics() { return Physics; }
		class BOX* box() { return Box; }
		class CLOUD* cloud() { return Cloud; }
		class NEXT* next() { return Next; }
		class SCORE* score() { return Score; }
		class DRAW_NUM* drawNum() { return DrawNum; }
		class FRUITS_BUBBLES* fruitsBubbles() { return FruitsBubbles; }
		class CURTAIN* curtain() { return Curtain; }
		class TRANSITION* transition() { return Transition; }
		class COMMAND* command() { return Command; }
		class EVOLUTIONARY_CIRCLE* eCircle() { return ECircle; }
		class READYGO* readyGo() { return ReadyGo; }
		class CRACKER* cracker() { return Cracker; }
		class SOUNDMNG* soundMNG() { return SoundMNG; }
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
		void changeScene(SCENE_ID sceneId);
		void returnScene(SCENE_ID sceneId);

		void backToMenu();
    };
}
