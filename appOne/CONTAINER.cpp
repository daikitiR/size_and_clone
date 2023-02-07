#include "CONTAINER.h"

void CONTAINER::load() {
	SceneSetData();
	ImageSetData();
}
void CONTAINER::ImageSetData() {
	//タイトル
		//背景
	Images.title.images[0].image = loadImage("assets\\title\\back.png");
	Images.title.images[0].pos.x = 0;
	Images.title.images[0].pos.y = 0;
	Images.title.images[0].angle = 0;
	//タイトル
	Images.title.images[4].image = loadImage("assets\\title\\size_and_clone.png");
	Images.title.images[4].pos.x = width / 2;
	Images.title.images[4].pos.y = height / 4;
	/*--------------forloopのため４を先に宣言してる------------------*/
		//play
	Images.title.images[1].image = loadImage("assets\\title\\play.png");
	Images.title.images[1].pos.x = width / 2;
	Images.title.images[1].pos.y = Images.title.images[4].pos.y / 2 +400;
		//newplay
	Images.title.images[2].image = loadImage("assets\\title\\new_play.png");
	Images.title.images[2].pos.x = width / 2;
	Images.title.images[2].pos.y = Images.title.images[1].pos.y + 150;
		//option
	Images.title.images[3].image = loadImage("assets\\title\\option.png");
	Images.title.images[3].pos.x = width / 2;
	Images.title.images[3].pos.y = Images.title.images[2].pos.y + 150;
		//Cursor
	Images.title.images[5].image = loadImage("assets\\title\\Cursor.png");
	
	//ステージ選択
	Images.stage_select.image = loadImage("assets\\stageselect.png");	
	Images.stage_select.pos.x = width / 10;
	Images.stage_select.pos.y = Data.stage_select.string[0].pos.y - Data.stage_select.expTextSize*2;
	Images.stage_select.angle = 0;
	Images.stage_select.size = 0.5;
	Images.stage_select.transmission = 0;
}

void CONTAINER::SceneSetData() {
	//タイトル
	Data.title.backColor = COLOR(0, 0, 0);
	Data.title.textColor = COLOR(255, 255, 255);
	Data.title.textSize = 300;
	strcpy_s(Data.title.menuname[0].str, Data.title.memorySize, "Size & Clone");
		//メニュー関連
	Data.title.MenuBarColor = COLOR(102, 221, 255,Data.title.alpha);
	Data.title.MenuTextColor = COLOR(171, 230, 247);
	Data.title.menuSize = 100;
	Data.title.added = 4;
	Data.title.alpha = 255;
	Data.title.selection = 1;
	

	//ステージ
	Data.stage.backColor = COLOR(0, 0, 0);
	Data.stage.textColor = COLOR(255, 255, 255);
	Data.stage.textSize = 300;
	strcpy_s(Data.stage.str, Data.stage.memorySize, "STAGE");
	Data.stage.pos.x = 0;
	Data.stage.pos.y = height / 2;
	//ステージ選択
	Data.stage_select.backColor = COLOR(205, 205, 205);
	Data.stage_select.textColor = COLOR(0, 11, 0);
	Data.stage_select.textSize = 100;
	strcpy_s(Data.stage_select.string[0].str, Data.stage_select.memorySize, "STAGE_SELECT");
	Data.stage_select.string[0].pos.x = width - strlen(Data.stage_select.string[0].str) * Data.stage_select.textSize / 2 - 100;
	Data.stage_select.string[0].pos.y = Data.stage_select.textSize * 2;
		//説明欄
	Data.stage_select.expTextSize = 50;
	strcpy_s(Data.stage_select.string[0].explain, Data.stage_select.chars,
		"ここに説明を入れる\nここに説明を入れる\nここに説明を入れる\n");
	Data.stage_select.string[0].exppos.x = Data.stage_select.string[0].pos.x;
	Data.stage_select.string[0].exppos.y = Data.stage_select.string[0].pos.y + Data.stage_select.expTextSize;
	//ゲームオーバー
	Data.game_over.backColor = COLOR(0, 0, 0);
	Data.game_over.textColor = COLOR(255, 255, 255);
	Data.game_over.textSize = 300;
	Data.game_over.pos.x = 0;
	Data.game_over.pos.y = height / 2;
	strcpy_s(Data.game_over.str, Data.game_over.memorySize, "game_over");
	//ゲームクリア
	Data.game_clear.backColor = COLOR(0, 0, 0);
	Data.game_clear.textColor = COLOR(255, 255, 255);
	Data.game_clear.textSize = 300;
	Data.game_clear.pos.x = 0;
	Data.game_clear.pos.y = height / 2;
	strcpy_s(Data.game_clear.str, Data.game_clear.memorySize, "game_clear");
}
