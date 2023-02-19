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
        const static int stageNum = 2;
        static const int chars = 128;
        static const int memorySize = 16;
        COLOR backColor = 0;
        COLOR textColor = 0;
        float textSize = 0;
        float expTextSize = 0;
        struct SELECTBLOCK {
            int Block;
            float Size;
            VECTOR2 pos;
        };
        SELECTBLOCK selectBlock[stageNum]{};
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
    IMAGES SS_Images;
public:
    STAGESELECT(class GAME* game);
    ~STAGESELECT();
    void draw();
    void create();
    void nextScene();
    void init();
};