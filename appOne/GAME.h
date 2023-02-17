#pragma once
class GAME
{
//ƒRƒ“ƒeƒi
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }

public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		STAGE_SELECT_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES,
	}; 
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
	class CHARACTER* Player;
	class CLONE* Clone;
	int EndTrigger = 0;
public:
	class CHARACTER* player() { return Player; }
	class CLONE* clone() { return Clone; }
	GAME();
	virtual ~GAME();
	void run();
	void changeScene(SCENE_ID sceneId);
};

