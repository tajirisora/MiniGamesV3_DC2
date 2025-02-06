#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME12.h"
namespace GAME12
{
	int GAME::create()
	{
		//title
		background = loadImage("..\\main\\assets\\game12\\image\\gakkou.jpg");
		//init
		teachimage = loadImage("..\\main\\assets\\game12\\image\\jyugyouF.png");
		//wait
		pretwoimage = loadImage("..\\main\\assets\\game12\\image\\gakuseiM.png");
		twoimage = loadImage("..\\main\\assets\\game12\\image\\daigakuM.png");
		preoneimage = loadImage("..\\main\\assets\\game12\\image\\obasannF.png");
		oneimage = loadImage("..\\main\\assets\\game12\\image\\baasannF.png");
		//play
		back1 = loadImage("..\\main\\assets\\game12\\image\\back1.jpg");
		back2 = loadImage("..\\main\\assets\\game12\\image\\back2.jpg");
		back3 = loadImage("..\\main\\assets\\game12\\image\\back3.jpg");
		back4 = loadImage("..\\main\\assets\\game12\\image\\kami.jpg");
		back5 = loadImage("..\\main\\assets\\game12\\image\\data.jpg");
		missimage = loadImage("..\\main\\assets\\game12\\image\\miss.png");
		//over
		overback = loadImage("..\\main\\assets\\game12\\image\\over.jpg");
		overmale = loadImage("..\\main\\assets\\game12\\image\\gameoverM.png");
		overfemale = loadImage("..\\main\\assets\\game12\\image\\gameoverF.png");
		//clear
		clearback = loadImage("..\\main\\assets\\game12\\image\\clearback.jpg");
		clearmale = loadImage("..\\main\\assets\\game12\\image\\clearM.png");
		clearfemale = loadImage("..\\main\\assets\\game12\\image\\clearF.png");

		//bgm
		//title
		backbgm = loadSound("..\\main\\assets\\game12\\sound\\back.wav");
		//play
		playbgm = loadSound("..\\main\\assets\\game12\\sound\\play.wav");
		correctsound = loadSound("..\\main\\assets\\game12\\sound\\correct.wav");
		incorrectsound = loadSound("..\\main\\assets\\game12\\sound\\incorrect.wav");
		//over
		oversound = loadSound("..\\main\\assets\\game12\\sound\\over.wav");
		//end
		endsound = loadSound("..\\main\\assets\\game12\\sound\\end.wav");
		return 0;
	}

	void GAME::destroy()
	{

	}

	void GAME::proc()
	{
		//�V�[���؂�ւ�
		if (State == TITLE)title();
		else if (State == INIT)init();
		else if (State == WAIT)wait();
		else if (State == PLAY1)play1();
		else if (State == PLAY2)play2();
		else if (State == PLAY3)play3();
		else if (State == PLAY4)play4();
		else if (State == PLAY5)play5();
		else if (State == OVER1)over1();
		else if (State == OVER2)over2();
		else if (State == OVER3)over3();
		else if (State == OVER4)over4();
		else if (State == OVER5)over5();
		else if (State == END)end();
	}
	void GAME::randomnum() {
		rnum = 0;
		srand((unsigned)time(NULL));
		for (int i = 0; i < 15; i++) {
			rnum = rand() % Qnumber;
			num[i] = rnum;
			for (int j = 0; j < i; j++) {
				if (num[j] == rnum) {
					i--;
					break;
				}
			}
		}
	}
	
	INPUT_CODE GAME::gettriggerkeycode() {
		for (int i = (int)KEY_A; i <= (int)KEY_ENTER; i++) {
			if (isTrigger((INPUT_CODE)i)) {
				return (INPUT_CODE)i;
			}
		}
		return (INPUT_CODE)0;
	}
	std::map<INPUT_CODE, std::string>KeytoAlphabet = {
		{KEY_Q, "q"},{KEY_W, "w"},{KEY_E, "e"},
		{KEY_R, "r"},{KEY_T, "t"},{KEY_Y, "y"},
		{KEY_U, "u"},{KEY_I, "i"},{KEY_O, "o"},
		{KEY_P, "p"},{KEY_A, "a"},{KEY_S, "s"},
		{KEY_D, "d"},{KEY_F, "f"},{KEY_G, "g"},
		{KEY_H, "h"},{KEY_J, "j"},{KEY_K, "k"},
		{KEY_L, "l"},{KEY_Z, "z"},{KEY_X, "x"},
		{KEY_C, "c"},{KEY_V, "v"},{KEY_B, "b"},
		{KEY_N, "n"},{KEY_M, "m"},{KEY_SPACE, " "},
		{KEY_ENTER, "@"},
	};
	
