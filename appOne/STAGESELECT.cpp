#include "STAGESELECT.h"
#include "libOne.h"
#include "CONTAINER.h"
STAGESELECT::STAGESELECT(class GAME* game) :
	SCENE(game) {

}
STAGESELECT::~STAGESELECT() {

}
//void STAGESELECT::newLineText() {
void STAGESELECT::draw() {
	clear(StageSelect.backColor);
	image(SS_Images.image, 0, 0);
	imageColor(155);
	rectMode(CORNER);
}
void STAGESELECT::create() {
	StageSelect = game()->container()->stageselect();
	SS_Images = game()->container()->stage_select_image();
}
void STAGESELECT::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->player()->init();
		game()->clone()->init();
		game()->woodbox()->init();
		game()->changeScene(GAME::STAGE_ID);
	}
}

void STAGESELECT::init()
{
	game()->player()->init();
	game()->clone()->init();
	game()->woodbox()->init();
}
