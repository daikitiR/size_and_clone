#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_OVER.h"
#include "GAME_CLEAR.h"
class CONTAINER
{
	struct DATA
	{
		TITLE::DATA title;
		STAGE::DATA stage;
		GAME_OVER::DATA game_over;
		GAME_CLEAR::DATA game_clear;
	};
	DATA Data;
public:
	void load();
	void SceneSetData();
	const TITLE::DATA& title() { return Data.title; }
	const STAGE::DATA& stage() { return Data.stage; }
	const GAME_OVER::DATA& game_over() { return Data.game_over; }
	const GAME_CLEAR::DATA& game_clear() { return Data.game_clear; }
};