	std::map<std::string, std::string> wardmap = {
		{"ka", "��"},{"ki", "��"},{"ku", "��"},
		{"ke", "��" }, {"ko", "��" },{"sa", "��" }, 
		{"si", "��"},{"shi", "��"} ,{"su", "��"},
		{"se", "��"}, {"so", "��"},{"ta", "��"},
		{"ti", "��"},{"chi", "��"}, {"tu", "��"},
		{"tsu", "��"}, {"te", "��"},{"to", "��"},
		{"na", "��"}, {"ni", "��"},{"nu", "��"},
		{"ne", "��"},{"no", "��"},{"ha", "��"},
		{"hi", "��"},{"fu", "��"}, {"hu", "��"},
		{"he", "��"}, {"ho", "��"},{"ma", "��"},
		{"mi", "��"},{"mu", "��"}, {"me", "��"},
		{"mo", "��"},{"ya", "��"}, {"yu", "��"},
		{"yo", "��"},{"ra", "��"}, {"ri", "��"},
		{"ru", "��"}, {"re", "��"},{"ro", "��"},
		{"wa", "��"}, {"wo", "��"},{"nn", "��"},
		{"nn", "��"},{"ga", "��"}, {"gi", "��"},
		{"gu", "��"}, {"ge", "��"},{"go", "��"},
		{"za", "��"}, {"ji", "��"},{"zi", "��"},
		{"zu", "��"},{"ze", "��"}, {"zo", "��"},
		{"da", "��"}, {"di", "��"},{"du", "��"},
		{"de", "��"},{"do", "��"},{"ba", "��"},
		{"bi", "��"},{"bu", "��"}, {"be", "��"},
		{"bo", "��"},{"pa", "��"}, {"pi", "��"},
		{"pu", "��"}, {"pe", "��"},{"po", "��"},
		{"kya", "����"}, {"kyu", "����"},{"kyo", "����"},
		{"sya", "����"}, {"sha", "����"},{"syu", "����"},
		{"shu", "����"},{"syo", "����"}, {"sho", "����"},
		{"tya", "����"}, {"cya", "����"},{"cha", "����"}, 
		{"tyu", "����"},{"cyu", "����"}, {"chu", "����"},
		{"tyo", "����"},{"cyo", "����"},{"cho", "����"},
		{"nya", "�ɂ�"}, {"nyu", "�ɂ�"},{"nyo", "�ɂ�"},
		{"hya", "�Ђ�"}, {"hyu", "�Ђ�"},{"hyo", "�Ђ�"},
		{"mya", "�݂�"}, {"myu", "�݂�"},{"myo", "�݂�"},
		{"rya", "���"}, {"ryu", "���"},{"ryo", "���"},
		{"gya", "����"}, {"gyu", "����"},{"gyo", "����"},
		{"ja", "����"}, {"jya", "����"},{"zya", "����"},
		{"ju", "����"},{"jyu", "����"}, {"zyu", "����"},
		{"jo", "����"}, {"jyo", "����"},{"zyo", "����"},
		{"bya", "�т�"}, {"byu", "�т�"},{"byo", "�т�"},
		{"pya", "�҂�"}, {"pyu", "�҂�"},{"pyo", "�҂�"},
		{"xtsu", "��"}, {"ltsu", "��"},{"xa", "��"},
		{"la", "��"},{"xi", "��"}, {"li", "��"},
		{"xu", "��"}, {"lu", "��"},{"xe", "��"},
		{"le", "��"},{"xo", "��"}, {"lo", "��"},
		{"xya", "��"}, {"lya", "��"},{"xyu", "��"},
		{"lyu", "��"},{"xyo", "��"}, {"lyo", "��"},
		{"xwa", "��"}, {"lwa", "��"},

		{"kka", "����"}, {"kki", "����"},
		{"kku", "����"}, {"kke", "����"},
		{"kko", "����"},
		{"ssa", "����"}, {"ssi", "����"},
		{"sshi","����"}, {"ssu", "����"},
		{"sse", "����"}, {"sso", "����"},
		{"tta", "����"}, {"tti", "����"},
		{"cchi", "����"}, {"ttu", "����"},
		{"ttsu", "����"}, {"tte", "����"},
		{"tto", "����"},
		{"nna", "����"}, {"nni", "����"},
		{"nnu", "����"}, {"nne", "����"},
		{"nno", "����"},
		{"hha", "����"}, {"hhi", "����"},
		{"ffu", "����"}, {"hhu", "����"},
		{"hhe", "����"}, {"hho", "����"},
		{"mma", "����"}, {"mmi", "����"},
		{"mmu", "����"}, {"mme", "����"},
		{"mmo", "����"},
		{"yya", "����"}, {"yyu", "����"},
		{"yyo", "����"},
		{ "rra", "����" }, { "rri", "����" },
		{ "rru", "����" }, { "rre", "����" },
		{ "rro", "����" },
		{ "wwa", "����" }, { "wwo", "����" },
		{ "gga", "����" }, { "ggi", "����" },
		{ "ggu", "����" }, { "gge", "����" },
		{ "ggo", "����" },
		{ "zza", "����" }, { "jji", "����" },
		{ "zzi", "����" }, { "zzu", "����" },
		{ "zze", "����" }, { "zzo", "����" },
		{ "dda", "����" }, { "ddi", "����" },
		{ "ddu", "����" }, { "dde", "����" },
		{ "ddo", "����" },
		{ "bba", "����" }, { "bbi", "����" },
		{ "bbu", "����" }, { "bbe", "����" },
		{ "bbo", "����" },
		{ "ppa", "����" }, { "ppi", "����" },
		{ "ppu", "����" }, { "ppe", "����" },
		{ "ppo", "����" },
		{ "kkya", "������" }, { "kkyu", "������" },
		{ "kkyo", "������" },
		{ "ssya", "������" }, { "ssha", "������" },
		{ "ssyu", "������" }, { "sshu", "������" },
		{ "ssyo", "������" }, { "ssho", "������" },
		{ "ttya", "������" }, { "ccya", "������" },
		{ "ccha", "������" }, { "ttyu", "������" },
		{ "ccyu", "������" }, { "cchu", "������" },
		{ "ttyo", "������" }, { "ccyo", "������" },
		{ "ccho", "������" },
		{ "hhya", "���Ђ�" }, { "hhyu", "���Ђ�" },
		{ "hhyo", "���Ђ�" },
		{ "mmya", "���݂�" }, { "mmyu", "���݂�" },
		{ "mmyo", "���݂�" },
		{ "rrya", "�����" }, { "rryu", "�����" },
		{ "rryo", "�����" },
		{ "ggya", "������" }, { "ggyu", "������" },
		{ "ggyo", "������" },
		{ "jja", "������" }, { "jjya", "������" },
		{ "zzya", "������" }, { "jju", "������" },
		{ "jjyu", "������" }, { "zzyu", "������" },
		{ "jjo", "������" }, { "jjyo", "������" },
		{ "zzyo", "������" },
		{ "bbya", "���т�" }, { "bbyu", "���т�" },
		{ "bbyo", "���т�" },
		{ "ppya", "���҂�" }, { "ppyu", "���҂�" },
		{ "ppyo", "���҂�" },
		{ "xtsu", "��" }, { "ltsu", "��" },
		{ "xxa", "����" }, { "lla", "����" },
		{ "xxi", "����" }, { "lli", "����" },
		{ "xxu", "����" }, { "llu", "����" },
		{ "xxe", "����" }, { "lle", "����" },
		{ "xxo", "����" }, { "llo", "����" },
		{ "xxya", "����" }, { "llya", "����" },
		{ "xxyu", "����" }, { "llyu", "����" },
		{ "xxyo", "����" }, { "llyo", "����" },
		{ "xxwa", "����" }, { "llwa", "����" },
		{ "a", "��" }, { "i", "��" }, { "u", "��" },
		{ "e", "��" }, { "o", "��" },
	};

