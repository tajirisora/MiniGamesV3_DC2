#include <string>
#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME15.h"
#include <iomanip>
#include <sstream>
namespace GAME15
{
	int GAME::create()
	{
		return 0;
	}

	void GAME::destroy()
	{
	}

	void GAME::play()
	{
	}

	void GAME::move()
	{
	}

	void GAME::draw()
	{
		//stringで文字列+浮動小数点数(※DeltaTimeはfloatなので小数点以下6桁がデフォ)
		print((std::string("フレームタイム:") + std::to_string(DeltaTime)).c_str());

		//ostringstreamで文字列+浮動小数点数(※cout類似なので小数点部の末尾0のはカットされる)
		std::ostringstream sss; //#include <stringstream>。sssはcoutっぽい書き方が可能になる。
		sss << "フレームタイム:" << DeltaTime;
		print(sss.str().c_str()); //ostringstreamはstr()でstd::string型に出来る。std::string型はc_str()でconst char*に出来る。

		//ostringstreamで0付20桁の数字(スコア等)
		sss.str(""); //sssの再利用
		sss << std::setfill('0') << std::setw(20) << 999999999999999999i64;
		print(sss.str().c_str());

		//★ostringstreamで改行付き文字列(セリフ等)はうまくいかない!!!
		//sss.str(""); //sssの再利用
		//sss << "1行目\n2行目"; //★★PEND; \nが・になる。text()は非対応、、、
		//print(sss.str().c_str());
	}

	void GAME::proc()
	{
		clear(0, 0, 64);

		play();
		move();
		draw();

		fill(255);
		text("ENTERキーでメニューに戻る", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
