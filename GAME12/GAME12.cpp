#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME12.h"
namespace GAME12
{
	int GAME::create()
	{
		return 0;
	}

	void GAME::destroy()
	{

	}

	void GAME::proc()
	{
		//シーン切り替え
		if (State == TITLE)title();
		else if (State == INIT)init();
		else if (State == WAIT)wait();
		else if (State == PLAY1)play1();
		else if (State == PLAY2)play2();
		else if (State == PLAY3)play3();
		else if (State == PLAY4)play4();
		else if (State == OVER)over();
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
		{"ka", "か"},{"ki", "き"},{"ku", "く"},
		{"ke", "け" }, {"ko", "こ" },{"sa", "さ" }, 
		{"si", "し"},{"shi", "し"} ,{"su", "す"},
		{"se", "せ"}, {"so", "そ"},{"ta", "た"},
		{"ti", "ち"},{"chi", "ち"}, {"tu", "つ"},
		{"tsu", "つ"}, {"te", "て"},{"to", "と"},
		{"na", "な"}, {"ni", "に"},{"nu", "ぬ"},
		{"ne", "ね"},{"no", "の"},{"ha", "は"},
		{"hi", "ひ"},{"fu", "ふ"}, {"hu", "ふ"},
		{"he", "へ"}, {"ho", "ほ"},{"ma", "ま"},
		{"mi", "み"},{"mu", "む"}, {"me", "め"},
		{"mo", "も"},{"ya", "や"}, {"yu", "ゆ"},
		{"yo", "よ"},{"ra", "ら"}, {"ri", "り"},
		{"ru", "る"}, {"re", "れ"},{"ro", "ろ"},
		{"wa", "わ"}, {"wo", "を"},{"nn", "ん"},
		{"nn", "ん"},{"ga", "が"}, {"gi", "ぎ"},
		{"gu", "ぐ"}, {"ge", "げ"},{"go", "ご"},
		{"za", "ざ"}, {"ji", "じ"},{"zi", "じ"},
		{"zu", "ず"},{"ze", "ぜ"}, {"zo", "ぞ"},
		{"da", "だ"}, {"di", "ぢ"},{"du", "づ"},
		{"de", "で"},{"do", "ど"},{"ba", "ば"},
		{"bi", "び"},{"bu", "ぶ"}, {"be", "べ"},
		{"bo", "ぼ"},{"pa", "ぱ"}, {"pi", "ぴ"},
		{"pu", "ぷ"}, {"pe", "ぺ"},{"po", "ぽ"},
		{"kya", "きゃ"}, {"kyu", "きゅ"},{"kyo", "きょ"},
		{"sya", "しゃ"}, {"sha", "しゃ"},{"syu", "しゅ"},
		{"shu", "しゅ"},{"syo", "しょ"}, {"sho", "しょ"},
		{"tya", "ちゃ"}, {"cya", "ちゃ"},{"cha", "ちゃ"}, 
		{"tyu", "ちゅ"},{"cyu", "ちゅ"}, {"chu", "ちゅ"},
		{"tyo", "ちょ"},{"cyo", "ちょ"},{"cho", "ちょ"},
		{"nya", "にゃ"}, {"nyu", "にゅ"},{"nyo", "にょ"},
		{"hya", "ひゃ"}, {"hyu", "ひゅ"},{"hyo", "ひょ"},
		{"mya", "みゃ"}, {"myu", "みゅ"},{"myo", "みょ"},
		{"rya", "りゃ"}, {"ryu", "りゅ"},{"ryo", "りょ"},
		{"gya", "ぎゃ"}, {"gyu", "ぎゅ"},{"gyo", "ぎょ"},
		{"ja", "じゃ"}, {"jya", "じゃ"},{"zya", "じゃ"},
		{"ju", "じゅ"},{"jyu", "じゅ"}, {"zyu", "じゅ"},
		{"jo", "じょ"}, {"jyo", "じょ"},{"zyo", "じょ"},
		{"bya", "びゃ"}, {"byu", "びゅ"},{"byo", "びょ"},
		{"pya", "ぴゃ"}, {"pyu", "ぴゅ"},{"pyo", "ぴょ"},
		{"xtsu", "っ"}, {"ltsu", "っ"},{"xa", "ぁ"},
		{"la", "ぁ"},{"xi", "ぃ"}, {"li", "ぃ"},
		{"xu", "ぅ"}, {"lu", "ぅ"},{"xe", "ぇ"},
		{"le", "ぇ"},{"xo", "ぉ"}, {"lo", "ぉ"},
		{"xya", "ゃ"}, {"lya", "ゃ"},{"xyu", "ゅ"},
		{"lyu", "ゅ"},{"xyo", "ょ"}, {"lyo", "ょ"},
		{"xwa", "ゎ"}, {"lwa", "ゎ"},

		{"kka", "っか"}, {"kki", "っき"},
		{"kku", "っく"}, {"kke", "っけ"},
		{"kko", "っこ"},
		{"ssa", "っさ"}, {"ssi", "っし"},
		{"sshi","っし"}, {"ssu", "っす"},
		{"sse", "っせ"}, {"sso", "っそ"},
		{"tta", "った"}, {"tti", "っち"},
		{"cchi", "っち"}, {"ttu", "っつ"},
		{"ttsu", "っつ"}, {"tte", "って"},
		{"tto", "っと"},
		{"nna", "っな"}, {"nni", "っに"},
		{"nnu", "っぬ"}, {"nne", "っね"},
		{"nno", "っの"},
		{"hha", "っは"}, {"hhi", "っひ"},
		{"ffu", "っふ"}, {"hhu", "っふ"},
		{"hhe", "っへ"}, {"hho", "っほ"},
		{"mma", "っま"}, {"mmi", "っみ"},
		{"mmu", "っむ"}, {"mme", "っめ"},
		{"mmo", "っも"},
		{"yya", "っや"}, {"yyu", "っゆ"},
		{"yyo", "っよ"},
		{ "rra", "っら" }, { "rri", "っり" },
		{ "rru", "っる" }, { "rre", "っれ" },
		{ "rro", "っろ" },
		{ "wwa", "っわ" }, { "wwo", "っを" },
		{ "gga", "っが" }, { "ggi", "っぎ" },
		{ "ggu", "っぐ" }, { "gge", "っげ" },
		{ "ggo", "っご" },
		{ "zza", "っざ" }, { "jji", "っじ" },
		{ "zzi", "っじ" }, { "zzu", "っず" },
		{ "zze", "っぜ" }, { "zzo", "っぞ" },
		{ "dda", "っだ" }, { "ddi", "っぢ" },
		{ "ddu", "っづ" }, { "dde", "っで" },
		{ "ddo", "っど" },
		{ "bba", "っば" }, { "bbi", "っび" },
		{ "bbu", "っぶ" }, { "bbe", "っべ" },
		{ "bbo", "っぼ" },
		{ "ppa", "っぱ" }, { "ppi", "っぴ" },
		{ "ppu", "っぷ" }, { "ppe", "っぺ" },
		{ "ppo", "っぽ" },
		{ "kkya", "っきゃ" }, { "kkyu", "っきゅ" },
		{ "kkyo", "っきょ" },
		{ "ssya", "っしゃ" }, { "ssha", "っしゃ" },
		{ "ssyu", "っしゅ" }, { "sshu", "っしゅ" },
		{ "ssyo", "っしょ" }, { "ssho", "っしょ" },
		{ "ttya", "っちゃ" }, { "ccya", "っちゃ" },
		{ "ccha", "っちゃ" }, { "ttyu", "っちゅ" },
		{ "ccyu", "っちゅ" }, { "cchu", "っちゅ" },
		{ "ttyo", "っちょ" }, { "ccyo", "っちょ" },
		{ "ccho", "っちょ" },
		{ "hhya", "っひゃ" }, { "hhyu", "っひゅ" },
		{ "hhyo", "っひょ" },
		{ "mmya", "っみゃ" }, { "mmyu", "っみゅ" },
		{ "mmyo", "っみょ" },
		{ "rrya", "っりゃ" }, { "rryu", "っりゅ" },
		{ "rryo", "っりょ" },
		{ "ggya", "っぎゃ" }, { "ggyu", "っぎゅ" },
		{ "ggyo", "っぎょ" },
		{ "jja", "っじゃ" }, { "jjya", "っじゃ" },
		{ "zzya", "っじゃ" }, { "jju", "っじゅ" },
		{ "jjyu", "っじゅ" }, { "zzyu", "っじゅ" },
		{ "jjo", "っじょ" }, { "jjyo", "っじょ" },
		{ "zzyo", "っじょ" },
		{ "bbya", "っびゃ" }, { "bbyu", "っびゅ" },
		{ "bbyo", "っびょ" },
		{ "ppya", "っぴゃ" }, { "ppyu", "っぴゅ" },
		{ "ppyo", "っぴょ" },
		{ "xtsu", "っ" }, { "ltsu", "っ" },
		{ "xxa", "っぁ" }, { "lla", "っぁ" },
		{ "xxi", "っぃ" }, { "lli", "っぃ" },
		{ "xxu", "っぅ" }, { "llu", "っぅ" },
		{ "xxe", "っぇ" }, { "lle", "っぇ" },
		{ "xxo", "っぉ" }, { "llo", "っぉ" },
		{ "xxya", "っゃ" }, { "llya", "っゃ" },
		{ "xxyu", "っゅ" }, { "llyu", "っゅ" },
		{ "xxyo", "っょ" }, { "llyo", "っょ" },
		{ "xxwa", "っゎ" }, { "llwa", "っゎ" },
		{ "a", "あ" }, { "i", "い" }, { "u", "う" },
		{ "e", "え" }, { "o", "お" },
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
		//描画--------------------------------------------------
		clear(120);
		//テキスト情報
		fill(0, 255, 0);
		textSize(100);
		text("漢字検定", 600, 450);
		fill(0, 0, 0);
		textSize(40);
		text("クリックでゲームスタート", 750, 500);
		text("Enterでメニューに戻る", 750, 550);
		//シーン切り替え-----------------------------------------

		if (isTrigger(MOUSE_LBUTTON)) {
			//次のシーケンス
			State = INIT;
			return;
		}
		//メニューに戻る-----------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}

	void GAME::init() {
		clear(120);
		flag = 0;
		number = 0;
		set = 0;
		curtime = 30.0;
		stop = 0;
		count = 0;
		ch.clear();
		currentInput.clear();
		fill(0, 0, 0);
		textSize(60);
		text("表示された漢字の読みを30秒以内で当てる", 525, 200);
		text("入力確定or消去にENTER", 525, 300);
		text("Q　準2級", 575, 400);
		text("W　2級", 575, 500);
		text("E　準1級", 575, 600);
		text("R　1級", 575, 700);
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
	}

	void GAME::wait() {
		clear(200);
		textSize(60);
		if (set == 1) {
			text("準2級で開始", 525, 600);
		}
		else if (set == 2) {
			text("2級で開始", 525, 600);
		}
		else if (set == 3) {
			text("準1級で開始", 525, 600);
		}
		else if (set == 4) {
			text("1級で開始", 525, 600);
		}
		text("エンターキーでスタート", 625, 400);
		text("スペースキーで戻る", 675, 500);
		if (isTrigger(KEY_ENTER) && set == 1) {
			clear(200);
			randomnum();
			State = PLAY1;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 2) {
			clear(200);
			randomnum();
			State = PLAY2;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 3) {
			clear(200);
			randomnum();
			State = PLAY3;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 4) {
			clear(200);
			randomnum();
			State = PLAY4;
			return;
		}
		else if (isTrigger(KEY_SPACE)) {
			clear(200);
			State = INIT;
			return;
		}
	}

	void GAME::draw1(int snum) {
		fill(100);
		textSize(200);
		text((let)+pretwoWard[snum][0], 550, 300);
		textSize(50);
		if(ch.empty()){ 
			text(currentInput.c_str(), 600, 800); 
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("ゲーム終了　左クリック", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}
	void GAME::draw2(int snum) {
		fill(100);
		textSize(200);
		text((let)+twoWard[snum][0], 550, 300);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("ゲーム終了　左クリック", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}
	void GAME::draw3(int snum) {
		fill(100);
		textSize(200);
		text((let)+preoneWard[snum][0], 550, 300);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("ゲーム終了　左クリック", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}
	void GAME::draw4(int snum) {
		fill(100);
		textSize(200);
		text((let)+oneWard[snum][0], 550, 300);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("ゲーム終了　左クリック", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}

	void GAME::play1() {
		clear(200);
		curtime -= delta;
		draw1(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == pretwoWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != pretwoWard[num[number]][1]) {
			textSize(500);
			text("×", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {

			State = OVER;
		}
		if (count == 15) {
			State = END;
		}
	}

	void GAME::play2() {
		clear(200);

		curtime -= delta;
		draw2(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == twoWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != twoWard[num[number]][1]) {
			textSize(120);
			text("×", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			State = OVER;
		}
		if (count == 15) {
			State = END;
		}
	}
	void GAME::play3() {
		clear(200);
		curtime -= delta;
		draw3(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == preoneWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();

		}
		else if (flag == 1 && ch != preoneWard[num[number]][1]) {
			textSize(120);
			text("×", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			State = OVER;
		}
		if (count == 15) {
			State = END;
		}
	}
	void GAME::play4() {
		clear(200);

		curtime -= delta;
		draw4(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == oneWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != oneWard[num[number]][1]) {
			textSize(120);
			text("×", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			ch.clear();
			State = OVER;
		}
		if (count == 15) {
			ch.clear();
			State = END;
		}
	}

	void GAME::over() {
		clear(200);
		fill(0);
		//ゲームオーバーテキスト 
		textSize(80);
		text("GAMEOVER", 650, 450);
		text("SPACEキーでタイトルに戻る", 500, 550);
		if (isTrigger(KEY_SPACE)) {
			State = TITLE;
		}
	}

	void GAME::end() {
		clear(0, 255, 0);
		fill(0, 0, 255);
		//ゲームクリアテキスト
		textSize(80);
		text("おめでとう", 650, 450);
		text("SPACEキーでタイトルに戻る", 500, 550);
		if (isTrigger(KEY_SPACE)) {
			State = TITLE;
		}
	}


	void GAME::gmain() {
		window(1920, 1080, full);

	}
}
