#include "WOODBOX.h"
#include "STAGE.h"
#include "PLAYER.h"
#include "CLONE.h"
#include "CONTAINER.h"
WOODBOX::WOODBOX(class GAME* game) :
	CHARACTER(game) {
};
WOODBOX::~WOODBOX()
{
}
//�������݂����Ȃ���
void WOODBOX::create()
{
	woodbox = game()->container()->woodbox();

}
//������
void WOODBOX::init()
{
	woodbox = game()->container()->woodbox();
	woodBoxRect = game()->container()->woodboxRect();
}
void WOODBOX::update()
{
	moveX();
	collisionX();
	moveY();
	collisionY();
}
void WOODBOX::draw()
{
	image(woodbox.image, woodbox.pos.x, woodbox.pos.y);
}

void WOODBOX::PlayercolMove(VECTOR2* pos, float size)
{
	PLAYER::RECT* rect = new PLAYER::RECT;
	*rect = game()->container()->playerRect();
	//�v���C���[�̓����蔻��
	rect->x = pos->x + 18;
	rect->y = pos->y;
	rect->right = rect->x + rect->w * size;
	rect->left = rect->x + 15 * size;
	rect->bottom = rect->y + rect->h * size;
	rect->top = rect->y;
	//�ؔ��̓����蔻��
	woodBoxRect.x = woodbox.pos.x;
	woodBoxRect.y = woodbox.pos.y;
	woodBoxRect.right = woodBoxRect.x + woodBoxRect.w;
	woodBoxRect.left = woodBoxRect.x;
	woodBoxRect.bottom = woodBoxRect.y + woodBoxRect.h;
	woodBoxRect.top = woodBoxRect.y;
	//�ؔ��̍��E����̐�Βl�̋���
	float Pmidx = rect->x + rect->w / 2;
	float Pmidy = rect->y + rect->h / 2;
	float WdisP_R = abs(Pmidx - woodBoxRect.right);
	float WdisP_L = abs(Pmidx - woodBoxRect.left);
	float WdisP_T = abs(Pmidy - woodBoxRect.top);
	float WdisP_B = abs(Pmidy - woodBoxRect.bottom);
	//�ؔ��ɓ��������Ȃ�
	if (woodBoxRect.right > rect->left &&
		woodBoxRect.left < rect->right &&
		woodBoxRect.bottom > rect->top &&
		woodBoxRect.top < rect->bottom) {
		if (woodBoxRect.top > Pmidy) {
			game()->player()->woodcol(&woodbox.pos);
		}
		//�E�̂ق�����������
		else if (WdisP_R > WdisP_L) {
			woodbox.pos.x = rect->right;
		}
		//��
		else if(WdisP_R < WdisP_L){
			woodbox.pos.x = rect->left - woodBoxRect.w;
		}
	
	}
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	//����������
	for (int i = 0; i < map->COLS; i++) {
		for (int j = 0; j < map->ROWS; j++) {
			if (woodBoxRect.right > map->left[i][j] &&
				woodBoxRect.left < map->right[i][j] &&
				woodBoxRect.bottom > map->top[i][j] &&
				woodBoxRect.top < map->bottom[i][j]) {
				if (map->MAP[0][i][j] == 1) {
					//migi
					if (woodBoxRect.right > map->left[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
					//hidari
					if (woodBoxRect.left < map->right[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
				}
				else if (map->MAP[0][i][j] == 2) {
					if (woodBoxRect.right > map->left[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
					//hidari
					if (woodBoxRect.left < map->right[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
				}
			}
		}
	}
	delete map;
}
void WOODBOX::ClonecolMove(VECTOR2* pos, int i)
{
	CLONE::RECT* rect = new CLONE::RECT;
	*rect = game()->container()->cloneRect();
	//�v���C���[�̓����蔻��
	rect->x = pos->x + 18;
	rect->y = pos->y;
	rect->right = rect->x + rect->w;
	rect->left = rect->x + 15;
	rect->bottom = rect->y + rect->h;
	rect->top = rect->y;
	//�ؔ��̓����蔻��
	woodBoxRect.x = woodbox.pos.x;
	woodBoxRect.y = woodbox.pos.y;
	woodBoxRect.right = woodBoxRect.x + woodBoxRect.w;
	woodBoxRect.left = woodBoxRect.x;
	woodBoxRect.bottom = woodBoxRect.y + woodBoxRect.h;
	woodBoxRect.top = woodBoxRect.y;
	//�ؔ��̍��E����̐�Βl�̋���
	float Pmidx = rect->x + rect->w / 2;
	float Pmidy = rect->y + rect->h / 2;
	float WdisP_R = abs(Pmidx - woodBoxRect.right);
	float WdisP_L = abs(Pmidx - woodBoxRect.left);
	float WdisP_T = abs(Pmidy - woodBoxRect.top);
	float WdisP_B = abs(Pmidy - woodBoxRect.bottom);
	//�ؔ��ɓ��������Ȃ�
	if (woodBoxRect.right > rect->left &&
		woodBoxRect.left < rect->right &&
		woodBoxRect.bottom > rect->top &&
		woodBoxRect.top < rect->bottom) {
		if (woodBoxRect.top > Pmidy) {
			game()->clone()->woodcol(i,&woodbox.pos);
		}
		//�E�̂ق�����������
		else if (WdisP_R > WdisP_L) {
			woodbox.pos.x = rect->right;
		}
		//��
		else if (WdisP_R < WdisP_L) {
			woodbox.pos.x = rect->left - woodBoxRect.w;
		}

	}
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	//����������
	for (int i = 0; i < map->COLS; i++) {
		for (int j = 0; j < map->ROWS; j++) {
			if (woodBoxRect.right > map->left[i][j] &&
				woodBoxRect.left < map->right[i][j] &&
				woodBoxRect.bottom > map->top[i][j] &&
				woodBoxRect.top < map->bottom[i][j]) {
				if (map->MAP[0][i][j] == 1) {
					//migi
					if (woodBoxRect.right > map->left[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
					//hidari
					if (woodBoxRect.left < map->right[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
				}
				else if (map->MAP[0][i][j] == 2) {
					if (woodBoxRect.right > map->left[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
					//hidari
					if (woodBoxRect.left < map->right[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
				}
			}
		}
	}
	delete map;
}


//���� �v���C�x�[�g�֐�
void WOODBOX::moveX()
{
	pustWoodBoxX = woodbox.pos.x;
}
void WOODBOX::moveY()
{
	pustWoodBoxY = woodbox.pos.y;
	gravity();
}
void WOODBOX::collisionX()
{
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	//�ؔ��̓����蔻��
	woodBoxRect.x = woodbox.pos.x;
	woodBoxRect.y = woodbox.pos.y;
	woodBoxRect.right = woodBoxRect.x + woodBoxRect.w;
	woodBoxRect.left = woodBoxRect.x;
	woodBoxRect.bottom = woodBoxRect.y + woodBoxRect.h;
	woodBoxRect.top = woodBoxRect.y;
	//����������
	for (int i = 0; i < map->COLS; i++) {
		for (int j = 0; j < map->ROWS; j++) {
			if (woodBoxRect.right > map->left[i][j] &&
				woodBoxRect.left < map->right[i][j] &&
				woodBoxRect.bottom > map->top[i][j] &&
				woodBoxRect.top < map->bottom[i][j]) {
				if (map->MAP[0][i][j] == 1) {
					//�m�F�p
					fill(0, 255, 0, 155);
					rect(map->pos[i][j].x, map->pos[i][j].y, 60, 60);
					//migi
					if (woodBoxRect.right > map->left[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
					//hidari
					if (woodBoxRect.left < map->right[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
				}
				else if (map->MAP[0][i][j] == 2) {
					if (woodBoxRect.right > map->left[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
					//hidari
					if (woodBoxRect.left < map->right[i][j]) {
						woodbox.pos.x = pustWoodBoxX;
					}
				}
			}
		}
	}
	delete map;
}
void WOODBOX::collisionY() {
	STAGE::MAPS* map = new STAGE::MAPS;
	*map = game()->container()->stage_map();
	//�v���C���[�̓����蔻��
	woodBoxRect.x = woodbox.pos.x;
	woodBoxRect.y = woodbox.pos.y;
	woodBoxRect.right = woodBoxRect.x + woodBoxRect.w;
	woodBoxRect.left = woodBoxRect.x;
	woodBoxRect.bottom = woodBoxRect.y + woodBoxRect.h;
	woodBoxRect.top = woodBoxRect.y;
	//����������
	for (int i = 0; i < map->COLS; i++) {
		for (int j = 0; j < map->ROWS; j++) {
			if (woodBoxRect.right > map->left[i][j] &&
				woodBoxRect.left < map->right[i][j] &&
				woodBoxRect.bottom > map->top[i][j] &&
				woodBoxRect.top < map->bottom[i][j]) {
				if (map->MAP[0][i][j] == 1) {
					//�m�F�p
					fill(255, 0, 0, 155);
					rect(map->pos[i][j].x, map->pos[i][j].y, 60, 60);
					//sita
					if (woodBoxRect.bottom > map->top[i][j]) {
						woodbox.pos.y = pustWoodBoxY;
					}
					//ue
					if (woodBoxRect.top < map->bottom[i][j]) {
						woodbox.pos.y = pustWoodBoxY;
					}
				}
				else if (map->MAP[0][i][j] == 2) {
					//sita
					if (woodBoxRect.bottom > map->top[i][j]) {
						woodbox.pos.y = pustWoodBoxY;
					}
					//ue
					if (woodBoxRect.top < map->bottom[i][j]) {
						woodbox.pos.y = pustWoodBoxY;
					}
				}
			}
		}
	}
	delete map;
}
void WOODBOX::gravity()
{
	woodbox.pos.y += woodbox.vec.y * woodbox.g;
}
//�`��