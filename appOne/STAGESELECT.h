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
        COLOR textColor = 0;
        const static int stageNum = 1;
        static const int chars = 128;
        static const int memorySize = 16;
        float textSize = 0;
        float expTextSize = 0;
        struct EXPLAN {
            char str[memorySize]{};
            char explain[chars]{};
            VECTOR2 pos;
            VECTOR2 exppos;
        };
        EXPLAN string[stageNum];
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
    IMAGES S_Images;
public:
    STAGESELECT(class GAME* game);
    ~STAGESELECT();
    void draw();
    void create();
    void nextScene();
private:
    void newLineText();
};