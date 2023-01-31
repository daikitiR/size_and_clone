#include "STAGE.h"
#include "CONTAINER.h"
#include "libOne.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {

}
STAGE::~STAGE() {

}
void STAGE::draw() {
	clear(Stage.backColor);
	fill(Stage.textColor);
	textSize(Stage.textSize);
	text(Stage.str, Stage.pos.x, Stage.pos.y);
}
void STAGE::create() {
	Stage = game()->container()->stage();
}
void STAGE::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}