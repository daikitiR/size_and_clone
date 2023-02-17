#include "GAME_CLEAR.h"
#include "CONTAINER.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {

}
GAME_CLEAR::~GAME_CLEAR() {

}
void GAME_CLEAR::draw() {
	clear(Game_clear.backColor);
	image(C_image.images[0].image, 0, 0, 0);
}
void GAME_CLEAR::create()
{
	Game_clear = game()->container()->game_clear();
	C_image = game()->container()->game_clear_image();
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
