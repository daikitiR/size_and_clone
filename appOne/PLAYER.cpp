#include "PLAYER.h"
#include"CLONE.h"
#include "STAGE.h"
#include "CONTAINER.h"
#include "WOODBOX.h"
PLAYER::PLAYER(class GAME* game) :
	CHARACTER(game) {
};
PLAYER::~PLAYER()
{
}
//初期化みたいなもん
void PLAYER::create()
{
	Player = game()->container()->player();
}
//初期化
void PLAYER::init()
{
	Player = game()->container()->player();
	p = game()->container()->playerRect();
}

void PLAYER::update()
{
	sizeChange();
	game()->woodbox()->PlayercolMove(&Player.pos,p.sizecal);
	cloneSpawn();
	moveX();
	collisionX();
	moveY();
	collisionY();
}
//動き
void PLAYER::moveX()
{
	Player.vec = normalize(Player.vec);
	pustPlayerX = Player.pos.x;
	if (isPress(KEY_D)) {
		Player.pos.x += Player.vec.x * Player.moveSpeed;
	}
	if (isPress(KEY_A)) {
		Player.pos.x -= Player.vec.x * Player.moveSpeed;
	}
}
void PLAYER::moveY()
{
	Player.vec = normalize(Player.vec);
	pustPlayerY = Player.pos.y;
	if (isPress(KEY_W)) {
		Player.pos.y -= Player.vec.y * Player.moveSpeed;
	}
	if (isPress(KEY_S)) {
		Player.pos.y += Player.vec.y * Player.moveSpeed;
	}
	//gravity();
}
void PLAYER::collisionX()
{

	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	//プレイヤーの当たり判定
	p.x = Player.pos.x + 18;
	p.y = Player.pos.y;
	p.right = p.x + p.w;
	p.left = p.x + 15 * p.sizecal;
	p.bottom = p.y + p.h ;
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
						Player.pos.x = pustPlayerX;
					}
					//hidari
					if (p.left < map->right[i][j]) {
						Player.pos.x = pustPlayerX;
					}
				}
			}
		}
	}
	delete map;
}
void PLAYER::collisionY() {
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();	
	//プレイヤーの当たり判定
	p.x = Player.pos.x + 18;
	p.y = Player.pos.y;
	p.right = p.x + p.w;
	p.left = p.x + 15* p.sizecal;
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
						Player.pos.y = pustPlayerY;
					}
					//ue
					if (p.top < map->bottom[i][j]) {
						Player.pos.y = pustPlayerY;
					}
				}
				//とげに当たったら
				else if (map->MAP[0][i][j] == 2) {					
					playSound(Player.sound);
					game()->changeScene(GAME::GAME_OVER_ID);					
				}
			}
		}
	}
	delete map;
}
void PLAYER::gravity()
{
	Player.pos.y += Player.vec.y * Player.g;
	if (JumpNow == 0) {
		if (isTrigger(KEY_SPACE)) {
			JumpNow = 1;
			vy = -19;
		}
	}
	if (JumpNow) {
		vy += 0.5f;
		Player.pos.y += vy;
		if (vy == Player.g) {
			JumpNow = 0;
		}
	}
}
//描画
void PLAYER::draw()
{
	image(Player.image, Player.pos.x, Player.pos.y,Player.angle,Player.size);
}

void PLAYER::woodcol(VECTOR2* wpos)
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
	p.x = Player.pos.x + 18;
	p.y = Player.pos.y;
	p.right = p.x + p.w;
	p.left = p.x + 15 * p.sizecal;
	p.bottom = p.y + p.h;
	p.top = p.y;
	if (p.right > rect->left &&
		p.left < rect->right &&
		p.top < rect->bottom &&
		p.bottom > rect->top) {
		Player.pos.y = pustPlayerY;
	}

}

void PLAYER::cloneSpawn() {
	if (isTrigger(KEY_G)) {
		game()->clone()->spawn(Player.pos);
	}
}

void PLAYER::sizeChange() {
	if (Player.flag == 0) {
		if (isTrigger(KEY_E)) {
			Player.size = 2;
			Player.pos.y -= p.h;
			p.sizecal = 2;
			p.w *= 2;
			p.h *= 2;
			Player.flag = 1;
		}
	}
	if (Player.flag == 1) {
		if (isTrigger(KEY_Q)) {
			Player.size = 1;
			p.w /= 2;
			p.h /= 2;
			Player.pos.y += p.h;
			p.sizecal = 1;
			Player.flag = 0;
		}
	}
}