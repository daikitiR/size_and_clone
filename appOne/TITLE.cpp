#include "TITLE.h"
#include "libOne.h"
#include "CONTAINER.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game) {

}
TITLE::~TITLE() {
}
void TITLE::draw() {
	clear(Title.backColor);
	fill(Title.textColor);
	textSize(Title.textSize);
	text(Title.str, Title.pos.x, Title.pos.y);
}
void TITLE::create() {
	Title = game()->container()->title();
}
void TITLE::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}