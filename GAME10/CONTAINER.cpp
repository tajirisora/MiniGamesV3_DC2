#include "CONTAINER.h"
#include "../../libOne/inc/libOne.h"
void CONTAINER::load(){
	setData();
	setImage();
}
void CONTAINER::setImage() {
	Data.title.titleImg = loadImage("..\\main\\assets\\game10\\title.png");
	Data.stage.backImg = loadImage("..\\main\\assets\\game10\\title.png");
	Data.result.resultImg = loadImage("..\\main\\assets\\game10\\title.png");
}
void CONTAINER::setData(){
	Data.title.imgPos.x = 0;
	Data.title.imgPos.y = 0;

	Data.stage.imgPos.x = 0;
	Data.stage.imgPos.y = 0;
	Data.stage.opx = 300;
	Data.stage.opy = 300;
	Data.stage.My = 150;
	for (int i = 0; i < 4; i++) {
		Data.stage.Lanes[i].Pos.y = Data.stage.opy + Data.stage.My * i;
		Data.stage.Lanes[i].Pos.x = 300;
	}

	Data.result.imgPos.x = 0;
	Data.result.imgPos.y = 0;
}