	void GAME::recordInputToKana() {

		INPUT_CODE code = gettriggerkeycode();

		if (code == (INPUT_CODE)0) {
			return;
		}

		if (KeytoAlphabet.find(code) != KeytoAlphabet.end()) {
			std::string keyStr = KeytoAlphabet[code];
			stop = 1;
			if (keyStr != "@" && stop == 1) {
				
				currentInput += keyStr;
				stop = 0;
				if (!currentInput.empty()) {

					if (wardmap.find(currentInput) != wardmap.end()) {
						ch += wardmap[currentInput];
						currentInput.clear();
					}
				}
			}

			else if (keyStr == "@") {
				flag = 1;
				return;
			}
		}
	}
	
	void GAME::title() {
		//�`��--------------------------------------------------
		clear(120);
		//�e�L�X�g���
		playSound(backbgm);
		setVolume(backbgm, -4000);
		rectMode(CORNER);
		image(background, 0, 0);
		fill(255, 0, 0);
		textSize(200);
		text("��������", 625, 270);
		fill(0);
		textSize(75);
		text("�N���b�N�ŃQ�[���X�^�[�g", 600, 450);
		text("Enter�Ń��j���[�ɖ߂�", 650, 550);
		//�V�[���؂�ւ�-----------------------------------------

		if (isTrigger(MOUSE_LBUTTON)) {
			//���̃V�[�P���X
			State = INIT;
			return;
		}
		//���j���[�ɖ߂�-----------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}

	void GAME::init() {
		clear(240);
		rectMode(CENTER);
		image(teachimage, 1500, 700);
		flag = 0;
		number = 0;
		set = 0;
		curtime = 30.0;
		mflag = 0.0;
		stop = 0;
		count = 0;
		ch.clear();
		currentInput.clear();
		fill(200, 0, 0);
		textSize(60);
		text("�\�����ꂽ�����̓ǂ݂�30�b�ȓ��œ��Ă�", 525, 125);
		text("�L�[�{�[�h�œ��́@�m���ENTER", 600, 200);
		text("15�␳���ŃN���A�I", 750, 275);
		fill(0, 0, 200);
		text("Q", 700, 600);
		text("W", 700, 700);
		text("E", 700, 800);
		text("R", 700, 900);
		text("T", 700, 1000);
		fill(0);
		text("������V�т܂����H", 575, 500);
		text("��2��", 800, 600);
		text("2��", 800, 700);
		text("��1��", 800, 800);
		text("1��", 800, 900);
		text("�H�H�H", 800, 1000);
		if (isTrigger(KEY_Q)) {
			set = 1;
			State = WAIT;
			return;
		}
		else if (isTrigger(KEY_W)) {
			set = 2;
			State = WAIT;
			return;
		}
		else if (isTrigger(KEY_E)) {
			set = 3;
			State = WAIT;
			return;
		}
		else if (isTrigger(KEY_R)) {
			set = 4;
			State = WAIT;
			return;
		}
		else if (isTrigger(KEY_T)) {
			set = 5;
			State = WAIT;
			return;
		}
	}

	void GAME::wait() {
		clear(240);
		textSize(60);
		rectMode(CORNER);
		image(background, 0, 0);
		rectMode(CENTER);
		fill(200, 0, 0);
		if (set == 1) {
			image(pretwoimage, 1600, 650);
			text("��2���ŊJ�n", 725, 200);
		}
		else if (set == 2) {
			image(twoimage, 1600, 650);
			text("2���ŊJ�n", 725, 200);
		}
		else if (set == 3) {
			image(preoneimage, 1600, 650);
			text("��1���ŊJ�n", 725, 200);
		}
		else if (set == 4) {
			image(oneimage, 1600, 650);
			text("1���ŊJ�n", 725, 200);
		}
		else if (set == 5) {
			text("��Ǌ����ɒ���", 725, 200);
		}
		fill(0);
		text("�G���^�[�L�[�ŃX�^�[�g", 575, 450);
		text("�X�y�[�X�L�[�Ŗ߂�", 625, 550);
		if (isTrigger(KEY_ENTER) && set == 1) {
			clear(200);
			randomnum();
			stopSound(backbgm);
			playSound(playbgm);
			setVolume(playbgm, -4000);
			State = PLAY1;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 2) {
			clear(200);
			randomnum();
			stopSound(backbgm);
			playSound(playbgm);
			setVolume(playbgm, -4000);
			State = PLAY2;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 3) {
			clear(200);
			randomnum();
			stopSound(backbgm);
			playSound(playbgm);
			setVolume(playbgm, -4000);
			State = PLAY3;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 4) {
			clear(200);
			randomnum();
			stopSound(backbgm);
			playSound(playbgm);
			setVolume(playbgm, -4000);
			State = PLAY4;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 5) {
			clear(200);
			randomnum();
			stopSound(backbgm);
			playSound(playbgm);
			setVolume(playbgm, -4000);
			State = PLAY5;
			return;
		}
		else if (isTrigger(KEY_SPACE)) {
			clear(200);
			State = INIT;
			return;
		}
	}
	void GAME::draw1(int snum) {
		rectMode(CORNER);
		image(back1, 0, 0);
		fill(0);
		textSize(200);
		text((let)+pretwoWord[snum][0], 550, 300);
		fill(40);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			fill(0);
			textSize(100);
			text(ch.c_str(), 600, 800);
			fill(40);
			textSize(50);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(50);
		text("�Q�[���I���@���N���b�N", 1350, 200);
		if (20 < curtime) {
			fill(50, 0, 0);
		}
		else if (10 < curtime) {
			fill(100, 0, 0);
		}
		else {
			fill(200, 0, 0);
		}
		print(curtime);
		fill(0);
		text("����", 0, 100);
		text((let)+count, 200, 100);
	}
	void GAME::draw2(int snum) {
		rectMode(CORNER);
		image(back2, 0, 0);
		fill(0);
		textSize(200);
		text((let)+twoWord[snum][0], 550, 300);
		fill(40);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			fill(0);
			textSize(100);
			text(ch.c_str(), 600, 800);
			fill(40);
			textSize(50);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(50);
		text("�Q�[���I���@���N���b�N", 1350, 200);
		if (20 < curtime) {
			fill(50, 0, 0);
		}
		else if (10 < curtime) {
			fill(100, 0, 0);
		}
		else {
			fill(200, 0, 0);
		}
		print(curtime);
		fill(0);
		text("����", 0, 100);
		text((let)+count, 200, 100);
	}
	void GAME::draw3(int snum) {
		rectMode(CORNER);
		image(back3, 0, 0);
		fill(0);
		textSize(200);
		text((let)+preoneWord[snum][0], 550, 300);
		fill(40);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			fill(0);
			textSize(100);
			text(ch.c_str(), 600, 800);
			fill(40);
			textSize(50);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(50);
		text("�Q�[���I���@���N���b�N", 1350, 200);
		if (20 < curtime) {
			fill(50, 0, 0);
		}
		else if (10 < curtime) {
			fill(100, 0, 0);
		}
		else {
			fill(200, 0, 0);
		}
		print(curtime);
		fill(0);
		text("����", 0, 100);
		text((let)+count, 200, 100);
	}
	void GAME::draw4(int snum) {
		rectMode(CORNER);
		image(back4, 0, 0);
		fill(0);
		textSize(200);
		text((let)+oneWord[snum][0], 550, 300);
		fill(40);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			fill(0);
			textSize(100);
			text(ch.c_str(), 600, 800);
			fill(40);
			textSize(50);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(50);
		text("�Q�[���I���@���N���b�N", 1350, 200);
		if (20 < curtime) {
			fill(50, 0, 0);
		}
		else if (10 < curtime) {
			fill(100, 0, 0);
		}
		else {
			fill(200, 0, 0);
		}
		print(curtime);
		fill(0);
		text("����", 0, 100);
		text((let)+count, 200, 100);
	}
	void GAME::draw5(int snum) {
		rectMode(CORNER);
		image(back5, 0, 0);
		fill(0);
		textSize(200);
		text((let)+dontknowWord[snum][0], 550, 300);
		fill(40);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			fill(0);
			textSize(100);
			text(ch.c_str(), 600, 800);
			fill(40);
			textSize(50);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(50);
		text("�Q�[���I���@���N���b�N", 1350, 600);
		if (20 < curtime) {
			fill(50, 0, 0);
		}
		else if (10 < curtime) {
			fill(100, 0, 0);
		}
		else {
			fill(200, 0, 0);
		}
		print(curtime);
		fill(0);
		text("����", 0, 100);
		text((let)+count, 200, 100);
	}

	void GAME::play1() {
		clear(200);
		curtime -= delta;
		draw1(num[number]);
		if (flag != 1) {
			recordInputToKana();
		}
		if (flag == 1 && ch == pretwoWord[num[number]][1]) {
			playSound(correctsound);
			setVolume(correctsound, -4000);
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != pretwoWord[num[number]][1]) {
			if (mflag != 1) {
				playSound(incorrectsound);
				setVolume(incorrectsound, -3000);
				mflag = 1;
			}
			else if (mflag == 1) {
				rectMode(CENTER);
				image(missimage, 990, 540);
				fill(0);
				text("SPACE�ő��s", 500, 650);
				if (isTrigger(KEY_SPACE)) {
					ch.clear();
					currentInput.clear();
					flag = 0;
					mflag = 0.0;
				}
			}
		}

		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			stopSound(playbgm);
			playSound(oversound);
			setVolume(oversound, -4000);
			State = OVER1;
		}
		if (count == 15) {
			stopSound(playbgm);
			playSound(endsound);
			setVolume(endsound, -4000);
			State = END;
		}
	}

