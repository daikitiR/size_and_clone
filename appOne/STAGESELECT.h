#pragma once
#include "SCENE.h"
#include "libOne.h"
#include <string.h>

class STAGESELECT :
    public SCENE
{
public:
    struct DATA
    {

        COLOR backColor = 0;
    };
    struct IMAGES
    {
        int image = 0;
        VECTOR2 pos;
        float angle = 0;
        float size = 0;
        float transmission = 0;
    };
private:
    DATA StageSelect;
    IMAGES SS_Images;
public:
    STAGESELECT(class GAME* game);
    ~STAGESELECT();
    void draw();
    void create();
    void nextScene();
    void init();
};