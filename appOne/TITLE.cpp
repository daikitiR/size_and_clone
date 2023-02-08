#include "TITLE.h"
#include "CONTAINER.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game) {

}
TITLE::~TITLE() {
}
//プライベート関数
void TITLE::select(int *selection) {
	static int i = 1;

	if (isTrigger(KEY_W) || isTrigger(KEY_UP)) {
		i--;
		if (i == 0)
			i = 3;
		*selection = i;
	}
	else if (isTrigger(KEY_S)|| isTrigger(KEY_DOWN)) {
		i = i % 3 + 1;
		*selection = i;
	}
}
void TITLE::MenuBarDraw() {
	int curimageX = 125/2;
	int imageX[3] = { 244/2 +curimageX ,491/2+curimageX,366/2 +curimageX };
	noStroke();
	if (Title.alpha > 255 || Title.alpha < 50) {
		Title.added *= -1;
	}
	Title.alpha += Title.added;
	
	fill(Title.MenuBarColor);
	//選択
	select(&Title.selection);
	//表示
	imageColor(255,255,255,Title.alpha);
	image(T_Images.images[5].image, T_Images.images[Title.selection].pos.x-imageX[Title.selection-1], T_Images.images[Title.selection].pos.y, T_Images.images[5].angle, T_Images.images[5].size);
	//ここをいじればタイトルの画面の明るさを調整できる
	/*何かに利用できるかも*/
	imageColor(200);
}
//パブリック関数
void TITLE::draw() {
	clear(Title.backColor);
	image(T_Images.images[0].image, T_Images.images[0].pos.x, T_Images.images[0].pos.y, T_Images.images[0].angle, T_Images.images[0].size);
	for (int i = 1; i < T_Images.T_image_num - 1; i++) {
		imageColor(200);
		rectMode(CENTER);
		image(T_Images.images[i].image, T_Images.images[i].pos.x, T_Images.images[i].pos.y, T_Images.images[i].angle, T_Images.images[i].size);
		
	}
	//メニューバー
	MenuBarDraw();
	rectMode(CORNER);
}
	//初期化
void TITLE::create() {
	Title = game()->container()->title();
	T_Images = game()->container()->title_image();
}
void TITLE::update() {

}
void TITLE::nextScene() {

	switch (Title.selection)
	{
	case 1:
		if (isTrigger(KEY_Z)) {
			game()->changeScene(GAME::STAGE_SELECT_ID);
		}
		break;
	case 2:
		if (isTrigger(KEY_Z)) {
			game()->changeScene(GAME::STAGE_SELECT_ID);
		}
		break;
	default:
		if (isTrigger(KEY_Z)) {
			
		}
		break;
	}
}