#pragma once
namespace GAME11 {
	struct DICE {
		int num = 0;
		int img = 0;
		int rand = 0;
		bool setflag = false;//�����Ȃ����Ȃ�false�A�ۑ�����Ȃ�true

	};

	typedef struct {
		struct DICE dice[5];
	}DiceSync;
}