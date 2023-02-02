#include "CONTAINER.h"

void CONTAINER::load() {
	SceneSetData();
	ImageSetData();
}
void CONTAINER::ImageSetData() {
	//タイトル
	Images.title.title_image = loadImage("assets\\kariTitle.png");
	Images.title.pos.x = 0;
	Images.title.pos.y = 0;
	Images.title.angle = 0;
	Images.title.size = 2;
	Images.title.transmission = 0;
	//ステージ選択
	
}

void CONTAINER::SceneSetData() {
	//タイトル
	Data.title.backColor = COLOR(0, 0, 0);
	Data.title.textColor = COLOR(255, 255, 255);
	Data.title.textSize = 300;
	Data.title.menuname[0].pos.x = 70;
	Data.title.menuname[0].pos.y = height / 2 + -200;
	strcpy_s(Data.title.menuname[0].str, Data.title.memorySize, "Size & Clone");
		//メニュー関連
	Data.title.MenuBarColor = COLOR(102, 221, 255,Data.title.alpha);
	Data.title.MenuTextColor = COLOR(171, 230, 247);
	Data.title.menuSize = 100;
	Data.title.added = 4;
	Data.title.alpha = 255;
	Data.title.selection = 1;
	strcpy_s(Data.title.menuname[1].str, Data.title.memorySize, "はじめから");
	strcpy_s(Data.title.menuname[2].str, Data.title.memorySize, "続きから");
	strcpy_s(Data.title.menuname[3].str, Data.title.memorySize, "おわる");
	for (int i = 1; i < Data.title.menunum; i++) {
		Data.title.menuname[i].pos.x = width / 2 - 250 + 25 * (i-1);
		Data.title.menuname[i].pos.y = Data.title.menuname[0].pos.y + 400 + (i-1) * 100;
	}

	//ステージ
	Data.stage.backColor = COLOR(0, 0, 0);
	Data.stage.textColor = COLOR(255, 255, 255);
	Data.stage.textSize = 300;
	Data.stage.pos.x = 0;
	Data.stage.pos.y = height / 2;
	strcpy_s(Data.stage.str, Data.stage.memorySize, "STAGE");
	//ステージ選択
	Data.stage_select.backColor = COLOR(205, 205, 205);
	Data.stage_select.textColor = COLOR(0, 11, 0);
	Data.stage_select.textSize = 300;
	Data.stage_select.pos.x = 0;
	Data.stage_select.pos.y = height / 2;
	strcpy_s(Data.stage_select.str, Data.stage_select.memorySize, "STAGE_SELECT");
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
