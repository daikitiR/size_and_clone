#include "CONTAINER.h"

void CONTAINER::load() {
	SceneSetData();
	ImageSetData();
	MapSetData();
	CharacterSetData();
}
void CONTAINER::ImageSetData() {
	//タイトル
		//背景
	Images.title.images[0].image = loadImage("assets\\title\\back.png");
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
	/*---------------------------------------------------------*/
	//ステージ選択
	Images.stage_select.image = loadImage("assets\\stageselect.png");	
	Images.stage_select.pos.x = width / 10;
	Images.stage_select.pos.y = Data.stage_select.string[0].pos.y - Data.stage_select.expTextSize*2;
	Images.stage_select.angle = 0;
	Images.stage_select.size = 0.5;
	Images.stage_select.transmission = 0;
	/*---------------------------------------------------------*/
	//ステージ
	Images.stage.image = loadImage("assets\\character\\player96.png");
	Images.stage.back = loadImage("assets\\stage\\back.png");
	Images.stage.tile = loadImage("assets\\stage\\tile60.png");
	Images.stage.thorn = loadImage("assets\\stage\\thorn60.png");
	Images.stage.clone_machine = loadImage("assets\\stage\\clone_machine128.png");
	//ゲームクリア
	Images.game_clear.images[0].image = loadImage("assets\\stage_clear\\model.png");
	//ゲームクリア
	Images.game_over.images[0].image = loadImage("assets\\game_over\\model.png");
}

void CONTAINER::SceneSetData() {
	//タイトル
		//メニュー関連
	Data.title.added = 4;
	Data.title.alpha = 255;
	Data.title.selection = 1;
	//ステージ

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
		//下のステージの数を表すブロック
	for (int i = 0; i < Data.stage_select.stageNum; i++) {
		Data.stage_select.selectBlock[i].Size = 20;
		Data.stage_select.selectBlock[i].Block = 0;
		Data.stage_select.selectBlock[i].pos.x = width / 2 + i * 100;
		Data.stage_select.selectBlock[i].pos.y = height - 100;
	}
	//ゲームオーバー
	Data.game_over.backColor = COLOR(0, 0, 0);
	Data.game_over.textColor = COLOR(255, 255, 255);
	Data.game_over.textSize = 300;
	Data.game_over.pos.x = 0;
	Data.game_over.pos.y = height / 2;
	strcpy_s(Data.game_over.str, Data.game_over.memorySize, "game_over");
	//ゲームクリア
	Data.game_clear.backColor = COLOR(0, 0, 0);
	Data.game_clear.pos.x = 0;
	Data.game_clear.pos.y = height / 2;
}

void CONTAINER::MapSetData() {
	const int MAPNUM = Maps.stage.MAPNUM;
	const int COLS = Maps.stage.COLS;
	const int ROWS = Maps.stage.ROWS;

	int MAP[MAPNUM][COLS][ROWS]{
		{
			//1ステージ
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//1
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//2
			{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//3
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//4
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//5
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//6
			{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//7
			{0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//8
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},//9
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},//10
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//11
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//12
			{0,4,0,0,0,0,0,3,2,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//13
			{1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},//14
			{1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1},//15
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//16
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//17
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//18
		},
		{
			//2ステージ
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//1
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//2
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//3
				{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//4
				{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//5
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//6
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//7
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//8
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//9
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//10
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//11
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//12
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//13
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//14
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//15
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//16
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//17
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},//18
				}
	};
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			Maps.stage.MAP[0][i][j] = MAP[0][i][j];
			float I = i, J = j;
			Maps.stage.pos[i][j].x = 60 * J;
			Maps.stage.pos[i][j].y = 60 * I;
			Maps.stage.w= 60;
			Maps.stage.h= 60;
			Maps.stage.right[i][j] = Maps.stage.pos[i][j].x + Maps.stage.w;
			Maps.stage.left[i][j] = Maps.stage.pos[i][j].x;
			Maps.stage.bottom[i][j] = Maps.stage.pos[i][j].y + Maps.stage.h;
			Maps.stage.top[i][j] = Maps.stage.pos[i][j].y;
		}
	}
}

void CONTAINER::CharacterSetData() {
	//プレイヤー
	Character.player.image = loadImage("assets\\character\\player96.png");
	Character.player.pos.x = 0;
	Character.player.pos.y = height / 2;
	Character.player.vec.x = 1;
	Character.player.vec.y = 1;
	Character.player.moveSpeed = 7;
	Character.player.g = 10;
	Character.player.angle = 0;
	Character.player.size = 1;
	Character.player.sound = loadSound("assets\\sound\\gutya.wav");
	//クローン
	Character.clone.cloneNum = 0;
	Character.clone.cloneTotalNum = 5;
	Character.clone.image = loadImage("assets\\character\\clone96.png");
	Character.clone.moveSpeed = 7;
	Character.clone.g = 10;
	Character.clone.angle = 0;
	//単体のデータ
	
}