	void GAME::play2() {
		clear(200);

		curtime -= delta;
		draw2(num[number]);
		if (flag != 1) {
			recordInputToKana();
		}
		if (flag == 1 && ch == twoWord[num[number]][1]) {
			playSound(correctsound);
			setVolume(correctsound, -4000);
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != twoWord[num[number]][1]) {
			if (mflag != 1) {
				playSound(incorrectsound);
				setVolume(incorrectsound, -3000);
				mflag = 1;
			}
			else if (mflag == 1) {
				rectMode(CENTER);
				image(missimage, 990, 540);
				fill(0);
				text("SPACE�ő��s", 500, 650);
				if (isTrigger(KEY_SPACE)) {
					ch.clear();
					currentInput.clear();
					flag = 0;
					mflag = 0.0;
				}
			}
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			stopSound(playbgm);
			playSound(oversound);
			setVolume(oversound, -4000);
			State = OVER2;
		}
		if (count == 15) {
			stopSound(playbgm);
			playSound(endsound);
			setVolume(endsound, -4000);
			State = END;
		}
	}
	void GAME::play3() {
		clear(200);
		curtime -= delta;
		draw3(num[number]);
		if (flag != 1) {
			recordInputToKana();
		}
		if (flag == 1 && ch == preoneWord[num[number]][1]) {
			playSound(correctsound);
			setVolume(correctsound, -4000);
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();

		}
		else if (flag == 1 && ch != preoneWord[num[number]][1]) {
			if (mflag != 1) {
				playSound(incorrectsound);
				setVolume(incorrectsound, -3000);
				mflag = 1;
			}
			else if (mflag == 1) {
				rectMode(CENTER);
				image(missimage, 990, 540);
				fill(0);
				text("SPACE�ő��s", 500, 650);
				if (isTrigger(KEY_SPACE)) {
					ch.clear();
					currentInput.clear();
					flag = 0;
					mflag = 0.0;
				}
			}
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			stopSound(playbgm);
			playSound(oversound);
			setVolume(oversound, -4000);
			State = OVER3;
		}
		if (count == 15) {
			stopSound(playbgm);
			playSound(endsound);
			setVolume(endsound, -4000);
			State = END;
		}
	}
	void GAME::play4() {
		clear(200);

		curtime -= delta;
		draw4(num[number]);
		if (flag != 1) {
			recordInputToKana();
		}
		if (flag == 1 && ch == oneWord[num[number]][1]) {
			playSound(correctsound);
			setVolume(correctsound, -4000);
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != preoneWord[num[number]][1]) {
			if (mflag != 1) {
				playSound(incorrectsound);
				setVolume(incorrectsound, -3000);
				mflag = 1;
			}
			else if (mflag == 1) {
				rectMode(CENTER);
				image(missimage, 990, 540);
				fill(0);
				text("SPACE�ő��s", 500, 650);
				if (isTrigger(KEY_SPACE)) {
					ch.clear();
					currentInput.clear();
					flag = 0;
					mflag = 0.0;
				}
			}
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			stopSound(playbgm);
			playSound(oversound);
			setVolume(oversound, -4000);
			State = OVER4;
		}
		if (count == 15) {
			stopSound(playbgm);
			playSound(endsound);
			setVolume(endsound, -4000);
			State = END;
		}
	}
	void GAME::play5() {
		clear(200);
		curtime -= delta;
		draw5(num[number]);
		if (flag != 1) {
			recordInputToKana();
		}
		if (flag == 1 && ch == dontknowWord[num[number]][1]) {
			playSound(correctsound);
			setVolume(correctsound, -4000);
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != dontknowWord[num[number]][1]) {
			if (mflag != 1) {
				playSound(incorrectsound);
				setVolume(incorrectsound, -3000);
				mflag = 1;
			}
			else if (mflag == 1) {
				rectMode(CENTER);
				image(missimage, 990, 540);
				fill(0);
				text("SPACE�ő��s", 500, 650);
				if (isTrigger(KEY_SPACE)) {
					ch.clear();
					currentInput.clear();
					flag = 0;
					mflag = 0.0;
				}
			}
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			stopSound(playbgm);
			playSound(oversound);
			setVolume(oversound, -4000);
			State = OVER5;
		}
		if (count == 15) {
			stopSound(playbgm);
			playSound(endsound);
			setVolume(endsound, -4000);
			State = END;
		}
	}
	void GAME::over1() {
		clear(0);
		rectMode(CORNER);
		image(overback, 0, 0);
		rectMode(CENTER);
		image(overmale, 200, 600);
		image(overfemale, 1700, 600);
		//�Q�[���I�[�o�[�e�L�X�g 
		fill(0);
		textSize(100);
		text("����", 550, 800);
		text((let) + pretwoWord[num[number]][1], 850, 800);
		fill(255, 0, 0);
		textSize(200);
		text("GAMEOVER", 550, 525);
		textSize(80);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 1000);
		if (isTrigger(KEY_SPACE)) {
			stopSound(oversound);
			State = TITLE;
		}
	}
	void GAME::over2() {
		clear(0);
		rectMode(CORNER);
		image(overback, 0, 0);
		rectMode(CENTER);
		image(overmale, 200, 600);
		image(overfemale, 1700, 600);
		//�Q�[���I�[�o�[�e�L�X�g 
		fill(0);
		textSize(100);
		text("����", 550, 800);
		text((let)+twoWord[num[number]][1], 850, 800);
		fill(255, 0, 0);
		textSize(200);
		text("GAMEOVER", 550, 525);
		textSize(80);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 1000);
		if (isTrigger(KEY_SPACE)) {
			stopSound(oversound);
			State = TITLE;
		}
	}
	void GAME::over3() {
		clear(0);
		rectMode(CORNER);
		image(overback, 0, 0);
		rectMode(CENTER);
		image(overmale, 200, 600);
		image(overfemale, 1700, 600);
		//�Q�[���I�[�o�[�e�L�X�g 
		fill(0);
		textSize(100);
		text("����", 550, 800);
		text((let)+preoneWord[num[number]][1], 850, 800);
		fill(255, 0, 0);
		textSize(200);
		text("GAMEOVER", 550, 525);
		textSize(80);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 1000);
		if (isTrigger(KEY_SPACE)) {
			stopSound(oversound);
			State = TITLE;
		}
	}
	void GAME::over4() {
		clear(0);
		rectMode(CORNER);
		image(overback, 0, 0);
		rectMode(CENTER);
		image(overmale, 200, 600);
		image(overfemale, 1700, 600);
		//�Q�[���I�[�o�[�e�L�X�g 
		fill(0);		
		textSize(100);
		text("����", 550, 800);
		text((let)+oneWord[num[number]][1], 850, 800);
		fill(255, 0, 0);
		textSize(200);
		text("GAMEOVER", 550, 525);
		textSize(80);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 1000);
		if (isTrigger(KEY_SPACE)) {
			stopSound(oversound);
			State = TITLE;
		}
	}
	void GAME::over5() {
		clear(0);
		rectMode(CORNER);
		image(overback, 0, 0);
		rectMode(CENTER);
		image(overmale, 200, 600);
		image(overfemale, 1700, 600);
		//�Q�[���I�[�o�[�e�L�X�g 
		fill(0);
		textSize(100);
		text("����", 300, 800);
		text((let)+dontknowWord[num[number]][1], 600, 800);
		fill(255, 0, 0);
		textSize(200);
		text("GAMEOVER", 550, 525);
		textSize(80);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 1000);
		if (isTrigger(KEY_SPACE)) {
			stopSound(oversound);
			State = TITLE;
		}
	}
	void GAME::end() {
		clear(0);
		rectMode(CORNER);
		image(clearback, 0, 0);
		rectMode(CENTER);
		image(clearmale, 200, 600);
		image(clearfemale, 1700, 600);
		fill(0, 0, 255);
		//�Q�[���N���A�e�L�X�g
		textSize(200);
		text("���߂łƂ��I", 400, 450);
		textSize(80);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 1000);
		if (isTrigger(KEY_SPACE)) {
			stopSound(endsound);
			State = TITLE;
		}
	}
}
