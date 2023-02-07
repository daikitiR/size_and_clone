#include "STAGE.h"
#include "CONTAINER.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {

}
STAGE::~STAGE() {

}
void STAGE::draw() {
	clear(Stage.backColor);
	fill(Stage.textColor);
	image(S_Images.image2, 0,0);
	image(S_Images.image, 0, height / 2+175, 0, 1);
	for (int i = 0; i < 32; i++) {
		//‰¡‚U‚O@c‚U‚O
		stroke(0);
		strokeWeight(1);
		for (int j = 0;j < 18; j++) {
			rect(60*i, 60 * j, 60, 60);
		}
	}
}
void STAGE::mapcreate()
{
	const char* fileName = "assets\\maps\\map1.txt";
	FILE* fp;
	fopen_s(&fp, fileName, "rb");
	fseek(fp, 0, SEEK_END);
	int fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	



	fclose(fp);
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