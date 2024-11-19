#include"string.h"
#include "CONTAINER.h"
namespace GAME14 {
	void CONTAINER::load() {
		setData();
		setImage();
	}
	void CONTAINER::setData(){
		
		Data.title.backColor = COLOR(125.0f, 125.0f, 125.0f);
		Data.title.str = "スロカスシミュレター";
		Data.title.strSize = 150.0f;
		Data.title.strColor = COLOR(0.0f, 0.0f, 0.0f);
		Data.title.strPos = VECTOR2((width - Data.title.strSize * strlen(Data.title.str)/2) / 2.0f,
											height / 2.0f);
		Data.title.msg = "click to START...";
		Data.title.msgSize = 50.0f;
		Data.title.msgColor = COLOR(0.0f, 0.0f, 0.0f);
		Data.title.msgPos = VECTOR2((width - Data.title.msgSize * strlen(Data.title.msg) / 2) / 2.0f,
			                        height *3.0f/4.0f);
		
		float kyoutaiW = 1200;
		float kyoutaiH = height;
		float kyoutaiX = (width - kyoutaiW) / 2;
		float kyoutaiY = 0;
		float reeloffset = 350;
		float reelW = 250;
		float reelH = 400;
		Data.left.pos = VECTOR2((width - reelW * 3) / 2,kyoutaiY+reeloffset);
		Data.middle.pos = VECTOR2(Data.left.pos.x + reelW, Data.left.pos.y);
		Data.right.pos = VECTOR2(Data.left.pos.x + reelW*2, Data.left.pos.y);
		Data.left.color = COLOR(255, 0, 0);

		Data.stop.numButton = 3;
		Data.stop.offset = 150.0f;
		Data.stopButton.r = (100.0f * 3.0f / 5.0f)/2.0f;
		Data.stopButton.basePos = VECTOR2(width / 2.0f, 960.0f);
		Data.stopButton.areaColor = COLOR(0.0f, 0.0f, 255.0f);
		Data.stopButton.filter = COLOR(255.0f, 255.0f, 255.0f,80.0f);
		Data.stopButton.imgSize = 1.0f;
		Data.stopButton.sistemFlag = false;
		Data.stopButton.drawFlag = false;
		Data.stopButton.filterFlag = false;
		Data.stop.imgAlterSize = 0.9f;

		Data.leverButton.basePos = VECTOR2(width / 2.0f- Data.stop.offset*2.50f, 960.0f);
		Data.leverButton.areaColor = COLOR(255.0f, 0.0f, 0.0f);
		Data.leverButton.filter = COLOR(255.0f, 255.0f, 255.0f, 80.0f);
		Data.leverButton.sistemFlag = false;
		Data.leverButton.drawFlag = false;
		Data.leverButton.filterFlag = false;
		Data.leverButton.r = (100.0f*4.0f/6.0f)/2.0f;
		Data.lever.moveDis = Data.leverButton.r / 3.50f;

		Data.lottery.waitTime = 0.5f;
	}
	void CONTAINER::setImage(){
		Data.stopButton.img = 0;
		/*Data.control.img[0] = loadImage("../MAIN\\assets\\game14\\bonus.1.png");
		Data.control.img[1] = loadImage("../MAIN\\assets\\game14\\bonus.2.png");
		Data.control.img[2] = loadImage("../MAIN\\assets\\game14\\bar.3.png");
		Data.control.img[3] = loadImage("../MAIN\\assets\\game14\\replay.4.png");
		Data.control.img[4] = loadImage("../MAIN\\assets\\game14\\watermelonA.5.png");
		Data.control.img[5] = loadImage("../MAIN\\assets\\game14\\watermelonB.6.png");
		Data.control.img[6] = loadImage("../MAIN\\assets\\game14\\cherry.7.png");
		Data.control.img[7] = loadImage("../MAIN\\assets\\game14\\bellA.8.png");
		Data.control.img[8] = loadImage("../MAIN\\assets\\game14\\bellB.9.png");
		*/


	}
}