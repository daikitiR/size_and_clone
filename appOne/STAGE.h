#pragma once
#include "SCENE.h"
#include "libOne.h"
class STAGE :
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
    struct IMAGES
    {
        //ˆê’U‚Ë
        int image=0;
        int image2=0;
        VECTOR2 pos;
        float angle = 0;
        float size = 1;
        float transmission = 0;
    };
    struct MAPS 
    {
        int blocks = 0;
        int player = 0;
        int enemy = 0;
        int trap = 0;

    };
private:
    DATA Stage;
    IMAGES S_Images;
    MAPS Map;
public:
    STAGE(class GAME* game);
    ~STAGE();
    void draw();
    void mapcreate();
    void create();
    void nextScene();
};