#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"RESULT.h"
#include"PLAYER.h"
class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		STAGE::DATA stage;
		RESULT::DATA result;
	};
	DATA Data;
public:
	void load();
	void setImage();
	void setData();
	const TITLE::DATA& title() { return Data.title; }
	const STAGE::DATA& stage() { return Data.stage; }
	const RESULT::DATA& result() { return Data.result; }
};

