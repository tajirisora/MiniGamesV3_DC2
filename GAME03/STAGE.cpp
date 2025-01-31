#include "../../libOne/inc/libOne.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"MAP.h"
#include"CHARACTER_MANAGER.h"
#include "STAGE.h"
#include<time.h>

namespace GAME03 {
	void STAGE::create() {
		Stage = game()->container()->data().stage;
	}
	void STAGE::init() {
		Stage.backToTitleTime = game()->container()->data().stage.backToTitleTime;
		game()->map()->init();
		game()->characterManager()->init();
		game()->fade()->inTrigger();
		time(&Stage.s_time);
		time(&Stage.n_time);
		Stage.mtime = 0;
		Stage.time = 0;
		loopBgm = true;
		op_option = false;
		flg_clear = false;
		once = true;
		k = 0.0f;
		l = 0.0f;
		f1c = 0;
		f2c = 0;
	}

	void STAGE::update() {
		game()->characterManager()->update();
		game()->map()->update();
	}

	void STAGE::draw() {
		if (loopBgm) {
			playLoopSound(game()->container()->data().volume.Snd_B);
			loopBgm = false;
		}
		BackGround();
		if (!op_option && !game()->characterManager()->player()->died() && !game()->characterManager()->player()->survived()) {
			for (float i = 130.0f; i < 1790.0f; i += 65.0f) {
				for (float j = -190.0f; j < 1270.0f; j += 95.0f) {
					if (i + k < 1760 && i + k>160 && j + l < 1175 && j + l>-95) {
						image(Stage.forestImg, i + k, j + l);
					}

					if ((isPress(KEY_A) || isPress(KEY_LEFT)) ||
						(isPress(MOUSE_LBUTTON) && width / 2 >= mouseX)) {
						k += 0.005f;
						if (k >= 65.0f) {
							k = 0;
						}
					}
					if ((isPress(KEY_D) || isPress(KEY_RIGHT)) ||
						(isPress(MOUSE_LBUTTON) && width / 2 <= mouseX)) {
						k -= 0.005f;
						if (k <= -65.0f) {
							k = 0;
						}
					}

					if ((isPress(KEY_W) || isPress(KEY_UP)) ||
						(isPress(MOUSE_LBUTTON) && height / 2 >= mouseY)) {
						l += 0.005f;
						if (l >= 95.0f) {
							l = 0;
						}
					}
					if ((isPress(KEY_S) || isPress(KEY_DOWN)) ||
						(isPress(MOUSE_LBUTTON) && height / 2 <= mouseY)) {
						l -= 0.005f;
						if (l <= -95.0f) {
							l = 0;
						}
					}
				}
			}
		}
		game()->map()->draw();
		game()->characterManager()->draw();
		if (game()->characterManager()->player()->died()) {
			Logo(Stage.gameOverImg, Stage.gameOverColor);
		}
		else if (game()->characterManager()->player()->survived()) {
			if(game()->select()->timepls() >= 150){
				fopen_s(&fp, "assets/game03/data/achievements/achievements.txt", "w");
				if (fp != NULL) {
					fprintf(fp,"3•ªˆÈã¶‚«Žc‚éB\n");
					fclose(fp);
				}
			}
			Logo(Stage.stageClearImg, Stage.stageClearColor);
		}
		else {
			fill(225);
			textSize(30);
			text((let)game()->characterManager()->player()->playerHp(), width / 2 + 10, height / 2 + 60);
			if (!op_option) {
				if (isTrigger(KEY_ESCAPE) ||
					((mouseX > 12 && mouseX < 100 && mouseY>12 && mouseY < 83) && isTrigger(MOUSE_LBUTTON))) {
					Stage.time = Stage.stp_time;
					op_option = true;
					playSound(game()->container()->data().volume.Se_D);
				}
			}
			if (op_option) {
				if (once) {
					fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "r");
					if (fp != NULL) {
						fscanf_s(fp, "%d\n%d\n", &f1, &f2);
						fclose(fp);
						if (f1 == 0) {
							Stage.bgm = "‚n‚e‚e";
						}
						else {
							f1c = f1;
						}
						if (f2 == 0) {
							Stage.se = "‚n‚e‚e";
						}
						else {
							f2c = f2;
						}
					}
					once = false;
				}
				time(&Stage.cnt_time);
				imageColor(COLOR(255,255,255));
				image(Stage.playStopImg, 0, 0);
				image(Stage.backTitleImg, 0, 0);
				image(Stage.restartImg, 0, 0);
				fill(0);
				textSize(30);
				text("‚n", 790, 800);
				text("‚m", 1110, 800);
				text("‚v", 1200, 390);
				text("‚r", 1200, 540);
				textSize(50);
				text("‚a‚f‚l : ", 700, 400);
				text(" ‚r ‚d : ", 700, 550);
				if ((isTrigger(MOUSE_LBUTTON) && (mouseX >= 990 && mouseX <= 1145 && mouseY >= 350 && mouseY <= 390)) ||
					isTrigger(KEY_W)) {
					playSound(game()->container()->data().volume.Se_E);
					if (Stage.bgm == " ‚n ‚m") {
						Stage.bgm = "‚n‚e‚e";
						f1 = 0;
						fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "w");
						if (fp != NULL) {
							fprintf_s(fp, "%d\n", f1);
							fprintf_s(fp, "%d\n", f2);
							fclose(fp);
						}
					}
					else if (Stage.bgm == "‚n‚e‚e") {
						fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "r");
						if (fp != NULL) {
							fscanf_s(fp, "%d\n%d\n", &f1, &f2);
							fclose(fp);
							if (f1 == 0) {
								fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "w");
								if (fp != NULL) {
									if (f1c > 0) {
										f1 = f1c;
									}
									else {
										f1 = 80;
									}
									fprintf_s(fp, "%d\n", f1);
									fprintf_s(fp, "%d\n", f2);
									fclose(fp);
								}
							}
						}
						Stage.bgm = " ‚n ‚m";
					}
					setVolume(game()->container()->data().volume.Snd_A, -(100 - f1) * (100 - f1));
					setVolume(game()->container()->data().volume.Snd_B, -(100 - f1) * (100 - f1));
					setVolume(game()->container()->data().volume.Snd_C, -(100 - f1) * (100 - f1));
					setVolume(game()->container()->data().volume.Snd_D, -(100 - f1) * (100 - f1));
				}
				if ((isTrigger(MOUSE_LBUTTON) && (mouseX >= 990 && mouseX <= 1145 && mouseY >= 500 && mouseY <= 550)) ||
					isTrigger(KEY_S)) {
					playSound(game()->container()->data().volume.Se_E);
					if (Stage.se == " ‚n ‚m") {
						Stage.se = "‚n‚e‚e";
						f2 = 0;
						fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "w");
						if (fp != NULL) {
							fprintf_s(fp, "%d\n", f1);
							fprintf_s(fp, "%d\n", f2);
							fclose(fp);
						}
						fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "r");
						if (fp != NULL) {
							fscanf_s(fp, "%d\n%d\n", &f1, &f2);
							fclose(fp);
						}
					}
					else if (Stage.se == "‚n‚e‚e") {
						fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "r");
						if (fp != NULL) {
							fscanf_s(fp, "%d\n%d\n", &f1, &f2);
							fclose(fp);
							if (f2 == 0) {
								fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "w");
								if (fp != NULL) {
									if (f2c > 0) {
										f2 = f2c;
									}
									else {
										f2 = 80;
									}
									fprintf_s(fp, "%d\n", f1);
									fprintf_s(fp, "%d\n", f2);
									fclose(fp);
								}
							}
						}
						Stage.se = " ‚n ‚m";
					}
					setVolume(game()->container()->data().volume.Se_A, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_B, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_C, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_D, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_E, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_F, -(100 - f2) * (100 - f2));
				}
				text((let)Stage.bgm, 1000, 400);
				text((let)Stage.se, 1000, 550);
				if (isTrigger(KEY_N) ||
					((mouseX > 1005 && mouseX < 1234 && mouseY>707 && mouseY < 772) && isTrigger(MOUSE_LBUTTON))) {
					playSound(game()->container()->data().volume.Se_E);
					Stage.s_time += (Stage.cnt_time - Stage.n_time);
					op_option = false;
				}
				if (isTrigger(KEY_O) || 
					((mouseX > 687 && mouseX < 918 && mouseY>707 && mouseY < 772)&&isTrigger(MOUSE_LBUTTON))) {
					playSound(game()->container()->data().volume.Se_D);
					once = true;
					game()->fade()->outTrigger();
				}
			}
			else {
				time(&Stage.n_time);
				Stage.time = Stage.n_time - Stage.s_time;
				Stage.stp_time = Stage.time;
			}
			if (Stage.time >= 30 + game()->select()->timepls()) {
				flg_clear = true;
			}
			if (Stage.time >= 60 && (Stage.time + (-60 * Stage.mtime)) >= 60) {
				Stage.mtime++;
			}
			fill(225);
			textSize(90);
			if (Stage.time <= 9) {
				text((let)(int)Stage.mtime + ":" + "0" + (let)(int)(Stage.time + (-60 * Stage.mtime)), width / 2.0f, height / 10.0f);
			}
			else {
				text((let)(int)Stage.mtime + ":" + (let)(int)(Stage.time + (-60 * Stage.mtime)), width / 2.0f, height / 10.0f);
			}
			//text((let)mouseX + "   " + (let)mouseY, width / 2, height / 2);
		}
		fill(0);
		game()->fade()->draw();
	}
	void STAGE::BackGround() const {
		clear();
		rectMode(CORNER);
		imageColor(Stage.backColor);
		image(Stage.backImg, 0, 0);
		image(Stage.playStopButtonImg, 0, 0);
		for (float i = 130.0f; i < 1790.0f; i += 65.0f) {
			for (float j = 0.0f; j < 1080.0f; j += 95.0f) {
				image(Stage.forestImg, i, j);
			}
		}
	}
	void STAGE::Logo(int img, const COLOR& color) {
		imageColor(color);
		image(img, Stage.logoPx, Stage.logoPy);
		Stage.backToTitleTime -= delta;
	}
	void STAGE::nextScene() {
		if (Stage.backToTitleTime <= 0) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			stopSound(game()->container()->data().volume.Snd_B);
			f1c = 0, f2c = 0;
			game()->setCurScene(game()->title());
		}
	}
}
