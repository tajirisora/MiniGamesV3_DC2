#include "JUDGEMANAGER.h"
#include "SOUNDMANAGER.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "LONGNOTE.h"
#include "TAPNOTE.h"
//#include "BEAM.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09 {
	JUDGEMANAGER::JUDGEMANAGER(GAME* game) :
		GAME_OBJECT(game) {
	}
	JUDGEMANAGER::~JUDGEMANAGER() {

	}

	void JUDGEMANAGER::create() {
		JudgeMNG = game()->container()->data().judge;
		Cont = game()->rgCont();
		Sound = game()->soundMNG();
		KeyCon = game()->keyConfig();
	}

	void JUDGEMANAGER::init() {
		AnimeTime = JudgeMNG.activeTime;
		for (int i = 0; i < NUM_JUDGE; i++) {
			JudgeResult[i] = 0;
		}
		for (int i = 0; i < NUM_ACCURACY; i++) {
			Accuracy[i] = 0;
		}
		Combo = 0;
		MaxCombo = 0;
	}

	void JUDGEMANAGER::update() {
		if (AnimeTime < JudgeMNG.activeTime) {
			AnimeTime += delta;
		}
		game()->keyConfig()->update();

		autoPlay();
		//judgeNotes();
	}

	void JUDGEMANAGER::draw() {
		rectMode(CENTER);
		float ratio = AnimeTime / JudgeMNG.appearAnimeTime;
		if (ratio > 1) ratio = 1;

		//判定の文字
		if (AnimeTime < JudgeMNG.activeTime) {
			float size = JudgeMNG.imgSizeMin + (JudgeMNG.imgSize - JudgeMNG.imgSizeMin) * ratio;
			image(JudgeMNG.judge[Judge].img, JudgeMNG.pos.x, JudgeMNG.pos.y, 0, size);
			size *= JudgeMNG.accImgSizeRate;
			VECTOR2 pos = JudgeMNG.pos + JudgeMNG.accOfst;
			if (Acc == FAST) {
				image(JudgeMNG.fastImg, pos.x, pos.y, 0, size);
			}
			else if (Acc == SLOW) {
				image(JudgeMNG.slowImg, pos.x, pos.y, 0, size);
			}
		}

		//debug
		fill(0);
		print(JudgeResult[0]);
		print(JudgeResult[1]);
		print(JudgeResult[2]);

		//コンボ
		//if (Combo >= 5) {
		//	float comboAnimeRatio = JudgeMNG.comboSizeMinRate + (1 - JudgeMNG.comboSizeMinRate) * ratio;
		//	game()->combo()->draw(Combo, JudgeMNG.comboPos, comboAnimeRatio);
		//}
	}

	void JUDGEMANAGER::resetCombo() {
		if (Combo > MaxCombo) {
			MaxCombo = Combo;
		}
		Combo = 0;
	}

	void JUDGEMANAGER::AccCnt(ACCURACY acc) {
		Acc = acc;
		Accuracy[acc] ++;
	}

	
	void JUDGEMANAGER::judgeNotes() {
		std::vector<NOTE*>& notes = game()->notes();
		//ノーツすべてをループ
		for (auto it = notes.begin(); it != notes.end();) {
			//タップノーツなら
			if ((*it)->noteName() == NOTE::TAP) {
				//そのノーツが置かれてるレーンが押された瞬間なら
				if (KeyCon->keyTrigger((*it)->getKey().main) ||
					KeyCon->keyTrigger((*it)->getKey().sub)) {
					bool isJudge = false;
					//上位の判定から順番に判定の範囲内か確認
					for (int i = 0; i < NUM_JUDGE; i++) {
						if (Abs((float)((*it)->getTime() - Cont->curTime())) < JudgeMNG.judge[i].time) {
							Judge = (JUDGE)i;
							if (Judge == GREAT) {
								if ((*it)->getTime() - Cont->curTime() > 0) {
									AccCnt(FAST);
								}
								else {
									AccCnt(SLOW);
								}
							}
							else {
								AccCnt(NONE);
							}
							if (Judge == MISS) {
								resetCombo();
							}
							else {
								Combo++;
							}
							JudgeResult[i]++;
							Sound->tapSound();
							AnimeTime = 0;
							//同じレーンの2個以上のノーツが同時に反応しないように一回判定したら押してないことにする
							if (KeyCon->keyTrigger((*it)->getKey().main)) {
								KeyCon->setTrigger((*it)->getKey().main, false);
							}
							else {
								KeyCon->setTrigger((*it)->getKey().sub, false);
							}
							delete (*it);
							it = notes.erase(it);
							isJudge = true;
							break;
						}
					}
					//一番下の判定の範囲にも入っていなければ
					if (!isJudge) {
						//判定ラインより後ろならミス
						if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
							Judge = MISS;
							AccCnt(NONE);
							resetCombo();
							JudgeResult[MISS]++;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
						//手前ならスルー
						else {
							it++;
						}
					}
				}
				//ノーツが押されてなければ
				else {
					//一番下の判定の範囲にも入ってなく、判定ラインの後ろならミス
					if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
						Judge = MISS;
						AccCnt(NONE);
						resetCombo();
						JudgeResult[MISS]++;
						AnimeTime = 0;
						delete (*it);
						it = notes.erase(it);
					}
					//それ以外ならスルー
					else {
						it++;
					}
				}
			}
			//ロングノーツなら
			else if ((*it)->noteName() == NOTE::LONG) {
				//始点が押されてなければ
				if (!((LONGNOTE*)*it)->getPress()) {
					//押された瞬間なら
					if (KeyCon->keyTrigger((*it)->getKey().main) ||
						KeyCon->keyTrigger((*it)->getKey().sub)) {
						bool isJudge = false;
						//上位の判定から順番に判定の範囲内か確認
						for (int i = 0; i < NUM_JUDGE; i++) {
							if (Abs((float)((*it)->getTime() - Cont->curTime())) < JudgeMNG.judge[i].time) {
								Judge = (JUDGE)i;
								if (Judge == GREAT) {
									if ((*it)->getTime() - Cont->curTime() > 0) {
										AccCnt(FAST);
									}
									else {
										AccCnt(SLOW);
									}
								}
								else {
									AccCnt(NONE);
								}
								JudgeResult[i]++;
								//同じレーンの2個以上のノーツが同時に反応しないように一回判定したら押してないことにする
								if (KeyCon->keyTrigger((*it)->getKey().main)) {
									KeyCon->setTrigger((*it)->getKey().main, false);
								}
								else {
									KeyCon->setTrigger((*it)->getKey().sub, false);
								}
								isJudge = true;
								AnimeTime = 0;
								//判定がミスの場合
								if (Judge == MISS) {
									delete (*it);
									it = notes.erase(it);
									//終点もミスなのでミスのカウントを増やす
									JudgeResult[i]++;
									resetCombo();
									break;
								}
								//それ以外
								else {
									Combo++;
									//始点は押されてますよフラグを立てる
									((LONGNOTE*)*it)->setPress(true);
									Sound->tapSound();
									break;
								}
							}
						}
						//判定されてなければ
						if (!isJudge) {
							//過ぎ去ったノーツをミスにする
							if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
								Judge = MISS;
								AccCnt(NONE);
								resetCombo();
								//終点もミスなのでミスカウントを2増やす
								JudgeResult[MISS] += 2;
								AnimeTime = 0;
								delete (*it);
								it = notes.erase(it);
							}
							else {
								it++;
							}
						}
					}
					//押された瞬間じゃないなら
					else {
						//過ぎ去ったノーツをミスにする
						if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
							Judge = MISS;
							AccCnt(NONE);
							resetCombo();
							//終点もミスなのでミスカウントを2増やす
							JudgeResult[MISS] += 2;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
						else {
							it++;
						}
					}
				}
				//始点が押されてるとき
				else {
					//長押しされてるとき
					if (KeyCon->keyPress((*it)->getKey().main) ||
						KeyCon->keyPress((*it)->getKey().sub)) {
						//終点を過ぎて押されていたらPERFECT
						if ((*it)->getTimeE() - Cont->curTime() < 0) {
							Judge = PERFECT;
							AccCnt(NONE);
							Combo++;
							JudgeResult[PERFECT]++;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
						else {
							it++;
						}
					}
					//長押しされてない時(ここで必ず消滅するので実質的には離された瞬間)
					else {
						bool isJudge = false;
						//上位から判定
						for (int i = 0; i < NUM_JUDGE; i++) {
							if (Abs((float)((*it)->getTimeE() - Cont->curTime())) < JudgeMNG.judge[i].time) {
								Judge = (JUDGE)i;
								AccCnt(NONE);
								if (Judge == MISS) {
									resetCombo();
								}
								else {
									Combo++;
								}
								JudgeResult[i]++;
								AnimeTime = 0;
								delete (*it);
								it = notes.erase(it);
								isJudge = true;
								break;
							}
						}
						//判定の範囲外(つまりとんでもなく早く離したとき)
						if (!isJudge) {
							//当然ミス
							Judge = MISS;
							AccCnt(NONE);
							resetCombo();
							JudgeResult[MISS]++;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
					}
				}
			}
			//それ以外のノーツ(今はない)
			else {
				it++;
			}
		}
	}
	

	void JUDGEMANAGER::autoPlay() {
		std::vector<NOTE*>& notes = game()->notes();
		//ノーツすべてをループ
		for (auto it = notes.begin(); it != notes.end();) {
			//タップノーツなら
			if ((*it)->noteName() == NOTE::TAP) {
				//判定ラインを越したら
				if ((*it)->getTime() - Cont->curTime() < 0) {
					Judge = PERFECT;
					Combo++;
					JudgeResult[PERFECT]++;
					Sound->tapSound();
					AnimeTime = 0;
					delete (*it);
					it = notes.erase(it);
				}
				else {
					it++;
				}
			}
			//ロングノーツなら
			else if ((*it)->noteName() == NOTE::LONG) {
				//始点が押されてなければ
				if (!((LONGNOTE*)*it)->getPress()) {
					//始点が判定ラインを越したら
					if ((*it)->getTime() - Cont->curTime() < 0) {
						Judge = PERFECT;
						Combo++;
						JudgeResult[PERFECT]++;
						Sound->tapSound();
						AnimeTime = 0;
						//始点は押されてますよフラグを立てる
						((LONGNOTE*)*it)->setPress(true);
					}
					else {
						it++;
					}
				}
				//始点が押されてるとき
				else {
					//終点を過ぎたら
					if ((*it)->getTimeE() - Cont->curTime() < 0) {
						Judge = PERFECT;
						Combo++;
						JudgeResult[PERFECT]++;
						AnimeTime = 0;
						delete (*it);
						it = notes.erase(it);
					}
					else {
						it++;
					}
				}
			}
			//それ以外のノーツ(今はない)
			else {
				it++;
			}
		}
	}
}