#include "GAME_OVER.h"
#include "CONTAINER.h"
#include "libOne.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {

}
GAME_OVER::~GAME_OVER() {

}
void GAME_OVER::draw() {
	clear(Game_over.backColor);
	fill(Game_over.textColor);
	textSize(Game_over.textSize);
	text(Game_over.str, Game_over.pos.x, Game_over.pos.y);
}
void GAME_OVER::create()
{
	Game_over = game()->container()->game_over();
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}