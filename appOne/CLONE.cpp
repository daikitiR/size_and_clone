#include "CLONE.h"
#include "STAGE.h"
#include "CONTAINER.h"
CLONE::CLONE(class GAME* game) :
	CHARACTER(game) {
};
CLONE::~CLONE()
{
	delete[] TheClone;
}

void CLONE::create()
{
	Clone = game()->container()->clone();
	TheClone = new TheCLONE[Clone.cloneTotalNum];	
}
void CLONE::init()
{
	Clone.cloneNum = 0;
}
void CLONE::update()
{
	for (int i = Clone.cloneNum - 1; i >= 0; i--) {
		moveX(i);
		collisionX(i);
		moveY(i);
		collisionY(i);

	}
}
void CLONE::spawn(const VECTOR2& pos)
{
	
	if (Clone.cloneNum < Clone.cloneTotalNum) {
		int i = Clone.cloneNum;
		TheClone[i].pos.x = pos.x;
		TheClone[i].pos.y = pos.y;
		Clone.cloneNum++;
	}
}
//描画
void CLONE::draw()
{
	fill(255);
	text(Clone.cloneNum, width / 2, height / 2);
	for (int i = 0; i<Clone.cloneNum; i++) {
		image(Clone.image, TheClone[i].pos.x, TheClone[i].pos.y, Clone.angle, TheClone[i].size);
	}
}
//動き
void CLONE::moveX(int i)
{
	TheClone[i].vec = normalize(TheClone[i].vec);
	TheClone[i].pustCloneX = TheClone[i].pos.x;

	if (isPress(KEY_D)) {
		TheClone[i].pos.x += TheClone[i].vec.x * Clone.moveSpeed;
	}
	if (isPress(KEY_A)) {
		TheClone[i].pos.x -= TheClone[i].vec.x * Clone.moveSpeed;
	}
}
void CLONE::moveY(int i )
{
	TheClone[i].vec = normalize(TheClone[i].vec);
	TheClone[i].pustCloneY = TheClone[i].pos.y;
	gravity(i);
}
void CLONE::collisionX(int NUM)
{
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	struct RECT {
		float x, y, w, h;
		float right, left, top, bottom;
	};
	RECT p{};
	//プレイヤーの当たり判定
	p.x = TheClone[NUM].pos.x + 18;
	p.y = TheClone[NUM].pos.y;
	p.w = 60;
	p.h = 96 - 7;
	p.right = p.x + p.w;
	p.left = p.x;
	p.bottom = p.y + p.h;
	p.top = p.y;
	//当たったら
	for (int i = 0; i < map->COLS; i++) {
		for (int j = 0; j < map->ROWS; j++) {
			if (p.right > map->left[i][j] &&
				p.left < map->right[i][j] &&
				p.bottom > map->top[i][j] &&
				p.top < map->bottom[i][j]) {
				if (map->MAP[0][i][j] == 1) {
					//確認用
					fill(0, 255, 0, 155);
					rect(map->pos[i][j].x, map->pos[i][j].y, 60, 60);
					//migi
					if (p.right > map->left[i][j]) {
						TheClone[NUM].pos.x = TheClone[NUM].pustCloneX;
					}
					//hidari
					if (p.left < map->right[i][j]) {
						TheClone[NUM].pos.x = TheClone[NUM].pustCloneX;
					}

				}
				else if (map->MAP[0][i][j] == 2) {
					int sound = loadSound("assets\\sound\\gutya.wav");
					playSound(sound);
					kill(NUM);
				}
			}
		}
	}
	delete map;
}
void CLONE::collisionY(int NUM) {
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	struct RECT {
		float x, y, w, h;
		float right, left, top, bottom;
	};
	RECT p{};
	//プレイヤーの当たり判定
	p.x = TheClone[NUM].pos.x + 18;
	p.y = TheClone[NUM].pos.y;
	p.w = 60;
	p.h = 96 - 7;
	p.right = p.x + p.w;
	p.left = p.x;
	p.bottom = p.y + p.h;
	p.top = p.y;
	//当たったら
	for (int i = 0; i < map->COLS; i++) {
		for (int j = 0; j < map->ROWS; j++) {
			if (p.right > map->left[i][j] &&
				p.left < map->right[i][j] &&
				p.bottom > map->top[i][j] &&
				p.top < map->bottom[i][j]) {
				//タイル（ブロック）に当たったら
 				if (map->MAP[0][i][j] == 1) {
					//確認用
					fill(255, 0, 0, 155);
					rect(map->pos[i][j].x, map->pos[i][j].y, 60, 60);
					//sita
					if (p.bottom > map->top[i][j]) {
						TheClone[NUM].pos.y = TheClone[NUM].pustCloneY;
					}
					//ue
					if (p.top < map->bottom[i][j]) {
						TheClone[NUM].pos.y = TheClone[NUM].pustCloneY;
					}
				}
				//とげに当たったら
				else if (map->MAP[0][i][j] == 2) {
				}
			}
		}
	}
	delete map;
}
void CLONE::gravity(int i)
{
	TheClone[i].pos.y += TheClone[i].vec.y * Clone.g;
	if (JumpNow == 0) {
		if (isTrigger(KEY_SPACE)) {
			JumpNow = 1;
			vy = -19;
		}
	}
	if (JumpNow) {
		vy += 0.5f;
		TheClone[i].pos.y += vy;
		if (vy == Clone.g) {
			JumpNow = 0;
		}
	}
}

void CLONE::kill(int i)
{
	Clone.cloneNum--;
	TheClone[i] = TheClone[Clone.cloneNum];
}
