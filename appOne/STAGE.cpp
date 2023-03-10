#include "STAGE.h"
#include "CONTAINER.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {

}
STAGE::~STAGE() {

}
void STAGE::draw() {
	clear(Stage.backColor);
	imageColor(255);
	image(S_Images.back, 0,0);	
	//マップ
	for (int i = 0; i < Map.COLS; i++) {
		for (int j = 0; j < Map.ROWS; j++) {
			strokeWeight(1);
			switch (Map.MAP[0][i][j])
			{
				//タイル
			case 1:
				image(S_Images.tile,Map.pos[i][j].x, Map.pos[i][j].y, 0, 1);
				break;
			//とげ
		case 2:
				image(S_Images.thorn, Map.pos[i][j].x, Map.pos[i][j].y, 0, 1);
				break;
			//クローン装置
			case 3:
				rectMode(CENTER);
				image(S_Images.clone_machine, Map.pos[i][j].x, Map.pos[i][j].y-4, 0, 1);
				rectMode(CORNER);
				break;
			case 4:
				break;
			case 5:
				image(S_Images.button, Map.pos[i][j].x, Map.pos[i][j].y+26, 0, 1);
				break;
			default:
				break;
			}
		}
	}
	//プレイヤー描画
	game()->player()->draw();
	game()->clone()->draw();
	game()->woodbox()->draw();
	imageColor(255);
}

void STAGE::create() {
	Stage = game()->container()->stage();
	S_Images = game()->container()->stage_image();
	Map = game()->container()->stage_map();
}
//アップデート
void STAGE::update()
{
	game()->player()->update();
	game()->clone()->update();
	game()->woodbox()->update();
}
void STAGE::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}