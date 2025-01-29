#pragma once
#include"SCENE.h"
namespace GAME03 {
	class STAGE :public SCENE {
	public:
		struct DATA {
			int backImg = 0;
			int forestImg = 0;
			int stageClearImg = 0;
			int playStopButtonImg = 0;
			int gameOverImg = 0;
			int playStopImg = 0;
			int restartImg = 0;
			int backTitleImg = 0;

			float backToTitleTime = 0;

			COLOR backColor;
			COLOR gameOverColor;
			COLOR stageClearColor;

			float logoPx = 0;
			float logoPy = 0;

			time_t time  = 0;
			time_t mtime = 0;
			time_t stp_time = 0;
			time_t cnt_time = 0;
			time_t s_time   = 0, e_time = 0, n_time = 0;

			const char* bgm = " ‚n ‚m";
			const char* se  = " ‚n ‚m";
		};
	private:
		FILE* fp{};
		DATA Stage;
		void BackGround() const;
		void Logo(int img, const COLOR& color);

	public:
		STAGE(class GAME* game) :SCENE(game) {}
		void create();
		void init();
		void update();
		void draw();
		void nextScene();
		int loopBgm = true;
		int op_option = false;
		float k = 0.0f;
		float l = 0.0f;
		int f1 = 0, f2 = 0;
		int f1c = 0, f2c = 0;
		bool once = true;
	};
}