#include "CONTAINER.h"
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
	}
	void CONTAINER::loadGraphic() {
		Data.chartMNG.tempImage = loadImage("..\\main\\assets\\game09\\texture\\temp_image.png");
	}
	void CONTAINER::loadSounds() {

	}
}