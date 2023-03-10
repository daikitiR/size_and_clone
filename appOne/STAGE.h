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
        int Woodnum = 0;
    };
    struct IMAGES
    {
        int image=0;
        int back=0;
        int tile = 0;
        int thorn = 0;
        int clone_machine = 0;
        int woodBox = 0;
        int button = 0;
        VECTOR2 pos;
        float angle = 0;
        float size = 1;
        float transmission = 0;
    };
    struct MAPS 
    {
        bool col = 0;
        static const int MAPNUM = 2;
        static const int COLS = 18;
        static const int ROWS = 32;
        int MAP[MAPNUM][COLS][ROWS]{ {} };
        VECTOR2 pos[COLS][ROWS];
        float w;
        float h;
        float right[COLS][ROWS];
        float left[COLS][ROWS];
        float top[COLS][ROWS]; 
        float bottom[COLS][ROWS];
    };
    
private:
    DATA Stage;
    MAPS Map;
    IMAGES S_Images;
public:
    STAGE(class GAME* game);
    ~STAGE();
    void draw();
    void create();
    void update();
    void nextScene();
};