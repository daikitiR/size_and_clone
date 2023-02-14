#include "PLAYER.h"
#include "STAGE.h"
#include "CONTAINER.h"
PLAYER::PLAYER(class GAME* game) :
	CHARACTER(game) {
};
PLAYER::~PLAYER()
{
}

void PLAYER::create()
{
	Player = game()->container()->player();

}

void PLAYER::init()
{
	Player = game()->container()->player();
}


void PLAYER::update()
{
	moveX();
	collisionX();
	moveY();
	collisionY();
}


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

}
void PLAYER::collisionX()
{
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	struct RECT {
		float x, y, w, h;
		float right, left, top, bottom;
	};
	RECT p{};
	//動的確保しろ
	//プレイヤーの当たり判定
	p.x = Player.pos.x + 18;
	p.y = Player.pos.y;
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
					//右の判定が働いているときに上下の判定を行わない
					if (p.right > map->left[i][j]) {
						Player.pos.x = pustPlayerX;
					}
					//hidari
					//左の判定が働いているときに上下の判定を行わない
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
	struct RECT {
		float x, y, w, h;
		float right, left, top, bottom;
	};
	RECT p{};
	//動的確保しろ
	//プレイヤーの当たり判定
	p.x = Player.pos.x + 18;
	p.y = Player.pos.y;
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
			}
		}
	}
	delete map;
}

void PLAYER::draw()
{
	image(Player.image, Player.pos.x, Player.pos.y,Player.angle,Player.size);
}
