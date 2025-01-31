#include"../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include"../../libOne/inc/input.h"
#include "EXPLANACHION.h"
#include"GAME03.h"
#include"CONTAINER.h"
namespace GAME03 {
	void EXPLANACHION::create(){
		Explan = game()->container()->data().explan;

	}
	void EXPLANACHION::init(){
		game()->fade()->inTrigger();
	}
	void EXPLANACHION::draw(){
		imageColor(240);
		image(game()->container()->data().stage.backImg, 0, 0);
		image(Explan.explanationImg, 0, 0);
		for (int i = 0; i < 10; i++) {
			if (i == 8) {
				fill(255, 255, 255, 150);
				textSize(40);
				text("Escキーでタイトルに戻る", width / 1.4f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
			}
			else {
				fill(100, 50.0f + (float)i * 10.0f, (float)i * 10.0f, 30);
				text("Escキーでタイトルに戻る", width / 1.4f, height / 1.00625f - (float)i * 1.0f);
			}
		}
		fill(0);
		game()->fade()->draw();
	}
	void EXPLANACHION::nextScene(){
		if (isTrigger(KEY_ESCAPE)) {
			playSound(game()->container()->data().volume.Se_D);
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->title());
		}

	}
}