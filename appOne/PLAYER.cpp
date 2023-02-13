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
	collision();
	move();
}

void PLAYER::move() {
	Player.vec = normalize(Player.vec);
	if (isPress(KEY_D)) {
		Player.pos.x += Player.vec.x * Player.moveSpeed;
	}
	if (isPress(KEY_A)) {
		Player.pos.x -= Player.vec.x * Player.moveSpeed;
	}
	if (isPress(KEY_W)) {
		Player.pos.y -= Player.vec.y * Player.moveSpeed;
	}
	if (isPress(KEY_S)) {
		Player.pos.y += Player.vec.y * Player.moveSpeed;
	}
}

void PLAYER::collision()
{
	STAGE::MAPS map = game()->container()->stage_map();
	struct RECT {
		float x,y, w, h;
		float right, left, top,bottom;
	};
	RECT p{}, b[map.COLS][map.ROWS]{};
	//プレイヤーの当たり判定
	p.x = Player.pos.x + 18;
	p.y = Player.pos.y;
	p.w = 60;	
	p.h = 96-7;
	p.right = p.x;
	p.left = p.x + p.w;
	p.bottom = p.y;
	p.top = p.y + p.h;
	//ブロックの当たり判定
	for (int i = 0; i < map.COLS; i++) {
		for (int j = 0; j < map.ROWS; j++) {
			b[i][j].x = map.pos[i][j].x;
			b[i][j].y = map.pos[i][j].y;
			b[i][j].w = 60;
			b[i][j].h = 60;
			b[i][j].right = b[i][j].x + b[i][j].w + p.w;
			b[i][j].left = b[i][j].x - p.w;
			b[i][j].bottom = b[i][j].y + b[i][j].h + p.h;
			b[i][j].top = b[i][j].y - p.h;
		}
	}
	//確認用
	int pxR = p.right;
	int pyB = p.bottom;
	textSize(200);
	fill(200);
	text(pxR, width / 2, height / 2);
	text(pyB, width / 2, height / 2+200);
	//当たったら
	for (int i = 0; i < map.COLS; i++) {
		for (int j = 0; j < map.ROWS; j++) {
			fill(0,0,0,75);
			textSize(20);
			text(b[i][j].left , 60 * j, 60 * i + 60);
			text(b[i][j].top, 60 * j, 60 * i + 40);
			
			if (p.right > b[i][j].left &&
				p.left < b[i][j].right &&
				p.bottom > b[i][j].top &&
				p.top < b[i][j].bottom) {
				if (map.MAP[0][i][j] == 1) {
					int flag = 0;
					flag == 1;
				//確認用
				fill(255, 0, 0,155);
				rect(map.pos[i][j].x, map.pos[i][j].y, 60, 60);
				float Pbacky = p.bottom - b[i][j].top;
				float Pbackx = p.right - b[i][j].left;
				Player.pos.y -= Pbacky;
				//Player.pos.x -= Pbackx;
					////調整するだけ

				}
			}
		}
	}
}

void PLAYER::draw()
{
	image(Player.image, Player.pos.x, Player.pos.y,Player.angle,Player.size);
}
