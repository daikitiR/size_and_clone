#pragma once
#include "SCENE.h"
#include "libOne.h"
class GAME_OVER :
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
    DATA Game_over;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void draw();
    void create();
    void nextScene();

};