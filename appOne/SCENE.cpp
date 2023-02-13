#include "SCENE.h"
SCENE::SCENE(GAME* game) :
	GAME_OBJECT(game) {

}

SCENE::~SCENE()
{
}

void SCENE::create()
{
}

void SCENE::init()
{
}
void SCENE::update()
{
}
void SCENE::proc()
{
	draw();
	update();
	nextScene();
}
void SCENE::draw()
{
}
void SCENE::nextScene()
{
}