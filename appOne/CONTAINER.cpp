#include "CONTAINER.h"

void CONTAINER::load() {
	SceneSetData();
	ImageSetData();
	MapSetData();
	CharacterSetData();
}
void CONTAINER::ImageSetData() {
	//�^�C�g��
		//�w�i
	Images.title.images[0].image = loadImage("assets\\title\\back.png");
		//�^�C�g��
	Images.title.images[4].image = loadImage("assets\\title\\size_and_clone.png");
	Images.title.images[4].pos.x = width / 2;
	Images.title.images[4].pos.y = height / 4;
	/*--------------forloop�̂��߂S���ɐ錾���Ă�------------------*/
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
	//�X�e�[�W�I��
	Images.stage_select.image = loadImage("assets\\stage_select\\Stage_Select.png");	
	Images.stage_select.pos.x = 0;
	Images.stage_select.pos.y = 0;
	Images.stage_select.size = 1;
	Images.stage_select.transmission = 0;
	/*---------------------------------------------------------*/
	//�X�e�[�W
	Images.stage.image = loadImage("assets\\character\\player96.png");
	Images.stage.back = loadImage("assets\\stage\\back.png");
	Images.stage.tile = loadImage("assets\\stage\\tile60.png");
	Images.stage.thorn = loadImage("assets\\stage\\thorn60.png");
	Images.stage.clone_machine = loadImage("assets\\stage\\clone_machine128.png");
	Images.stage.woodBox = loadImage("assets\\stage\\woodBox60.png");
	Images.stage.button = loadImage("assets\\stage\\button.png");
	//�Q�[���N���A
	Images.game_clear.images[0].image = loadImage("assets\\stage_clear\\model.png");
	//�Q�[���N���A
	Images.game_over.images[0].image = loadImage("assets\\game_over\\model.png");
}

void CONTAINER::SceneSetData() {
	//�^�C�g��
		//���j���[�֘A
	Data.title.added = 4;
	Data.title.alpha = 255;
	Data.title.selection = 1;
	//�X�e�[�W

	//�X�e�[�W�I��
	Data.stage_select.backColor = COLOR(205, 205, 205);
	
	//�Q�[���I�[�o�[
	Data.game_over.backColor = COLOR(0, 0, 0);
	Data.game_over.textColor = COLOR(255, 255, 255);
	Data.game_over.textSize = 300;
	Data.game_over.pos.x = 0;
	Data.game_over.pos.y = height / 2;
	strcpy_s(Data.game_over.str, Data.game_over.memorySize, "game_over");
	//�Q�[���N���A
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
			//1�X�e�[�W
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
			{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//2
			{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//3
			{1,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//4
			{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//6
			{1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//7
			{1,0,0,0,0,0,0,0,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,5,1},//8
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},//9
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},//10
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//11
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//12
			{1,0,1,0,1,0,0,3,2,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0},//13
			{1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},//14
			{1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1},//15
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//16
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//17
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//18
		},
		{
			//2�X�e�[�W
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
	//�v���C���[
	Character.player.image = loadImage("assets\\character\\player96.png");
	Character.player.pos.x = 120;
	Character.player.pos.y = height / 2;
	Character.player.vec.x = 1;
	Character.player.vec.y = 1;
	Character.player.moveSpeed = 7;
	Character.player.g = 10;
	Character.player.angle = 0;
	Character.player.size = 1;
	Rect.Prect.w = 55;
	Rect.Prect.h = 96-7;
	//��
	Character.player.sound = loadSound("assets\\sound\\gutya.wav");
	//�N���[��
	Character.clone.cloneNum = 0;
	Character.clone.cloneTotalNum = 5;
	Character.clone.image = loadImage("assets\\character\\clone96.png");
	Character.clone.moveSpeed = 7;
	Character.clone.angle = 0;
	//��
	Character.clone.sound = loadSound("assets\\sound\\gutya.wav");
	//�ؔ�
	Character.wbox.image = loadImage("assets\\stage\\woodBox60.png");
	Character.wbox.pos.x = 120;
	Character.wbox.pos.y = 120;
	Character.wbox.vec.x = 1;
	Character.wbox.vec.y = 1;
	Character.wbox.moveSpeed = 7;
	Character.wbox.g = 10;
}