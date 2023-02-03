#include "GAME_CLEAR.h"
#include "CONTAINER.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {

}
GAME_CLEAR::~GAME_CLEAR() {

}
void GAME_CLEAR::draw() {
	clear(Game_clear.backColor);
	fill(Game_clear.textColor);
	textSize(Game_clear.textSize);
	text(Game_clear.str, Game_clear.pos.x, Game_clear.pos.y);
}
void GAME_CLEAR::create()
{
	Game_clear = game()->container()->game_clear();
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
