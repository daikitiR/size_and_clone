#include "CONTAINER.h"
#include "BLOCK.h"
BLOCK::BLOCK(class GAME* game) :
	CHARACTER(game) {
};
BLOCK::~BLOCK()
{
}

void BLOCK::create()
{
	Block = game()->container()->block();
}

void BLOCK::init()
{
	Block = game()->container()->block();
}


void BLOCK::update(int i,int j)
{
	draw(i, j);
}




void BLOCK::draw(int i,int j)
{
	image(Block.image, Block.pos.x * j, Block.pos.y * i, Block.angle, Block.size);
}
