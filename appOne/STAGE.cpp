#include "STAGE.h"
#include "CONTAINER.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {

}
STAGE::~STAGE() {

}
void STAGE::draw() {
	clear(Stage.backColor);
	image(S_Images.image2, 0,0);
	image(S_Images.image, 0, height / 2+175, 0, 1);
	for (int i = 0; i < Map.COLS; i++) {
		for (int j = 0; j < Map.ROWS; j++) {
			strokeWeight(1);
			if (Map.MAP[0][i][j] == 1) {
				fill(255, 255, 255, 155);
				rect(60 * j, 60 * i, 60, 60);
			}
			else {
				fill(0,0,0,155);
				rect(60 * j, 60 * i, 60, 60);
			}
		}
	}
}
void STAGE::mapcreate()
{
	

}

void STAGE::create() {
	Stage = game()->container()->stage();
	S_Images = game()->container()->stage_image();
	Map = game()->container()->stage_map();
}
void STAGE::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}