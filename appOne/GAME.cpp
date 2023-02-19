#include "TITLE.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
#include "libOne.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "CLONE.h"
#include "WOODBOX.h"
#include "GAME.h"
GAME::GAME() {
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[STAGE_SELECT_ID] = new STAGESELECT(this);
	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	CurSceneId = TITLE_ID;
	Player = new PLAYER(this);
	Clone = new CLONE(this);
	WoodBox = new WOODBOX(this);
}

GAME::~GAME()
{
	delete Container;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	delete Player;
	delete Clone;
	delete WoodBox;
}

void GAME::run()
{
	window(1920, 1080,full);
	Container->load();
	for (int i = 0; i < NUM_SCENES; i++) {
		Scenes[i]->create();
	}
	Player->create();
	Clone->create();
	WoodBox->create();
	while (notQuit) {
		Scenes[CurSceneId]->proc();
	}
}

void GAME::changeScene(SCENE_ID sceneId)
{
	CurSceneId = sceneId;
}
