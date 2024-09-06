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
		Data.title.strPos = VECTOR2((width - Data.title.strSize * strlen(Data.title.str)/2) / 2,
											height / 2);
		Data.title.msg = "click to START...";
		Data.title.msgSize = 50.0f;
		Data.title.msgColor = COLOR(0.0f, 0.0f, 0.0f);
		Data.title.msgPos = VECTOR2((width - Data.title.msgSize * strlen(Data.title.msg) / 2) / 2,
			                        height *3/4);
	}
	void CONTAINER::setImage(){}
}