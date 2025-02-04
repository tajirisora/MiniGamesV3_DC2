#pragma once
#include "SCENE.h"
#include "../../libOne/inc/libOne.h"
class SELECT :public SCENE
{
public:
	struct DATA {
		VECTOR2 ImgPos;
		int backImg = 0;
		enum select{
			HANDGUN,
			SHOTGUN,
			MISSILE,
			SKIP,
			SELECT_NUM
		};
		int SELECT_NOW = HANDGUN;
		int weaponImg[SELECT_NUM];
		VECTOR2 textPos;
		VECTOR2 skipPos;
		int skipTextSize;
		COLOR selectColor;
		COLOR noSelectColor;
		const char* Moji[4];
		const char* noGetMoji[3];
		int textMy;
		VECTOR2 weaponImgPos;
		int weaponImgMy;
		bool getFlag[SELECT_NUM];
		bool selectFlag;
		int selectMoveSound;
		int selectSound;

		int upSound;
	};
private:
	DATA Select;
public:
	SELECT(class GAME10_GAME* game);
	~SELECT();
	void create();
	void init();
	void update();
	void draw();
	void sound();
	void nextScene();

};

