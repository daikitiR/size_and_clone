#include "GAME_OVER.h"
#include "CONTAINER.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {

}
GAME_OVER::~GAME_OVER() {

}
void GAME_OVER::draw() {
	clear(Game_over.backColor);
	image(O_image.images[0].image, 0, 0, 0);

}
void GAME_OVER::create()
{
	Game_over = game()->container()->game_over();
	O_image = game()->container()->game_over_image();
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}