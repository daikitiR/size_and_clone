#include "STAGESELECT.h"
#include "CONTAINER.h"
STAGESELECT::STAGESELECT(class GAME* game) :
	SCENE(game) {

}
STAGESELECT::~STAGESELECT() {

}
void STAGESELECT::draw() {
	clear(StageSelect.backColor);
	fill(StageSelect.textColor);
	image(S_Images.image, S_Images.pos.x, S_Images.pos.y, S_Images.angle, S_Images.size);
	textSize(StageSelect.textSize);
	text(StageSelect.string[0].str, StageSelect.string[0].pos.x, StageSelect.string[0].pos.y);
	textSize(StageSelect.expTextSize);
	text(StageSelect.string[0].explain, StageSelect.string[0].exppos.x, StageSelect.string[0].exppos.y);
}
void STAGESELECT::create() {
	StageSelect = game()->container()->stageselect();
	S_Images = game()->container()->stage_select_image();
}
void STAGESELECT::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}