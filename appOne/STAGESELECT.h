#pragma once
#include "SCENE.h"
#include "libOne.h"
class STAGESELECT :
    public SCENE
{
public:
    struct DATA
    {
        COLOR backColor = 0;
        COLOR textColor = 0;
        float textSize = 0;
        VECTOR2 pos;
        static const int memorySize = 16;
        char str[memorySize]{};
    };
private:
    DATA StageSelect;
public:
    STAGESELECT(class GAME* game);
    ~STAGESELECT();
    void draw();
    void create();
    void nextScene();
};