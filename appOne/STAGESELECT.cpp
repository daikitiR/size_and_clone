#include "STAGESELECT.h"
#include "CONTAINER.h"
#include "libOne.h"
STAGESELECT::STAGESELECT(class GAME* game) :
	SCENE(game) {

}
STAGESELECT::~STAGESELECT() {

}
void STAGESELECT::draw() {
	clear(StageSelect.backColor);
	fill(StageSelect.textColor);
	textSize(StageSelect.textSize);
	text(StageSelect.str, StageSelect.pos.x, StageSelect.pos.y);
}
void STAGESELECT::create() {
	StageSelect = game()->container()->stageselect();
}
void STAGESELECT::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}