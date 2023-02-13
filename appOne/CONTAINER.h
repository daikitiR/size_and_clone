#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_OVER.h"
#include "GAME_CLEAR.h"
#include "STAGESELECT.h"
#include "PLAYER.h"
#include "BLOCK.h"
class CONTAINER
{
	//数値データ
	struct DATA
	{
		TITLE::DATA title;
		STAGE::DATA stage;
		STAGESELECT::DATA stage_select;
		GAME_OVER::DATA game_over;
		GAME_CLEAR::DATA game_clear;
	};
	//画像データ
	struct IMAGES
	{
		TITLE::IMAGES title;
		STAGESELECT::IMAGES stage_select;
		STAGE::IMAGES stage;
	};
	//マップデータ
	struct MAPS
	{
		STAGE::MAPS stage;
	};
	//キャラクター
	struct CHARACTER {
		PLAYER::DATA player;
	};
	DATA Data;
	IMAGES Images;
	MAPS Maps;
	CHARACTER Character;
public:
	void load();
	void ImageSetData();
	void SceneSetData();
	void MapSetData();
	void CharacterSetData();
	//data
	const TITLE::DATA& title() { return Data.title; }
	const STAGE::DATA& stage() { return Data.stage; }
	const STAGESELECT::DATA& stageselect() { return Data.stage_select; }
	const GAME_OVER::DATA& game_over() { return Data.game_over; }
	const GAME_CLEAR::DATA& game_clear() { return Data.game_clear; }
	//image
	const TITLE::IMAGES& title_image() { return Images.title; }
	const STAGESELECT::IMAGES& stage_select_image() { return Images.stage_select; }
	const STAGE::IMAGES& stage_image() { return Images.stage; }
	//map
	STAGE::MAPS& stage_map() { return Maps.stage; }
	//character
	const PLAYER::DATA& player() { return Character.player; }
};