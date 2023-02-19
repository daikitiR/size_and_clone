#include "CLONE.h"
#include "STAGE.h"
#include "PLAYER.h"
#include "WOODBOX.h"
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
		game()->woodbox()->ClonecolMove(&TheClone[i].pos,1);
		moveX(i);
		collisionX(i);
		moveY(i);
		collisionY(i);
	}
}
void CLONE::spawn(float posx,float posy) {
	if (Clone.cloneNum < Clone.cloneTotalNum) {
		int i = Clone.cloneNum;
		TheClone[i].pos.x = posx;
		TheClone[i].pos.y = posy;
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
		//クローンの当たり判定
	p.x = TheClone[NUM].pos.x + 18;
	p.y = TheClone[NUM].pos.y;
	p.right = p.x + p.w;
	p.left = p.x;
	p.bottom = p.y + p.h;
	p.top = p.y;
	//当たったら
	int flag = 0;
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
					playSound(Clone.sound);
					if (flag == 0) {
						kill(NUM);
						flag = 1;
					}
				}
			}
		}
	}
	flag = 0;
	delete map;
}
void CLONE::collisionY(int NUM) {
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();

	//プレイヤーの当たり判定
	p.x = TheClone[NUM].pos.x + 18;
	p.y = TheClone[NUM].pos.y;
	p.right = p.x + p.w;
	p.left = p.x;
	p.bottom = p.y + p.h;
	p.top = p.y;
	//ブロックに当たったら
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
			}
		}
	}
	delete map;
}
void CLONE::gravity(int i)
{
	TheClone[i].pos.y += TheClone[i].vec.y * TheClone[i].g;
	if (TheClone[i].JumpNow == 0) {
		if (isTrigger(KEY_SPACE)) {
			TheClone[i].JumpNow = 1;
			TheClone[i].vy = -19;
		}
	}
	if (TheClone[i].JumpNow) {
		TheClone[i].vy += 0.5f;
		TheClone[i].pos.y += TheClone[i].vy;
		if (TheClone[i].vy == TheClone[i].g) {
			TheClone[i].JumpNow = 0;
		}
	}
}

void CLONE::woodcol(int i,VECTOR2* wpos)
{
	WOODBOX::RECT* rect = new WOODBOX::RECT;
	*rect = game()->container()->woodboxRect();
	//木箱の当たり判定
	rect->x = wpos->x;
	rect->y = wpos->y;
	rect->right = rect->x + rect->w;
	rect->left = rect->x;
	rect->bottom = rect->y + rect->h;
	rect->top = rect->y;
	//プレイヤーの当たり判定
	p.x = TheClone[i].pos.x + 18;
	p.y = TheClone[i].pos.y;
	p.right = p.x + p.w;
	p.left = p.x;
	p.bottom = p.y + p.h;
	p.top = p.y;
	if (p.right > rect->left &&
		p.left < rect->right &&
		p.top < rect->bottom &&
		p.bottom > rect->top) {
		TheClone[i].pos.y = TheClone[i].pustCloneY;
	}
}
void CLONE::kill(int i)
{
	Clone.cloneNum--;
	TheClone[i] = TheClone[Clone.cloneNum];
}
