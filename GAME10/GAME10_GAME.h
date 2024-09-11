#pragma once
#include"SCENE.h"
#include"PLAYER.h"
class GAME10_GAME
{
//ƒRƒ“ƒeƒi
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		RESULT_ID,
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
	class PLAYER* Player;
public:
	GAME10_GAME();
	~GAME10_GAME();
	void run();
	void changeScene(SCENE_ID SceneId);
};

