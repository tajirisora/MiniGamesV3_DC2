#pragma once
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
#include"TITLE.h"
#include"HOME.h"
#include"STAGE.h"
#include"RESULT.h"
#include"GAME14.h"
namespace GAME14 {
	class CONTAINER{
	private:
		struct DATA {
			GAME14::TITLE::DATA title;
		};
		DATA Data;
		void setData();
		void setImage();
	public:
		void load();
		DATA& data() { return Data; }
	};
}

