#include "CONTAINER.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
namespace GAME09
{
	void CONTAINER::load() {
		setData();
		loadGraphic();
		loadSounds();
	}
	void CONTAINER::setData() {

		Data.select.jacketTf.pos = VECTOR2(1340, 380);
		Data.select.jacketTf.size = 0.93f;

		Data.fade.alpha = 0;
		Data.fade.color = COLOR(0, 0, 0);
		Data.fade.speed = 700;

		Data.chartMNG.infoStartStr[CHARTMANAGER::TITLE] = "#TITLE";
		Data.chartMNG.infoStartStr[CHARTMANAGER::ARTIST] = "#ARTIST";
		Data.chartMNG.infoStartStr[CHARTMANAGER::CREDIT] = "#CREDIT";
		Data.chartMNG.infoStartStr[CHARTMANAGER::MUSIC] = "#MUSIC";
		Data.chartMNG.infoStartStr[CHARTMANAGER::BANNER] = "#BANNER";
		Data.chartMNG.infoStartStr[CHARTMANAGER::BACKGROUND] = "#BACKGROUND";
		Data.chartMNG.infoStartStr[CHARTMANAGER::OFFSET] = "#OFFSET";
		Data.chartMNG.infoStartStr[CHARTMANAGER::BASEBPM] = "#BASEBPM";
		Data.chartMNG.infoStartStr[CHARTMANAGER::MEASURE] = "#MEASURE";
		Data.chartMNG.infoStartStr[CHARTMANAGER::VOLUME] = "#VOLUME";
		Data.chartMNG.infoStartStr[CHARTMANAGER::LANES] = "#LANES";
		Data.chartMNG.infoStartStr[CHARTMANAGER::NOTES] = "#NOTES";
		Data.chartMNG.commandStr[CHARTMANAGER::BPMCHANGE] = "#BPMCHANGE";
		Data.chartMNG.commandStr[CHARTMANAGER::MEASURECHANGE] = "#MEASURECHANGE";
		Data.chartMNG.commandStr[CHARTMANAGER::LANECHANGE] = "#LANECHANGE";
		Data.chartMNG.scoreDataStr[CHARTMANAGER::SCORE] = "#SCORE";
		Data.chartMNG.scoreDataStr[CHARTMANAGER::ACHIEVEMENT] = "#ACHIEVEMENT";
		Data.chartMNG.chartPath = "..\\main\\assets\\game09\\charts";

		Data.banner.centerPos = VECTOR2(450, height / 2 - 30);
		Data.banner.nextPosOfst = VECTOR2(45, 150);
		Data.banner.imgSize = 2.0f;
		Data.banner.titlePosOfst = VECTOR2(-210, 5);
		Data.banner.artistPosOfst = VECTOR2(-210, 60);
		Data.banner.titleStrSize = VECTOR2(680, 50);
		Data.banner.artistStrSize = VECTOR2(700, 35);
		Data.banner.moveAnimeTime = 0.3f;

		Data.jacket.areaSize = VECTOR2(700, 700);

		Data.back.area = VECTOR2(width, height);

		Data.note.imgSize = 1;
		Data.note.edgeOfst = 25;
		Data.note.rectOfst = 30;
		Data.note.rectHeight = 30;

		Data.rgCont.rawSpeed = 10000;
		Data.rgCont.detailViewTime = 3;
		Data.rgCont.detailViewDisappearTime = 0.5f;
		Data.rgCont.BeforePlayTime = 2;

		Data.lane.laneWidth = 700;
		Data.lane.pos = VECTOR2(width / 2, 900);
		Data.lane.maxLaneNum = 6;

		Data.loadSongs.msgSize = 70;
		Data.loadSongs.barPos = VECTOR2(width / 2, 1000);
		Data.loadSongs.barSize = VECTOR2(width * 0.9f, 70);
		Data.loadSongs.msgPos = VECTOR2(100, 960);
		Data.loadSongs.percentPos = VECTOR2(1820 - Data.loadSongs.msgSize * 2.5f, 960);

		Data.loadChart.msgSize = 70;
		Data.loadChart.barPos = VECTOR2(width / 2, 1000);
		Data.loadChart.barSize = VECTOR2(width * 0.9f, 70);
		Data.loadChart.msgPos = VECTOR2(100, 960);
		Data.loadChart.percentPos = VECTOR2(1820 - Data.loadSongs.msgSize * 2.5f, 960);

		Data.longBelt.color = COLOR(0, 255, 255);
	}
	void CONTAINER::loadGraphic() {
		Data.chartMNG.tempImage = loadImage("..\\main\\assets\\game09\\texture\\temp_image.png");
		Data.jacket.areaBackImg = loadImage("..\\main\\assets\\game09\\texture\\jacket_back.png");
	}
	void CONTAINER::loadSounds() {
		Data.sound.tapSound = loadSound("..\\main\\assets\\game09\\sounds\\tap2.wav");
	}
}