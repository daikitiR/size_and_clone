#include "CONTAINER.h"

void CONTAINER::load() {
	SceneSetData();
}
void CONTAINER::SceneSetData() {
	//タイトル
	Data.title.backColor = COLOR(0, 0, 0);
	Data.title.textColor = COLOR(255, 255, 255);
	Data.title.textSize = 300;
	Data.title.pos.x = 0;
	Data.title.pos.y = height / 2;
	strcpy_s(Data.title.str,Data.title.memorySize, "Size & Clone");
	//ステージ
	Data.stage.backColor = COLOR(0, 0, 0);
	Data.stage.textColor = COLOR(255, 255, 255);
	Data.stage.textSize = 300;
	Data.stage.pos.x = 0;
	Data.stage.pos.y = height / 2;
	strcpy_s(Data.stage.str, Data.stage.memorySize, "STAGE");
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