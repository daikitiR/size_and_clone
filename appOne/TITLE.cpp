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

	if (isTrigger(KEY_W)) {
		i--;
		if (i == 0)
			i = 3;
		*selection = i;
	}
	else if (isTrigger(KEY_S)) {
		i = i % 3 + 1;
		*selection = i;
	}
}
void TITLE::MenuBarDraw() {
	noStroke();
	if (Title.alpha > 255 || Title.alpha < 50) {
		Title.added *= -1;
	}
	Title.alpha += Title.added;
	Title.MenuBarColor = COLOR(102, 221, 255, Title.alpha);
	fill(Title.MenuBarColor);
	//選択
	select(&Title.selection);
	//表示
	rect(Title.menuname[Title.selection].pos.x, Title.menuname[Title.selection].pos.y, 50 * strlen(Title.menuname[Title.selection].str), 5);
}
//パブリック関数
void TITLE::draw() {
	clear(Title.backColor);
	fill(Title.textColor);
	image(T_Images.image, T_Images.pos.x,T_Images.pos.y,T_Images.angle,T_Images.size);
	textSize(Title.textSize);
	text(Title.menuname->str, Title.menuname->pos.x, Title.menuname->pos.y);

	//メニュー
	textSize(Title.menuSize);
	fill(Title.MenuTextColor);
	for (int i = 1; i < Title.menunum; i++) {
		text(Title.menuname[i].str, Title.menuname[i].pos.x,Title.menuname[i].pos.y);
	}
	//メニューバー
	MenuBarDraw();

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